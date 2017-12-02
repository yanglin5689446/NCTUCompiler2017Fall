/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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


#line 114 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 49 "parser.y" /* yacc.c:355  */

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

#line 272 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 289 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   191

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    88,   100,   103,   104,   107,   108,   111,
     123,   129,   134,   135,   138,   143,   148,   153,   158,   163,
     168,   171,   176,   184,   185,   188,   189,   192,   194,   196,
     192,   205,   206,   209,   210,   213,   216,   219,   225,   226,
     229,   230,   233,   234,   235,   236,   239,   244,   245,   246,
     247,   248,   249,   250,   253,   253,   263,   264,   267,   268,
     271,   272,   273,   276,   279,   284,   287,   292,   297,   300,
     301,   304,   305,   308,   309,   312,   313,   316,   317,   320,
     321,   324,   325,   326,   327,   328,   329,   332,   333,   336,
     337,   340,   341,   344,   345,   346,   349,   350,   351,   352,
     353,   354,   355,   358,   361,   366
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "BEG", "BOOLEAN", "DEF", "DO",
  "ELSE", "END", "FOR", "INTEGER", "IF", "OF", "PRINT", "READ", "REAL",
  "RETURN", "STRING", "THEN", "TO", "VAR", "WHILE", "OP_ADD", "OP_SUB",
  "OP_MUL", "OP_DIV", "OP_MOD", "OP_ASSIGN", "OP_EQ", "OP_NE", "OP_GT",
  "OP_LT", "OP_GE", "OP_LE", "OP_AND", "OP_OR", "OP_NOT", "MK_COMMA",
  "MK_COLON", "MK_SEMICOLON", "MK_LPAREN", "MK_RPAREN", "MK_LB", "MK_RB",
  "TRUE", "FALSE", "ID", "INT_CONST", "OCTAL_CONST", "FLOAT_CONST",
  "SCIENTIFIC", "STR_CONST", "$accept", "program", "$@1", "program_body",
  "opt_decl_list", "decl_list", "decl", "int_const", "literal_const",
  "opt_func_decl_list", "func_decl_list", "func_decl", "$@2", "$@3", "$@4",
  "opt_param_list", "param_list", "param", "id_list", "opt_type", "type",
  "scalar_type", "array_type", "stmt", "compound_stmt", "$@5",
  "opt_stmt_list", "stmt_list", "simple_stmt", "proc_call_stmt",
  "cond_stmt", "while_stmt", "for_stmt", "return_stmt",
  "opt_boolean_expr_list", "boolean_expr_list", "boolean_expr",
  "boolean_term", "boolean_factor", "relop_expr", "rel_op", "expr",
  "add_op", "term", "mul_op", "factor", "var_ref", "dim", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -43,  -116,    17,   -12,  -116,    37,    13,    54,    18,    37,
    -116,  -116,     6,    30,  -116,    67,    18,  -116,  -116,    33,
      24,  -116,    65,  -116,  -116,  -116,  -116,    56,  -116,  -116,
    -116,  -116,    50,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,    75,    77,    87,    13,    37,   119,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,   107,  -116,    99,     9,    56,   106,
      13,    46,   102,    44,    44,    44,    44,    44,   110,  -116,
    -116,   143,     9,  -116,  -116,  -116,  -116,  -116,  -116,   -13,
     140,   115,  -116,  -116,  -116,  -116,   127,    85,    44,    44,
     116,  -116,     1,   121,  -116,  -116,    79,   104,  -116,   117,
      14,    42,    43,     7,    44,  -116,  -116,    44,    44,  -116,
      46,    46,  -116,    56,    44,   118,   117,  -116,   -20,    44,
       9,    44,    44,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,    73,    73,  -116,  -116,  -116,    73,  -116,  -116,  -116,
       9,   122,   123,   126,    48,     2,  -116,  -116,   125,   138,
       5,    44,  -116,   124,   133,   121,  -116,   120,   104,  -116,
     154,   128,    44,  -116,  -116,    67,    56,  -116,   129,  -116,
       9,   155,   162,  -116,   126,   161,   165,  -116,   164,  -116,
    -116,   130,     9,   163,  -116,   167,  -116,   171,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     6,     0,     0,    24,     5,
       8,    37,     0,     0,    27,     0,    23,    26,     7,     0,
       0,     3,     0,    54,     4,    25,    36,     0,    44,    42,
      43,    45,     0,    21,    22,    12,    13,    16,    18,    20,
      14,     0,     0,     0,    32,     6,     0,    17,    19,    15,
      11,     9,    10,    28,    31,    34,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,    59,
      47,     0,    56,    48,    53,    49,    50,    51,    52,     0,
       0,    39,    33,    35,    40,    41,     0,     0,     0,     0,
     103,   102,     0,    74,    76,    78,    80,    88,    92,    96,
       0,     0,     0,     0,    70,    55,    58,     0,     0,   104,
       0,     0,    29,     0,     0,   103,    97,    77,     0,    70,
      57,     0,     0,    89,    90,    83,    86,    85,    81,    84,
      82,     0,     0,    93,    94,    95,     0,    61,    62,    68,
      57,     0,    69,    72,     0,     0,    46,    38,     0,     0,
       0,    70,    98,     0,     0,    73,    75,    79,    87,    91,
       0,     0,     0,    60,   105,     0,     0,    99,     0,   100,
      57,     0,     0,    63,    71,     0,     0,   101,     0,    65,
      66,     0,    57,     0,    30,     0,    64,     0,    67
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,  -116,   134,  -116,   172,   -26,   160,  -116,
    -116,   158,  -116,  -116,  -116,  -116,  -116,   131,   176,  -116,
      35,   166,   168,   111,   -15,  -116,  -115,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -112,  -116,   -55,    63,   -86,  -116,
    -116,    58,  -116,    53,  -116,    51,   -54,  -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    10,    40,    91,    15,
      16,    17,    22,    59,   148,    53,    54,    55,    56,   112,
      83,    84,    85,    69,    70,    45,    71,    72,    73,    74,
      75,    76,    77,    78,   141,   142,   143,    93,    94,    95,
     131,    96,   132,    97,   136,    98,    99,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      24,    46,   117,    79,     1,   154,    49,   153,    92,   100,
     101,   102,   103,    23,   140,   107,   121,     4,    79,    62,
     120,    63,   152,    64,    65,   160,    66,    27,     5,    28,
     108,    67,    80,   116,   118,    29,   156,   121,   121,   168,
      30,   121,    31,   121,    19,    20,   164,   167,    32,    27,
     121,    28,   144,   145,   137,   178,    68,    29,     6,   150,
      11,    49,    30,    13,    31,    14,    79,   185,    87,    33,
      34,    23,    35,    36,    37,    38,    39,    21,   121,   121,
      26,    88,   138,   139,   121,    89,    79,   149,   163,    33,
      34,    90,    35,    36,    37,    38,    39,    87,    35,    36,
      47,    48,   123,   124,    35,    36,    44,   174,   125,   126,
     127,   128,   129,   130,    89,    50,    79,    51,    33,    34,
      90,    35,    36,    37,    38,    39,   114,    52,    79,   133,
     134,   135,   115,    35,    36,    47,    48,    19,    61,    58,
     176,   170,   171,   123,   124,   146,   147,    60,    81,    86,
     175,   104,   105,   110,   111,   113,   122,   119,   166,   151,
     108,   162,   121,   172,   161,   165,   169,   179,   173,   180,
     181,   177,   182,   183,    25,   186,   187,   184,   188,    57,
      41,    18,    12,   106,   155,   158,    42,   159,    43,   157,
       0,    82
};

