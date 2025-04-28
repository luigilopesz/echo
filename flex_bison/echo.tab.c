/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "echo.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos
extern int yylex();
extern char *yytext;
extern int yylineno;
void yyerror(const char *s);

// TODO: Incluir aqui declarações de estruturas de dados (tabela de símbolos, AST) se necessário.


#line 86 "echo.tab.c"

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

#include "echo.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_IDENTIFIER = 3,               /* T_IDENTIFIER  */
  YYSYMBOL_T_TXT_LITERAL = 4,              /* T_TXT_LITERAL  */
  YYSYMBOL_T_NUM_LITERAL = 5,              /* T_NUM_LITERAL  */
  YYSYMBOL_T_BOOL_LITERAL = 6,             /* T_BOOL_LITERAL  */
  YYSYMBOL_T_ECHO = 7,                     /* T_ECHO  */
  YYSYMBOL_T_RETURN = 8,                   /* T_RETURN  */
  YYSYMBOL_T_SHOW = 9,                     /* T_SHOW  */
  YYSYMBOL_T_GET = 10,                     /* T_GET  */
  YYSYMBOL_T_IF = 11,                      /* T_IF  */
  YYSYMBOL_T_OTIF = 12,                    /* T_OTIF  */
  YYSYMBOL_T_OTHER = 13,                   /* T_OTHER  */
  YYSYMBOL_T_LOOP = 14,                    /* T_LOOP  */
  YYSYMBOL_T_TIMES = 15,                   /* T_TIMES  */
  YYSYMBOL_T_BUBBLE = 16,                  /* T_BUBBLE  */
  YYSYMBOL_T_TRY = 17,                     /* T_TRY  */
  YYSYMBOL_T_OOPS = 18,                    /* T_OOPS  */
  YYSYMBOL_T_TYPE_TXT = 19,                /* T_TYPE_TXT  */
  YYSYMBOL_T_TYPE_NUM = 20,                /* T_TYPE_NUM  */
  YYSYMBOL_T_TYPE_BOOL = 21,               /* T_TYPE_BOOL  */
  YYSYMBOL_T_TYPE_OBJ = 22,                /* T_TYPE_OBJ  */
  YYSYMBOL_T_TYPE_LIST = 23,               /* T_TYPE_LIST  */
  YYSYMBOL_T_TYPE_SILENT = 24,             /* T_TYPE_SILENT  */
  YYSYMBOL_T_ASSIGN = 25,                  /* T_ASSIGN  */
  YYSYMBOL_T_CONCAT = 26,                  /* T_CONCAT  */
  YYSYMBOL_T_EQ = 27,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 28,                     /* T_NEQ  */
  YYSYMBOL_T_LT = 29,                      /* T_LT  */
  YYSYMBOL_T_GT = 30,                      /* T_GT  */
  YYSYMBOL_T_LTE = 31,                     /* T_LTE  */
  YYSYMBOL_T_GTE = 32,                     /* T_GTE  */
  YYSYMBOL_T_AND = 33,                     /* T_AND  */
  YYSYMBOL_T_OR = 34,                      /* T_OR  */
  YYSYMBOL_T_NOT = 35,                     /* T_NOT  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '!'  */
  YYSYMBOL_41_ = 41,                       /* '.'  */
  YYSYMBOL_42_ = 42,                       /* '['  */
  YYSYMBOL_43_ = 43,                       /* ']'  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_programa = 52,                  /* programa  */
  YYSYMBOL_declaracao_lista = 53,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 54,                /* declaracao  */
  YYSYMBOL_tipo_nome = 55,                 /* tipo_nome  */
  YYSYMBOL_atribuicao = 56,                /* atribuicao  */
  YYSYMBOL_reatribuicao = 57,              /* reatribuicao  */
  YYSYMBOL_definicao_funcao = 58,          /* definicao_funcao  */
  YYSYMBOL_parametros_opt = 59,            /* parametros_opt  */
  YYSYMBOL_parametros = 60,                /* parametros  */
  YYSYMBOL_parametro = 61,                 /* parametro  */
  YYSYMBOL_comando_retorno = 62,           /* comando_retorno  */
  YYSYMBOL_condicional = 63,               /* condicional  */
  YYSYMBOL_lista_otif = 64,                /* lista_otif  */
  YYSYMBOL_other_opt = 65,                 /* other_opt  */
  YYSYMBOL_repeticao = 66,                 /* repeticao  */
  YYSYMBOL_loop_especificador = 67,        /* loop_especificador  */
  YYSYMBOL_comando_show = 68,              /* comando_show  */
  YYSYMBOL_excecao = 69,                   /* excecao  */
  YYSYMBOL_escopo_isolado = 70,            /* escopo_isolado  */
  YYSYMBOL_bloco = 71,                     /* bloco  */
  YYSYMBOL_expressao = 72,                 /* expressao  */
  YYSYMBOL_literal_num = 73,               /* literal_num  */
  YYSYMBOL_literal_txt = 74,               /* literal_txt  */
  YYSYMBOL_literal_bool = 75,              /* literal_bool  */
  YYSYMBOL_acesso_membro = 76,             /* acesso_membro  */
  YYSYMBOL_acesso_indice = 77,             /* acesso_indice  */
  YYSYMBOL_chamada_funcao = 78,            /* chamada_funcao  */
  YYSYMBOL_argumentos_opt = 79,            /* argumentos_opt  */
  YYSYMBOL_argumento_lista = 80,           /* argumento_lista  */
  YYSYMBOL_lista_literal = 81,             /* lista_literal  */
  YYSYMBOL_elementos_lista_opt = 82,       /* elementos_lista_opt  */
  YYSYMBOL_elemento_lista = 83,            /* elemento_lista  */
  YYSYMBOL_objeto_literal = 84             /* objeto_literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   436

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,     2,     2,     2,
      44,    45,    38,    36,    47,    37,    41,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    74,    76,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    93,    97,    98,    99,   100,
     101,   102,   107,   119,   128,   136,   138,   142,   143,   147,
     157,   163,   167,   169,   173,   175,   181,   186,   191,   197,
     203,   209,   215,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   248,   252,   256,   257,
     258,   261,   270,   278,   286,   286,   287,   287,   290,   291,
     291,   292,   292,   295
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "T_IDENTIFIER",
  "T_TXT_LITERAL", "T_NUM_LITERAL", "T_BOOL_LITERAL", "T_ECHO", "T_RETURN",
  "T_SHOW", "T_GET", "T_IF", "T_OTIF", "T_OTHER", "T_LOOP", "T_TIMES",
  "T_BUBBLE", "T_TRY", "T_OOPS", "T_TYPE_TXT", "T_TYPE_NUM", "T_TYPE_BOOL",
  "T_TYPE_OBJ", "T_TYPE_LIST", "T_TYPE_SILENT", "T_ASSIGN", "T_CONCAT",
  "T_EQ", "T_NEQ", "T_LT", "T_GT", "T_LTE", "T_GTE", "T_AND", "T_OR",
  "T_NOT", "'+'", "'-'", "'*'", "'/'", "'!'", "'.'", "'['", "']'", "'('",
  "')'", "';'", "','", "':'", "'{'", "'}'", "$accept", "programa",
  "declaracao_lista", "declaracao", "tipo_nome", "atribuicao",
  "reatribuicao", "definicao_funcao", "parametros_opt", "parametros",
  "parametro", "comando_retorno", "condicional", "lista_otif", "other_opt",
  "repeticao", "loop_especificador", "comando_show", "excecao",
  "escopo_isolado", "bloco", "expressao", "literal_num", "literal_txt",
  "literal_bool", "acesso_membro", "acesso_indice", "chamada_funcao",
  "argumentos_opt", "argumento_lista", "lista_literal",
  "elementos_lista_opt", "elemento_lista", "objeto_literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -59,     7,   229,   -59,   -21,   -59,   -59,   -59,    -2,     6,
     -17,   -59,    -1,     2,   -19,   -19,   -59,   -59,   -59,   -59,
     -59,   -59,     6,     6,     6,   -59,   -59,   -59,    32,    -6,
      -4,   -59,     0,   -59,   -59,     1,   -59,   -59,   270,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,     6,     6,    34,
       5,   329,     6,     6,    80,   -59,   -59,    33,   -36,   329,
       9,    10,   291,   133,    28,   -59,   -59,   -59,   -59,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,    51,     6,   -59,   329,   329,    11,    12,    14,
     329,    69,   -12,   -19,   253,   181,   -19,   -59,     6,   -59,
     -59,     6,   -13,   363,   363,   394,   394,   394,   394,   380,
     346,   -13,   -13,   -36,   -36,   -59,   311,   -59,     6,    -2,
     -59,     6,   -59,   -59,   -59,   -59,   329,   329,   -59,   329,
      70,    30,    29,   -59,    21,   329,   -59,   -19,    -2,    53,
     -19,   -59,   -59,   -59,     6,   -59,    69,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,    46,    69,    68,    70,     0,     0,
       0,    47,     0,     0,     0,     0,    16,    17,    18,    19,
      20,    21,     0,    79,     0,    15,     3,     4,     0,     0,
       0,     5,     0,     6,     7,     0,     9,     8,     0,    43,
      44,    45,    49,    50,    48,    51,    52,     0,    74,     0,
      46,    30,     0,     0,     0,     3,    41,     0,    66,    81,
       0,    80,     0,     0,     0,    10,    11,    13,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    23,    76,     0,    75,     0,
      39,     0,    46,     0,     0,     0,     0,    78,     0,    67,
      83,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    53,    54,    55,    56,    71,     0,    73,     0,    25,
      32,     0,    36,    38,    42,    40,    82,    22,    72,    77,
       0,     0,    26,    27,    34,    37,    29,     0,     0,     0,
       0,    31,    24,    28,     0,    35,     0,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -24,   -59,    -5,   -59,   -59,   -59,   -59,   -59,
     -58,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -14,    -9,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    27,    28,    29,    30,    31,   131,   132,
     133,    32,    33,   134,   141,    34,    93,    35,    36,    37,
      56,    38,    39,    40,    41,    42,    43,    44,    87,    88,
      45,    60,    61,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    57,    63,    49,    47,    82,    83,     3,    52,    50,
       5,     6,     7,    58,    59,    62,    11,    16,    17,    18,
      19,    20,    21,    48,    53,    80,    81,    54,    82,    83,
      55,    95,    48,   139,   140,    64,   121,    89,    85,    86,
      65,    22,    66,    90,    91,    94,    67,    68,    23,    48,
      24,    96,    97,   101,   115,    26,   117,    98,   119,   118,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   136,   116,   137,   138,   120,   144,   122,
     143,     0,   125,    92,     5,     6,     7,     0,     0,   126,
      11,     0,   127,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,    78,    79,    80,    81,   129,
      82,    83,   135,     0,   130,    22,     0,     0,    55,     0,
       0,     0,    23,   142,    24,     0,   145,     0,     0,    26,
       0,     0,   147,   130,     0,   146,     4,     5,     6,     7,
       8,     9,    10,    11,    12,     0,     0,    13,     0,    14,
      15,     0,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,    23,     0,    24,     0,    25,
       0,     0,    26,   100,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,    13,     0,    14,    15,     0,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,    24,     0,    25,     0,     0,
      26,   124,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,     0,    13,     0,    14,    15,     0,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,   123,     0,
       0,    23,     0,    24,     0,    25,     0,     0,    26,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,    78,
      79,    80,    81,     0,    82,    83,    69,    70,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    79,    80,    81,
       0,    82,    83,     0,     0,     0,    84,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,    78,    79,    80,
      81,     0,    82,    83,     0,     0,    99,    69,    70,    71,
      72,    73,    74,    75,    76,    77,     0,    78,    79,    80,
      81,     0,    82,    83,   128,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,    78,    79,    80,    81,     0,
      82,    83,    69,    70,    71,    72,    73,    74,    75,    76,
       0,     0,    78,    79,    80,    81,     0,    82,    83,    69,
      -1,    -1,    72,    73,    74,    75,     0,     0,     0,    78,
      79,    80,    81,     0,    82,    83,    69,    70,    71,    72,
      73,    74,    75,     0,     0,     0,    78,    79,    80,    81,
      69,    82,    83,    -1,    -1,    -1,    -1,     0,     0,     0,
      78,    79,    80,    81,     0,    82,    83
};

static const yytype_int16 yycheck[] =
{
       9,    15,    26,     8,    25,    41,    42,     0,    25,     3,
       4,     5,     6,    22,    23,    24,    10,    19,    20,    21,
      22,    23,    24,    44,    25,    38,    39,    25,    41,    42,
      49,    55,    44,    12,    13,     3,    48,     3,    47,    48,
      46,    35,    46,    52,    53,    54,    46,    46,    42,    44,
      44,    18,    43,    25,     3,    49,    45,    47,    44,    47,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,     3,    83,    45,    47,    91,    25,    93,
     138,    -1,    96,     3,     4,     5,     6,    -1,    -1,    98,
      10,    -1,   101,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,   118,
      41,    42,   121,    -1,   119,    35,    -1,    -1,    49,    -1,
      -1,    -1,    42,   137,    44,    -1,   140,    -1,    -1,    49,
      -1,    -1,   146,   138,    -1,   144,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    14,    -1,    16,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    44,    -1,    46,
      -1,    -1,    49,    50,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    -1,    16,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    44,    -1,    46,    -1,    -1,
      49,    50,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    14,    -1,    16,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    15,    -1,
      -1,    42,    -1,    44,    -1,    46,    -1,    -1,    49,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    -1,    41,    42,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    38,    39,
      -1,    41,    42,    -1,    -1,    -1,    46,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    -1,    41,    42,    -1,    -1,    45,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,    38,
      39,    -1,    41,    42,    43,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    -1,
      41,    42,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    38,    39,    -1,    41,    42,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      37,    38,    39,    -1,    41,    42,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    36,    37,    38,    39,
      26,    41,    42,    29,    30,    31,    32,    -1,    -1,    -1,
      36,    37,    38,    39,    -1,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    52,    53,     0,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    14,    16,    17,    19,    20,    21,    22,
      23,    24,    35,    42,    44,    46,    49,    54,    55,    56,
      57,    58,    62,    63,    66,    68,    69,    70,    72,    73,
      74,    75,    76,    77,    78,    81,    84,    25,    44,    55,
       3,    72,    25,    25,    25,    49,    71,    71,    72,    72,
      82,    83,    72,    53,     3,    46,    46,    46,    46,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    36,    37,
      38,    39,    41,    42,    46,    72,    72,    79,    80,     3,
      72,    72,     3,    67,    72,    53,    18,    43,    47,    45,
      50,    25,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,     3,    72,    45,    47,    44,
      71,    48,    71,    15,    50,    71,    72,    72,    43,    72,
      55,    59,    60,    61,    64,    72,     3,    45,    47,    12,
      13,    65,    71,    61,    25,    71,    72,    71
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    56,    57,    58,    59,    59,    60,    60,    61,
      62,    63,    64,    64,    65,    65,    66,    67,    67,    68,
      69,    70,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    73,    74,
      75,    76,    77,    78,    79,    79,    80,    80,    81,    82,
      82,    83,    83,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     7,     0,     1,     1,     3,     2,
       2,     6,     0,     5,     0,     2,     4,     3,     2,     3,
       4,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     1,     1,
       1,     3,     4,     4,     0,     1,     1,     3,     3,     0,
       1,     1,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 4: /* declaracao_lista: declaracao_lista declaracao  */
