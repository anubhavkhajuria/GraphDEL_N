/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lrparser.y"

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <stdbool.h>
    #include "includeHeader.hpp"
	#include "../analyser/attachProp/attachPropAnalyser.h"
	#include "../analyser/dataRace/dataRaceAnalyser.h"
	#include "../analyser/deviceVars/deviceVarsAnalyser.h"
	#include "../analyser/pushpull/pushpullAnalyser.h"

	#include "../analyser/blockVars/blockVarsAnalyser.h"
	#include<getopt.h>
	//#include "../symbolutil/SymbolTableBuilder.cpp"
     
	void yyerror(const char *);
	int yylex(void);
    extern FILE* yyin;

	char mytext[100];
	char var[100];
	int num = 0;
	vector<map<int,vector<Identifier*>>> graphId(5);
	extern char *yytext;
	//extern SymbolTable* symbTab;
	FrontEndContext frontEndContext;
	map<string,int> push_map;
	set<string> allGpuUsedVars;
	char* backendTarget ;
    vector<Identifier*> tempIds; //stores graph vars in current function's param list.
    //symbTab=new SymbolTable();
	//symbolTableList.push_back(new SymbolTable());

#line 104 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    T_INT = 258,
    T_FLOAT = 259,
    T_BOOL = 260,
    T_DOUBLE = 261,
    T_LONG = 262,
    T_FORALL = 263,
    T_FOR = 264,
    T_P_INF = 265,
    T_INF = 266,
    T_N_INF = 267,
    T_FUNC = 268,
    T_IF = 269,
    T_ELSE = 270,
    T_WHILE = 271,
    T_RETURN = 272,
    T_DO = 273,
    T_IN = 274,
    T_FIXEDPOINT = 275,
    T_UNTIL = 276,
    T_FILTER = 277,
    T_ADD_ASSIGN = 278,
    T_SUB_ASSIGN = 279,
    T_MUL_ASSIGN = 280,
    T_DIV_ASSIGN = 281,
    T_MOD_ASSIGN = 282,
    T_AND_ASSIGN = 283,
    T_XOR_ASSIGN = 284,
    T_OR_ASSIGN = 285,
    T_INC_OP = 286,
    T_DEC_OP = 287,
    T_PTR_OP = 288,
    T_AND_OP = 289,
    T_OR_OP = 290,
    T_LE_OP = 291,
    T_GE_OP = 292,
    T_EQ_OP = 293,
    T_NE_OP = 294,
    T_AND = 295,
    T_OR = 296,
    T_SUM = 297,
    T_AVG = 298,
    T_COUNT = 299,
    T_PRODUCT = 300,
    T_MAX = 301,
    T_MIN = 302,
    T_GRAPH = 303,
    T_DIR_GRAPH = 304,
    T_NODE = 305,
    T_EDGE = 306,
    T_UPDATES = 307,
    T_CONTAINER = 308,
    T_NODEMAP = 309,
    T_NP = 310,
    T_EP = 311,
    T_LIST = 312,
    T_SET_NODES = 313,
    T_SET_EDGES = 314,
    T_FROM = 315,
    T_BFS = 316,
    T_REVERSE = 317,
    T_INCREMENTAL = 318,
    T_DECREMENTAL = 319,
    T_STATIC = 320,
    T_DYNAMIC = 321,
    T_BATCH = 322,
    T_ONADD = 323,
    T_ONDELETE = 324,
    ID = 325,
    INT_NUM = 326,
    FLOAT_NUM = 327,
    BOOL_VAL = 328,
    CHAR_VAL = 329
  };
#endif
/* Tokens.  */
#define T_INT 258
#define T_FLOAT 259
#define T_BOOL 260
#define T_DOUBLE 261
#define T_LONG 262
#define T_FORALL 263
#define T_FOR 264
#define T_P_INF 265
#define T_INF 266
#define T_N_INF 267
#define T_FUNC 268
#define T_IF 269
#define T_ELSE 270
#define T_WHILE 271
#define T_RETURN 272
#define T_DO 273
#define T_IN 274
#define T_FIXEDPOINT 275
#define T_UNTIL 276
#define T_FILTER 277
#define T_ADD_ASSIGN 278
#define T_SUB_ASSIGN 279
#define T_MUL_ASSIGN 280
#define T_DIV_ASSIGN 281
#define T_MOD_ASSIGN 282
#define T_AND_ASSIGN 283
#define T_XOR_ASSIGN 284
#define T_OR_ASSIGN 285
#define T_INC_OP 286
#define T_DEC_OP 287
#define T_PTR_OP 288
#define T_AND_OP 289
#define T_OR_OP 290
#define T_LE_OP 291
#define T_GE_OP 292
#define T_EQ_OP 293
#define T_NE_OP 294
#define T_AND 295
#define T_OR 296
#define T_SUM 297
#define T_AVG 298
#define T_COUNT 299
#define T_PRODUCT 300
#define T_MAX 301
#define T_MIN 302
#define T_GRAPH 303
#define T_DIR_GRAPH 304
#define T_NODE 305
#define T_EDGE 306
#define T_UPDATES 307
#define T_CONTAINER 308
#define T_NODEMAP 309
#define T_NP 310
#define T_EP 311
#define T_LIST 312
#define T_SET_NODES 313
#define T_SET_EDGES 314
#define T_FROM 315
#define T_BFS 316
#define T_REVERSE 317
#define T_INCREMENTAL 318
#define T_DECREMENTAL 319
#define T_STATIC 320
#define T_DYNAMIC 321
#define T_BATCH 322
#define T_ONADD 323
#define T_ONDELETE 324
#define ID 325
#define INT_NUM 326
#define FLOAT_NUM 327
#define BOOL_VAL 328
#define CHAR_VAL 329

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "lrparser.y"

    int  info;
    long ival;
	bool bval;
    double fval;
    char* text;
	char cval;
	ASTNode* node;
	paramList* pList;
	argList* aList;
	ASTNodeList* nodeList;
    tempNode* temporary;
     

#line 319 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   784

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  95
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  158
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  373

#define YYUNDEFTOK  2
#define YYMAXUTOK   329


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    92,     2,     2,     2,    83,     2,     2,
      84,    85,    81,    79,    86,    80,    88,    82,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    76,    87,
      77,    91,    78,    75,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    93,     2,    94,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,    90,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   104,   106,   113,   119,   125,   131,   137,
     144,   145,   148,   149,   151,   162,   166,   175,   178,   179,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   195,   197,   199,   201,   203,   205,   207,   210,
     218,   221,   224,   228,   229,   230,   233,   234,   235,   236,
     237,   240,   241,   243,   244,   246,   248,   249,   250,   252,
     253,   254,   257,   259,   260,   261,   263,   264,   265,   266,
     267,   269,   272,   273,   275,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     294,   295,   296,   297,   299,   301,   302,   304,   309,   313,
     317,   328,   329,   330,   331,   332,   333,   336,   337,   339,
     340,   341,   342,   344,   345,   346,   347,   348,   350,   351,
     353,   355,   356,   359,   360,   362,   365,   366,   367,   368,
     369,   371,   373,   375,   376,   378,   379,   388,   390,   391,
     392,   393,   394,   396,   397,   398,   401,   405,   422,   429,
     434,   442,   443,   447,   448,   451,   455,   462,   466
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INT", "T_FLOAT", "T_BOOL", "T_DOUBLE",
  "T_LONG", "T_FORALL", "T_FOR", "T_P_INF", "T_INF", "T_N_INF", "T_FUNC",
  "T_IF", "T_ELSE", "T_WHILE", "T_RETURN", "T_DO", "T_IN", "T_FIXEDPOINT",
  "T_UNTIL", "T_FILTER", "T_ADD_ASSIGN", "T_SUB_ASSIGN", "T_MUL_ASSIGN",
  "T_DIV_ASSIGN", "T_MOD_ASSIGN", "T_AND_ASSIGN", "T_XOR_ASSIGN",
  "T_OR_ASSIGN", "T_INC_OP", "T_DEC_OP", "T_PTR_OP", "T_AND_OP", "T_OR_OP",
  "T_LE_OP", "T_GE_OP", "T_EQ_OP", "T_NE_OP", "T_AND", "T_OR", "T_SUM",
  "T_AVG", "T_COUNT", "T_PRODUCT", "T_MAX", "T_MIN", "T_GRAPH",
  "T_DIR_GRAPH", "T_NODE", "T_EDGE", "T_UPDATES", "T_CONTAINER",
  "T_NODEMAP", "T_NP", "T_EP", "T_LIST", "T_SET_NODES", "T_SET_EDGES",
  "T_FROM", "T_BFS", "T_REVERSE", "T_INCREMENTAL", "T_DECREMENTAL",
  "T_STATIC", "T_DYNAMIC", "T_BATCH", "T_ONADD", "T_ONDELETE", "ID",
  "INT_NUM", "FLOAT_NUM", "BOOL_VAL", "CHAR_VAL", "'?'", "':'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "','", "';'",
  "'.'", "'{'", "'}'", "'='", "'!'", "'['", "']'", "$accept", "program",
  "function_def", "function_data", "paramList", "type", "param",
  "function_body", "statements", "statement", "blockstatements",
  "batch_blockstmt", "on_add_blockstmt", "on_delete_blockstmt",
  "block_begin", "block_end", "return_stmt", "declaration", "type1",
  "primitive", "graph", "collections", "container", "nodemap", "type2",
  "property", "assignment", "rhs", "expression", "indexExpr", "unary_expr",
  "proc_call", "val", "control_flow", "iteration_cf", "filterExpr",
  "boolean_expr", "selection_cf", "reduction", "reduce_op", "leftList",
  "rightList", "reductionCall", "reduction_calls", "leftSide", "arg_list",
  "bfs_abstraction", "reverse_abstraction", "oid", "tid", "id", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,    63,    58,    60,    62,    43,
      45,    42,    47,    37,    40,    41,    44,    59,    46,   123,
     125,    61,    33,    91,    93
};
# endif

