%{
#include <stdio.h>
#include <stdlib.h>

extern int linenum;             /* declared in lex.l */
extern FILE *yyin;              /* declared by lex */
extern char *yytext;            /* declared by lex */
extern char buf[256];           /* declared in lex.l */
%}

%token CONSTANT_INT CONSTANT_REAL CONSTANT_STRING 
%token ID
%token MOD
%token ASSIGN
%token SMALLER
%token SMALLER_EQUAL
%token NOT_EQUAL
%token GREATER_EQUAL
%token GREATER
%token EQUAL
%token AND
%token OR
%token NOT
%token ARRAY
%token _BEGIN
%token BOOLEAN
%token DEF
%token DO
%token ELSE
%token _END
%token FALSE
%token FOR
%token INTEGER
%token IF
%token OF
%token PRINT
%token READ
%token REAL
%token STRING
%token THEN
%token TO
%token TRUE
%token RETURN
%token VAR
%token WHILE
%start program

%left '('
%nonassoc UMINUS
%left '*' '/'
%left '+' '-'
%left NOT
%left AND
%left OR

%%

epsilon: ;

program: ID ';' program_body _END ID ;
program_body: var_declars func_declars compound_statement ;


/* types, value */
type: INTEGER  | REAL  | STRING  | BOOLEAN ; 
constant: CONSTANT_INT  | CONSTANT_REAL  | CONSTANT_STRING  | TRUE  | FALSE ;

/* declaration */
var_declars: var_declar var_declars | epsilon ;
var_declar: VAR identifiers ':' type ';' 
          | VAR identifiers ':' array_type ';' 
          | VAR identifiers ':' constant ';';
array_type:  type  | ARRAY CONSTANT_INT TO CONSTANT_INT OF array_type;
func_declars: func_declar func_declars | epsilon ;
func_declar: ID '(' arguments ')' func_type ';' compound_statement _END ID  ;
arguments: argument arguments| ',' argument arguments | epsilon ;
argument: identifiers ':' type
func_type: ':' type | epsilon;
identifiers: ID identifiers | ',' ID identifiers  | epsilon  ;

/* statements */
compound_statement: _BEGIN var_declars statements _END;
statements: statement statements  | epsilon ;
statement: read ';'| print ';' | assignment ';'| return ';'| function_call ';'| compound_statement | flow ;


read: READ var;
print: PRINT expr | PRINT CONSTANT_STRING ;
assignment: var ASSIGN expr;
return: RETURN expr;

var: ID var_;
var_: '[' expr ']' var_ | epsilon ;
function_call: ID '(' exprs ')';                       /* function call */
exprs: expr exprs | ',' expr exprs | epsilon ;
/* expr: operand | expr binary_operator expr | '(' expr ')'; */
expr: operand expr_ | '(' expr ')' expr_; 
expr_: binary_operator expr | epsilon;
operand: unary_operator operand %prec UMINUS | var | function_call | CONSTANT_INT | CONSTANT_REAL | TRUE | FALSE;
unary_operator: '-' | NOT;
binary_operator: '+' | '-' | '*' | '/' | MOD | SMALLER | SMALLER_EQUAL;
binary_operator: EQUAL | NOT_EQUAL | GREATER_EQUAL | GREATER | AND | OR;

flow: if | while | for;
if: IF expr THEN statements else _END IF;
else: ELSE statements | epsilon;
while: WHILE expr DO statements _END DO;
for: FOR ID ASSIGN CONSTANT_INT TO CONSTANT_INT DO statements _END DO;

%%

int yyerror( char *msg )
{
    fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
    fprintf( stderr, "|--------------------------------------------------------------------------\n" );
    exit(-1);
}

int  main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );
	
	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}
	
	yyin = fp;
	yyparse();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}

