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
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CONSTANT_INT = 258,
    CONSTANT_REAL = 259,
    CONSTANT_STRING = 260,
    ID = 261,
    MOD = 262,
    ASSIGN = 263,
    SMALLER = 264,
    SMALLER_EQUAL = 265,
    NOT_EQUAL = 266,
    GREATER_EQUAL = 267,
    GREATER = 268,
    EQUAL = 269,
    AND = 270,
    OR = 271,
    NOT = 272,
    ARRAY = 273,
    _BEGIN = 274,
    BOOLEAN = 275,
    DEF = 276,
    DO = 277,
    ELSE = 278,
    _END = 279,
    FALSE = 280,
    FOR = 281,
    INTEGER = 282,
    IF = 283,
    OF = 284,
    PRINT = 285,
    READ = 286,
    REAL = 287,
    STRING = 288,
    THEN = 289,
    TO = 290,
    TRUE = 291,
    RETURN = 292,
    VAR = 293,
    WHILE = 294,
    UMINUS = 295
  };
#endif
/* Tokens.  */
#define CONSTANT_INT 258
#define CONSTANT_REAL 259
#define CONSTANT_STRING 260
#define ID 261
#define MOD 262
#define ASSIGN 263
#define SMALLER 264
#define SMALLER_EQUAL 265
#define NOT_EQUAL 266
#define GREATER_EQUAL 267
#define GREATER 268
#define EQUAL 269
#define AND 270
#define OR 271
#define NOT 272
#define ARRAY 273
#define _BEGIN 274
#define BOOLEAN 275
#define DEF 276
#define DO 277
#define ELSE 278
#define _END 279
#define FALSE 280
#define FOR 281
#define INTEGER 282
#define IF 283
#define OF 284
#define PRINT 285
#define READ 286
#define REAL 287
#define STRING 288
#define THEN 289
#define TO 290
#define TRUE 291
#define RETURN 292
#define VAR 293
#define WHILE 294
#define UMINUS 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