#define YYPACT_NINF (-318)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-158)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -318,    17,  -318,   -56,   -42,   -29,   -56,   -56,  -318,   -16,
    -318,   -10,   715,   715,     5,     7,  -318,  -318,  -318,  -318,
     715,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,
      23,    28,     9,    30,    36,  -318,    80,    82,    51,    54,
     -56,  -318,  -318,  -318,  -318,  -318,   -56,  -318,    76,   715,
     715,   435,    77,   -56,   715,   715,   725,   345,   -56,   -56,
    -318,   715,  -318,    81,  -318,    84,    94,    83,   101,  -318,
    -318,  -318,   102,   103,   100,   -16,   145,   109,   114,   116,
     123,   127,   128,  -318,  -318,  -318,   -56,   100,  -318,   100,
    -318,  -318,  -318,  -318,  -318,  -318,   129,   131,   -56,   -56,
     132,   611,   -43,   133,   135,  -318,  -318,  -318,  -318,   138,
       8,  -318,  -318,  -318,   126,  -318,   110,   137,  -318,  -318,
     144,   152,   154,   163,   164,   165,   169,   171,   172,  -318,
     -56,  -318,  -318,   -56,   -56,   100,   100,   611,   176,  -318,
    -318,   189,   237,   190,   -56,   100,   100,   -56,   -56,   -56,
     197,   193,   575,   611,  -318,  -318,   185,   192,  -318,  -318,
    -318,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   -56,   100,  -318,  -318,  -318,  -318,
    -318,  -318,  -318,  -318,   100,    14,   100,   -56,  -318,   196,
    -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,  -318,   200,
     267,   268,   611,   203,   204,   208,   -56,   276,   212,   479,
     -45,   211,   216,   227,   287,   288,   218,   -56,  -318,   100,
     100,   158,   669,    63,    63,   355,   355,    63,    63,    37,
      37,    -3,    -3,   329,   226,  -318,   611,   228,  -318,  -318,
    -318,  -318,  -318,  -318,  -318,   230,   611,   -41,   100,  -318,
     100,   100,   531,   -16,   100,   235,   -56,   100,   100,   100,
    -318,  -318,   100,   -56,   -56,   238,  -318,  -318,  -318,  -318,
     100,  -318,   100,   -56,   -56,   -63,    16,   -50,   224,    62,
     -20,   231,   301,  -318,   233,   100,   232,  -318,  -318,   593,
     234,   236,   136,   240,   241,  -318,   229,  -318,   715,   -16,
     -16,   100,   -16,   -16,   100,   531,   242,   602,   100,   -16,
     100,   100,   244,  -318,  -318,  -318,   243,  -318,  -318,    70,
     -18,  -318,  -318,    70,  -318,  -318,   -16,   261,  -318,   246,
     247,   104,  -318,   305,   248,   -56,   249,  -318,   -56,   259,
     271,   251,   265,   258,   269,   -16,    61,   -16,   273,   -16,
     -16,   104,  -318,   104,   100,  -318,  -318,   281,  -318,  -318,
    -318,  -318,   274,   -16,  -318,   308,   -13,  -318,   100,  -318,
     299,   -16,  -318
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     3,     0,
     158,     0,     0,     0,     0,     0,    36,     4,    17,    18,
       0,    46,    47,    48,    49,    50,    51,    52,    63,    64,
       0,     0,     0,     0,     0,    53,     0,     0,     0,    10,
       0,    43,    44,    45,    57,    58,     0,    65,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       7,     0,    14,    15,     8,     0,     0,     0,     0,   105,
     104,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,     0,    37,     0,
      19,    26,    29,    30,    31,    32,     0,     0,     0,     0,
       0,     0,    93,    92,    75,    90,    23,   108,   107,     0,
      91,    25,   144,   145,   143,     5,     0,     0,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     6,     9,     0,     0,     0,     0,    38,    93,    92,
      75,    91,     0,     0,     0,   146,   146,     0,     0,     0,
       0,   132,     0,    88,    28,    20,    39,    41,    21,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,    22,    24,   126,
     130,   127,   129,   128,   146,     0,     0,     0,    56,    61,
      62,    70,    71,    66,    68,    67,    69,    54,    55,     0,
       0,     0,   120,     0,     0,     0,     0,     0,   150,   149,
      91,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,    80,    81,    82,    83,    86,    87,    84,    85,    76,
      77,    78,    79,     0,     0,    73,    74,     0,   138,   139,
     140,   141,   142,    72,   123,     0,   125,   155,   146,    16,
       0,     0,     0,     0,     0,     0,     0,   146,   146,     0,
      98,    99,     0,     0,     0,     0,   131,    40,    42,    94,
     146,    97,   146,     0,     0,     0,    93,    91,   143,    93,
      91,   143,   121,   110,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,   157,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   137,   156,     0,   117,   113,    75,
     143,   116,   114,    75,   122,   111,     0,    75,    33,    75,
      75,     0,    59,     0,     0,     0,     0,   109,     0,     0,
       0,   135,     0,   136,     0,     0,   155,     0,     0,     0,
       0,     0,   124,     0,     0,   112,   115,   118,    34,    35,
     133,   134,     0,     0,   119,   152,     0,   151,     0,   153,
       0,     0,   154
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -318,  -318,  -318,  -318,    59,   -37,  -318,  -318,  -318,  -251,
      -9,  -318,  -318,  -318,  -318,  -318,  -318,  -318,   -46,    67,
    -318,    72,  -318,  -318,   -35,  -318,   -48,   -87,   210,   -24,
     -47,   -39,  -310,  -318,  -318,  -317,  -123,  -318,  -318,  -318,
     173,  -302,    96,  -318,   -49,  -131,  -318,  -318,  -318,  -318,
       4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     8,     9,    38,   117,    39,    17,    51,    90,
      91,    92,    93,    94,    19,    95,    96,    97,    40,    41,
      42,    43,    44,    45,    46,    47,   208,   243,   101,   138,
     139,   140,   105,   106,   107,   334,   203,   108,   109,   186,
     150,   342,   244,   245,   141,   211,   111,   367,   112,   113,
     114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,   282,   110,   100,   103,    98,   336,    11,   118,   118,
      14,    15,   104,   204,    10,   212,    99,     2,   120,   119,
     119,   341,   297,   298,    69,    70,    71,   102,   159,   160,
       3,   179,   180,   181,   184,   300,   182,   151,   183,   184,
     363,   341,    12,   341,    62,   174,   259,   273,   175,   360,
      63,   361,   274,   237,   324,    13,   238,   116,   239,   240,
     241,   242,   127,   128,   184,   303,   142,  -155,   159,   160,
     335,   368,    48,    16,    20,   274,    16,    78,    79,    52,
       4,     5,     6,     7,    10,    83,    84,    85,   235,    49,
     173,    50,   184,    55,   159,   160,   210,   210,    87,   185,
      53,   299,   156,   157,   174,    54,    89,    56,    65,    66,
      69,    70,    71,    57,    69,    70,    71,   275,   171,   172,
     129,   102,   102,   123,   125,   234,   287,   288,   124,   126,
     173,   284,   267,   268,   199,   210,    60,   200,   201,   293,
      61,   294,   169,   170,   171,   172,  -157,   302,   207,   273,
     174,   213,   214,   215,   274,  -118,   173,    58,   333,    59,
     102,    64,   115,    78,    79,   130,   143,   133,   151,   131,
      10,    83,    84,    85,    10,    83,    84,    85,   238,   132,
     239,   240,   241,   242,    87,   134,   135,   136,   188,   159,
     160,   247,    89,   144,   163,   164,   165,   166,   145,   210,
     146,   277,   280,   110,   100,   103,    98,   147,   210,   210,
     255,   148,   149,   104,   187,   189,   154,    99,   155,   158,
     176,   210,   177,   210,   102,   178,   276,   279,   102,   190,
     191,   362,   192,   102,   102,   167,   168,   169,   170,   171,
     172,   193,   194,   195,   283,   370,   102,   196,   102,   197,
     198,   173,   118,   205,   278,   281,   110,   100,   103,    98,
     286,   316,   319,   119,   174,   323,   104,   290,   291,   327,
      99,   329,   330,   184,   206,   216,   219,   295,   296,   217,
     248,   102,   343,   220,   137,   249,   250,   251,   252,   253,
     317,   318,   254,   321,   322,   256,   260,   152,   257,   153,
     328,   261,   343,   262,   343,   320,   263,   264,   320,   265,
     270,   285,   301,   271,   272,   292,   305,   337,   306,   304,
     308,   338,   310,   315,   311,   313,   314,   344,   332,   325,
     331,   339,   340,   345,   347,   349,   355,   351,   356,   346,
     358,   359,   348,   352,   353,   202,   202,   350,    21,    22,
      23,    24,    25,   354,   365,   209,   209,   369,   357,   364,
     159,   160,   372,   161,   162,   163,   164,   165,   166,   333,
     366,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   371,   236,   159,   160,   312,     0,
     266,   163,   164,     0,   209,   236,   246,    30,    31,    32,
       0,     0,    35,    36,    37,     0,   167,   168,   169,   170,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,   269,     0,     0,     0,     0,     0,   236,
     236,     0,   167,   168,   169,   170,   171,   172,    21,    22,
      23,    24,    25,    67,    68,    69,    70,    71,   173,    72,
       0,    73,    74,    75,     0,    76,     0,     0,   209,     0,
       0,     0,     0,     0,   202,     0,     0,   209,   209,   236,
       0,     0,   289,     0,     0,     0,     0,     0,     0,     0,
     209,     0,   209,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,   307,    77,     0,    78,    79,
       0,     0,    80,    81,    82,    10,    83,    84,    85,     0,
     159,   160,    86,   161,   162,   163,   164,   165,   166,    87,
       0,     0,     0,     0,    16,    88,     0,    89,     0,     0,
       0,     0,     0,     0,    21,    22,    23,    24,    25,    67,
      68,    69,    70,    71,     0,    72,     0,    73,    74,    75,
       0,    76,     0,     0,     0,     0,   167,   168,   169,   170,
     171,   172,     0,     0,   202,   258,     0,     0,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,   202,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,     0,    77,     0,    78,    79,     0,     0,    80,    81,
      82,    10,    83,    84,    85,     0,   159,   160,    86,   161,
     162,   163,   164,   165,   166,    87,     0,     0,     0,     0,
      16,     0,     0,    89,   159,   160,     0,   161,   162,   163,
     164,   165,   166,   159,   160,     0,   161,   162,   163,   164,
     165,   166,   159,   160,     0,   161,   162,   163,   164,   165,
     166,     0,   167,   168,   169,   170,   171,   172,     0,     0,
     218,     0,     0,     0,     0,     0,     0,     0,   173,     0,
     167,   168,   169,   170,   171,   172,     0,     0,   309,   167,
     168,   169,   170,   171,   172,     0,   173,   326,   167,   168,
     169,   170,   171,   172,     0,   173,     0,     0,     0,     0,
     159,   160,     0,   161,   173,   163,   164,   165,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,    21,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,   168,   169,   170,
     171,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,   121,   122,    30,    31,    32,
       0,     0,    35,    36,    37
};

