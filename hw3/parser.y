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


void dumpsymbol() {
    int i, j;
    for(i=0;i< 110;i++)
        printf("=");
    printf("\n");
    printf("%-33s%-11s%-11s%-17s%-11s\n","Name","Kind","Level","Type","Attribute");
    for(i=0;i< 110;i++)
        printf("-");
    printf("\n");
    
    for(i = 0 ;i < symbol_table.level ; i ++)
        for(j = 0 ;j < symbol_table.levels[i].size ; j ++)
        {
            printf("%-33s", "func");
            printf("%-11s", "function");
            printf("%d%-10s", 0,"(global)");
            printf("%-17s", "boolean");
            printf("%-11s", "integer, real [2][3]");
            printf("\n");
        }
    for(i=0;i< 110;i++)
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
    struct ParamsList *params;
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

%type<type> type scalar_type array_type 
%type<id_list> id_list
%type<rvalue> literal_const
%type<func> func_decl
%type<params> param param_list opt_param_list
%type<int_val> int_const

/* start symbol */
%start program
%%

program			: ID {
                    //Symbol *prog_name = symbol($1, T_PROGRAM, NULL, NULL);
                    //symbol_table_insert(prog_name);
                } MK_SEMICOLON 
                program_body
                END ID{
                    if(strcmp($1, $6)){
                        printf("program id mismatch.\n");
                    }
                }
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
                    if(check_redeclar(id_node) == false){
                        Symbol *s = symbol(id_node->id, T_VAR, type, NULL);
                        symbol_table_insert(s);
                    }
                }
            } 
            | VAR id_list MK_COLON array_type MK_SEMICOLON {
                /* array type declaration */
                IDList *id_list = $2;
                TypeNode *type = $4;
            }
            
            | VAR id_list MK_COLON literal_const MK_SEMICOLON     {
                /* const declaration */
                IDList *id_list = $2;
            }
			;
int_const	:	INT_CONST { $$ = $1; }
			|	OCTAL_CONST { $$ = $1; }
			;

literal_const	: int_const {
                int val = $1;
                $$ = rvalue_node(T_INTEGER, &val);
                printf("rvalue: %d\n", $$->value.int_value);
            }
			| OP_SUB int_const {
                int val = -1 * $2;
                $$ = rvalue_node(T_INTEGER, &val);
                printf("rvalue: %d\n", $$->value.int_value);
            }
			| FLOAT_CONST {
                float val = $1;
                $$ = rvalue_node(T_REAL, &val);
                printf("rvalue: %f\n", $$->value.real_value);
            }
			| OP_SUB FLOAT_CONST {
                float val = -1 * $2;
                $$ = rvalue_node(T_REAL, &val);
                printf("rvalue: %f\n", $$->value.real_value);
            }
			| SCIENTIFIC {
                float val = $1;
                $$ = rvalue_node(T_REAL, &val);
                printf("rvalue: %f\n", $$->value.real_value);
            }
			| OP_SUB SCIENTIFIC {
                float val = -1 * $2;
                $$ = rvalue_node(T_REAL, &val);
                printf("rvalue: %f\n", $$->value.real_value);
            }
			| STR_CONST {
                $$ = rvalue_node(T_STRING, $1);
            }
			| TRUE {
                bool val = true;
                $$ = rvalue_node(T_BOOLEAN, &val);
                printf("rvalue: %d\n", $$->value.bool_value);
            }
			| FALSE {
                bool val  = false; 
                $$ = rvalue_node(T_BOOLEAN, &val);
                printf("rvalue: %d\n", $$->value.bool_value);
            
            }
			;

opt_func_decl_list	: func_decl_list
			| /* epsilon */
			;

func_decl_list		: func_decl_list func_decl
			| func_decl
			;

func_decl		: ID {
                
                } MK_LPAREN opt_param_list {
                
                }MK_RPAREN opt_type {
                
                }MK_SEMICOLON
			  compound_stmt
			  END ID {
              
              }
			;

opt_param_list		: param_list {}
			| /* epsilon */ {}
			;

param_list		: param_list MK_SEMICOLON param {}
			| param {}
			;

param			: id_list MK_COLON type {}
			;

id_list		: id_list MK_COMMA ID {
                id_list_insert($$, $3);
            }
			| ID {
                $$ = id_list_create();
                id_list_insert($$, $1);
            }
			;

opt_type		: MK_COLON type
			| /* epsilon */
			;

type			: scalar_type
			| array_type
			;

scalar_type	: INTEGER { $$ = type_node(T_INTEGER); }
			| REAL { $$ = type_node(T_REAL); }
			| BOOLEAN { $$ = type_node(T_BOOLEAN);}
			| STRING { $$ = type_node(T_STRING); }
			;

array_type	: ARRAY int_const TO int_const OF type {
                $$ = array_type_node($6, $2, $4);        
            }
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
                    symbol_table_new_scope();
                }
			  opt_decl_list
			  opt_stmt_list
			  END {
                    symbol_table_delete_scope();
              }
			;

opt_stmt_list		: stmt_list
			| /* epsilon */
			;

stmt_list		: stmt_list stmt
			| stmt
			;

simple_stmt		: var_ref OP_ASSIGN boolean_expr MK_SEMICOLON
			| PRINT boolean_expr MK_SEMICOLON
			| READ boolean_expr MK_SEMICOLON
			;

proc_call_stmt		: ID MK_LPAREN opt_boolean_expr_list MK_RPAREN MK_SEMICOLON
			;

cond_stmt		: IF boolean_expr THEN
			  opt_stmt_list
			  ELSE
			  opt_stmt_list
			  END IF
			| IF boolean_expr THEN opt_stmt_list END IF
			;

while_stmt		: WHILE boolean_expr DO
			  opt_stmt_list
			  END DO
			;

for_stmt		: FOR ID OP_ASSIGN int_const TO int_const DO
			  opt_stmt_list
			  END DO
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

var_ref			: ID{

            }
			| var_ref dim {
                
            }
			;

dim			: MK_LB boolean_expr MK_RB {

            }
			;

%%


int yyerror( char *msg )
{
	(void) msg;
	fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
	fprintf( stderr, "|--------------------------------------------------------------------------\n" );
	exit(-1);
}

