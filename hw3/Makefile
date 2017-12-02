TARGET   = parser
OBJECT   = lex.yy.c y.tab.c y.output parser y.tab.h semantic.o
CC       = gcc
CFLAGS   = -Wall -Wextra -pedantic -g3 
LEX      = flex
YACC     = yacc -v -t
YACCFLAG = -d
LIBS     = -lfl -lm

all: $(TARGET)
	
$(TARGET): y.tab.c lex.yy.c main.c semantic.c
	$(CC) $^ -o $(TARGET) $(CCFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c $< 

y.tab.c: parser.y
	$(YACC) $(YACCFLAG) $<

lex.yy.c: lex.l
	$(LEX) $<

.PHONY: clean

clean:
	$(RM) -f $(TARGET) $(OBJECT)