static const yytype_int16 yycheck[] =
{
       9,   252,    51,    51,    51,    51,   323,     3,    54,    55,
       6,     7,    51,   136,    70,   146,    51,     0,    55,    54,
      55,   331,    85,    86,    10,    11,    12,    51,    31,    32,
      13,    23,    24,    25,    84,    85,    28,    86,    30,    84,
     357,   351,    84,   353,    40,    88,    91,    88,    91,   351,
      46,   353,    93,   184,   305,    84,    42,    53,    44,    45,
      46,    47,    58,    59,    84,    85,    75,    85,    31,    32,
      88,    84,    13,    89,    84,    93,    89,    63,    64,    20,
      63,    64,    65,    66,    70,    71,    72,    73,   175,    84,
      93,    84,    84,    84,    31,    32,   145,   146,    84,    91,
      77,    85,    98,    99,    88,    77,    92,    77,    49,    50,
      10,    11,    12,    77,    10,    11,    12,   248,    81,    82,
      61,   145,   146,    56,    57,   174,   257,   258,    56,    57,
      93,   254,   219,   220,   130,   184,    85,   133,   134,   270,
      86,   272,    79,    80,    81,    82,    85,    85,   144,    88,
      88,   147,   148,   149,    93,    85,    93,    77,    88,    77,
     184,    85,    85,    63,    64,    84,    21,    84,   217,    85,
      70,    71,    72,    73,    70,    71,    72,    73,    42,    85,
      44,    45,    46,    47,    84,    84,    84,    84,    78,    31,
      32,   187,    92,    84,    36,    37,    38,    39,    84,   248,
      84,   250,   251,   252,   252,   252,   252,    84,   257,   258,
     206,    84,    84,   252,    88,    78,    87,   252,    87,    87,
      87,   270,    87,   272,   248,    87,   250,   251,   252,    85,
      78,   354,    78,   257,   258,    77,    78,    79,    80,    81,
      82,    78,    78,    78,   253,   368,   270,    78,   272,    78,
      78,    93,   298,    16,   250,   251,   305,   305,   305,   305,
     256,   298,   301,   298,    88,   304,   305,   263,   264,   308,
     305,   310,   311,    84,    84,    78,    91,   273,   274,    86,
      84,   305,   331,    91,    74,    85,    19,    19,    85,    85,
     299,   300,    84,   302,   303,    19,    85,    87,    86,    89,
     309,    85,   351,    76,   353,   301,    19,    19,   304,    91,
      84,    76,    88,    85,    84,    77,    15,   326,    85,    88,
      88,    60,    88,    94,    88,    85,    85,    22,    85,    87,
      86,    85,    85,    85,    85,    76,   345,    86,   347,   335,
     349,   350,   338,    78,    86,   135,   136,    76,     3,     4,
       5,     6,     7,    84,   363,   145,   146,   366,    85,    85,
      31,    32,   371,    34,    35,    36,    37,    38,    39,    88,
      62,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,    85,   175,    31,    32,   292,    -1,
     217,    36,    37,    -1,   184,   185,   186,    52,    53,    54,
      -1,    -1,    57,    58,    59,    -1,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    -1,    -1,    -1,   219,
     220,    -1,    77,    78,    79,    80,    81,    82,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    93,    14,
      -1,    16,    17,    18,    -1,    20,    -1,    -1,   248,    -1,
      -1,    -1,    -1,    -1,   254,    -1,    -1,   257,   258,   259,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     270,    -1,   272,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   285,    61,    -1,    63,    64,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,    -1,
      31,    32,    77,    34,    35,    36,    37,    38,    39,    84,
      -1,    -1,    -1,    -1,    89,    90,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    14,    -1,    16,    17,    18,
      -1,    20,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    -1,    -1,   354,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,   368,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    -1,    63,    64,    -1,    -1,    67,    68,
      69,    70,    71,    72,    73,    -1,    31,    32,    77,    34,
      35,    36,    37,    38,    39,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    92,    31,    32,    -1,    34,    35,    36,
      37,    38,    39,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    -1,    77,    78,    79,    80,    81,    82,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      77,    78,    79,    80,    81,    82,    -1,    -1,    85,    77,
      78,    79,    80,    81,    82,    -1,    93,    85,    77,    78,
      79,    80,    81,    82,    -1,    93,    -1,    -1,    -1,    -1,
      31,    32,    -1,    34,    93,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    50,    51,    52,    53,    54,
      -1,    -1,    57,    58,    59
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    96,     0,    13,    63,    64,    65,    66,    97,    98,
      70,   145,    84,    84,   145,   145,    89,   102,   105,   109,
      84,     3,     4,     5,     6,     7,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    99,   101,
     113,   114,   115,   116,   117,   118,   119,   120,    99,    84,
      84,   103,    99,    77,    77,    84,    77,    77,    77,    77,
      85,    86,   145,   145,    85,    99,    99,     8,     9,    10,
      11,    12,    14,    16,    17,    18,    20,    61,    63,    64,
      67,    68,    69,    71,    72,    73,    77,    84,    90,    92,
     104,   105,   106,   107,   108,   110,   111,   112,   113,   119,
     121,   123,   124,   125,   126,   127,   128,   129,   132,   133,
     139,   141,   143,   144,   145,    85,   145,   100,   113,   119,
     100,    50,    51,   114,   116,   114,   116,   145,   145,    99,
      84,    85,    85,    84,    84,    84,    84,   123,   124,   125,
     126,   139,   105,    21,    84,    84,    84,    84,    84,    84,
     135,   139,   123,   123,    87,    87,   145,   145,    87,    31,
      32,    34,    35,    36,    37,    38,    39,    77,    78,    79,
      80,    81,    82,    93,    88,    91,    87,    87,    87,    23,
      24,    25,    28,    30,    84,    91,   134,    88,    78,    78,
      85,    78,    78,    78,    78,    78,    78,    78,    78,   145,
     145,   145,   123,   131,   131,    16,    84,   145,   121,   123,
     139,   140,   140,   145,   145,   145,    78,    86,    85,    91,
      91,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   139,   122,   123,   140,    42,    44,
      45,    46,    47,   122,   137,   138,   123,   145,    84,    85,
      19,    19,    85,    85,    84,   145,    19,    86,    86,    91,
      85,    85,    76,    19,    19,    91,   135,   122,   122,    94,
      84,    85,    84,    88,    93,   140,   124,   139,   145,   124,
     139,   145,   104,   105,   131,    76,   145,   140,   140,   123,
     145,   145,    77,   140,   140,   145,   145,    85,    86,    85,
      85,    88,    85,    85,    88,    15,    85,   123,    88,    85,
      88,    88,   137,    85,    85,    94,   100,   105,   105,   126,
     145,   105,   105,   126,   104,    87,    85,   126,   105,   126,
     126,    86,    85,    88,   130,    88,   130,   105,    60,    85,
      85,   127,   136,   139,    22,    85,   145,    85,   145,    76,
      76,    86,    78,    86,    84,   105,   105,    85,   105,   105,
     136,   136,   131,   130,    85,   105,    62,   142,    84,   105,
     131,    85,   105
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    95,    96,    96,    97,    98,    98,    98,    98,    98,
      99,    99,   100,   100,   101,   101,   101,   102,   103,   103,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     112,   112,   112,   113,   113,   113,   114,   114,   114,   114,
     114,   115,   115,   116,   116,   116,   116,   116,   116,   117,
     117,   117,   118,   119,   119,   119,   120,   120,   120,   120,
     120,   120,   121,   121,   122,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   124,   125,   125,   126,   126,   126,
     126,   127,   127,   127,   127,   127,   127,   128,   128,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   130,   130,
     131,   132,   132,   133,   133,   133,   134,   134,   134,   134,
     134,   135,   135,   136,   136,   136,   136,   137,   138,   138,
     138,   138,   138,   139,   139,   139,   140,   140,   140,   140,
     140,   141,   141,   142,   142,   143,   143,   144,   145
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     5,     5,     4,     4,     5,
       1,     3,     1,     1,     2,     2,     5,     1,     0,     2,
       2,     2,     2,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     3,     7,    10,    10,     1,     1,     2,     2,
       4,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     1,     1,     9,
       7,     4,     4,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     4,     2,     2,     4,     4,     4,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     8,
       5,     7,    10,     7,     7,    10,     7,     7,     0,     5,
       1,     5,     7,     3,     9,     3,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     3,     3,     1,
       1,    13,    12,     2,     5,     3,     6,     5,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 3:
#line 104 "lrparser.y"
                               {/* printf("LIST SIZE %d",frontEndContext.getFuncList().size())  ;*/ }
#line 1842 "y.tab.c"
    break;

  case 4:
#line 106 "lrparser.y"
                                            { 
	                                          Function* func=(Function*)(yyvsp[-1].node);
                                              blockStatement* block=(blockStatement*)(yyvsp[0].node);
                                              func->setBlockStatement(block);
											   Util::addFuncToList(func);
											}
#line 1853 "y.tab.c"
    break;

  case 5:
#line 113 "lrparser.y"
                                           { 
										   (yyval.node)=Util::createFuncNode((yyvsp[-3].node),(yyvsp[-1].pList)->PList);
                                           Util::setCurrentFuncType(GEN_FUNC);
										   Util::resetTemp(tempIds);
										   tempIds.clear();
	                                      }
#line 1864 "y.tab.c"
    break;

  case 6:
#line 119 "lrparser.y"
                                                           { 
										   (yyval.node)=Util::createStaticFuncNode((yyvsp[-3].node),(yyvsp[-1].pList)->PList);
                                            Util::setCurrentFuncType(STATIC_FUNC);
											Util::resetTemp(tempIds);
											tempIds.clear();
	                                      }
#line 1875 "y.tab.c"
    break;

  case 7:
#line 125 "lrparser.y"
                                                     { 
										   (yyval.node)=Util::createIncrementalNode((yyvsp[-1].pList)->PList);
                                            Util::setCurrentFuncType(INCREMENTAL_FUNC);
											Util::resetTemp(tempIds);
											tempIds.clear();
	                                      }
#line 1886 "y.tab.c"
    break;

  case 8:
#line 131 "lrparser.y"
                                                             { 
										   (yyval.node)=Util::createDecrementalNode((yyvsp[-1].pList)->PList);
                                            Util::setCurrentFuncType(DECREMENTAL_FUNC);
											Util::resetTemp(tempIds);
											tempIds.clear();
	                                      }
#line 1897 "y.tab.c"
    break;

  case 9:
#line 137 "lrparser.y"
                                                        { (yyval.node)=Util::createDynamicFuncNode((yyvsp[-3].node),(yyvsp[-1].pList)->PList);
                                            Util::setCurrentFuncType(DYNAMIC_FUNC);
											Util::resetTemp(tempIds);
											tempIds.clear();
											}
#line 1907 "y.tab.c"
    break;

  case 10:
#line 144 "lrparser.y"
                 {(yyval.pList)=Util::createPList((yyvsp[0].node));}
#line 1913 "y.tab.c"
    break;

  case 11:
#line 145 "lrparser.y"
                                     {(yyval.pList)=Util::addToPList((yyvsp[0].pList),(yyvsp[-2].node)); 
			                           }
#line 1920 "y.tab.c"
    break;

  case 12:
#line 148 "lrparser.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1926 "y.tab.c"
    break;

  case 13:
#line 149 "lrparser.y"
            {(yyval.node) = (yyvsp[0].node);}
#line 1932 "y.tab.c"
    break;

  case 14:
#line 151 "lrparser.y"
                 {  //Identifier* id=(Identifier*)Util::createIdentifierNode($2);
                        Type* type=(Type*)(yyvsp[-1].node);
	                     Identifier* id=(Identifier*)(yyvsp[0].node);
						 
						 if(type->isGraphType())
						    {
							 tempIds.push_back(id);
						   
							}
					printf("\n");
                    (yyval.node)=Util::createParamNode((yyvsp[-1].node),(yyvsp[0].node)); }
#line 1948 "y.tab.c"
    break;

  case 15:
#line 162 "lrparser.y"
                          { // Identifier* id=(Identifier*)Util::createIdentifierNode($2);
			  
					
                             (yyval.node)=Util::createParamNode((yyvsp[-1].node),(yyvsp[0].node));}
#line 1957 "y.tab.c"
    break;

  case 16:
#line 166 "lrparser.y"
                                                 { // Identifier* id1=(Identifier*)Util::createIdentifierNode($4);
			                            //Identifier* id=(Identifier*)Util::createIdentifierNode($2);
				                        Type* tempType=(Type*)(yyvsp[-4].node);
			                            if(tempType->isNodeEdgeType())
										  tempType->addSourceGraph((yyvsp[-1].node));
				                         (yyval.node)=Util::createParamNode(tempType,(yyvsp[-3].node));
									 }
#line 1969 "y.tab.c"
    break;

  case 17:
#line 175 "lrparser.y"
                                {(yyval.node)=(yyvsp[0].node);}
#line 1975 "y.tab.c"
    break;

  case 18:
#line 178 "lrparser.y"
              {}
#line 1981 "y.tab.c"
    break;

  case 19:
#line 179 "lrparser.y"
                               { Util::addToBlock((yyvsp[0].node)); }
#line 1987 "y.tab.c"
    break;

  case 20:
#line 181 "lrparser.y"
                          {(yyval.node)=(yyvsp[-1].node);}
#line 1993 "y.tab.c"
    break;

  case 21:
#line 182 "lrparser.y"
                       {(yyval.node)=(yyvsp[-1].node);}
#line 1999 "y.tab.c"
    break;

  case 22:
#line 183 "lrparser.y"
                       {(yyval.node)=Util::createNodeForProcCallStmt((yyvsp[-1].node));}
#line 2005 "y.tab.c"
    break;

  case 23:
#line 184 "lrparser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2011 "y.tab.c"
    break;

  case 24:
#line 185 "lrparser.y"
                      {(yyval.node)=(yyvsp[-1].node);}
#line 2017 "y.tab.c"
    break;

  case 25:
#line 186 "lrparser.y"
                          {(yyval.node)=(yyvsp[0].node); }
#line 2023 "y.tab.c"
    break;

  case 26:
#line 187 "lrparser.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2029 "y.tab.c"
    break;

  case 27:
#line 188 "lrparser.y"
                         {(yyval.node)=Util::createNodeForUnaryStatements((yyvsp[-1].node));}
#line 2035 "y.tab.c"
    break;

  case 28:
#line 189 "lrparser.y"
                          {(yyval.node) = (yyvsp[-1].node) ;}
#line 2041 "y.tab.c"
    break;

  case 29:
#line 190 "lrparser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2047 "y.tab.c"
    break;

  case 30:
#line 191 "lrparser.y"
                           {(yyval.node) = (yyvsp[0].node);}
#line 2053 "y.tab.c"
    break;

  case 31:
#line 192 "lrparser.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2059 "y.tab.c"
    break;

  case 32:
#line 195 "lrparser.y"
                                                   { (yyval.node)=Util::finishBlock();}
#line 2065 "y.tab.c"
    break;

  case 33:
#line 197 "lrparser.y"
                                                                    {(yyval.node) = Util::createBatchBlockStmt((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2071 "y.tab.c"
    break;

  case 34:
#line 199 "lrparser.y"
                                                                                {(yyval.node) = Util::createOnAddBlock((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[0].node));}
#line 2077 "y.tab.c"
    break;

  case 35:
#line 201 "lrparser.y"
                                                                                      {(yyval.node) = Util::createOnDeleteBlock((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[0].node));}
#line 2083 "y.tab.c"
    break;

  case 36:
#line 203 "lrparser.y"
                { Util::createNewBlock(); }
#line 2089 "y.tab.c"
    break;

  case 38:
#line 207 "lrparser.y"
                                  {(yyval.node) = Util::createReturnStatementNode((yyvsp[0].node));}
#line 2095 "y.tab.c"
    break;

  case 39:
#line 210 "lrparser.y"
                         {
	                     Type* type=(Type*)(yyvsp[-1].node);
	                     Identifier* id=(Identifier*)(yyvsp[0].node);
						 
						 if(type->isGraphType())
						    Util::storeGraphId(id);

                         (yyval.node)=Util::createNormalDeclNode((yyvsp[-1].node),(yyvsp[0].node));}
#line 2108 "y.tab.c"
    break;

  case 40:
#line 218 "lrparser.y"
                            {//Identifier* id=(Identifier*)Util::createIdentifierNode($2);
	                    
	                    (yyval.node)=Util::createAssignedDeclNode((yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2116 "y.tab.c"
    break;

  case 41:
#line 221 "lrparser.y"
                    {//Identifier* id=(Identifier*)Util::createIdentifierNode($2);
	            
                         (yyval.node)=Util::createNormalDeclNode((yyvsp[-1].node),(yyvsp[0].node)); }
#line 2124 "y.tab.c"
    break;

  case 42:
#line 224 "lrparser.y"
                           {//Identifier* id=(Identifier*)Util::createIdentifierNode($2);
	                   
	                    (yyval.node)=Util::createAssignedDeclNode((yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2132 "y.tab.c"
    break;

  case 43:
#line 228 "lrparser.y"
                 {(yyval.node)=(yyvsp[0].node); }
#line 2138 "y.tab.c"
    break;

  case 44:
#line 229 "lrparser.y"
                {(yyval.node)=(yyvsp[0].node);}
#line 2144 "y.tab.c"
    break;

  case 45:
#line 230 "lrparser.y"
                      { (yyval.node)=(yyvsp[0].node);}
#line 2150 "y.tab.c"
    break;

  case 46:
#line 233 "lrparser.y"
                 { (yyval.node)=Util::createPrimitiveTypeNode(TYPE_INT);}
#line 2156 "y.tab.c"
    break;

  case 47:
#line 234 "lrparser.y"
                  { (yyval.node)=Util::createPrimitiveTypeNode(TYPE_FLOAT);}
#line 2162 "y.tab.c"
    break;

  case 48:
#line 235 "lrparser.y"
                 { (yyval.node)=Util::createPrimitiveTypeNode(TYPE_BOOL);}
#line 2168 "y.tab.c"
    break;

  case 49:
#line 236 "lrparser.y"
                   { (yyval.node)=Util::createPrimitiveTypeNode(TYPE_DOUBLE); }
#line 2174 "y.tab.c"
    break;

  case 50:
#line 237 "lrparser.y"
             {(yyval.node)=(yyval.node)=Util::createPrimitiveTypeNode(TYPE_LONG);}
#line 2180 "y.tab.c"
    break;

  case 51:
#line 240 "lrparser.y"
                { (yyval.node)=Util::createGraphTypeNode(TYPE_GRAPH,NULL);}
#line 2186 "y.tab.c"
    break;

  case 52:
#line 241 "lrparser.y"
                     {(yyval.node)=Util::createGraphTypeNode(TYPE_DIRGRAPH,NULL);}
#line 2192 "y.tab.c"
    break;

  case 53:
#line 243 "lrparser.y"
                     { (yyval.node)=Util::createCollectionTypeNode(TYPE_LIST,NULL);}
#line 2198 "y.tab.c"
    break;

  case 54:
#line 244 "lrparser.y"
                                         {//Identifier* id=(Identifier*)Util::createIdentifierNode($3);
			                     (yyval.node)=Util::createCollectionTypeNode(TYPE_SETN,(yyvsp[-1].node));}
#line 2205 "y.tab.c"
    break;

  case 55:
#line 246 "lrparser.y"
                                 {// Identifier* id=(Identifier*)Util::createIdentifierNode($3);
					                    (yyval.node)=Util::createCollectionTypeNode(TYPE_SETE,(yyvsp[-1].node));}
#line 2212 "y.tab.c"
    break;

  case 56:
#line 248 "lrparser.y"
                                         { (yyval.node)=Util::createCollectionTypeNode(TYPE_UPDATES,(yyvsp[-1].node));}
#line 2218 "y.tab.c"
    break;

  case 57:
#line 249 "lrparser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2224 "y.tab.c"
    break;

  case 58:
#line 250 "lrparser.y"
                            {(yyval.node) = (yyvsp[0].node);}
#line 2230 "y.tab.c"
    break;

  case 59:
#line 252 "lrparser.y"
                                                               {(yyval.node) = Util::createContainerTypeNode(TYPE_CONTAINER, (yyvsp[-6].node), (yyvsp[-3].aList)->AList, (yyvsp[-1].node));}
#line 2236 "y.tab.c"
    break;

  case 60:
#line 253 "lrparser.y"
                                                      { (yyval.node) =  Util::createContainerTypeNode(TYPE_CONTAINER, (yyvsp[-4].node), (yyvsp[-1].aList)->AList, NULL);}
#line 2242 "y.tab.c"
    break;

  case 61:
#line 254 "lrparser.y"
                                     { list<argument*> argList;
			                          (yyval.node) = Util::createContainerTypeNode(TYPE_CONTAINER, (yyvsp[-1].node), argList, NULL);}
#line 2249 "y.tab.c"
    break;

  case 62:
#line 257 "lrparser.y"
                                 {(yyval.node) = Util::createNodeMapTypeNode(TYPE_NODEMAP, (yyvsp[-1].node));}
#line 2255 "y.tab.c"
    break;

  case 63:
#line 259 "lrparser.y"
               {(yyval.node)=Util::createNodeEdgeTypeNode(TYPE_NODE) ;}
#line 2261 "y.tab.c"
    break;

  case 64:
#line 260 "lrparser.y"
                {(yyval.node)=Util::createNodeEdgeTypeNode(TYPE_EDGE);}
#line 2267 "y.tab.c"
    break;

  case 65:
#line 261 "lrparser.y"
                      {(yyval.node)=(yyvsp[0].node);}
#line 2273 "y.tab.c"
    break;

  case 66:
#line 263 "lrparser.y"
                                  { (yyval.node)=Util::createPropertyTypeNode(TYPE_PROPNODE,(yyvsp[-1].node)); }
#line 2279 "y.tab.c"
    break;

  case 67:
#line 264 "lrparser.y"
                                       { (yyval.node)=Util::createPropertyTypeNode(TYPE_PROPEDGE,(yyvsp[-1].node)); }
#line 2285 "y.tab.c"
    break;

  case 68:
#line 265 "lrparser.y"
                                                    {  (yyval.node)=Util::createPropertyTypeNode(TYPE_PROPNODE,(yyvsp[-1].node)); }
#line 2291 "y.tab.c"
    break;

  case 69:
#line 266 "lrparser.y"
                                                     {(yyval.node)=Util::createPropertyTypeNode(TYPE_PROPEDGE,(yyvsp[-1].node));}
#line 2297 "y.tab.c"
    break;

  case 70:
#line 267 "lrparser.y"
                                    {ASTNode* type = Util::createNodeEdgeTypeNode(TYPE_NODE);
			                         (yyval.node)=Util::createPropertyTypeNode(TYPE_PROPNODE, type); }
#line 2304 "y.tab.c"
    break;

  case 71:
#line 269 "lrparser.y"
                                                {ASTNode* type = Util::createNodeEdgeTypeNode(TYPE_EDGE);
			                         (yyval.node)=Util::createPropertyTypeNode(TYPE_PROPNODE, type); }
#line 2311 "y.tab.c"
    break;

  case 72:
#line 272 "lrparser.y"
                                { printf("testassign\n");(yyval.node)=Util::createAssignmentNode((yyvsp[-2].node),(yyvsp[0].node));}
#line 2317 "y.tab.c"
    break;

  case 73:
#line 273 "lrparser.y"
                                  { (yyval.node)=Util::createAssignmentNode((yyvsp[-2].node) , (yyvsp[0].node));}
#line 2323 "y.tab.c"
    break;

  case 74:
#line 275 "lrparser.y"
                 { (yyval.node)=(yyvsp[0].node);}
#line 2329 "y.tab.c"
    break;

  case 75:
#line 277 "lrparser.y"
                       { (yyval.node)=(yyvsp[0].node);}
#line 2335 "y.tab.c"
    break;

  case 76:
#line 278 "lrparser.y"
                                         { (yyval.node)=Util::createNodeForArithmeticExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_ADD);}
#line 2341 "y.tab.c"
    break;

  case 77:
#line 279 "lrparser.y"
                                             { (yyval.node)=Util::createNodeForArithmeticExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_SUB);}
#line 2347 "y.tab.c"
    break;

  case 78:
#line 280 "lrparser.y"
                                             {(yyval.node)=Util::createNodeForArithmeticExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_MUL);}
#line 2353 "y.tab.c"
    break;

  case 79:
#line 281 "lrparser.y"
                                           {(yyval.node)=Util::createNodeForArithmeticExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_DIV);}
#line 2359 "y.tab.c"
    break;

  case 80:
#line 282 "lrparser.y"
                                              {(yyval.node)=Util::createNodeForLogicalExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_AND);}
#line 2365 "y.tab.c"
    break;

  case 81:
#line 283 "lrparser.y"
                                                  {(yyval.node)=Util::createNodeForLogicalExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_OR);}
#line 2371 "y.tab.c"
    break;

  case 82:
#line 284 "lrparser.y"
                                                 {(yyval.node)=Util::createNodeForRelationalExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_LE);}
#line 2377 "y.tab.c"
    break;

  case 83:
#line 285 "lrparser.y"
                                                {(yyval.node)=Util::createNodeForRelationalExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_GE);}
#line 2383 "y.tab.c"
    break;

  case 84:
#line 286 "lrparser.y"
                                                    {(yyval.node)=Util::createNodeForRelationalExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_LT);}
#line 2389 "y.tab.c"
    break;

  case 85:
#line 287 "lrparser.y"
                                                    {(yyval.node)=Util::createNodeForRelationalExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_GT);}