#line 77 "echo.y"
        { printf("Linha %d: Declaração reconhecida.\n", yylineno); }
#line 1319 "echo.tab.c"
    break;

  case 10: /* declaracao: atribuicao ';'  */
#line 87 "echo.y"
                            { printf("-> Atribuição inicial finalizada.\n"); }
#line 1325 "echo.tab.c"
    break;

  case 11: /* declaracao: reatribuicao ';'  */
#line 88 "echo.y"
                            { printf("-> Reatribuição finalizada.\n"); }
#line 1331 "echo.tab.c"
    break;

  case 14: /* declaracao: expressao ';'  */
#line 91 "echo.y"
                            { printf("-> Expressão (ex: chamada func) como declaração finalizada.\n"); }
#line 1337 "echo.tab.c"
    break;

  case 15: /* declaracao: ';'  */
#line 93 "echo.y"
                            { printf("-> Declaração vazia.\n"); }
#line 1343 "echo.tab.c"
    break;

  case 16: /* tipo_nome: T_TYPE_TXT  */
#line 97 "echo.y"
                        { (yyval.sval) = strdup("txt"); }
#line 1349 "echo.tab.c"
    break;

  case 17: /* tipo_nome: T_TYPE_NUM  */
#line 98 "echo.y"
                        { (yyval.sval) = strdup("num"); }
