%{
/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 2 YACC sample
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include "nodedef.h"
#include "semantic.h"

extern int linenum;		/* declared in lex.l */
extern FILE *yyin;		/* declared by lex */
extern char *yytext;		/* declared by lex */
extern char buf[256];		/* declared in lex.l */
extern int yylex(void);
int yyerror(char* );
int Opt_D = 1;
bool parsing_func = false;


void dumpsymbol() {
    const char* __type_names[] = { "program", "void", "string", "real", "integer","boolean", "function", "", "parameter", "variable", "constant", "variable", "loop_variable" };
    for(int i = 0; i < 110; i++)
        printf("=");
    printf("\n");
    printf("%-33s%-11s%-11s%-17s%-11s\n", "Name", "Kind", "Level", "Type", "Attribute");
    for(int i = 0; i < 110; i++)
        printf("-");
    printf("\n");
    int n = symbol_table.level;
    for(int i = 0 ;i < symbol_table.levels[n].size ; i ++){
        Symbol *symbol = symbol_table.levels[n].symbols + i;
        if(symbol->node_type == T_LOOP_VAR)continue;
        // print symbol name
        printf("%-33s", symbol->name);
        // print symbol node_type (array, function, program ... etc)
        printf("%-11s", __type_names[symbol->node_type]);
        // print scope
        printf("%d%-10s", n, n ? "(local)" : "(global)");
        // print type
        char type[64] = ""; 
        if(symbol->type){
            sprintf(type, "%s", __type_names[symbol->type->type]);
            if(symbol->type->dims){
                strcat(type, " ");
                for(int k =  symbol->type->dims-1 ; k >= 0 ; k --){
                    int l = strlen(type);
                    type[l++] = '[';
                    sprintf(type + l, "%d", symbol->type->dim_nodes[k].size);
                    l = strlen(type);
                    type[l++] = ']';
                    type[l] = '\0';
                }
            }
        }
        printf("%-17s", type);
        // print attribute
        if(symbol->node_type == T_VAR || symbol->node_type == T_CONST_VAR){
            // check symbol have attribute or not
            if(symbol->attr != NULL){
                RValueNode *rvalue = symbol->attr->rvalue; 
                NodeType type = rvalue->type;
                if(type == T_INTEGER)
                    printf("%-11d", rvalue->value.int_value);
                else if(type == T_REAL)
                    printf("%-11f", rvalue->value.real_value);
                else if(type == T_STRING)
                    printf("%-11s", rvalue->value.str_value);
                else if(type == T_BOOLEAN)
                    printf("%-11s", rvalue->value.bool_value ? "true" : "false");
            }
        }
        else if(symbol->node_type == T_FUNCTION){
            char serialized_params[128] = "";
            for(int p = 0 ;p < symbol->attr->func_attr->params_size ; p ++){
                if(p)strcat(serialized_params, ", ");
                Param param = symbol->attr->func_attr->params[p];
                strcat(serialized_params, __type_names[param.type->type]);
                if(param.type->dims){
                    strcat(serialized_params, " ");
                    for(int k = param.type->dims - 1; k >= 0; k --){
                        int l = strlen(serialized_params);
                        serialized_params[l++] = '[';
                        sprintf(serialized_params + l, "%d", param.type->dim_nodes[k].size);
                        l = strlen(serialized_params);
                        serialized_params[l++] = ']';
                        serialized_params[l] = '\0';
                    }
                }
            }
            printf("%-11s", serialized_params);
        }
        printf("\n");
    }
    for(int i = 0; i < 110; i++)
        printf("-");
    printf("\n");
}

%}

%union{
    int int_val;
    float real_val;
    char *str_val;
    struct NodeType *node_type;
    struct TypeNode *type;
    struct IDList *id_list;
    struct RValueNode *rvalue;
    struct FuncNode *func;
    struct ParamList *params;
    struct ExprList *expr;
    struct ExprNode *exprs;
}

/* tokens */
%token ARRAY BEG BOOLEAN DEF DO ELSE END FOR INTEGER IF OF PRINT READ REAL RETURN STRING THEN TO VAR WHILE 
%token OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD OP_ASSIGN OP_EQ OP_NE OP_GT OP_LT OP_GE OP_LE OP_AND OP_OR OP_NOT 
%token MK_COMMA MK_COLON MK_SEMICOLON MK_LPAREN MK_RPAREN MK_LB MK_RB 

%token TRUE FALSE

%token<str_val> ID
%token<int_val> INT_CONST
%token<int_val> OCTAL_CONST
%token<real_val> FLOAT_CONST 
%token<real_val> SCIENTIFIC 
%token<str_val> STR_CONST

%type<type> type scalar_type array_type opt_type 
%type<id_list> id_list
%type<rvalue> literal_const
%type<func> func_decl
%type<params> param param_list opt_param_list
%type<int_val> int_const

/* start symbol */
%start program
%%