#line 2395 "y.tab.c"
    break;

  case 86:
#line 288 "lrparser.y"
                                                        {(yyval.node)=Util::createNodeForRelationalExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_EQ);}
#line 2401 "y.tab.c"
    break;

  case 87:
#line 289 "lrparser.y"
                                            {(yyval.node)=Util::createNodeForRelationalExpr((yyvsp[-2].node),(yyvsp[0].node),OPERATOR_NE);}
#line 2407 "y.tab.c"
    break;

  case 88:
#line 290 "lrparser.y"
                                         {(yyval.node)=Util::createNodeForUnaryExpr((yyvsp[0].node),OPERATOR_NOT);}
#line 2413 "y.tab.c"
    break;

  case 89:
#line 291 "lrparser.y"
                                          { Expression* expr=(Expression*)(yyvsp[-1].node);
				                     expr->setEnclosedBrackets();
			                        (yyval.node)=expr;}
#line 2421 "y.tab.c"
    break;

  case 90:
#line 294 "lrparser.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2427 "y.tab.c"
    break;

  case 91:
#line 295 "lrparser.y"
                                    { (yyval.node)=Util::createNodeForId((yyvsp[0].node));}
#line 2433 "y.tab.c"
    break;

  case 92:
#line 296 "lrparser.y"
                                      {(yyval.node)=(yyvsp[0].node);}