#line 1355 "echo.tab.c"
    break;

  case 18: /* tipo_nome: T_TYPE_BOOL  */
#line 99 "echo.y"
                        { (yyval.sval) = strdup("bool"); }
#line 1361 "echo.tab.c"
    break;

  case 19: /* tipo_nome: T_TYPE_OBJ  */
#line 100 "echo.y"
                        { (yyval.sval) = strdup("obj"); }
#line 1367 "echo.tab.c"
    break;

  case 20: /* tipo_nome: T_TYPE_LIST  */
#line 101 "echo.y"
                        { (yyval.sval) = strdup("list"); }
#line 1373 "echo.tab.c"
    break;

  case 21: /* tipo_nome: T_TYPE_SILENT  */
#line 102 "echo.y"
                        { (yyval.sval) = strdup("silent"); }
#line 1379 "echo.tab.c"
    break;

  case 22: /* atribuicao: tipo_nome T_IDENTIFIER T_ASSIGN expressao  */
#line 109 "echo.y"
        {
            printf("-> Atribuição Inicial: Tipo=%s, ID=%s\n", (yyvsp[-3].sval), (yyvsp[-2].sval));
            // Lembre-se de liberar a memória dos strings quando não forem mais necessários!
            free((yyvsp[-3].sval)); // Libera memória do nome do tipo
            free((yyvsp[-2].sval)); // Libera memória do identificador
        }