program		: ID {
                TypeNode *type = (TypeNode*)malloc(sizeof(TypeNode));
                *type = (TypeNode){ .type = T_VOID, .dims = 0, .__max_dims = 0, .dim_nodes = NULL };
                Symbol *prog_name = symbol($1, T_PROGRAM, type, NULL);
                symbol_table_insert(prog_name);
            } MK_SEMICOLON 
            program_body
            END ID { if(Opt_D)dumpsymbol(); }
			;

program_body		: opt_decl_list opt_func_decl_list compound_stmt
			;

opt_decl_list	    : decl_list 
			| /* epsilon */
			;

decl_list		: decl_list decl
			| decl
			;

decl		: VAR id_list MK_COLON scalar_type MK_SEMICOLON {       
                /* scalar type declaration */
                IDList *id_list = $2;
                TypeNode *type = $4;
                for(int i = 0; i < id_list->size ;i ++){
                    IDNode *id_node = id_list->id_nodes + i;
                    if(check_redeclar(id_node->id) == false){
                        Symbol *s = symbol(id_node->id, T_VAR, type, NULL);
                        symbol_table_insert(s);
                    }
                    else printf("<Error> found in Line %d: symbol %s is redeclared\n", linenum, id_node->id);
                }
            } 
            | VAR id_list MK_COLON array_type MK_SEMICOLON {
                /* array type declaration */
                IDList *id_list = $2;
                TypeNode *type = $4;
                for(int i = 0; i < id_list->size ;i ++){
                    IDNode *id_node = id_list->id_nodes + i;
                    if(check_redeclar(id_node->id) == false){
                        Symbol *s = symbol(id_node->id, T_ARRAY, type, NULL);
                        symbol_table_insert(s);
                    }
                    else printf("<Error> found in Line %d: symbol %s is redeclared\n", linenum, id_node->id);
                }
            }
            
            | VAR id_list MK_COLON literal_const MK_SEMICOLON     {
                /* const declaration */
                IDList *id_list = $2;
                TypeNode *type = type_node($4->type);
                AttrNode *attr = (AttrNode*)malloc(sizeof(AttrNode));
                attr->rvalue = (RValueNode*)malloc(sizeof(RValueNode));
                attr->rvalue->type = $4->type;
                if($4->type == T_INTEGER)attr->rvalue->value.int_value = $4->value.int_value;
                else if($4->type == T_REAL)attr->rvalue->value.real_value = $4->value.real_value;
                else if($4->type == T_STRING)attr->rvalue->value.str_value = strdup($4->value.str_value);
                else if($4->type == T_BOOLEAN)attr->rvalue->value.bool_value = $4->value.bool_value;
                for(int i = 0; i < id_list->size ;i ++){
                    IDNode *id_node = id_list->id_nodes + i;
                    if(check_redeclar(id_node->id) == false){
                        Symbol *s = symbol(id_node->id, T_CONST_VAR, type, attr);
                        symbol_table_insert(s);
                    }
                    else printf("<Error> found in Line %d: symbol %s is redeclared\n", linenum, id_node->id);
                }
            }
			;
int_const	:	INT_CONST { $$ = $1; }
			|	OCTAL_CONST { $$ = $1; }
			;

literal_const	: int_const {
                int val = $1;
                $$ = rvalue_node(T_INTEGER, &val);
            }
			| OP_SUB int_const {
                int val = -1 * $2;
                $$ = rvalue_node(T_INTEGER, &val);
            }
			| FLOAT_CONST {
                float val = $1;
                $$ = rvalue_node(T_REAL, &val);
            }
			| OP_SUB FLOAT_CONST {
                float val = -1 * $2;
                $$ = rvalue_node(T_REAL, &val);
            }
			| SCIENTIFIC {
                float val = $1;
                $$ = rvalue_node(T_REAL, &val);
            }
			| OP_SUB SCIENTIFIC {
                float val = -1 * $2;
                $$ = rvalue_node(T_REAL, &val);
            }
			| STR_CONST {
                $$ = rvalue_node(T_STRING, $1);
            }
			| TRUE {
                bool val = true;
                $$ = rvalue_node(T_BOOLEAN, &val);
            }
			| FALSE {
                bool val  = false; 
                $$ = rvalue_node(T_BOOLEAN, &val);
            }
			;

opt_func_decl_list	: func_decl_list
			| /* epsilon */
			;

func_decl_list		: func_decl_list func_decl
			| func_decl
			;

func_decl	: ID MK_LPAREN {
                parsing_func = true;
                symbol_table_new_scope();
            } opt_param_list MK_RPAREN opt_type {
                ParamList *param_list = $4;
                TypeNode *type = $6;
                AttrNode *attr = (AttrNode*)malloc(sizeof(AttrNode));
                attr->func_attr = (FuncAttr*)malloc(sizeof(FuncAttr));
                attr->func_attr->return_type = type;
                attr->func_attr->params_size = param_list->size;
                attr->func_attr->params = param_list->params;
                Symbol *func_name = symbol($1, T_FUNCTION, type, attr);
                symbol_table_global(func_name);
                
                for(int i = 0 ;i < param_list->size ;i ++){
                    Param *p = param_list->params + i;
                    if(check_redeclar(p->name) == false){
                        Symbol *s = symbol(p->name, T_PARAM, p->type, NULL);
                        symbol_table_insert(s);
                    }
                    else printf("<Error> found in Line %d: symbol %s is redeclared\n", linenum, p->name);
                }
            } MK_SEMICOLON
			compound_stmt 
			END ID {
                // check $1 $12 equal 
            } 
			;