#line 2439 "y.tab.c"
    break;

  case 93:
#line 297 "lrparser.y"
                                     {(yyval.node) = (yyvsp[0].node);}
#line 2445 "y.tab.c"
    break;

  case 94:
#line 299 "lrparser.y"
                                          {printf("first done this \n");(yyval.node) = Util::createNodeForIndexExpr((yyvsp[-3].node), (yyvsp[-1].node), OPERATOR_INDEX);}
#line 2451 "y.tab.c"
    break;

  case 95:
#line 301 "lrparser.y"
                                   {(yyval.node)=Util::createNodeForUnaryExpr((yyvsp[-1].node),OPERATOR_INC);}
#line 2457 "y.tab.c"
    break;

  case 96:
#line 302 "lrparser.y"
                                                {(yyval.node)=Util::createNodeForUnaryExpr((yyvsp[-1].node),OPERATOR_DEC);}
#line 2463 "y.tab.c"
    break;

  case 97:
#line 304 "lrparser.y"
                                      { 
                                       
                                       (yyval.node) = Util::createNodeForProcCall((yyvsp[-3].node),(yyvsp[-1].aList)->AList,NULL); 

									    }
#line 2473 "y.tab.c"
    break;

  case 98:
#line 309 "lrparser.y"
                                                         { ASTNode* id = Util::createIdentifierNode("Incremental");
			                                   (yyval.node) = Util::createNodeForProcCall(id, (yyvsp[-1].aList)->AList,NULL); 

				                               }