#line 1390 "echo.tab.c"
    break;

  case 23: /* reatribuicao: T_IDENTIFIER T_ASSIGN expressao  */
#line 120 "echo.y"
        {
            printf("-> Reatribuição: ID=%s\n", (yyvsp[-2].sval));
            free((yyvsp[-2].sval)); // Libera memória do identificador
        }
#line 1399 "echo.tab.c"
    break;

  case 24: /* definicao_funcao: T_ECHO tipo_nome T_IDENTIFIER '(' parametros_opt ')' bloco  */
#line 129 "echo.y"
        {
            printf("-> Definição Função: Tipo Retorno=%s, Nome=%s\n", (yyvsp[-5].sval), (yyvsp[-4].sval));
            free((yyvsp[-5].sval));
            free((yyvsp[-4].sval));
        }
#line 1409 "echo.tab.c"
    break;

  case 29: /* parametro: tipo_nome T_IDENTIFIER  */
#line 148 "echo.y"
        {
            printf("--> Parâmetro: Tipo=%s, Nome=%s\n", (yyvsp[-1].sval), (yyvsp[0].sval));
            free((yyvsp[-1].sval));
            free((yyvsp[0].sval));
        }
#line 1419 "echo.tab.c"
    break;

  case 30: /* comando_retorno: T_RETURN expressao  */
