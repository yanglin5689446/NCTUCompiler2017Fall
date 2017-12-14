/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 2 main function
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */
extern char *filename;

int  main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );
    filename = strtok(argv[1], "/");
    char *s = filename;
    while(s){
        filename = s;
        s = strtok(NULL, "/");
    }
    filename = strtok(filename, ".");

	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}
	
	yyin = fp;
	yyparse();	/* primary procedure of parser */
	
	exit(0);
}

