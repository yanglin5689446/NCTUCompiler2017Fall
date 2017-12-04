

y.tab.c: 
	yacc -d -v parser.y

lex.yy.c:y.tab.c
	lex scanner.l

all: lex.yy.c y.tab.c
	gcc -Wno-implicit-function-declaration lex.yy.c y.tab.c -ly -lfl -o parser

clean: 
	rm -f lex.yy.c y.output y.tab.c y.tab.h parser