#line 158 "echo.y"
        { printf("-> Retorno de função\n"); }
#line 1425 "echo.tab.c"
    break;

  case 31: /* condicional: T_IF T_ASSIGN expressao bloco lista_otif other_opt  */
#line 164 "echo.y"
        { printf("-> Estrutura IF completa\n"); }
#line 1431 "echo.tab.c"
    break;

  case 33: /* lista_otif: lista_otif T_OTIF T_ASSIGN expressao bloco  */
#line 170 "echo.y"
        { printf("--> Bloco OTIF\n"); }
#line 1437 "echo.tab.c"
    break;

  case 35: /* other_opt: T_OTHER bloco  */
#line 176 "echo.y"
        { printf("--> Bloco OTHER\n"); }
#line 1443 "echo.tab.c"
    break;

  case 36: /* repeticao: T_LOOP T_ASSIGN loop_especificador bloco  */
#line 182 "echo.y"
        { printf("-> Estrutura LOOP\n"); }
#line 1449 "echo.tab.c"
    break;

  case 37: /* loop_especificador: T_IDENTIFIER ':' expressao  */
#line 187 "echo.y"
        {
            printf("--> Loop For-Each: var=%s\n", (yyvsp[-2].sval));
            free((yyvsp[-2].sval)); // Libera var 'item'
        }
