%{
/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 2 YACC sample
 */
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include "cpp.h"
#include "semantic.h"

extern int linenum;		/* declared in lex.l */
extern FILE *yyin;		/* declared by lex */
extern char *yytext;		/* declared by lex */
extern char buf[256];		/* declared in lex.l */
extern int yylex(void);
int yyerror(const char* );
int Opt_D = 1;

SymbolTable symbol_table;
%}

%union{
    int int_val;
    float real_val;
    char *str_val;
    int *node_type;     // node type
    struct IDList *id_list;
    struct TypeNode *type;
    struct ConstValue *rvalue;
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
%type<params> param param_list opt_param_list
%type<int_val> int_const

/* start symbol */
%start program
%%

program		: ID { symbol_table.insert(Symbol($1, T_PROGRAM ,new TypeNode(T_VOID))); } MK_SEMICOLON 
            program_body
            END ID { if(Opt_D)symbol_table.dump_symbols(); }
			;

program_body		: opt_decl_list opt_func_decl_list compound_stmt
            ;

opt_decl_list	    : decl_list 
			| /* epsilon */
			;

decl_list	: decl_list decl
			| decl
			;

decl		: VAR id_list MK_COLON scalar_type MK_SEMICOLON { 
                for(auto& id: $2->ids)symbol_table.insert(Symbol(id.c_str(), T_VAR, $4)); 
                delete $2;
            } 
            | VAR id_list MK_COLON array_type MK_SEMICOLON { 
                for(auto& id: $2->ids)symbol_table.insert(Symbol(id.c_str(), T_ARRAY , $4)); 
                delete $2;
            }
            | VAR id_list MK_COLON literal_const MK_SEMICOLON { 
                for(auto& id: $2->ids)
                    symbol_table.insert(Symbol(id.c_str(), T_CONST_VAR, new TypeNode($4->type), new AttrNode($4))); 
                delete $2;
            }
			;
int_const	:	INT_CONST { $$ = $1; }
			|	OCTAL_CONST { $$ = $1; }
			;

literal_const	: int_const { $$ = new ConstValue(T_INTEGER, new int($1));}
			| OP_SUB int_const { $$ = new ConstValue(T_INTEGER, new int(-1 * $2)); }
			| FLOAT_CONST { $$ = new ConstValue(T_REAL, new float($1)); }
			| OP_SUB FLOAT_CONST { $$ = new ConstValue(T_REAL, new float( -1 * $2)); }
			| SCIENTIFIC { $$ = new ConstValue(T_REAL, new float($1)); }
			| OP_SUB SCIENTIFIC { $$ = new ConstValue(T_REAL, new float( -1 * $2 )); }
			| STR_CONST { $$ = new ConstValue(T_STRING, $1); }
			| TRUE { $$ = new ConstValue(T_BOOLEAN, new bool(true)); }
			| FALSE { $$ = new ConstValue(T_BOOLEAN, new bool(false)); }
			;

opt_func_decl_list	: func_decl_list
			| /* epsilon */
			;

func_decl_list		: func_decl_list func_decl
			| func_decl
			;

func_decl	: ID { symbol_table.new_scope(FUNCTION_SCOPE); } MK_LPAREN opt_param_list MK_RPAREN 
            opt_type MK_SEMICOLON { 
                symbol_table.insert(Symbol($1, T_FUNCTION, $6, new AttrNode($4)), GLOBAL_SCOPE); 
                for(auto &param: $4->params) symbol_table.insert(Symbol(param.name, T_PARAM, param.type)); 
            } 
			compound_stmt 
			END ID { /* check $1 $12 equal */ } 
			;

opt_param_list		: param_list { $$ = $1; }
			| /* epsilon */ { $$ = new ParamList(); }
			;

param_list	: param_list MK_SEMICOLON param { $$->extend($3); }
			| param { $$ = $1; }
			;

param		: id_list MK_COLON type { $$ = new ParamList($1, $3); }
			;

id_list		: id_list MK_COMMA ID { $$->insert($3); }
			| ID { $$ = new IDList($1); }
			;

opt_type		: MK_COLON type { $$ = $2; }
			| /* epsilon */ { $$ = new TypeNode(T_VOID); }
			;

type			: scalar_type
			| array_type
			;

scalar_type	: INTEGER { $$ = new TypeNode(T_INTEGER); }
			| REAL { $$ = new TypeNode(T_REAL); }
			| BOOLEAN { $$ = new TypeNode(T_BOOLEAN);}
			| STRING { $$ = new TypeNode(T_STRING); }
			;

array_type	: ARRAY int_const TO int_const OF type { $$ = new TypeNode($6, $2, $4); }
			;

stmt		: compound_stmt
			| simple_stmt
			| cond_stmt
			| while_stmt
			| for_stmt
			| return_stmt
			| proc_call_stmt
			;

compound_stmt	: BEG { symbol_table.new_scope(); }
			    opt_decl_list
			    opt_stmt_list
			    END { symbol_table.delete_scope(Opt_D); }
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
                symbol_table.new_scope();
                symbol_table.insert(Symbol($2, T_LOOP_VAR, new TypeNode(T_INTEGER), NULL));
            }
            DO opt_stmt_list END DO { symbol_table.delete_scope(false); }
			;

return_stmt	: RETURN boolean_expr MK_SEMICOLON
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

rel_op		: OP_LT
			| OP_LE
			| OP_EQ
			| OP_GE
			| OP_GT
			| OP_NE
			;

expr		: expr add_op term
			| term
			;

add_op		: OP_ADD
			| OP_SUB
			;

term		: term mul_op factor
			| factor
			;

mul_op		: OP_MUL
			| OP_DIV
			| OP_MOD
			;

factor		: var_ref
			| OP_SUB var_ref
			| MK_LPAREN boolean_expr MK_RPAREN
			| OP_SUB MK_LPAREN boolean_expr MK_RPAREN
			| ID MK_LPAREN opt_boolean_expr_list MK_RPAREN
			| OP_SUB ID MK_LPAREN opt_boolean_expr_list MK_RPAREN
			| literal_const
			;

var_ref		: ID
			| var_ref dim 
			;

dim			: MK_LB boolean_expr MK_RB ;

%%
int yyerror( const char *msg ){ exit(-1); }

