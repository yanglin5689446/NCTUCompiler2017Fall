
#ifndef CPP_H
#define CPP_H

extern "C" {
    int yyerror(const char *msg);
    extern int yylex(void);
} 

#endif