#line 1458 "echo.tab.c"
    break;

  case 38: /* loop_especificador: expressao T_TIMES  */
#line 192 "echo.y"
        { printf("--> Loop Times\n"); }
#line 1464 "echo.tab.c"
    break;

  case 39: /* comando_show: T_SHOW T_ASSIGN expressao  */
#line 198 "echo.y"
        { printf("-> Comando SHOW (Valor expr simplificado: %f)\n", (yyvsp[0].dval)); /* $3 é o valor double da expressao */ }
#line 1470 "echo.tab.c"
    break;

  case 40: /* excecao: T_TRY bloco T_OOPS bloco  */
#line 204 "echo.y"
        { printf("-> Estrutura TRY-OOPS\n"); }
#line 1476 "echo.tab.c"
    break;

  case 41: /* escopo_isolado: T_BUBBLE bloco  */
#line 210 "echo.y"
        { printf("-> Estrutura BUBBLE\n"); }
#line 1482 "echo.tab.c"
    break;

  case 42: /* bloco: '{' declaracao_lista '}'  */
#line 216 "echo.y"
        { printf("--> Bloco de código {} finalizado\n"); }
#line 1488 "echo.tab.c"
    break;

  case 43: /* expressao: literal_num  */
#line 221 "echo.y"
                                { (yyval.dval) = (yyvsp[0].dval); printf("Expr: Literal Num (%f)\n", (yyval.dval)); }
#line 1494 "echo.tab.c"
    break;

  case 44: /* expressao: literal_txt  */
#line 222 "echo.y"
                                { printf("Expr: Literal Txt (%s)\n", (yyvsp[0].sval)); free((yyvsp[0].sval)); (yyval.dval) = 0; }
#line 1500 "echo.tab.c"
    break;

  case 45: /* expressao: literal_bool  */
#line 223 "echo.y"
                                { (yyval.dval) = (yyvsp[0].bval); printf("Expr: Literal Bool (%d)\n", (yyvsp[0].bval)); }
#line 1506 "echo.tab.c"
    break;

  case 46: /* expressao: T_IDENTIFIER  */
#line 224 "echo.y"
                                { (yyval.dval) = 0; printf("Expr: ID (%s)\n", (yyvsp[0].sval)); free((yyvsp[0].sval)); }
#line 1512 "echo.tab.c"
    break;

  case 47: /* expressao: T_GET  */
#line 225 "echo.y"
                                { (yyval.dval) = 0; printf("Expr: GET\n"); }
#line 1518 "echo.tab.c"
    break;

  case 48: /* expressao: chamada_funcao  */
#line 226 "echo.y"
                                { (yyval.dval) = (yyvsp[0].dval); printf("Expr: Chamada Função\n"); }
#line 1524 "echo.tab.c"
    break;

  case 49: /* expressao: acesso_membro  */
#line 227 "echo.y"
                                { (yyval.dval) = (yyvsp[0].dval); printf("Expr: Acesso Membro\n"); }
#line 1530 "echo.tab.c"
    break;

  case 50: /* expressao: acesso_indice  */
#line 228 "echo.y"
                                { (yyval.dval) = (yyvsp[0].dval); printf("Expr: Acesso Indice\n"); }
#line 1536 "echo.tab.c"
    break;

  case 51: /* expressao: lista_literal  */
#line 229 "echo.y"
                                { (yyval.dval) = (yyvsp[0].dval); printf("Expr: Lista Literal\n"); }
#line 1542 "echo.tab.c"
    break;

  case 52: /* expressao: objeto_literal  */
#line 230 "echo.y"
                                { (yyval.dval) = (yyvsp[0].dval); printf("Expr: Objeto Literal\n"); }
