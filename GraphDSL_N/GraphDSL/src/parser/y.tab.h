/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
     

#line 220 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
