/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ECHO_TAB_H_INCLUDED
# define YY_YY_ECHO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_IDENTIFIER = 258,            /* T_IDENTIFIER  */
    T_TXT_LITERAL = 259,           /* T_TXT_LITERAL  */
    T_NUM_LITERAL = 260,           /* T_NUM_LITERAL  */
    T_BOOL_LITERAL = 261,          /* T_BOOL_LITERAL  */
    T_ECHO = 262,                  /* T_ECHO  */
    T_RETURN = 263,                /* T_RETURN  */
    T_SHOW = 264,                  /* T_SHOW  */
    T_GET = 265,                   /* T_GET  */
    T_IF = 266,                    /* T_IF  */
    T_OTIF = 267,                  /* T_OTIF  */
    T_OTHER = 268,                 /* T_OTHER  */
    T_LOOP = 269,                  /* T_LOOP  */
    T_TIMES = 270,                 /* T_TIMES  */
    T_BUBBLE = 271,                /* T_BUBBLE  */
    T_TRY = 272,                   /* T_TRY  */
    T_OOPS = 273,                  /* T_OOPS  */
    T_TYPE_TXT = 274,              /* T_TYPE_TXT  */
    T_TYPE_NUM = 275,              /* T_TYPE_NUM  */
    T_TYPE_BOOL = 276,             /* T_TYPE_BOOL  */
    T_TYPE_OBJ = 277,              /* T_TYPE_OBJ  */
    T_TYPE_LIST = 278,             /* T_TYPE_LIST  */
    T_TYPE_SILENT = 279,           /* T_TYPE_SILENT  */
    T_ASSIGN = 280,                /* T_ASSIGN  */
    T_CONCAT = 281,                /* T_CONCAT  */
    T_EQ = 282,                    /* T_EQ  */
    T_NEQ = 283,                   /* T_NEQ  */
    T_LT = 284,                    /* T_LT  */
    T_GT = 285,                    /* T_GT  */
    T_LTE = 286,                   /* T_LTE  */
    T_GTE = 287,                   /* T_GTE  */
    T_AND = 288,                   /* T_AND  */
    T_OR = 289,                    /* T_OR  */
    T_NOT = 290                    /* T_NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "echo.y"

    double dval; // Para números e resultados de expressões numéricas
    char  *sval; // Para identificadores e literais de texto
    int    bval; // Para literais booleanos e resultados de expressões lógicas
    // Ex: struct AST_Node *node; // Se construir uma AST

#line 106 "echo.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ECHO_TAB_H_INCLUDED  */