#line 1548 "echo.tab.c"
    break;

  case 53: /* expressao: expressao '+' expressao  */
#line 233 "echo.y"
                                { (yyval.dval) = (yyvsp[-2].dval) + (yyvsp[0].dval); printf("Expr: +\n"); }
#line 1554 "echo.tab.c"
    break;

  case 54: /* expressao: expressao '-' expressao  */
#line 234 "echo.y"
                                { (yyval.dval) = (yyvsp[-2].dval) - (yyvsp[0].dval); printf("Expr: -\n"); }
#line 1560 "echo.tab.c"
    break;

  case 55: /* expressao: expressao '*' expressao  */
#line 235 "echo.y"
                                { (yyval.dval) = (yyvsp[-2].dval) * (yyvsp[0].dval); printf("Expr: *\n"); }
#line 1566 "echo.tab.c"
    break;

  case 56: /* expressao: expressao '/' expressao  */
#line 236 "echo.y"
                                { if((yyvsp[0].dval) == 0) { yyerror("Divisão por zero"); (yyval.dval) = 0; } else { (yyval.dval) = (yyvsp[-2].dval) / (yyvsp[0].dval); } printf("Expr: /\n"); }
#line 1572 "echo.tab.c"
    break;

  case 57: /* expressao: expressao T_CONCAT expressao  */
#line 237 "echo.y"
                                   { printf("AVISO: Concatenação não implementada\n"); (yyval.dval) = 0; }
#line 1578 "echo.tab.c"
    break;

  case 58: /* expressao: expressao T_EQ expressao  */
#line 238 "echo.y"
                                { (yyval.dval) = ((yyvsp[-2].dval) == (yyvsp[0].dval)); printf("Expr: ==\n"); }
#line 1584 "echo.tab.c"
    break;

  case 59: /* expressao: expressao T_NEQ expressao  */
#line 239 "echo.y"
                                { (yyval.dval) = ((yyvsp[-2].dval) != (yyvsp[0].dval)); printf("Expr: !=\n"); }
#line 1590 "echo.tab.c"
    break;

  case 60: /* expressao: expressao T_LT expressao  */
#line 240 "echo.y"
                                { (yyval.dval) = ((yyvsp[-2].dval) < (yyvsp[0].dval)); printf("Expr: <\n"); }
#line 1596 "echo.tab.c"
    break;

  case 61: /* expressao: expressao T_GT expressao  */
#line 241 "echo.y"
                                { (yyval.dval) = ((yyvsp[-2].dval) > (yyvsp[0].dval)); printf("Expr: >\n"); }
#line 1602 "echo.tab.c"
    break;

  case 62: /* expressao: expressao T_LTE expressao  */
#line 242 "echo.y"
                                { (yyval.dval) = ((yyvsp[-2].dval) <= (yyvsp[0].dval)); printf("Expr: <=\n"); }
#line 1608 "echo.tab.c"
    break;

  case 63: /* expressao: expressao T_GTE expressao  */
#line 243 "echo.y"
                                { (yyval.dval) = ((yyvsp[-2].dval) >= (yyvsp[0].dval)); printf("Expr: >=\n"); }
#line 1614 "echo.tab.c"
    break;

  case 64: /* expressao: expressao T_AND expressao  */
#line 244 "echo.y"
                                { (yyval.dval) = ((yyvsp[-2].dval) && (yyvsp[0].dval)); printf("Expr: &&\n"); }
#line 1620 "echo.tab.c"
    break;

  case 65: /* expressao: expressao T_OR expressao  */
#line 245 "echo.y"
                                { (yyval.dval) = ((yyvsp[-2].dval) || (yyvsp[0].dval)); printf("Expr: \\\\\n"); }
#line 1626 "echo.tab.c"
    break;

  case 66: /* expressao: T_NOT expressao  */
#line 248 "echo.y"
                                { (yyval.dval) = !(yyvsp[0].dval); printf("Expr: !\n"); }
#line 1632 "echo.tab.c"
    break;

  case 67: /* expressao: '(' expressao ')'  */
