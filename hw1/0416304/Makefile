
lex: 
	lex hw1.l

all: lex.yy.c
	gcc lex.yy.c -o scanner -lfl 

clean: 
	rm -f scanner