static const yytype_int16 yycheck[] =
{
      15,    27,    88,    57,    47,   120,    32,   119,    63,    64,
      65,    66,    67,     4,     7,    28,    36,     0,    72,    10,
      19,    12,    42,    14,    15,   140,    17,     3,    40,     5,
      43,    22,    58,    87,    89,    11,   122,    36,    36,   151,
      16,    36,    18,    36,    38,    39,    44,    42,    24,     3,
      36,     5,   107,   108,    40,   170,    47,    11,    21,   114,
      47,    87,    16,     9,    18,    47,   120,   182,    24,    45,
      46,     4,    48,    49,    50,    51,    52,    47,    36,    36,
      47,    37,    40,    40,    36,    41,   140,   113,    40,    45,
      46,    47,    48,    49,    50,    51,    52,    24,    48,    49,
      50,    51,    23,    24,    48,    49,    41,   162,    29,    30,
      31,    32,    33,    34,    41,    40,   170,    40,    45,    46,
      47,    48,    49,    50,    51,    52,    41,    40,   182,    25,
      26,    27,    47,    48,    49,    50,    51,    38,    39,    20,
     166,     8,     9,    23,    24,   110,   111,    40,    42,    47,
     165,    41,     9,    13,    39,    28,    35,    41,    20,    41,
      43,    38,    36,     9,    42,    40,    42,    12,    40,     7,
       9,    42,     7,     9,    16,    12,     9,    47,     7,    45,
      20,     9,     6,    72,   121,   132,    20,   136,    20,   131,
      -1,    60
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    54,    55,     0,    40,    21,    56,    57,    58,
      59,    47,    71,     9,    47,    62,    63,    64,    59,    38,
      39,    47,    65,     4,    77,    64,    47,     3,     5,    11,
      16,    18,    24,    45,    46,    48,    49,    50,    51,    52,
      60,    61,    74,    75,    41,    78,    60,    50,    51,    60,
      40,    40,    40,    68,    69,    70,    71,    57,    20,    66,
      40,    39,    10,    12,    14,    15,    17,    22,    47,    76,
      77,    79,    80,    81,    82,    83,    84,    85,    86,    99,
      60,    42,    70,    73,    74,    75,    47,    24,    37,    41,
      47,    61,    89,    90,    91,    92,    94,    96,    98,    99,
      89,    89,    89,    89,    41,     9,    76,    28,    43,   100,
      13,    39,    72,    28,    41,    47,    99,    91,    89,    41,
      19,    36,    35,    23,    24,    29,    30,    31,    32,    33,
      34,    93,    95,    25,    26,    27,    97,    40,    40,    40,
       7,    87,    88,    89,    89,    89,    73,    73,    67,    60,
      89,    41,    42,    87,    79,    90,    91,    94,    96,    98,
      79,    42,    38,    40,    44,    40,    20,    42,    87,    42,
       8,     9,     9,    40,    89,    77,    60,    42,    79,    12,
       7,     9,     7,     9,    47,    79,    12,     9,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    55,    54,    56,    57,    57,    58,    58,    59,
      59,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    65,    66,    67,
      64,    68,    68,    69,    69,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    74,    74,    75,    76,    76,    76,
      76,    76,    76,    76,    78,    77,    79,    79,    80,    80,
      81,    81,    81,    82,    83,    83,    84,    85,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    99,    99,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     3,     1,     0,     2,     1,     5,
       5,     5,     1,     1,     1,     2,     1,     2,     1,     2,
       1,     1,     1,     1,     0,     2,     1,     0,     0,     0,
      12,     1,     0,     3,     1,     3,     3,     1,     2,     0,
       1,     1,     1,     1,     1,     1,     6,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     1,     0,     2,     1,
       4,     3,     3,     5,     8,     6,     6,    10,     3,     1,
       0,     3,     1,     3,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     2,     3,     4,
       4,     5,     1,     1,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 88 "parser.y" /* yacc.c:1646  */
    {
                    //Symbol *prog_name = symbol($1, T_PROGRAM, NULL, NULL);
                    //symbol_table_insert(prog_name);
                }
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 93 "parser.y" /* yacc.c:1646  */
    {
                    if(strcmp((yyvsp[-5].str_val), (yyvsp[0].str_val))){
                        printf("program id mismatch.\n");
                    }
                }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "parser.y" /* yacc.c:1646  */
    {       
                /* scalar type declaration */
                IDList *id_list = (yyvsp[-3].id_list);
                TypeNode *type = (yyvsp[-1].type);
                for(int i = 0; i < id_list->size ;i ++){
                    IDNode *id_node = id_list->id_nodes + i;
                    if(check_redeclar(id_node) == false){
                        Symbol *s = symbol(id_node->id, T_VAR, type, NULL);
                        symbol_table_insert(s);
                    }
                }
            }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 123 "parser.y" /* yacc.c:1646  */
    {
                /* array type declaration */
                IDList *id_list = (yyvsp[-3].id_list);
                TypeNode *type = (yyvsp[-1].type);
            }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 129 "parser.y" /* yacc.c:1646  */
    {
                /* const declaration */
                IDList *id_list = (yyvsp[-3].id_list);
            }
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 134 "parser.y" /* yacc.c:1646  */
    { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.int_val) = (yyvsp[0].int_val); }
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 138 "parser.y" /* yacc.c:1646  */
    {
                int val = (yyvsp[0].int_val);
                (yyval.rvalue) = rvalue_node(T_INTEGER, &val);
                printf("rvalue: %d\n", (yyval.rvalue)->value.int_value);
            }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "parser.y" /* yacc.c:1646  */
    {
                int val = -1 * (yyvsp[0].int_val);
                (yyval.rvalue) = rvalue_node(T_INTEGER, &val);
                printf("rvalue: %d\n", (yyval.rvalue)->value.int_value);
            }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 148 "parser.y" /* yacc.c:1646  */
    {
                float val = (yyvsp[0].real_val);
                (yyval.rvalue) = rvalue_node(T_REAL, &val);
                printf("rvalue: %f\n", (yyval.rvalue)->value.real_value);
            }
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 153 "parser.y" /* yacc.c:1646  */
    {
                float val = -1 * (yyvsp[0].real_val);
                (yyval.rvalue) = rvalue_node(T_REAL, &val);
                printf("rvalue: %f\n", (yyval.rvalue)->value.real_value);
            }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 158 "parser.y" /* yacc.c:1646  */
    {
                float val = (yyvsp[0].real_val);
                (yyval.rvalue) = rvalue_node(T_REAL, &val);
                printf("rvalue: %f\n", (yyval.rvalue)->value.real_value);
            }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 163 "parser.y" /* yacc.c:1646  */
    {
                float val = -1 * (yyvsp[0].real_val);
                (yyval.rvalue) = rvalue_node(T_REAL, &val);
                printf("rvalue: %f\n", (yyval.rvalue)->value.real_value);
            }
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 168 "parser.y" /* yacc.c:1646  */
    {
                (yyval.rvalue) = rvalue_node(T_STRING, (yyvsp[0].str_val));
            }
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 171 "parser.y" /* yacc.c:1646  */
    {
                bool val = true;
                (yyval.rvalue) = rvalue_node(T_BOOLEAN, &val);
                printf("rvalue: %d\n", (yyval.rvalue)->value.bool_value);
            }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 176 "parser.y" /* yacc.c:1646  */
    {
                bool val  = false; 
                (yyval.rvalue) = rvalue_node(T_BOOLEAN, &val);
                printf("rvalue: %d\n", (yyval.rvalue)->value.bool_value);
            
            }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 192 "parser.y" /* yacc.c:1646  */
    {
                
                }
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 194 "parser.y" /* yacc.c:1646  */
    {
                
                }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 196 "parser.y" /* yacc.c:1646  */
    {
                
                }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 200 "parser.y" /* yacc.c:1646  */
    {
              
              }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 205 "parser.y" /* yacc.c:1646  */
    {}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 206 "parser.y" /* yacc.c:1646  */
    {}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 209 "parser.y" /* yacc.c:1646  */
    {}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 210 "parser.y" /* yacc.c:1646  */
    {}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 213 "parser.y" /* yacc.c:1646  */
    {}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 216 "parser.y" /* yacc.c:1646  */
    {
                id_list_insert((yyval.id_list), (yyvsp[0].str_val));
            }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 219 "parser.y" /* yacc.c:1646  */
    {
                (yyval.id_list) = id_list_create();
                id_list_insert((yyval.id_list), (yyvsp[0].str_val));
            }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 233 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_node(T_INTEGER); }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 234 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_node(T_REAL); }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 235 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_node(T_BOOLEAN);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 236 "parser.y" /* yacc.c:1646  */
    { (yyval.type) = type_node(T_STRING); }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 239 "parser.y" /* yacc.c:1646  */
    {
                (yyval.type) = array_type_node((yyvsp[0].type), (yyvsp[-4].int_val), (yyvsp[-2].int_val));        
            }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 253 "parser.y" /* yacc.c:1646  */
    {
                    symbol_table_new_scope();
                }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 258 "parser.y" /* yacc.c:1646  */
    {
                    symbol_table_delete_scope();
              }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 358 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 361 "parser.y" /* yacc.c:1646  */
    {
                
            }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 366 "parser.y" /* yacc.c:1646  */
    {

            }
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1814 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 371 "parser.y" /* yacc.c:1906  */



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