#line 252 "echo.y"
                                { (yyval.dval) = (yyvsp[-1].dval); printf("Expr: ()\n"); }
#line 1638 "echo.tab.c"
    break;

  case 68: /* literal_num: T_NUM_LITERAL  */
#line 256 "echo.y"
                                { (yyval.dval) = (yyvsp[0].dval); }
#line 1644 "echo.tab.c"
    break;

  case 69: /* literal_txt: T_TXT_LITERAL  */
#line 257 "echo.y"
                                { (yyval.sval) = (yyvsp[0].sval); }
#line 1650 "echo.tab.c"
    break;

  case 70: /* literal_bool: T_BOOL_LITERAL  */
#line 258 "echo.y"
                               { (yyval.bval) = (yyvsp[0].bval); }
#line 1656 "echo.tab.c"
    break;

  case 71: /* acesso_membro: expressao '.' T_IDENTIFIER  */
#line 262 "echo.y"
               {
                   printf("--> Acesso Membro: %s\n", (yyvsp[0].sval));
                   free((yyvsp[0].sval)); // Libera ID do membro
                   (yyval.dval) = 0; // Valor temporário
               }
#line 1666 "echo.tab.c"
    break;

  case 72: /* acesso_indice: expressao '[' expressao ']'  */
#line 271 "echo.y"
               {
                   printf("--> Acesso Indice (valor indice: %f)\n", (yyvsp[-1].dval)); // $3 é double aqui
                   (yyval.dval) = 0; // Valor temporário
               }
#line 1675 "echo.tab.c"
    break;

  case 73: /* chamada_funcao: T_IDENTIFIER '(' argumentos_opt ')'  */
#line 279 "echo.y"
               {
                   printf("--> Chamada Func: %s()\n", (yyvsp[-3].sval));
                   free((yyvsp[-3].sval)); // Libera ID da função
                   (yyval.dval) = 0; // Valor temporário (retorno da função)
               }
#line 1685 "echo.tab.c"
    break;

  case 78: /* lista_literal: '[' elementos_lista_opt ']'  */
#line 290 "echo.y"
                                           { printf("--> Lista Literal\n"); (yyval.dval) = 0; }
#line 1691 "echo.tab.c"
    break;

  case 83: /* objeto_literal: '{' declaracao_lista '}'  */
#line 295 "echo.y"
                                         { printf("--> Objeto Literal\n"); (yyval.dval) = 0; }
#line 1697 "echo.tab.c"
    break;


#line 1701 "echo.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 298 "echo.y"

/*** Seção de Código C Adicional ***/

int main(int argc, char **argv) {
    // yydebug = 1; // Habilita modo de debug do Bison via código

    FILE *inputFile = stdin;
    // yyin é global e usado pelo Flex
    extern FILE *yyin;

    if (argc > 1) {
        inputFile = fopen(argv[1], "r");
        if (!inputFile) {
            perror(argv[1]); // Reporta erro se não puder abrir o arquivo
            return 1;
        }
        yyin = inputFile; // Aponta yyin para o arquivo aberto
    } else {
       // Se nenhum arquivo for dado, Flex usará stdin por padrão (yyin já é stdin)
       printf("Lendo da entrada padrão (Ctrl+D para EOF em Linux/WSL, Ctrl+Z em Windows)...\n");
    }

    printf("Iniciando análise...\n"); // Mensagem inicial
    if (yyparse() == 0) { // Inicia a análise. yyparse chama yylex() automaticamente.
        printf("\nAnálise Sintática concluída com sucesso!\n"); // Mensagem de sucesso
    } else {
        printf("\nAnálise Sintática falhou.\n"); // Mensagem de falha
    }

    if (inputFile != stdin) {
        fclose(inputFile); // Fecha o arquivo se ele foi aberto
    }

    return 0;
}

// Função de erro sintático (obrigatória)
void yyerror(const char *s) {
    // Imprime a mensagem de erro, linha e o texto onde ocorreu (se disponível)
    fprintf(stderr, "Erro de Sintaxe na linha %d perto de '%s': %s\n", yylineno, yytext ? yytext : "", s);
    // exit(1); // Pode comentar/remover para que o Bison tente continuar (se possível)
}