opt_param_list		: param_list { $$ = $1; }
			| /* epsilon */ { $$ = param_list_create(); }
			;

param_list	: param_list MK_SEMICOLON param {
                param_list_extend($$, $3);
            }
			| param { $$ = $1; }
			;

param		: id_list MK_COLON type {
                $$ = param_list_create(); 
                IDList *id_list = $1;
                TypeNode *type = $3;
                for(int i = 0; i < id_list->size ;i ++){
                    IDNode *id_node = id_list->id_nodes + i;
                    Param *p = param(id_node->id, type->dims ? T_ARRAY : T_VAR , type);
                    param_list_insert($$, p);
                }   
            }
			;

id_list		: id_list MK_COMMA ID {
                id_list_insert($$, $3);
            }
			| ID {
                $$ = id_list_create();
                id_list_insert($$, $1);
            }
			;

opt_type		: MK_COLON type { $$ = $2; }
			| /* epsilon */ { $$ = type_node(T_VOID); }
			;

type			: scalar_type
			| array_type
			;

scalar_type	: INTEGER { $$ = type_node(T_INTEGER); }
			| REAL { $$ = type_node(T_REAL); }
			| BOOLEAN { $$ = type_node(T_BOOLEAN);}
			| STRING { $$ = type_node(T_STRING); }
			;

array_type	: ARRAY int_const TO int_const OF type { $$ = array_type_node($6, $2, $4); }
			;

stmt			: compound_stmt
			| simple_stmt
			| cond_stmt
			| while_stmt
			| for_stmt
			| return_stmt
			| proc_call_stmt
			;

compound_stmt	: BEG {
                    if(!parsing_func) symbol_table_new_scope();
                    else parsing_func = false;
                }
			    opt_decl_list
			    opt_stmt_list
			    END {
                    if(Opt_D)dumpsymbol();
                    symbol_table_delete_scope();
                }
			;

opt_stmt_list		: stmt_list
			| /* epsilon */
			;

stmt_list	: stmt_list stmt
			| stmt
			;

simple_stmt		: var_ref OP_ASSIGN boolean_expr MK_SEMICOLON
			| PRINT boolean_expr MK_SEMICOLON
			| READ boolean_expr MK_SEMICOLON
			;

proc_call_stmt		: ID MK_LPAREN opt_boolean_expr_list MK_RPAREN MK_SEMICOLON
			;

cond_stmt		: IF boolean_expr THEN opt_stmt_list ELSE opt_stmt_list END IF
			| IF boolean_expr THEN opt_stmt_list END IF
			;

while_stmt		: WHILE boolean_expr DO
			  opt_stmt_list
			  END DO
			;

for_stmt	: FOR ID OP_ASSIGN int_const TO int_const {
                symbol_table_new_scope(); 
                if(check_redeclar($2) == false){
                    Symbol *s = symbol($2, T_LOOP_VAR, type_node(T_INTEGER), NULL);
                    symbol_table_insert(s);
                }
                else printf("<Error> found in Line %d: symbol %s is redeclared\n", linenum, $2);
            }
                DO
			    opt_stmt_list
			END DO { symbol_table_delete_scope(); }
			;

return_stmt		: RETURN boolean_expr MK_SEMICOLON
			;

opt_boolean_expr_list	: boolean_expr_list
			| /* epsilon */
			;

boolean_expr_list	: boolean_expr_list MK_COMMA boolean_expr
			| boolean_expr
			;

boolean_expr		: boolean_expr OP_OR boolean_term
			| boolean_term
			;

boolean_term		: boolean_term OP_AND boolean_factor
			| boolean_factor
			;

boolean_factor		: OP_NOT boolean_factor 
			| relop_expr
			;

relop_expr		: expr rel_op expr
			| expr
			;

rel_op			: OP_LT
			| OP_LE
			| OP_EQ
			| OP_GE
			| OP_GT
			| OP_NE
			;

expr			: expr add_op term
			| term
			;

add_op			: OP_ADD
			| OP_SUB
			;

term			: term mul_op factor
			| factor
			;

mul_op			: OP_MUL
			| OP_DIV
			| OP_MOD
			;

factor			: var_ref
			| OP_SUB var_ref
			| MK_LPAREN boolean_expr MK_RPAREN
			| OP_SUB MK_LPAREN boolean_expr MK_RPAREN
			| ID MK_LPAREN opt_boolean_expr_list MK_RPAREN
			| OP_SUB ID MK_LPAREN opt_boolean_expr_list MK_RPAREN
			| literal_const
			;

var_ref			: ID
			| var_ref dim 
			;

dim			: MK_LB boolean_expr MK_RB ;

%%

int yyerror( char *msg )
{
	exit(-1);
}