#line 2482 "y.tab.c"
    break;

  case 99:
#line 313 "lrparser.y"
                                                         { ASTNode* id = Util::createIdentifierNode("Decremental");
			                                   (yyval.node) = Util::createNodeForProcCall(id, (yyvsp[-1].aList)->AList,NULL); 

				                               }
#line 2491 "y.tab.c"
    break;

  case 100:
#line 317 "lrparser.y"
                                                                  {
                                                   
													 Expression* expr = (Expression*)(yyvsp[-5].node);
                                                     (yyval.node) = Util::createNodeForProcCall((yyvsp[-3].node) , (yyvsp[-1].aList)->AList, expr); 

									                 }
#line 2502 "y.tab.c"
    break;

  case 101:
#line 328 "lrparser.y"
              { (yyval.node) = Util::createNodeForIval((yyvsp[0].ival)); }
#line 2508 "y.tab.c"
    break;

  case 102:
#line 329 "lrparser.y"
                    {(yyval.node) = Util::createNodeForFval((yyvsp[0].fval));}
#line 2514 "y.tab.c"
    break;

  case 103:
#line 330 "lrparser.y"
                   { (yyval.node) = Util::createNodeForBval((yyvsp[0].bval));}
#line 2520 "y.tab.c"
    break;

  case 104:
#line 331 "lrparser.y"
                {(yyval.node)=Util::createNodeForINF(true);}
#line 2526 "y.tab.c"
    break;

  case 105:
#line 332 "lrparser.y"
                  {(yyval.node)=Util::createNodeForINF(true);}
#line 2532 "y.tab.c"
    break;

  case 106:
#line 333 "lrparser.y"
                  {(yyval.node)=Util::createNodeForINF(false);}
#line 2538 "y.tab.c"
    break;

  case 107:
#line 336 "lrparser.y"
                            { (yyval.node)=(yyvsp[0].node); }
#line 2544 "y.tab.c"
    break;

  case 108:
#line 337 "lrparser.y"
                             { (yyval.node)=(yyvsp[0].node); }
#line 2550 "y.tab.c"
    break;

  case 109:
#line 339 "lrparser.y"
                                                                              { (yyval.node)=Util::createNodeForFixedPointStmt((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 2556 "y.tab.c"
    break;

  case 110:
#line 340 "lrparser.y"
                                                                 {(yyval.node)=Util::createNodeForWhileStmt((yyvsp[-2].node),(yyvsp[0].node)); }
#line 2562 "y.tab.c"
    break;

  case 111:
#line 341 "lrparser.y"
                                                                           {(yyval.node)=Util::createNodeForDoWhileStmt((yyvsp[-2].node),(yyvsp[-5].node));  }
#line 2568 "y.tab.c"
    break;

  case 112:
#line 342 "lrparser.y"
                                                                                       { 
																				(yyval.node)=Util::createNodeForForAllStmt((yyvsp[-7].node),(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node),true);}
#line 2575 "y.tab.c"
    break;

  case 113:
#line 344 "lrparser.y"
                                                                        { (yyval.node)=Util::createNodeForForStmt((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node),true);}
#line 2581 "y.tab.c"
    break;

  case 114:
#line 345 "lrparser.y"
                                                                 { (yyval.node)=Util::createNodeForForStmt((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node),false);}
#line 2587 "y.tab.c"
    break;

  case 115:
#line 346 "lrparser.y"
                                                                                    {(yyval.node)=Util::createNodeForForAllStmt((yyvsp[-7].node),(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node),false);}
#line 2593 "y.tab.c"
    break;

  case 116:
#line 347 "lrparser.y"
                                                                  {(yyval.node) = Util::createNodeForForStmt((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), false);}
#line 2599 "y.tab.c"
    break;

  case 117:
#line 348 "lrparser.y"
                                                                     {(yyval.node) = Util::createNodeForForStmt((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), true);}
#line 2605 "y.tab.c"
    break;

  case 118:
#line 350 "lrparser.y"
                      { (yyval.node)=NULL;}
#line 2611 "y.tab.c"
    break;

  case 119:
#line 351 "lrparser.y"
                                              { (yyval.node)=(yyvsp[-1].node);}
#line 2617 "y.tab.c"
    break;

  case 120:
#line 353 "lrparser.y"
                          { (yyval.node)=(yyvsp[0].node) ;}
#line 2623 "y.tab.c"
    break;

  case 121:
#line 355 "lrparser.y"
                                                   { (yyval.node)=Util::createNodeForIfStmt((yyvsp[-2].node),(yyvsp[0].node),NULL); }
#line 2629 "y.tab.c"
    break;

  case 122:
#line 356 "lrparser.y"
                                                                           {(yyval.node)=Util::createNodeForIfStmt((yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 2635 "y.tab.c"
    break;

  case 123:
#line 359 "lrparser.y"
                                       { (yyval.node)=Util::createNodeForReductionStmt((yyvsp[-2].node),(yyvsp[0].node)) ;}
#line 2641 "y.tab.c"
    break;

  case 124:
#line 360 "lrparser.y"
                                                                              { reductionCall* reduc=(reductionCall*)(yyvsp[-3].node);
		                                                               (yyval.node)=Util::createNodeForReductionStmtList((yyvsp[-7].nodeList)->ASTNList,reduc,(yyvsp[-1].nodeList)->ASTNList);}
#line 2648 "y.tab.c"
    break;

  case 125:
#line 362 "lrparser.y"
                                                   {(yyval.node)=Util::createNodeForReductionOpStmt((yyvsp[-2].node),(yyvsp[-1].ival),(yyvsp[0].node));}
#line 2654 "y.tab.c"
    break;

  case 126:
#line 365 "lrparser.y"
                         {(yyval.ival)=OPERATOR_ADDASSIGN;}
#line 2660 "y.tab.c"
    break;

  case 127:
#line 366 "lrparser.y"
                         {(yyval.ival)=OPERATOR_MULASSIGN;}
#line 2666 "y.tab.c"
    break;

  case 128:
#line 367 "lrparser.y"
                                 {(yyval.ival)=OPERATOR_ORASSIGN;}
#line 2672 "y.tab.c"
    break;

  case 129:
#line 368 "lrparser.y"
                                 {(yyval.ival)=OPERATOR_ANDASSIGN;}
#line 2678 "y.tab.c"
    break;

  case 130:
#line 369 "lrparser.y"
                                 {(yyval.ival)=OPERATOR_SUBASSIGN;}
#line 2684 "y.tab.c"
    break;

  case 131:
#line 371 "lrparser.y"
                                  { (yyval.nodeList)=Util::addToNList((yyvsp[0].nodeList),(yyvsp[-2].node));
                                         }
#line 2691 "y.tab.c"
    break;

  case 132:
#line 373 "lrparser.y"
                            { (yyval.nodeList)=Util::createNList((yyvsp[0].node));}
#line 2697 "y.tab.c"
    break;

  case 133:
#line 375 "lrparser.y"
                              { (yyval.nodeList)=Util::addToNList((yyvsp[0].nodeList),(yyvsp[-2].node));}
#line 2703 "y.tab.c"
    break;

  case 134:
#line 376 "lrparser.y"
                                   { ASTNode* node = Util::createNodeForId((yyvsp[-2].node));
			                         (yyval.nodeList)=Util::addToNList((yyvsp[0].nodeList),node);}
#line 2710 "y.tab.c"
    break;

  case 135:
#line 378 "lrparser.y"
                   { (yyval.nodeList)=Util::createNList((yyvsp[0].node));}
#line 2716 "y.tab.c"
    break;

  case 136:
#line 379 "lrparser.y"
                              { ASTNode* node = Util::createNodeForId((yyvsp[0].node));
			            (yyval.nodeList)=Util::createNList(node);}
#line 2723 "y.tab.c"
    break;

  case 137:
#line 388 "lrparser.y"
                                                 {(yyval.node)=Util::createNodeforReductionCall((yyvsp[-3].ival),(yyvsp[-1].aList)->AList);}
#line 2729 "y.tab.c"
    break;

  case 138:
#line 390 "lrparser.y"
                        { (yyval.ival)=REDUCE_SUM;}
#line 2735 "y.tab.c"
    break;

  case 139:
#line 391 "lrparser.y"
                           {(yyval.ival)=REDUCE_COUNT;}
#line 2741 "y.tab.c"
    break;

  case 140:
#line 392 "lrparser.y"
                             {(yyval.ival)=REDUCE_PRODUCT;}
#line 2747 "y.tab.c"
    break;

  case 141:
#line 393 "lrparser.y"
                         {(yyval.ival)=REDUCE_MAX;}
#line 2753 "y.tab.c"
    break;

  case 142:
#line 394 "lrparser.y"
                         {(yyval.ival)=REDUCE_MIN;}
#line 2759 "y.tab.c"
    break;

  case 143:
#line 396 "lrparser.y"
              { (yyval.node)=(yyvsp[0].node); }
#line 2765 "y.tab.c"
    break;

  case 144:
#line 397 "lrparser.y"
               { printf("Here hello \n"); (yyval.node)=(yyvsp[0].node); }
#line 2771 "y.tab.c"
    break;

  case 145:
#line 398 "lrparser.y"
               {(yyval.node) = (yyvsp[0].node); }
#line 2777 "y.tab.c"
    break;

  case 146:
#line 401 "lrparser.y"
              {
                 argList* aList=new argList();
				 (yyval.aList)=aList;  }
#line 2785 "y.tab.c"
    break;

  case 147:
#line 405 "lrparser.y"
                                         {argument* a1=new argument();
		                          assignment* assign=(assignment*)(yyvsp[-2].node);
		                     a1->setAssign(assign);
							 a1->setAssignFlag();
		                 //a1->assignExpr=(assignment*)$1;
						 // a1->assign=true;
						  (yyval.aList)=Util::addToAList((yyvsp[0].aList),a1);
						  /*
						  for(argument* arg:$$->AList)
						  {
							  printf("VALUE OF ARG %d",arg->getAssignExpr()); //rm for warnings
						  }
						  */ 
						  
                          }
#line 2805 "y.tab.c"
    break;

  case 148:
#line 422 "lrparser.y"
                                             {argument* a1=new argument();
		                                Expression* expr=(Expression*)(yyvsp[-2].node);
										a1->setExpression(expr);
										a1->setExpressionFlag();
						               // a1->expressionflag=true;
										 (yyval.aList)=Util::addToAList((yyvsp[0].aList),a1);
						                }
#line 2817 "y.tab.c"
    break;

  case 149:
#line 429 "lrparser.y"
                            {argument* a1=new argument();
		                 Expression* expr=(Expression*)(yyvsp[0].node);
						 a1->setExpression(expr);
						a1->setExpressionFlag();
						  (yyval.aList)=Util::createAList(a1); }
#line 2827 "y.tab.c"
    break;

  case 150:
#line 434 "lrparser.y"
                            { argument* a1=new argument();
		                   assignment* assign=(assignment*)(yyvsp[0].node);
		                     a1->setAssign(assign);
							 a1->setAssignFlag();
						   (yyval.aList)=Util::createAList(a1);
						   }
#line 2838 "y.tab.c"
    break;

  case 151:
#line 442 "lrparser.y"
                                                                                                                 {(yyval.node)=Util::createIterateInBFSNode((yyvsp[-10].node),(yyvsp[-8].node),(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)) ;}
#line 2844 "y.tab.c"
    break;

  case 152:
#line 443 "lrparser.y"
                                                                                                      {(yyval.node)=Util::createIterateInBFSNode((yyvsp[-9].node),(yyvsp[-7].node),(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node),(yyvsp[0].node),NULL) ; }
#line 2850 "y.tab.c"
    break;

  case 153:
#line 447 "lrparser.y"
                                                 {(yyval.node)=Util::createIterateInReverseBFSNode(NULL,(yyvsp[0].node));}
#line 2856 "y.tab.c"
    break;

  case 154:
#line 448 "lrparser.y"
                                                                       {(yyval.node)=Util::createIterateInReverseBFSNode((yyvsp[-2].node),(yyvsp[0].node));}
#line 2862 "y.tab.c"
    break;

  case 155:
#line 451 "lrparser.y"
                 { //Identifier* id1=(Identifier*)Util::createIdentifierNode($1);
                  // Identifier* id2=(Identifier*)Util::createIdentifierNode($1);
				   (yyval.node) = Util::createPropIdNode((yyvsp[-2].node),(yyvsp[0].node));
				    }
#line 2871 "y.tab.c"
    break;

  case 156:
#line 455 "lrparser.y"
                                { ASTNode* expr1 = Util::createNodeForId((yyvsp[-3].node));
	                          ASTNode* expr2 = Util::createNodeForId((yyvsp[-1].node));
							  ASTNode* indexexpr =  Util::createNodeForIndexExpr(expr1, expr2, OPERATOR_INDEX);
	                          (yyval.node) = Util::createPropIdNode((yyvsp[-5].node) , indexexpr);}
#line 2880 "y.tab.c"
    break;

  case 157:
#line 462 "lrparser.y"
                       {// Identifier* id1=(Identifier*)Util::createIdentifierNode($1);
                  // Identifier* id2=(Identifier*)Util::createIdentifierNode($1);
				   (yyval.node)=Util::createPropIdNode((yyvsp[-4].node),(yyvsp[-2].node));
				    }
#line 2889 "y.tab.c"
    break;

  case 158:
#line 466 "lrparser.y"
          { 
	         (yyval.node)=Util::createIdentifierNode((yyvsp[0].text));  

            
            }
#line 2899 "y.tab.c"
    break;


#line 2903 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 474 "lrparser.y"



void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}


int main(int argc,char **argv) 
{
  
  if(argc<4){
    std::cout<< "Usage: " << argv[0] << " [-s|-d] -f <dsl.sp> -b [cuda|omp|mpi|acc|multigpu|amd] " << '\n';
    std::cout<< "E.g. : " << argv[0] << " -s -f ../graphcode/sssp_dslV2 -b omp " << '\n';
    exit(-1);
  }
  
    //dsl_cpp_generator cpp_backend;
    SymbolTableBuilder stBuilder;
     FILE    *fd;
     
  int opt;
  char* fileName=NULL;
  backendTarget = NULL;
  bool staticGen = false;
  bool dynamicGen = false;
  bool optimize = false;

  while ((opt = getopt(argc, argv, "sdf:b:o")) != -1) 
  {
     switch (opt) 
     {
      case 'f':
        fileName = optarg;
        break;
      case 'b':
        backendTarget = optarg;
        break;
      case 's':
	    staticGen = true;
		break;
	  case 'd':
	    dynamicGen = true;
        break;	
	  case 'o':
	  	optimize = true;
		break;	
      case '?':
        fprintf(stderr,"Unknown option: %c\n", optopt);
		exit(-1);
        break;
      case ':':
        fprintf(stderr,"Missing arg for %c\n", optopt);
		exit(-1);
        break;
     }
  }
   
   printf("fileName %s\n",fileName);
   printf("Backend Target %s\n",backendTarget);

   
   if(fileName==NULL||backendTarget==NULL)
   {
	   if(fileName==NULL)
	      fprintf(stderr,"FileName option Error!\n");
	   if(backendTarget==NULL)
	      fprintf(stderr,"backendTarget option Error!\n")	;
	   exit(-1);	    
   }
   else
    {

		if(!((strcmp(backendTarget,"omp")==0)|| (strcmp(backendTarget,"amd")==0) || (strcmp(backendTarget,"mpi")==0)||(strcmp(backendTarget,"cuda")==0) || (strcmp(backendTarget,"acc")==0) || (strcmp(backendTarget,"sycl")==0)|| (strcmp(backendTarget,"multigpu")==0)))

		   {
			  fprintf(stderr, "Specified backend target is not implemented in the current version!\n");
			   exit(-1);
		   }
	}

   if(!(staticGen || dynamicGen)) {
		fprintf(stderr, "Type of graph(static/dynamic) not specified!\n");
		exit(-1);
     }
	  
     


   yyin= fopen(fileName,"r");
   
   if(!yyin) {
	printf("file doesn't exists!\n");
	exit(-1);
   }
   
   
   int error=yyparse();
   printf("error val %d\n",error);


	if(error!=1)
	{
     //TODO: redirect to different backend generator after comparing with the 'b' option
    std::cout << "at 1" << std::endl;
	stBuilder.buildST(frontEndContext.getFuncList());
	frontEndContext.setDynamicLinkFuncs(stBuilder.getDynamicLinkedFuncs());
	std::cout << "at 2" << std::endl;

	if(staticGen)
	  {
		  /*
		  if(optimize)
		  {
			  attachPropAnalyser apAnalyser;
			  apAnalyser.analyse(frontEndContext.getFuncList());

			  dataRaceAnalyser drAnalyser;
			  drAnalyser.analyse(frontEndContext.getFuncList());
			  
			  if(strcmp(backendTarget,"cuda")==0)
			  {
			  	deviceVarsAnalyser dvAnalyser;
				//cpp_backend.setOptimized();
			  	dvAnalyser.analyse(frontEndContext.getFuncList());
			  }
		  }
		  */
	  //cpp_backend.setFileName(fileName);
	  //cpp_backend.generate();
     if (strcmp(backendTarget, "cuda") == 0) {
        spcuda::dsl_cpp_generator cpp_backend;
        cpp_backend.setFileName(fileName);
	//~ cpp_backend.setOptimized();
	
	if (optimize) {
	  attachPropAnalyser apAnalyser;
	  apAnalyser.analyse(frontEndContext.getFuncList());

	  dataRaceAnalyser drAnalyser;
	  drAnalyser.analyse(frontEndContext.getFuncList());

	  deviceVarsAnalyser dvAnalyser;
	  dvAnalyser.analyse(frontEndContext.getFuncList());
	  cpp_backend.setOptimized();
	}
		  
        cpp_backend.generate();
      } 
      else if (strcmp(backendTarget, "omp") == 0) {
        spomp::dsl_cpp_generator cpp_backend;
	std::cout<< "size:" << frontEndContext.getFuncList().size() << '\n';
        cpp_backend.setFileName(fileName);
        cpp_backend.generate();
      } 
	  else if (strcmp(backendTarget, "mpi") == 0) {
        spmpi::dsl_cpp_generator cpp_backend;
		std::cout<< "size:" << frontEndContext.getFuncList().size() << '\n';
        cpp_backend.setFileName(fileName);
        cpp_backend.generate();
      } 
      else if (strcmp(backendTarget, "acc") == 0) {
        spacc::dsl_cpp_generator cpp_backend;
        cpp_backend.setFileName(fileName);
		if(optimize) {
			cpp_backend.setOptimized();
			blockVarsAnalyser bvAnalyser;
			bvAnalyser.analyse(frontEndContext.getFuncList());
		}
        cpp_backend.generate();
      }
	  else if(strcmp(backendTarget, "multigpu") == 0){
		spmultigpu::dsl_cpp_generator cpp_backend;
		pushpullAnalyser pp;
		pp.analyse(frontEndContext.getFuncList());
		cpp_backend.setFileName(fileName);
		cpp_backend.generate();
}
	  else if (strcmp(backendTarget, "sycl") == 0) {
		std::cout<<"GENERATING SYCL CODE"<<std::endl;
        spsycl::dsl_cpp_generator cpp_backend;
        cpp_backend.setFileName(fileName);
        cpp_backend.generate();
	  }
	  else if (strcmp(backendTarget, "amd") == 0) {
		std::cout<<"GENERATING OPENCL CODE"<<std::endl;
        spamd::dsl_cpp_generator cpp_backend;
        cpp_backend.setFileName(fileName);
        cpp_backend.generate();
	  }
      else
	    std::cout<< "invalid backend" << '\n';
	  }
	else 
	 {
		if(strcmp(backendTarget, "omp") == 0) {
		   spdynomp::dsl_dyn_cpp_generator cpp_dyn_gen;
		   cpp_dyn_gen.setFileName(fileName);
	       cpp_dyn_gen.generate();
		}
		if(strcmp(backendTarget, "mpi") == 0){
		   spdynmpi::dsl_dyn_cpp_generator cpp_dyn_gen;
		   std::cout<<"created dyn mpi"<<std::endl;
		   cpp_dyn_gen.setFileName(fileName);
		   std::cout<<"file name set"<<std::endl;
	       cpp_dyn_gen.generate();	
		}
	 }
	
   }

	printf("finished successfully\n");
   
   /* to generate code, ./finalcode -s/-d -f "filename" -b "backendname"*/
	return 0;   
	 
}
