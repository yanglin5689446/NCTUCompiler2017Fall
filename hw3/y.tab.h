/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    BEG = 259,
    BOOLEAN = 260,
    DEF = 261,
    DO = 262,
    ELSE = 263,
    END = 264,
    FOR = 265,
    INTEGER = 266,
    IF = 267,
    OF = 268,
    PRINT = 269,
    READ = 270,
    REAL = 271,
    RETURN = 272,
    STRING = 273,
    THEN = 274,
    TO = 275,
    VAR = 276,
    WHILE = 277,
    OP_ADD = 278,
    OP_SUB = 279,
    OP_MUL = 280,
    OP_DIV = 281,
    OP_MOD = 282,
    OP_ASSIGN = 283,
    OP_EQ = 284,
    OP_NE = 285,
    OP_GT = 286,
    OP_LT = 287,
    OP_GE = 288,
    OP_LE = 289,
    OP_AND = 290,
    OP_OR = 291,
    OP_NOT = 292,
    MK_COMMA = 293,
    MK_COLON = 294,
    MK_SEMICOLON = 295,
    MK_LPAREN = 296,
    MK_RPAREN = 297,
    MK_LB = 298,
    MK_RB = 299,
    TRUE = 300,
    FALSE = 301,
    ID = 302,
    INT_CONST = 303,
    OCTAL_CONST = 304,
    FLOAT_CONST = 305,
    SCIENTIFIC = 306,
    STR_CONST = 307
  };
#endif
/* Tokens.  */
#define ARRAY 258
#define BEG 259
#define BOOLEAN 260
#define DEF 261
#define DO 262
#define ELSE 263
#define END 264
#define FOR 265
#define INTEGER 266
#define IF 267
#define OF 268
#define PRINT 269
#define READ 270
#define REAL 271
#define RETURN 272
#define STRING 273
#define THEN 274
#define TO 275
#define VAR 276
#define WHILE 277
#define OP_ADD 278
#define OP_SUB 279
#define OP_MUL 280
#define OP_DIV 281
#define OP_MOD 282
#define OP_ASSIGN 283
#define OP_EQ 284
#define OP_NE 285
#define OP_GT 286
#define OP_LT 287
#define OP_GE 288
#define OP_LE 289
#define OP_AND 290
#define OP_OR 291
#define OP_NOT 292
#define MK_COMMA 293
#define MK_COLON 294
#define MK_SEMICOLON 295
#define MK_LPAREN 296
#define MK_RPAREN 297
#define MK_LB 298
#define MK_RB 299
#define TRUE 300
#define FALSE 301
#define ID 302
#define INT_CONST 303
#define OCTAL_CONST 304
#define FLOAT_CONST 305
#define SCIENTIFIC 306
#define STR_CONST 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 49 "parser.y" /* yacc.c:1909  */

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

#line 172 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
