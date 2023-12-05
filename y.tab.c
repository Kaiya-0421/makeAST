/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     CONST = 297,
     VOLATILE = 298,
     VOID = 299,
     STRUCT = 300,
     UNION = 301,
     ENUM = 302,
     ELLIPSIS = 303,
     CASE = 304,
     DEFAULT = 305,
     IF = 306,
     ELSE = 307,
     SWITCH = 308,
     WHILE = 309,
     DO = 310,
     FOR = 311,
     GOTO = 312,
     CONTINUE = 313,
     BREAK = 314,
     RETURN = 315,
     MPFI = 316,
     MPFR = 317,
     GMPFI = 318
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define CHAR 289
#define SHORT 290
#define INT 291
#define LONG 292
#define SIGNED 293
#define UNSIGNED 294
#define FLOAT 295
#define DOUBLE 296
#define CONST 297
#define VOLATILE 298
#define VOID 299
#define STRUCT 300
#define UNION 301
#define ENUM 302
#define ELLIPSIS 303
#define CASE 304
#define DEFAULT 305
#define IF 306
#define ELSE 307
#define SWITCH 308
#define WHILE 309
#define DO 310
#define FOR 311
#define GOTO 312
#define CONTINUE 313
#define BREAK 314
#define RETURN 315
#define MPFI 316
#define MPFR 317
#define GMPFI 318




/* Copy the first part of user declarations.  */
#line 1 "ANSI.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #define YYERROR_VERBOSE
    #include "DEFINE_macro.h"
    #include "ANSI_print.h"
    #include "ANSI_Sprint.h"
    #include "ANSI_For_list.h"
    #include "ANSI_tree.h"
    #include "ANSI_symbol_table.h"
    #include "ANSI_symbol_table_list.h"
    #include "ANSI_flow_graph.h"
    #include "ANSI_basic_block_list.h"
    int yylex();
    void yyerror(char *s);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "ANSI.y"
{
    struct Primary_expression *tree_Primary_expression;
    struct Postfix_expression *tree_Postfix_expression;
    struct Argument_expression_list *tree_Argument_expression_list;
    struct Unary_expression *tree_Unary_expression;
    struct Unary_operator *tree_Unary_operator;
    struct Cast_expression *tree_Cast_expression;
    struct Multiplicative_expression *tree_Multiplicative_expression;
    struct Additive_expression *tree_Additive_expression;
    struct Shift_expression *tree_Shift_expression;
    struct Relational_expression *tree_Relational_expression;
    struct Equality_expression *tree_Equality_expression;
    struct And_expression *tree_And_expression;
    struct Exclusive_or_expression *tree_Exclusive_or_expression;
    struct Inclusive_or_expression *tree_Inclusive_or_expression;
    struct Logical_and_expression *treeLogical_and_expression;
    struct Logical_or_expression *tree_Logical_or_expression;
    struct Conditional_expression *tree_Conditional_expression;
    struct Assignment_expression *tree_Assignment_expression;
    struct Assignment_operator *tree_Assignment_operator;
    struct Expression *tree_Expression;
    struct Constant_expression *tree_Constant_expression;
    struct Declaration *tree_Declaration;
    struct Declaration_specifiers *tree_Declaration_specifiers;
    struct Init_declarator_list *tree_Init_declarator_list;
    struct Init_declarator *tree_Init_declarator;
    struct Storage_class_specifier *tree_Storage_class_specifier;
    struct Type_specifier *tree_Type_specifier;
    struct Struct_or_union_specifier *tree_Struct_or_union_specifier;
    struct Struct_or_union *tree_Struct_or_union;
    struct Struct_declaration_list *tree_Struct_declaration_list;
    struct Struct_declaration *tree_Struct_declaration;
    struct Specifier_qualifier_list *tree_Specifier_qualifier_list;
    struct Struct_declarator_list *tree_Struct_declarator_list;
    struct Struct_declarator *tree_Struct_declarator; 
    struct Enum_specifier *tree_Enum_specifier;
    struct Enumerator_list *tree_Enumerator_list;
    struct Enumerator *tree_Enumerator;
    struct Type_qualifier *tree_Type_qualifier;
    struct Declarator *tree_Declarator;
    struct Direct_declarator *tree_Direct_declarator;
    struct Pointer *tree_Pointer;
    struct Type_qualifier_list *tree_Type_qualifier_list; 
    struct Parameter_type_list *tree_Parameter_type_list;
    struct Parameter_list *tree_Parameter_list;
    struct Parameter_declaration *tree_Parameter_declaration;
    struct Identifier_list *tree_Identifier_list;
    struct Type_name *tree_Type_name;
    struct Abstract_declarator *tree_Abstract_declarator;
    struct Direct_abstract_declarator *tree_Direct_abstract_declarator;
    struct Initializer *tree_Initializer;
    struct Initializer_list *tree_Initializer_list;
    struct Statement *tree_Statement;
    struct Labeled_statement *tree_Labeled_statement;
    struct Compound_statement *tree_Compound_statement;
    struct Declaration_list *tree_Declaration_list;
    struct Statement_list *tree_Statement_list;
    struct Expression_statement *tree_Expression_statement;
    struct Selection_statement *tree_Selection_statement;
    struct Iteration_statement *tree_Iteration_statement;
    struct Jump_statement *tree_Jump_statement;
    struct Translation_unit *tree_Translation_unit; 
    struct External_declaration *tree_External_declaration;
    struct Function_definition *tree_Function_definition;

    char *str_STR;
    char *str_ID;
    char *str_CONST;
}
/* Line 193 of yacc.c.  */
#line 311 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 324 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1195

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  64
/* YYNRULES -- Number of rules.  */
#define YYNRULES  214
/* YYNRULES -- Number of states.  */
#define YYNSTATES  350

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,     2,     2,    77,    70,     2,
      64,    65,    71,    72,    69,    73,    68,    76,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    85,
      78,    84,    79,    82,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    66,     2,    67,    80,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,    81,    87,    74,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    68,    70,    72,    74,    76,    78,    80,    82,
      87,    89,    93,    97,   101,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   135,   139,   141,   145,   149,   151,
     155,   157,   161,   163,   167,   169,   173,   175,   179,   181,
     187,   189,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   221,   223,   226,   230,   232,
     235,   237,   240,   242,   245,   247,   251,   253,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   293,   295,   297,   303,
     308,   311,   313,   315,   317,   320,   324,   327,   329,   332,
     334,   336,   340,   342,   345,   349,   354,   360,   363,   365,
     369,   371,   375,   377,   379,   382,   384,   386,   390,   395,
     399,   404,   409,   413,   415,   418,   421,   425,   427,   430,
     432,   436,   438,   442,   445,   448,   450,   452,   456,   458,
     461,   463,   465,   468,   472,   475,   479,   483,   488,   491,
     495,   499,   504,   506,   510,   515,   517,   521,   523,   525,
     527,   529,   531,   533,   535,   539,   544,   548,   551,   555,
     557,   560,   562,   565,   567,   570,   576,   584,   590,   596,
     604,   611,   619,   623,   626,   629,   632,   636,   638,   641,
     643,   645,   650,   654,   658
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    64,
     108,    65,    -1,    89,    -1,    90,    66,   108,    67,    -1,
      90,    64,    65,    -1,    90,    64,    91,    65,    -1,    90,
      68,     3,    -1,    90,     7,     3,    -1,    90,     8,    -1,
      90,     9,    -1,   106,    -1,    91,    69,   106,    -1,    90,
      -1,     8,    92,    -1,     9,    92,    -1,    93,    94,    -1,
       6,    92,    -1,     6,    64,   135,    65,    -1,    70,    -1,
      71,    -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,
      92,    -1,    64,   135,    65,    94,    -1,    94,    -1,    95,
      71,    94,    -1,    95,    76,    94,    -1,    95,    77,    94,
      -1,    95,    -1,    96,    72,    95,    -1,    96,    73,    95,
      -1,    96,    -1,    97,    10,    96,    -1,    97,    11,    96,
      -1,    97,    -1,    98,    78,    97,    -1,    98,    79,    97,
      -1,    98,    12,    97,    -1,    98,    13,    97,    -1,    98,
      -1,    99,    14,    98,    -1,    99,    15,    98,    -1,    99,
      -1,   100,    70,    99,    -1,   100,    -1,   101,    80,   100,
      -1,   101,    -1,   102,    81,   101,    -1,   102,    -1,   103,
      16,   102,    -1,   103,    -1,   104,    17,   103,    -1,   104,
      -1,   104,    82,   108,    83,   105,    -1,   105,    -1,    92,
     107,   106,    -1,    84,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,   106,    -1,   108,    69,   106,
      -1,   105,    -1,   111,    85,    -1,   111,   112,    85,    -1,
     114,    -1,   114,   111,    -1,   115,    -1,   115,   111,    -1,
     126,    -1,   126,   111,    -1,   113,    -1,   112,    69,   113,
      -1,   127,    -1,   127,    84,   138,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    33,    -1,    44,    -1,    34,
      -1,    35,    -1,    36,    -1,    37,    -1,    40,    -1,    41,
      -1,    38,    -1,    39,    -1,   116,    -1,   123,    -1,    28,
      -1,    61,    -1,    63,    -1,    62,    -1,   117,     3,    86,
     118,    87,    -1,   117,    86,   118,    87,    -1,   117,     3,
      -1,    45,    -1,    46,    -1,   119,    -1,   118,   119,    -1,
     120,   121,    85,    -1,   115,   120,    -1,   115,    -1,   126,
     120,    -1,   126,    -1,   122,    -1,   121,    69,   122,    -1,
     127,    -1,    83,   109,    -1,   127,    83,   109,    -1,    47,
      86,   124,    87,    -1,    47,     3,    86,   124,    87,    -1,
      47,     3,    -1,   125,    -1,   124,    69,   125,    -1,     3,
      -1,     3,    84,   109,    -1,    42,    -1,    43,    -1,   129,
     128,    -1,   128,    -1,     3,    -1,    64,   127,    65,    -1,
     128,    66,   109,    67,    -1,   128,    66,    67,    -1,   128,
      64,   131,    65,    -1,   128,    64,   134,    65,    -1,   128,
      64,    65,    -1,    71,    -1,    71,   130,    -1,    71,   129,
      -1,    71,   130,   129,    -1,   126,    -1,   130,   126,    -1,
     132,    -1,   132,    69,    48,    -1,   133,    -1,   132,    69,
     133,    -1,   111,   127,    -1,   111,   136,    -1,   111,    -1,
       3,    -1,   134,    69,     3,    -1,   120,    -1,   120,   136,
      -1,   129,    -1,   137,    -1,   129,   137,    -1,    64,   136,
      65,    -1,    66,    67,    -1,    66,   109,    67,    -1,   137,
      66,    67,    -1,   137,    66,   109,    67,    -1,    64,    65,
      -1,    64,   131,    65,    -1,   137,    64,    65,    -1,   137,
      64,   131,    65,    -1,   106,    -1,    86,   139,    87,    -1,
      86,   139,    69,    87,    -1,   138,    -1,   139,    69,   138,
      -1,   141,    -1,   142,    -1,   145,    -1,   146,    -1,   147,
      -1,   148,    -1,   110,    -1,     3,    83,   140,    -1,    49,
     109,    83,   140,    -1,    50,    83,   140,    -1,    86,    87,
      -1,    86,   144,    87,    -1,   110,    -1,   143,   110,    -1,
     140,    -1,   140,   144,    -1,    85,    -1,   108,    85,    -1,
      51,    64,   108,    65,   140,    -1,    51,    64,   108,    65,
     140,    52,   140,    -1,    53,    64,   108,    65,   140,    -1,
      54,    64,   108,    65,   140,    -1,    55,   140,    54,    64,
     108,    65,    85,    -1,    56,    64,   145,   145,    65,   140,
      -1,    56,    64,   145,   145,   108,    65,   140,    -1,    57,
       3,    85,    -1,    58,    85,    -1,    59,    85,    -1,    60,
      85,    -1,    60,   108,    85,    -1,   150,    -1,   149,   150,
      -1,   151,    -1,   110,    -1,   111,   127,   143,   142,    -1,
     111,   127,   142,    -1,   127,   143,   142,    -1,   127,   142,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   176,   176,   181,   186,   191,   199,   204,   210,   215,
     221,   228,   234,   239,   247,   252,   261,   266,   271,   276,
     282,   287,   295,   299,   303,   307,   311,   315,   322,   327,
     336,   341,   347,   353,   362,   367,   373,   382,   387,   393,
     402,   407,   413,   419,   425,   434,   439,   445,   454,   459,
     468,   473,   482,   487,   496,   501,   510,   515,   524,   529,
     539,   544,   554,   558,   562,   566,   570,   574,   578,   582,
     586,   590,   594,   601,   606,   615,   623,   628,   637,   642,
     648,   653,   659,   664,   673,   678,   687,   692,   701,   705,
     709,   713,   717,   724,   728,   732,   736,   740,   744,   748,
     752,   756,   760,   765,   770,   774,   778,   782,   789,   796,
     802,   811,   815,   822,   827,   836,   845,   851,   856,   862,
     870,   875,   884,   889,   894,   903,   908,   914,   922,   927,
     936,   941,   950,   954,   961,   967,   975,   980,   985,   991,
     996,  1002,  1008,  1016,  1020,  1025,  1030,  1039,  1044,  1053,
    1058,  1066,  1071,  1079,  1085,  1091,  1099,  1104,  1113,  1118,
    1127,  1132,  1137,  1146,  1151,  1155,  1160,  1165,  1171,  1175,
    1180,  1185,  1194,  1199,  1204,  1212,  1217,  1226,  1231,  1236,
    1241,  1246,  1251,  1256,  1264,  1270,  1276,  1284,  1288,  1298,
    1303,  1312,  1317,  1327,  1331,  1339,  1345,  1352,  1361,  1367,
    1373,  1380,  1391,  1396,  1400,  1404,  1408,  1416,  1422,  1432,
    1437,  1445,  1453,  1460,  1467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "MPFI", "MPFR", "GMPFI", "'('", "')'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'",
  "'{'", "'}'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    40,    41,    91,    93,    46,    44,
      38,    42,    43,    45,   126,    33,    47,    37,    60,    62,
      94,   124,    63,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    89,    89,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    91,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    95,    95,    96,    96,    96,    97,    97,    97,
      98,    98,    98,    98,    98,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   108,   108,   109,   110,   110,   111,   111,
     111,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     114,   114,   114,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   116,   116,
     116,   117,   117,   118,   118,   119,   120,   120,   120,   120,
     121,   121,   122,   122,   122,   123,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   128,
     128,   128,   128,   129,   129,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   133,   134,   134,   135,   135,
     136,   136,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   138,   138,   138,   139,   139,   140,   140,   140,
     140,   140,   140,   140,   141,   141,   141,   142,   142,   143,
     143,   144,   144,   145,   145,   146,   146,   146,   147,   147,
     147,   147,   148,   148,   148,   148,   148,   149,   149,   150,
     150,   151,   151,   151,   151
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     4,
       2,     1,     1,     1,     2,     3,     2,     1,     2,     1,
       1,     3,     1,     2,     3,     4,     5,     2,     1,     3,
       1,     3,     1,     1,     2,     1,     1,     3,     4,     3,
       4,     4,     3,     1,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     2,     1,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     1,
       2,     1,     2,     1,     2,     5,     7,     5,     5,     7,
       6,     7,     3,     2,     2,     2,     3,     1,     2,     1,
       1,     4,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   136,   104,    88,    89,    90,    91,    92,    94,    95,
      96,    97,   100,   101,    98,    99,   132,   133,    93,   111,
     112,     0,   105,   107,   106,     0,   143,   210,     0,    78,
      80,   102,     0,   103,    82,     0,   135,     0,     0,   207,
     209,   127,     0,     0,   147,   145,   144,    76,     0,    84,
      86,    79,    81,   110,     0,    83,     0,   189,     0,   214,
       0,     0,     0,   134,     1,   208,     0,   130,     0,   128,
     137,   148,   146,     0,    77,     0,   212,     0,     0,   117,
       0,   113,     0,   119,     2,     3,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    25,    26,    27,   193,   187,
       6,    16,    28,     0,    30,    34,    37,    40,    45,    48,
      50,    52,    54,    56,    58,    60,    73,     0,   183,   191,
     177,   178,     0,   179,   180,   181,   182,    86,   190,   213,
     156,   142,   155,     0,   149,   151,     0,     2,   139,    28,
      75,     0,     0,     0,     0,   125,    85,     0,   172,    87,
     211,     0,   116,   109,   114,     0,     0,   120,   122,   118,
       0,     0,    20,     0,    17,    18,     0,     0,     0,     0,
       0,     0,     0,     0,   203,   204,   205,     0,     0,   158,
       0,     0,    12,    13,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    62,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   192,   188,     0,     0,   153,   160,   154,   161,   140,
       0,   141,     0,   138,   126,   131,   129,   175,     0,   108,
     123,     0,   115,     0,   184,     0,     0,   186,     0,     0,
       0,     0,     0,   202,   206,     5,     0,   160,   159,     0,
      11,     8,     0,    14,     0,    10,    61,    31,    32,    33,
      35,    36,    38,    39,    43,    44,    41,    42,    46,    47,
      49,    51,    53,    55,    57,     0,    74,   168,     0,     0,
     164,     0,   162,     0,     0,   150,   152,   157,     0,   173,
     121,   124,    21,   185,     0,     0,     0,     0,     0,    29,
       9,     0,     7,     0,   169,   163,   165,   170,     0,   166,
       0,   174,   176,   195,   197,   198,     0,     0,     0,    15,
      59,   171,   167,     0,     0,   200,     0,   196,   199,   201
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   110,   111,   272,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   208,
     127,   151,   128,    58,    48,    49,    29,    30,    31,    32,
      80,    81,    82,   166,   167,    33,    68,    69,    34,    35,
      36,    37,    46,   298,   144,   145,   146,   190,   299,   238,
     159,   248,   129,   130,   131,    60,   132,   133,   134,   135,
     136,    38,    39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -218
static const yytype_int16 yypact[] =
{
     799,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,     6,  -218,  -218,  -218,   126,   181,  -218,    23,  1102,
    1102,  -218,    12,  -218,  1102,   948,   129,    15,   709,  -218,
    -218,   -33,    61,     1,  -218,  -218,   181,  -218,    63,  -218,
     912,  -218,  -218,     7,  1132,  -218,   280,  -218,    23,  -218,
     948,   844,   455,   129,  -218,  -218,    61,    26,   -52,  -218,
    -218,  -218,  -218,   126,  -218,    72,  -218,   948,  1132,  1132,
     643,  -218,    24,  1132,    45,  -218,  -218,   576,   649,   649,
     661,    78,   156,   166,   174,   353,   185,   268,   191,   202,
     370,   443,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,   142,   674,   661,  -218,    -3,   -41,    10,   106,   138,
     224,   215,   216,   282,   -10,  -218,  -218,   113,  -218,   353,
    -218,  -218,   209,  -218,  -218,  -218,  -218,   217,  -218,  -218,
    -218,  -218,   130,   234,   233,  -218,    44,  -218,  -218,  -218,
    -218,   237,   -25,   661,    61,  -218,  -218,    72,  -218,  -218,
    -218,   876,  -218,  -218,  -218,   661,   118,  -218,   222,  -218,
     353,   443,  -218,   661,  -218,  -218,   223,   353,   661,   661,
     661,   253,   427,   243,  -218,  -218,  -218,   122,    66,   145,
     267,   342,  -218,  -218,   528,   661,   343,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,   661,  -218,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
    -218,  -218,  -218,   754,   540,  -218,    93,  -218,   182,  -218,
    1066,  -218,   344,  -218,  -218,  -218,  -218,  -218,   -18,  -218,
    -218,    24,  -218,   661,  -218,   283,   353,  -218,   148,   150,
     157,   285,   427,  -218,  -218,  -218,   984,   194,  -218,   661,
    -218,  -218,   170,  -218,   205,  -218,  -218,  -218,  -218,  -218,
      -3,    -3,   -41,   -41,    10,    10,    10,    10,   106,   106,
     138,   224,   215,   216,   282,     2,  -218,  -218,   298,   299,
    -218,   301,   182,  1028,   552,  -218,  -218,  -218,    51,  -218,
    -218,  -218,  -218,  -218,   353,   353,   353,   661,   564,  -218,
    -218,   661,  -218,   661,  -218,  -218,  -218,  -218,   304,  -218,
     305,  -218,  -218,   319,  -218,  -218,   190,   353,   192,  -218,
    -218,  -218,  -218,   353,   292,  -218,   353,  -218,  -218,  -218
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,  -218,  -218,  -218,   -48,  -218,  -109,    49,    52,    73,
      59,   178,   195,   155,   179,   193,  -218,   -54,   -74,  -218,
     -89,   -53,   154,     0,  -218,   345,  -218,   -31,  -218,  -218,
     351,   -47,   -55,  -218,   171,  -218,   355,   296,   199,   -15,
     -34,    -1,  -218,   -59,  -218,   197,  -218,   286,  -126,  -217,
    -152,  -218,   -73,  -218,   177,   403,   325,  -176,  -218,  -218,
    -218,  -218,   418,  -218
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      28,   158,   143,    63,   209,   247,   262,   227,   150,    41,
      43,   187,   188,    50,   149,    53,   237,   154,     1,   302,
     215,   216,   181,    79,   162,    45,     1,     1,   169,    51,
      52,   213,   214,   164,    55,   155,   150,   176,    28,   172,
     174,   175,   149,   137,   154,    72,   189,    79,    79,    79,
     302,   308,    79,    66,   147,    85,    86,    87,   137,    88,
      89,   142,   244,   268,    67,   149,    70,   168,   210,   309,
      79,   229,   228,   211,   212,   147,    85,    86,    87,    25,
      88,    89,   188,   158,   188,   323,   318,    25,    25,   258,
     259,   260,    42,    78,    26,    26,     1,   254,    54,   150,
     245,   277,   278,   279,   257,   149,   274,   165,    47,   241,
     153,   150,   250,   242,   164,   101,   189,   149,   217,   218,
     273,   102,   103,   104,   105,   106,   107,   235,   170,     1,
      79,   265,    73,     1,   276,   229,   101,   157,   331,   295,
      79,   236,   102,   103,   104,   105,   106,   107,    74,   191,
     192,   193,   221,   222,    27,   296,   332,   233,   157,   234,
     319,   177,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     150,   301,   229,   313,   219,   220,   149,   251,   267,    57,
      25,   229,    27,    61,   233,    62,   234,    26,   230,   150,
     311,    26,    63,   252,    57,   149,   194,   264,   195,   266,
     196,   234,    59,   314,   138,   315,    26,   229,    43,   229,
     178,   149,   316,    16,    17,    44,   229,    76,   336,   338,
     179,   138,   236,   142,   158,   320,   168,   139,   180,   321,
     142,   333,   334,   335,   328,    71,   303,   339,   304,   182,
     150,   330,    26,    83,   160,   344,   149,   346,   266,   229,
     234,   229,   280,   281,   345,   267,   142,   282,   283,   340,
     347,   183,   322,   349,   229,   149,   184,    83,    83,    83,
     288,   289,    83,    84,    85,    86,    87,   185,    88,    89,
     284,   285,   286,   287,   223,   224,   232,   225,   226,   239,
      83,    75,   240,   142,   243,   253,   256,   261,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   263,    90,
      91,    92,   269,    93,    94,    95,    96,    97,    98,    99,
     100,    22,    23,    24,   101,   270,   275,   307,   312,   317,
     102,   103,   104,   105,   106,   107,    84,    85,    86,    87,
      83,    88,    89,   324,   325,   108,    56,   109,   326,   341,
      83,   343,   342,   147,    85,    86,    87,   348,    88,    89,
     292,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   290,    90,    91,    92,   293,    93,    94,    95,    96,
      97,    98,    99,   100,    22,    23,    24,   101,   156,   291,
     294,   152,   310,   102,   103,   104,   105,   106,   107,   161,
     147,    85,    86,    87,   101,    88,    89,   306,   108,    56,
     102,   103,   104,   105,   106,   107,   147,    85,    86,    87,
     246,    88,    89,    77,   231,   186,    65,   255,   147,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,     0,    22,    23,    24,   101,     0,     0,
       0,     0,   108,   102,   103,   104,   105,   106,   107,   101,
       0,     0,   148,     0,     0,   102,   103,   104,   105,   106,
     107,   147,    85,    86,    87,     0,    88,    89,     0,     0,
       0,     0,     0,   147,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     0,     0,   147,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,     0,   147,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,     0,   147,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,     0,   101,   271,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   101,     0,     0,   300,     0,     0,
     102,   103,   104,   105,   106,   107,   101,     0,     0,   329,
       0,     0,   102,   103,   104,   105,   106,   107,   101,   337,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     171,     0,     0,     0,     0,     0,   102,   103,   104,   105,
     106,   107,   147,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,   147,    85,    86,    87,     0,    88,
      89,     2,     0,     0,     0,     0,     0,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     0,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,     0,     0,    22,    23,    24,     0,     0,    64,
       0,     0,     1,   173,     0,     0,     0,     0,     0,   102,
     103,   104,   105,   106,   107,   101,     0,     0,     0,     0,
     163,   102,   103,   104,   105,   106,   107,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     1,   207,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
      26,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,   233,   297,
     234,     0,     0,     0,     0,    26,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
      26,     0,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    22,    23,    24,     0,   141,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    75,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,     0,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,   266,   297,
     234,     0,     0,     0,     0,    26,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,    24,     0,   327,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   305,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    23,    24,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     0,    22,    23,    24,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,    24
};

static const yytype_int16 yycheck[] =
{
       0,    75,    61,    37,   113,   157,   182,    17,    62,     3,
      25,   100,   101,    28,    62,     3,   142,    69,     3,   236,
      10,    11,    95,    54,    79,    26,     3,     3,    83,    29,
      30,    72,    73,    80,    34,    87,    90,    90,    38,    87,
      88,    89,    90,    58,    69,    46,   101,    78,    79,    80,
     267,    69,    83,    86,     3,     4,     5,     6,    73,     8,
       9,    61,    87,   189,     3,   113,    65,    82,    71,    87,
     101,    69,    82,    76,    77,     3,     4,     5,     6,    64,
       8,     9,   171,   157,   173,    83,   262,    64,    64,   178,
     179,   180,    86,    86,    71,    71,     3,   170,    86,   153,
     153,   210,   211,   212,   177,   153,   195,    83,    85,    65,
      84,   165,   165,    69,   161,    64,   171,   165,    12,    13,
     194,    70,    71,    72,    73,    74,    75,   142,    83,     3,
     161,    65,    69,     3,   208,    69,    64,    86,    87,   228,
     171,   142,    70,    71,    72,    73,    74,    75,    85,     7,
       8,     9,    14,    15,     0,   229,   308,    64,    86,    66,
     269,    83,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     234,   234,    69,   256,    78,    79,   234,    69,   189,    35,
      64,    69,    38,    64,    64,    66,    66,    71,    85,   253,
     253,    71,   236,    85,    50,   253,    64,    85,    66,    64,
      68,    66,    35,    65,    60,    65,    71,    69,   233,    69,
      64,   269,    65,    42,    43,    26,    69,    50,   317,   318,
      64,    77,   233,   233,   308,    65,   251,    60,    64,    69,
     240,   314,   315,   316,   303,    46,    64,   321,    66,    64,
     304,   304,    71,    54,    77,    65,   304,    65,    64,    69,
      66,    69,   213,   214,   337,   266,   266,   215,   216,   323,
     343,     3,    67,   346,    69,   323,    85,    78,    79,    80,
     221,   222,    83,     3,     4,     5,     6,    85,     8,     9,
     217,   218,   219,   220,    70,    80,    87,    81,    16,    65,
     101,    84,    69,   303,    67,    83,    83,    54,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    85,    49,
      50,    51,    65,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,     3,     3,     3,    65,    64,
      70,    71,    72,    73,    74,    75,     3,     4,     5,     6,
     161,     8,     9,    65,    65,    85,    86,    87,    67,    65,
     171,    52,    67,     3,     4,     5,     6,    85,     8,     9,
     225,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   223,    49,    50,    51,   226,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    73,   224,
     227,    66,   251,    70,    71,    72,    73,    74,    75,    78,
       3,     4,     5,     6,    64,     8,     9,   240,    85,    86,
      70,    71,    72,    73,    74,    75,     3,     4,     5,     6,
     154,     8,     9,    50,   129,    85,    38,   171,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    85,    70,    71,    72,    73,    74,    75,    64,
      -1,    -1,    67,    -1,    -1,    70,    71,    72,    73,    74,
      75,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    64,    -1,    -1,    67,    -1,    -1,
      70,    71,    72,    73,    74,    75,    64,    -1,    -1,    67,
      -1,    -1,    70,    71,    72,    73,    74,    75,    64,    65,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    61,    62,    63,    -1,    -1,     0,
      -1,    -1,     3,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    64,    -1,    -1,    -1,    -1,
      87,    70,    71,    72,    73,    74,    75,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    61,    62,    63,    -1,    65,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    84,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    -1,    71,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    65,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    61,    62,    63,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    61,    62,    63,    64,    71,   110,   111,   114,
     115,   116,   117,   123,   126,   127,   128,   129,   149,   150,
     151,     3,    86,   127,   126,   129,   130,    85,   112,   113,
     127,   111,   111,     3,    86,   111,    86,   110,   111,   142,
     143,    64,    66,   128,     0,   150,    86,     3,   124,   125,
      65,   126,   129,    69,    85,    84,   142,   143,    86,   115,
     118,   119,   120,   126,     3,     4,     5,     6,     8,     9,
      49,    50,    51,    53,    54,    55,    56,    57,    58,    59,
      60,    64,    70,    71,    72,    73,    74,    75,    85,    87,
      89,    90,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   108,   110,   140,
     141,   142,   144,   145,   146,   147,   148,   127,   110,   142,
       3,    65,   111,   131,   132,   133,   134,     3,    67,    92,
     105,   109,   124,    84,    69,    87,   113,    86,   106,   138,
     142,   118,   120,    87,   119,    83,   121,   122,   127,   120,
      83,    64,    92,    64,    92,    92,   109,    83,    64,    64,
      64,   140,    64,     3,    85,    85,    85,   108,   108,   120,
     135,     7,     8,     9,    64,    66,    68,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    84,   107,    94,
      71,    76,    77,    72,    73,    10,    11,    12,    13,    78,
      79,    14,    15,    70,    80,    81,    16,    17,    82,    69,
      85,   144,    87,    64,    66,   127,   129,   136,   137,    65,
      69,    65,    69,    67,    87,   109,   125,   138,   139,    87,
     109,    69,    85,    83,   140,   135,    83,   140,   108,   108,
     108,    54,   145,    85,    85,    65,    64,   129,   136,    65,
       3,    65,    91,   106,   108,     3,   106,    94,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    97,    98,    98,
      99,   100,   101,   102,   103,   108,   106,    65,   131,   136,
      67,   109,   137,    64,    66,    48,   133,     3,    69,    87,
     122,   109,    65,   140,    65,    65,    65,    64,   145,    94,
      65,    69,    67,    83,    65,    65,    67,    65,   131,    67,
     109,    87,   138,   140,   140,   140,   108,    65,   108,   106,
     105,    65,    67,    52,    65,   140,    65,   140,    85,   140
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 176 "ANSI.y"
    {
        (yyval.tree_Primary_expression) = (struct Primary_expression*) malloc(sizeof(struct Primary_expression));
        (yyval.tree_Primary_expression) -> str_ID = (yyvsp[(1) - (1)].str_ID);
        (yyval.tree_Primary_expression) -> kind = IDENTIFIER_kind;
    }
    break;

  case 3:
#line 181 "ANSI.y"
    {
        (yyval.tree_Primary_expression) = (struct Primary_expression*) malloc(sizeof(struct Primary_expression));
        (yyval.tree_Primary_expression) -> str_CONST = (yyvsp[(1) - (1)].str_CONST);
        (yyval.tree_Primary_expression) -> kind = CONSTANT_kind;
    }
    break;

  case 4:
#line 186 "ANSI.y"
    {
        (yyval.tree_Primary_expression) = (struct Primary_expression*) malloc(sizeof(struct Primary_expression));
        (yyval.tree_Primary_expression) -> str_STR = (yyvsp[(1) - (1)].str_STR);
        (yyval.tree_Primary_expression) -> kind = STRING_LITERAL_kind;
    }
    break;

  case 5:
#line 191 "ANSI.y"
    {
        (yyval.tree_Primary_expression) = (struct Primary_expression*) malloc(sizeof(struct Primary_expression));
        (yyval.tree_Primary_expression) -> expression = (yyvsp[(2) - (3)].tree_Expression);
        (yyval.tree_Primary_expression) -> kind = expression_kind;
    }
    break;

  case 6:
#line 199 "ANSI.y"
    {
        (yyval.tree_Postfix_expression) = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        (yyval.tree_Postfix_expression) -> primary_expression = (yyvsp[(1) - (1)].tree_Primary_expression);
        (yyval.tree_Postfix_expression) -> kind = primary_expression_kind;
    }
    break;

  case 7:
#line 204 "ANSI.y"
    {
        (yyval.tree_Postfix_expression) = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        (yyval.tree_Postfix_expression) -> postfix_expression = (yyvsp[(1) - (4)].tree_Postfix_expression);
        (yyval.tree_Postfix_expression) -> expression = (yyvsp[(3) - (4)].tree_Expression);
        (yyval.tree_Postfix_expression) -> kind = postfix_expression_expression_kind;
    }
    break;

  case 8:
#line 210 "ANSI.y"
    {
        (yyval.tree_Postfix_expression) = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        (yyval.tree_Postfix_expression) -> postfix_expression = (yyvsp[(1) - (3)].tree_Postfix_expression);
        (yyval.tree_Postfix_expression) -> kind = postfix_expression_not_kind;
    }
    break;

  case 9:
#line 215 "ANSI.y"
    {
        (yyval.tree_Postfix_expression) = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        (yyval.tree_Postfix_expression) -> postfix_expression = (yyvsp[(1) - (4)].tree_Postfix_expression);
        (yyval.tree_Postfix_expression) -> argument_expression_list = (yyvsp[(3) - (4)].tree_Argument_expression_list);
        (yyval.tree_Postfix_expression) -> kind = postfix_expression_argument_kind;
    }
    break;

  case 10:
#line 221 "ANSI.y"
    {
        (yyval.tree_Postfix_expression) = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        (yyval.tree_Postfix_expression) -> postfix_expression = (yyvsp[(1) - (3)].tree_Postfix_expression);
        (yyval.tree_Postfix_expression) -> str_ID = (yyvsp[(3) - (3)].str_ID);
        (yyval.tree_Postfix_expression) -> kind = postfix_expression_IDENTIFIER_kind;

    }
    break;

  case 11:
#line 228 "ANSI.y"
    {
        (yyval.tree_Postfix_expression) = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        (yyval.tree_Postfix_expression) -> postfix_expression = (yyvsp[(1) - (3)].tree_Postfix_expression);
        (yyval.tree_Postfix_expression) -> str_ID = (yyvsp[(3) - (3)].str_ID);
        (yyval.tree_Postfix_expression) -> kind = postfix_expression_PTR;
    }
    break;

  case 12:
#line 234 "ANSI.y"
    {
        (yyval.tree_Postfix_expression) = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        (yyval.tree_Postfix_expression) -> postfix_expression = (yyvsp[(1) - (2)].tree_Postfix_expression);
        (yyval.tree_Postfix_expression) -> kind = postfix_expression_INC;
    }
    break;

  case 13:
#line 239 "ANSI.y"
    {
        (yyval.tree_Postfix_expression) = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        (yyval.tree_Postfix_expression) -> postfix_expression = (yyvsp[(1) - (2)].tree_Postfix_expression);
        (yyval.tree_Postfix_expression) -> kind = postfix_expression_DEC;
    }
    break;

  case 14:
#line 247 "ANSI.y"
    {
        (yyval.tree_Argument_expression_list) = (struct Argument_expression_list*) malloc(sizeof(struct Argument_expression_list));
        (yyval.tree_Argument_expression_list) -> assignment_expression = (yyvsp[(1) - (1)].tree_Assignment_expression);
        (yyval.tree_Argument_expression_list) -> kind = assignment_expression_kind;
    }
    break;

  case 15:
#line 252 "ANSI.y"
    {
        (yyval.tree_Argument_expression_list) = (struct Argument_expression_list*) malloc(sizeof(struct Argument_expression_list));
        (yyval.tree_Argument_expression_list) -> argument_expression_list = (yyvsp[(1) - (3)].tree_Argument_expression_list);
        (yyval.tree_Argument_expression_list) -> assignment_expression = (yyvsp[(3) - (3)].tree_Assignment_expression);
        (yyval.tree_Argument_expression_list) -> kind = argument_expression_list_kind;
    }
    break;

  case 16:
#line 261 "ANSI.y"
    {
        (yyval.tree_Unary_expression) = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        (yyval.tree_Unary_expression) -> postfix_expression = (yyvsp[(1) - (1)].tree_Postfix_expression);
        (yyval.tree_Unary_expression) -> kind = postfix_expression_kind;
    }
    break;

  case 17:
#line 266 "ANSI.y"
    {
        (yyval.tree_Unary_expression) = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        (yyval.tree_Unary_expression) -> unary_expression = (yyvsp[(2) - (2)].tree_Unary_expression);
        (yyval.tree_Unary_expression) -> kind = INC_OP_kind;
    }
    break;

  case 18:
#line 271 "ANSI.y"
    {
        (yyval.tree_Unary_expression) = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        (yyval.tree_Unary_expression) -> unary_expression = (yyvsp[(2) - (2)].tree_Unary_expression);
        (yyval.tree_Unary_expression) -> kind = DEC_OP_kind;
    }
    break;

  case 19:
#line 276 "ANSI.y"
    {
        (yyval.tree_Unary_expression) = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        (yyval.tree_Unary_expression) -> unary_operator = (yyvsp[(1) - (2)].tree_Unary_operator);
        (yyval.tree_Unary_expression) -> cast_expression = (yyvsp[(2) - (2)].tree_Cast_expression);
        (yyval.tree_Unary_expression) -> kind = unary_operator_kind;
    }
    break;

  case 20:
#line 282 "ANSI.y"
    {
        (yyval.tree_Unary_expression) = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        (yyval.tree_Unary_expression) -> unary_expression = (yyvsp[(2) - (2)].tree_Unary_expression);
        (yyval.tree_Unary_expression) -> kind = SIZEOF_unary_expression_kind;
    }
    break;

  case 21:
#line 287 "ANSI.y"
    {
        (yyval.tree_Unary_expression) = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        (yyval.tree_Unary_expression) -> type_name = (yyvsp[(3) - (4)].tree_Type_name);
        (yyval.tree_Unary_expression) -> kind = SIZEOF_type_name_kind;
    }
    break;

  case 22:
#line 295 "ANSI.y"
    {
        (yyval.tree_Unary_operator) = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        (yyval.tree_Unary_operator) -> kind = AND_kind;
    }
    break;

  case 23:
#line 299 "ANSI.y"
    {
        (yyval.tree_Unary_operator) = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        (yyval.tree_Unary_operator) -> kind = MUL_kind;
    }
    break;

  case 24:
#line 303 "ANSI.y"
    {
        (yyval.tree_Unary_operator) = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        (yyval.tree_Unary_operator) -> kind = ADD_kind;
    }
    break;

  case 25:
#line 307 "ANSI.y"
    {
        (yyval.tree_Unary_operator) = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        (yyval.tree_Unary_operator) -> kind = SUB_kind;
    }
    break;

  case 26:
#line 311 "ANSI.y"
    {
        (yyval.tree_Unary_operator) = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        (yyval.tree_Unary_operator) -> kind = NAMI_kind;
    }
    break;

  case 27:
#line 315 "ANSI.y"
    {
        (yyval.tree_Unary_operator) = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        (yyval.tree_Unary_operator) -> kind = BIKKURI_kind;
    }
    break;

  case 28:
#line 322 "ANSI.y"
    {
        (yyval.tree_Cast_expression) = (struct Cast_expression*) malloc(sizeof(struct Cast_expression));
        (yyval.tree_Cast_expression) -> unary_expression = (yyvsp[(1) - (1)].tree_Unary_expression);
        (yyval.tree_Cast_expression) -> kind = unary_expression_kind;
    }
    break;

  case 29:
#line 327 "ANSI.y"
    {
        (yyval.tree_Cast_expression) = (struct Cast_expression*) malloc(sizeof(struct Cast_expression));
        (yyval.tree_Cast_expression) -> type_name = (yyvsp[(2) - (4)].tree_Type_name);
        (yyval.tree_Cast_expression) -> cast_expression = (yyvsp[(4) - (4)].tree_Cast_expression);
        (yyval.tree_Cast_expression) -> kind = type_name_kind;
    }
    break;

  case 30:
#line 336 "ANSI.y"
    {
        (yyval.tree_Multiplicative_expression) = (struct Multiplicative_expression*) malloc(sizeof(struct Multiplicative_expression));
        (yyval.tree_Multiplicative_expression) -> cast_expression = (yyvsp[(1) - (1)].tree_Cast_expression);
        (yyval.tree_Multiplicative_expression) -> kind = cast_expression_kind;
    }
    break;

  case 31:
#line 341 "ANSI.y"
    {
        (yyval.tree_Multiplicative_expression) = (struct Multiplicative_expression*) malloc(sizeof(struct Multiplicative_expression));
        (yyval.tree_Multiplicative_expression) -> multiplicative_expression = (yyvsp[(1) - (3)].tree_Multiplicative_expression);
        (yyval.tree_Multiplicative_expression) -> cast_expression = (yyvsp[(3) - (3)].tree_Cast_expression);
        (yyval.tree_Multiplicative_expression) -> kind = MUL_expression_kind;
    }
    break;

  case 32:
#line 347 "ANSI.y"
    {
        (yyval.tree_Multiplicative_expression) = (struct Multiplicative_expression*) malloc(sizeof(struct Multiplicative_expression));
        (yyval.tree_Multiplicative_expression) -> multiplicative_expression = (yyvsp[(1) - (3)].tree_Multiplicative_expression);
        (yyval.tree_Multiplicative_expression) -> cast_expression = (yyvsp[(3) - (3)].tree_Cast_expression);
        (yyval.tree_Multiplicative_expression) -> kind = DIV_expression_kind;
    }
    break;

  case 33:
#line 353 "ANSI.y"
    {
        (yyval.tree_Multiplicative_expression) = (struct Multiplicative_expression*) malloc(sizeof(struct Multiplicative_expression));
        (yyval.tree_Multiplicative_expression) -> multiplicative_expression = (yyvsp[(1) - (3)].tree_Multiplicative_expression);
        (yyval.tree_Multiplicative_expression) -> cast_expression = (yyvsp[(3) - (3)].tree_Cast_expression);
        (yyval.tree_Multiplicative_expression) -> kind = PCT_expression_kind;
    }
    break;

  case 34:
#line 362 "ANSI.y"
    {
        (yyval.tree_Additive_expression) = (struct Additive_expression*) malloc(sizeof(struct Additive_expression));
        (yyval.tree_Additive_expression) -> multiplicative_expression = (yyvsp[(1) - (1)].tree_Multiplicative_expression);
        (yyval.tree_Additive_expression) -> kind = multiplicative_expression_kind;
    }
    break;

  case 35:
#line 367 "ANSI.y"
    {
        (yyval.tree_Additive_expression) = (struct Additive_expression*) malloc(sizeof(struct Additive_expression));
        (yyval.tree_Additive_expression) -> additive_expression = (yyvsp[(1) - (3)].tree_Additive_expression);
        (yyval.tree_Additive_expression) -> multiplicative_expression = (yyvsp[(3) - (3)].tree_Multiplicative_expression);
        (yyval.tree_Additive_expression) -> kind = ADD_expression_kind;
    }
    break;

  case 36:
#line 373 "ANSI.y"
    {
        (yyval.tree_Additive_expression) = (struct Additive_expression*) malloc(sizeof(struct Additive_expression));
        (yyval.tree_Additive_expression) -> additive_expression = (yyvsp[(1) - (3)].tree_Additive_expression);
        (yyval.tree_Additive_expression) -> multiplicative_expression = (yyvsp[(3) - (3)].tree_Multiplicative_expression);
        (yyval.tree_Additive_expression) -> kind = SUB_expression_kind;
    }
    break;

  case 37:
#line 382 "ANSI.y"
    {
        (yyval.tree_Shift_expression) = (struct Shift_expression*) malloc(sizeof(struct Shift_expression));
        (yyval.tree_Shift_expression) -> additive_expression = (yyvsp[(1) - (1)].tree_Additive_expression);
        (yyval.tree_Shift_expression) -> kind = additive_expression_kind;
    }
    break;

  case 38:
#line 387 "ANSI.y"
    {
        (yyval.tree_Shift_expression) = (struct Shift_expression*) malloc(sizeof(struct Shift_expression));
        (yyval.tree_Shift_expression) -> shift_expression = (yyvsp[(1) - (3)].tree_Shift_expression);
        (yyval.tree_Shift_expression) -> additive_expression = (yyvsp[(3) - (3)].tree_Additive_expression);
        (yyval.tree_Shift_expression) -> kind = shift_LEFT_OP_kind;
    }
    break;

  case 39:
#line 393 "ANSI.y"
    {
        (yyval.tree_Shift_expression) = (struct Shift_expression*) malloc(sizeof(struct Shift_expression));
        (yyval.tree_Shift_expression) -> shift_expression = (yyvsp[(1) - (3)].tree_Shift_expression);
        (yyval.tree_Shift_expression) -> additive_expression = (yyvsp[(3) - (3)].tree_Additive_expression);
        (yyval.tree_Shift_expression) -> kind = shift_RIGHT_OP_kind;
    }
    break;

  case 40:
#line 402 "ANSI.y"
    {
        (yyval.tree_Relational_expression) = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        (yyval.tree_Relational_expression) -> shift_expression = (yyvsp[(1) - (1)].tree_Shift_expression);
        (yyval.tree_Relational_expression) -> kind = shift_expression_kind;
    }
    break;

  case 41:
#line 407 "ANSI.y"
    {
        (yyval.tree_Relational_expression) = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        (yyval.tree_Relational_expression) -> relational_expression = (yyvsp[(1) - (3)].tree_Relational_expression);
        (yyval.tree_Relational_expression) -> shift_expression = (yyvsp[(3) - (3)].tree_Shift_expression);
        (yyval.tree_Relational_expression) -> kind = relat_sho;
    }
    break;

  case 42:
#line 413 "ANSI.y"
    {
        (yyval.tree_Relational_expression) = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        (yyval.tree_Relational_expression) -> relational_expression = (yyvsp[(1) - (3)].tree_Relational_expression);
        (yyval.tree_Relational_expression) -> shift_expression = (yyvsp[(3) - (3)].tree_Shift_expression);
        (yyval.tree_Relational_expression) -> kind = relat_dai;
    }
    break;

  case 43:
#line 419 "ANSI.y"
    {
        (yyval.tree_Relational_expression) = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        (yyval.tree_Relational_expression) -> relational_expression = (yyvsp[(1) - (3)].tree_Relational_expression);
        (yyval.tree_Relational_expression) -> shift_expression = (yyvsp[(3) - (3)].tree_Shift_expression);
        (yyval.tree_Relational_expression) -> kind = relat_LE_OP;
    }
    break;

  case 44:
#line 425 "ANSI.y"
    {
        (yyval.tree_Relational_expression) = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        (yyval.tree_Relational_expression) -> relational_expression = (yyvsp[(1) - (3)].tree_Relational_expression);
        (yyval.tree_Relational_expression) -> shift_expression = (yyvsp[(3) - (3)].tree_Shift_expression);
        (yyval.tree_Relational_expression) -> kind = relat_GE;
    }
    break;

  case 45:
#line 434 "ANSI.y"
    {
        (yyval.tree_Equality_expression) = (struct Equality_expression*) malloc(sizeof(struct Equality_expression));
        (yyval.tree_Equality_expression) -> relational_expression = (yyvsp[(1) - (1)].tree_Relational_expression);
        (yyval.tree_Equality_expression) -> kind = relational_expression_kind;
    }
    break;

  case 46:
#line 439 "ANSI.y"
    {
        (yyval.tree_Equality_expression) = (struct Equality_expression*) malloc(sizeof(struct Equality_expression));
        (yyval.tree_Equality_expression) -> equality_expression = (yyvsp[(1) - (3)].tree_Equality_expression);
        (yyval.tree_Equality_expression) -> relational_expression = (yyvsp[(3) - (3)].tree_Relational_expression);
        (yyval.tree_Equality_expression) -> kind = eq_EQ_OP;
    }
    break;

  case 47:
#line 445 "ANSI.y"
    {
        (yyval.tree_Equality_expression) = (struct Equality_expression*) malloc(sizeof(struct Equality_expression));
        (yyval.tree_Equality_expression) -> equality_expression = (yyvsp[(1) - (3)].tree_Equality_expression);
        (yyval.tree_Equality_expression) -> relational_expression = (yyvsp[(3) - (3)].tree_Relational_expression);
        (yyval.tree_Equality_expression) -> kind = eq_NE_OP;
    }
    break;

  case 48:
#line 454 "ANSI.y"
    {
        (yyval.tree_And_expression) = (struct And_expression*) malloc(sizeof(struct And_expression));
        (yyval.tree_And_expression) -> equality_expression = (yyvsp[(1) - (1)].tree_Equality_expression);
        (yyval.tree_And_expression) -> kind = equality_expression_kind;
    }
    break;

  case 49:
#line 459 "ANSI.y"
    {
        (yyval.tree_And_expression) = (struct And_expression*) malloc(sizeof(struct And_expression));
        (yyval.tree_And_expression) -> and_expression = (yyvsp[(1) - (3)].tree_And_expression);
        (yyval.tree_And_expression) -> equality_expression = (yyvsp[(3) - (3)].tree_Equality_expression);
        (yyval.tree_And_expression) -> kind = and_expression_kind;
    }
    break;

  case 50:
#line 468 "ANSI.y"
    {
        (yyval.tree_Exclusive_or_expression) = (struct Exclusive_or_expression*) malloc(sizeof(struct Exclusive_or_expression));
        (yyval.tree_Exclusive_or_expression) -> and_expression = (yyvsp[(1) - (1)].tree_And_expression);
        (yyval.tree_Exclusive_or_expression) -> kind = and_expression_kind2;
    }
    break;

  case 51:
#line 473 "ANSI.y"
    {
        (yyval.tree_Exclusive_or_expression) = (struct Exclusive_or_expression*) malloc(sizeof(struct Exclusive_or_expression));
        (yyval.tree_Exclusive_or_expression) -> exclusive_or_expression = (yyvsp[(1) - (3)].tree_Exclusive_or_expression);
        (yyval.tree_Exclusive_or_expression) -> and_expression = (yyvsp[(3) - (3)].tree_And_expression);
        (yyval.tree_Exclusive_or_expression) -> kind = exclusive_or_expression_kind;
    }
    break;

  case 52:
#line 482 "ANSI.y"
    {
        (yyval.tree_Inclusive_or_expression) = (struct Inclusive_or_expression*) malloc(sizeof(struct Inclusive_or_expression));
        (yyval.tree_Inclusive_or_expression) -> exclusive_or_expression = (yyvsp[(1) - (1)].tree_Exclusive_or_expression);
        (yyval.tree_Inclusive_or_expression) -> kind = exclusive_or_expression_kind2;
    }
    break;

  case 53:
#line 487 "ANSI.y"
    {
        (yyval.tree_Inclusive_or_expression) = (struct Inclusive_or_expression*) malloc(sizeof(struct Inclusive_or_expression));
        (yyval.tree_Inclusive_or_expression) -> inclusive_or_expression = (yyvsp[(1) - (3)].tree_Inclusive_or_expression);
        (yyval.tree_Inclusive_or_expression) -> exclusive_or_expression = (yyvsp[(3) - (3)].tree_Exclusive_or_expression);
        (yyval.tree_Inclusive_or_expression) -> kind = inclusive_or_expression_kind;
    }
    break;

  case 54:
#line 496 "ANSI.y"
    {
        (yyval.treeLogical_and_expression) = (struct Logical_and_expression*) malloc(sizeof(struct Logical_and_expression));
        (yyval.treeLogical_and_expression) -> inclusive_or_expression = (yyvsp[(1) - (1)].tree_Inclusive_or_expression);
        (yyval.treeLogical_and_expression) -> kind = inclusive_or_expression_kind2;
    }
    break;

  case 55:
#line 501 "ANSI.y"
    {
        (yyval.treeLogical_and_expression) = (struct Logical_and_expression*) malloc(sizeof(struct Logical_and_expression));
        (yyval.treeLogical_and_expression) -> logical_and_expression = (yyvsp[(1) - (3)].treeLogical_and_expression);
        (yyval.treeLogical_and_expression) -> inclusive_or_expression = (yyvsp[(3) - (3)].tree_Inclusive_or_expression);
        (yyval.treeLogical_and_expression) -> kind = logical_and_expression_kind;
    }
    break;

  case 56:
#line 510 "ANSI.y"
    {
        (yyval.tree_Logical_or_expression) = (struct Logical_or_expression*) malloc(sizeof(struct Logical_or_expression));
        (yyval.tree_Logical_or_expression) -> logical_and_expression = (yyvsp[(1) - (1)].treeLogical_and_expression);
        (yyval.tree_Logical_or_expression) -> kind = logical_and_expression_kind2;
    }
    break;

  case 57:
#line 515 "ANSI.y"
    {
        (yyval.tree_Logical_or_expression) = (struct Logical_or_expression*) malloc(sizeof(struct Logical_or_expression));
        (yyval.tree_Logical_or_expression) -> logical_or_expression = (yyvsp[(1) - (3)].tree_Logical_or_expression);
        (yyval.tree_Logical_or_expression) -> logical_and_expression = (yyvsp[(3) - (3)].treeLogical_and_expression);
        (yyval.tree_Logical_or_expression) -> kind = logical_or_expression_kind;
    }
    break;

  case 58:
#line 524 "ANSI.y"
    {
        (yyval.tree_Conditional_expression) = (struct Conditional_expression*) malloc(sizeof(struct Conditional_expression));
        (yyval.tree_Conditional_expression) -> logical_or_expression = (yyvsp[(1) - (1)].tree_Logical_or_expression);
        (yyval.tree_Conditional_expression) -> kind = logical_or_expression_kind2;
    }
    break;

  case 59:
#line 529 "ANSI.y"
    {
        (yyval.tree_Conditional_expression) = (struct Conditional_expression*) malloc(sizeof(struct Conditional_expression));
        (yyval.tree_Conditional_expression) -> logical_or_expression = (yyvsp[(1) - (5)].tree_Logical_or_expression);
        (yyval.tree_Conditional_expression) -> expression = (yyvsp[(3) - (5)].tree_Expression);
        (yyval.tree_Conditional_expression) -> conditional_expression = (yyvsp[(5) - (5)].tree_Conditional_expression);
        (yyval.tree_Conditional_expression) -> kind = logical_or_expression_expression_kind;
    }
    break;

  case 60:
#line 539 "ANSI.y"
    {
        (yyval.tree_Assignment_expression) = (struct Assignment_expression*) malloc(sizeof(struct Assignment_expression));
        (yyval.tree_Assignment_expression) -> conditional_expression = (yyvsp[(1) - (1)].tree_Conditional_expression);
        (yyval.tree_Assignment_expression) -> kind = conditional_expression_kind2;
    }
    break;

  case 61:
#line 544 "ANSI.y"
    {
        (yyval.tree_Assignment_expression) = (struct Assignment_expression*) malloc(sizeof(struct Assignment_expression));
        (yyval.tree_Assignment_expression) -> unary_expression = (yyvsp[(1) - (3)].tree_Unary_expression);
        (yyval.tree_Assignment_expression) -> assignment_operator = (yyvsp[(2) - (3)].tree_Assignment_operator);
        (yyval.tree_Assignment_expression) -> assignment_expression = (yyvsp[(3) - (3)].tree_Assignment_expression);
        (yyval.tree_Assignment_expression) -> kind = unary_expression_kind2;
    }
    break;

  case 62:
#line 554 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = EQUAL_kind;
    }
    break;

  case 63:
#line 558 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = MUL_ASSIGN_kind;
    }
    break;

  case 64:
#line 562 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = DIV_ASSIGN_kind;
    }
    break;

  case 65:
#line 566 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = MOD_ASSIGN_kind;
    }
    break;

  case 66:
#line 570 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = ADD_ASSIGN_kind;
    }
    break;

  case 67:
#line 574 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = SUB_ASSIGN_kind;
    }
    break;

  case 68:
#line 578 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = LEFT_ASSIGN;
    }
    break;

  case 69:
#line 582 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = RIGHT_ASSIGN_kind;
    }
    break;

  case 70:
#line 586 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = AND_ASSIGN_kind;
    }
    break;

  case 71:
#line 590 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = XOR_ASSIGN_kind;
    }
    break;

  case 72:
#line 594 "ANSI.y"
    {
        (yyval.tree_Assignment_operator) = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        (yyval.tree_Assignment_operator) -> kind = OR_ASSIGN_kind;
    }
    break;

  case 73:
#line 601 "ANSI.y"
    {
        (yyval.tree_Expression) = (struct Expression*) malloc(sizeof(struct Expression));
        (yyval.tree_Expression) -> assignment_expression = (yyvsp[(1) - (1)].tree_Assignment_expression);
        (yyval.tree_Expression) -> kind = assignment_expression_kind2;
    }
    break;

  case 74:
#line 606 "ANSI.y"
    {
        (yyval.tree_Expression) = (struct Expression*) malloc(sizeof(struct Expression));
        (yyval.tree_Expression) -> expression = (yyvsp[(1) - (3)].tree_Expression);
        (yyval.tree_Expression) -> assignment_expression = (yyvsp[(3) - (3)].tree_Assignment_expression);
        (yyval.tree_Expression) -> kind = expression_kind2;
    }
    break;

  case 75:
#line 615 "ANSI.y"
    {
        (yyval.tree_Constant_expression) = (struct Constant_expression*) malloc(sizeof(struct Constant_expression));
        (yyval.tree_Constant_expression) -> conditional_expression = (yyvsp[(1) - (1)].tree_Conditional_expression);
        (yyval.tree_Constant_expression) -> kind = conditional_expression_kind3;
    }
    break;

  case 76:
#line 623 "ANSI.y"
    {
        (yyval.tree_Declaration) = (struct Declaration*) malloc(sizeof(struct Declaration));
        (yyval.tree_Declaration) -> declaration_specifiers = (yyvsp[(1) - (2)].tree_Declaration_specifiers);
        (yyval.tree_Declaration) -> kind = dec_spe_kind;
    }
    break;

  case 77:
#line 628 "ANSI.y"
    {
        (yyval.tree_Declaration) = (struct Declaration*) malloc(sizeof(struct Declaration));
        (yyval.tree_Declaration) -> declaration_specifiers = (yyvsp[(1) - (3)].tree_Declaration_specifiers);
        (yyval.tree_Declaration) -> init_declarator_list = (yyvsp[(2) - (3)].tree_Init_declarator_list);
        (yyval.tree_Declaration) -> kind = dec_spe_ini_kind;
    }
    break;

  case 78:
#line 637 "ANSI.y"
    {
        (yyval.tree_Declaration_specifiers) = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        (yyval.tree_Declaration_specifiers) -> storage_class_specifier = (yyvsp[(1) - (1)].tree_Storage_class_specifier);
        (yyval.tree_Declaration_specifiers) -> kind = storage_class_specifier_kind;
    }
    break;

  case 79:
#line 642 "ANSI.y"
    {
        (yyval.tree_Declaration_specifiers) = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        (yyval.tree_Declaration_specifiers) -> storage_class_specifier = (yyvsp[(1) - (2)].tree_Storage_class_specifier);
        (yyval.tree_Declaration_specifiers) -> declaration_specifiers = (yyvsp[(2) - (2)].tree_Declaration_specifiers);
        (yyval.tree_Declaration_specifiers) -> kind = storage_class_specifier_declaration_kind;
    }
    break;

  case 80:
#line 648 "ANSI.y"
    {
        (yyval.tree_Declaration_specifiers) = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        (yyval.tree_Declaration_specifiers) -> type_specifier = (yyvsp[(1) - (1)].tree_Type_specifier);
        (yyval.tree_Declaration_specifiers) -> kind = type_specifier_kind;
    }
    break;

  case 81:
#line 653 "ANSI.y"
    {
        (yyval.tree_Declaration_specifiers) = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        (yyval.tree_Declaration_specifiers) -> type_specifier = (yyvsp[(1) - (2)].tree_Type_specifier);
        (yyval.tree_Declaration_specifiers) -> declaration_specifiers = (yyvsp[(2) - (2)].tree_Declaration_specifiers);
        (yyval.tree_Declaration_specifiers) -> kind = type_specifier_declaration_kind;
    }
    break;

  case 82:
#line 659 "ANSI.y"
    {
        (yyval.tree_Declaration_specifiers) = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        (yyval.tree_Declaration_specifiers) -> type_qualifier = (yyvsp[(1) - (1)].tree_Type_qualifier);
        (yyval.tree_Declaration_specifiers) -> kind = type_qualifier_kind;
    }
    break;

  case 83:
#line 664 "ANSI.y"
    {
        (yyval.tree_Declaration_specifiers) = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        (yyval.tree_Declaration_specifiers) -> type_qualifier = (yyvsp[(1) - (2)].tree_Type_qualifier);
        (yyval.tree_Declaration_specifiers) -> declaration_specifiers = (yyvsp[(2) - (2)].tree_Declaration_specifiers);
        (yyval.tree_Declaration_specifiers) -> kind = type_qualifier_declaration_kind;
    }
    break;

  case 84:
#line 673 "ANSI.y"
    {
        (yyval.tree_Init_declarator_list) = (struct Init_declarator_list*) malloc(sizeof(struct Init_declarator_list));
        (yyval.tree_Init_declarator_list) -> init_declarator = (yyvsp[(1) - (1)].tree_Init_declarator);
        (yyval.tree_Init_declarator_list) -> kind = init_declarator_kind;
    }
    break;

  case 85:
#line 678 "ANSI.y"
    {
        (yyval.tree_Init_declarator_list) = (struct Init_declarator_list*) malloc(sizeof(struct Init_declarator_list));
        (yyval.tree_Init_declarator_list) -> init_declarator_list = (yyvsp[(1) - (3)].tree_Init_declarator_list);
        (yyval.tree_Init_declarator_list) -> init_declarator = (yyvsp[(3) - (3)].tree_Init_declarator);
        (yyval.tree_Init_declarator_list) -> kind = init_declarator_list_kind;
    }
    break;

  case 86:
#line 687 "ANSI.y"
    {
        (yyval.tree_Init_declarator) = (struct Init_declarator*) malloc(sizeof(struct Init_declarator));
        (yyval.tree_Init_declarator) -> declarator = (yyvsp[(1) - (1)].tree_Declarator);
        (yyval.tree_Init_declarator) -> kind = declarator_kind;
    }
    break;

  case 87:
#line 692 "ANSI.y"
    {
        (yyval.tree_Init_declarator) = (struct Init_declarator*) malloc(sizeof(struct Init_declarator));
        (yyval.tree_Init_declarator) -> declarator = (yyvsp[(1) - (3)].tree_Declarator);
        (yyval.tree_Init_declarator) -> initializer = (yyvsp[(3) - (3)].tree_Initializer);
        (yyval.tree_Init_declarator) -> kind = declarator_EQUAL_kind;
    }
    break;

  case 88:
#line 701 "ANSI.y"
    {
        (yyval.tree_Storage_class_specifier) = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        (yyval.tree_Storage_class_specifier) -> kind = TYPEDEF_kind;
    }
    break;

  case 89:
#line 705 "ANSI.y"
    {
        (yyval.tree_Storage_class_specifier) = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        (yyval.tree_Storage_class_specifier) -> kind = EXTERN_kind;
    }
    break;

  case 90:
#line 709 "ANSI.y"
    {
        (yyval.tree_Storage_class_specifier) = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        (yyval.tree_Storage_class_specifier) -> kind = STATIC_kind;
    }
    break;

  case 91:
#line 713 "ANSI.y"
    {
        (yyval.tree_Storage_class_specifier) = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        (yyval.tree_Storage_class_specifier) -> kind = AUTO_kind;
    }
    break;

  case 92:
#line 717 "ANSI.y"
    {
        (yyval.tree_Storage_class_specifier) = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        (yyval.tree_Storage_class_specifier) -> kind = REGISTER_kind;
    }
    break;

  case 93:
#line 724 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = VOID_kind;
    }
    break;

  case 94:
#line 728 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = CHAR_kind;
    }
    break;

  case 95:
#line 732 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = SHORT_kind;
    }
    break;

  case 96:
#line 736 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = INT_kind;
    }
    break;

  case 97:
#line 740 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = LONG_kind;
    }
    break;

  case 98:
#line 744 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = FLOAT_kind;
    }
    break;

  case 99:
#line 748 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = DOUBLE_kind;
    }
    break;

  case 100:
#line 752 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = SIGNED_kind;
    }
    break;

  case 101:
#line 756 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = UNSIGNED_kind;
    }
    break;

  case 102:
#line 760 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> struct_or_union_specifier = (yyvsp[(1) - (1)].tree_Struct_or_union_specifier);
        (yyval.tree_Type_specifier) -> kind = struct_or_union_specifier_kind;
    }
    break;

  case 103:
#line 765 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> enum_specifier = (yyvsp[(1) - (1)].tree_Enum_specifier);
        (yyval.tree_Type_specifier) -> kind = enum_specifier_kind;
    }
    break;

  case 104:
#line 770 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = TYPE_NAME_kind;
    }
    break;

  case 105:
#line 774 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = MPFI_kind;
    }
    break;

  case 106:
#line 778 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = GMPFI_kind;
    }
    break;

  case 107:
#line 782 "ANSI.y"
    {
        (yyval.tree_Type_specifier) = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        (yyval.tree_Type_specifier) -> kind = MPFR_kind;
    }
    break;

  case 108:
#line 789 "ANSI.y"
    {
        (yyval.tree_Struct_or_union_specifier) = (struct Struct_or_union_specifier*) malloc(sizeof(struct Struct_or_union_specifier));
        (yyval.tree_Struct_or_union_specifier) -> struct_or_union = (yyvsp[(1) - (5)].tree_Struct_or_union);
        (yyval.tree_Struct_or_union_specifier) -> str_ID = (yyvsp[(2) - (5)].str_ID);
        (yyval.tree_Struct_or_union_specifier) -> struct_declaration_list = (yyvsp[(4) - (5)].tree_Struct_declaration_list);
        (yyval.tree_Struct_or_union_specifier) -> kind = struct_ID_struct_kind;
    }
    break;

  case 109:
#line 796 "ANSI.y"
    {
        (yyval.tree_Struct_or_union_specifier) = (struct Struct_or_union_specifier*) malloc(sizeof(struct Struct_or_union_specifier));
        (yyval.tree_Struct_or_union_specifier) -> struct_or_union = (yyvsp[(1) - (4)].tree_Struct_or_union);
        (yyval.tree_Struct_or_union_specifier) -> struct_declaration_list = (yyvsp[(3) - (4)].tree_Struct_declaration_list);
        (yyval.tree_Struct_or_union_specifier) -> kind = struct_struct;
    }
    break;

  case 110:
#line 802 "ANSI.y"
    {
        (yyval.tree_Struct_or_union_specifier) = (struct Struct_or_union_specifier*) malloc(sizeof(struct Struct_or_union_specifier));
        (yyval.tree_Struct_or_union_specifier) -> struct_or_union = (yyvsp[(1) - (2)].tree_Struct_or_union);
        (yyval.tree_Struct_or_union_specifier) -> str_ID = (yyvsp[(2) - (2)].str_ID);
        (yyval.tree_Struct_or_union_specifier) -> kind = struct_ID;
    }
    break;

  case 111:
#line 811 "ANSI.y"
    {
        (yyval.tree_Struct_or_union) = (struct Struct_or_union*) malloc(sizeof(struct Struct_or_union));
        (yyval.tree_Struct_or_union) -> kind = STRUCT_kind;
    }
    break;

  case 112:
#line 815 "ANSI.y"
    {
        (yyval.tree_Struct_or_union) = (struct Struct_or_union*) malloc(sizeof(struct Struct_or_union));
        (yyval.tree_Struct_or_union) -> kind = UNION_kind;
    }
    break;

  case 113:
#line 822 "ANSI.y"
    {
        (yyval.tree_Struct_declaration_list) = (struct Struct_declaration_list*) malloc(sizeof(struct Struct_declaration_list));
        (yyval.tree_Struct_declaration_list) -> struct_declaration = (yyvsp[(1) - (1)].tree_Struct_declaration);
        (yyval.tree_Struct_declaration_list) -> kind = struct_declaration_kind;
    }
    break;

  case 114:
#line 827 "ANSI.y"
    {
        (yyval.tree_Struct_declaration_list) = (struct Struct_declaration_list*) malloc(sizeof(struct Struct_declaration_list));
        (yyval.tree_Struct_declaration_list) -> struct_declaration_list = (yyvsp[(1) - (2)].tree_Struct_declaration_list);
        (yyval.tree_Struct_declaration_list) -> struct_declaration = (yyvsp[(2) - (2)].tree_Struct_declaration);
        (yyval.tree_Struct_declaration_list) -> kind = struct_declaration_list_kind;
    }
    break;

  case 115:
#line 836 "ANSI.y"
    {
        (yyval.tree_Struct_declaration) = (struct Struct_declaration*) malloc(sizeof(struct Struct_declaration));
        (yyval.tree_Struct_declaration) -> specifier_qualifier_list = (yyvsp[(1) - (3)].tree_Specifier_qualifier_list);
        (yyval.tree_Struct_declaration) -> struct_declarator_list = (yyvsp[(2) - (3)].tree_Struct_declarator_list);
        (yyval.tree_Struct_declaration) -> kind = specifier_qualifier_list_kind;
    }
    break;

  case 116:
#line 845 "ANSI.y"
    {
        (yyval.tree_Specifier_qualifier_list) = (struct Specifier_qualifier_list*) malloc(sizeof(struct Specifier_qualifier_list));
        (yyval.tree_Specifier_qualifier_list) -> type_specifier = (yyvsp[(1) - (2)].tree_Type_specifier);
        (yyval.tree_Specifier_qualifier_list) -> specifier_qualifier_list = (yyvsp[(2) - (2)].tree_Specifier_qualifier_list);
        (yyval.tree_Specifier_qualifier_list) -> kind = type_spe_spe_kind;
    }
    break;

  case 117:
#line 851 "ANSI.y"
    {
        (yyval.tree_Specifier_qualifier_list) = (struct Specifier_qualifier_list*) malloc(sizeof(struct Specifier_qualifier_list));
        (yyval.tree_Specifier_qualifier_list) -> type_specifier = (yyvsp[(1) - (1)].tree_Type_specifier);
        (yyval.tree_Specifier_qualifier_list) -> kind = type_spe_kind;
    }
    break;

  case 118:
#line 856 "ANSI.y"
    {
        (yyval.tree_Specifier_qualifier_list) = (struct Specifier_qualifier_list*) malloc(sizeof(struct Specifier_qualifier_list));
        (yyval.tree_Specifier_qualifier_list) -> type_qualifier = (yyvsp[(1) - (2)].tree_Type_qualifier);
        (yyval.tree_Specifier_qualifier_list) -> specifier_qualifier_list = (yyvsp[(2) - (2)].tree_Specifier_qualifier_list);
        (yyval.tree_Specifier_qualifier_list) -> kind = type_qua_spe_kind;
    }
    break;

  case 119:
#line 862 "ANSI.y"
    {
        (yyval.tree_Specifier_qualifier_list) = (struct Specifier_qualifier_list*) malloc(sizeof(struct Specifier_qualifier_list));
        (yyval.tree_Specifier_qualifier_list) -> type_qualifier = (yyvsp[(1) - (1)].tree_Type_qualifier);
        (yyval.tree_Specifier_qualifier_list) -> kind = type_qua_kind;
    }
    break;

  case 120:
#line 870 "ANSI.y"
    {
        (yyval.tree_Struct_declarator_list) = (struct Struct_declarator_list*) malloc(sizeof(struct Struct_declarator_list));
        (yyval.tree_Struct_declarator_list) -> struct_declarator = (yyvsp[(1) - (1)].tree_Struct_declarator);
        (yyval.tree_Struct_declarator_list) -> kind = struct_declarator_kind;
    }
    break;

  case 121:
#line 875 "ANSI.y"
    { 
        (yyval.tree_Struct_declarator_list) = (struct Struct_declarator_list*) malloc(sizeof(struct Struct_declarator_list));
        (yyval.tree_Struct_declarator_list) -> struct_declarator_list = (yyvsp[(1) - (3)].tree_Struct_declarator_list);
        (yyval.tree_Struct_declarator_list) -> struct_declarator = (yyvsp[(3) - (3)].tree_Struct_declarator);
        (yyval.tree_Struct_declarator_list) -> kind = struct_declarator_list_kind;
    }
    break;

  case 122:
#line 884 "ANSI.y"
    {
        (yyval.tree_Struct_declarator) = (struct Struct_declarator*) malloc(sizeof(struct Struct_declarator));
        (yyval.tree_Struct_declarator) -> declarator = (yyvsp[(1) - (1)].tree_Declarator);
        (yyval.tree_Struct_declarator) -> kind = dec_kind;
    }
    break;

  case 123:
#line 889 "ANSI.y"
    {
        (yyval.tree_Struct_declarator) = (struct Struct_declarator*) malloc(sizeof(struct Struct_declarator));
        (yyval.tree_Struct_declarator) -> constant_expression = (yyvsp[(2) - (2)].tree_Constant_expression);
        (yyval.tree_Struct_declarator) -> kind = con_kind;
    }
    break;

  case 124:
#line 894 "ANSI.y"
    {
        (yyval.tree_Struct_declarator) = (struct Struct_declarator*) malloc(sizeof(struct Struct_declarator));
        (yyval.tree_Struct_declarator) -> declarator = (yyvsp[(1) - (3)].tree_Declarator);
        (yyval.tree_Struct_declarator) -> constant_expression = (yyvsp[(3) - (3)].tree_Constant_expression);
        (yyval.tree_Struct_declarator) -> kind = dec_con_kind;
    }
    break;

  case 125:
#line 903 "ANSI.y"
    {
        (yyval.tree_Enum_specifier) = (struct Enum_specifier*) malloc(sizeof(struct Enum_specifier));
        (yyval.tree_Enum_specifier) -> enumerator_list = (yyvsp[(3) - (4)].tree_Enumerator_list);
        (yyval.tree_Enum_specifier) -> kind = ENUM_enu_kind;
    }
    break;

  case 126:
#line 908 "ANSI.y"
    {
        (yyval.tree_Enum_specifier) = (struct Enum_specifier*) malloc(sizeof(struct Enum_specifier));
        (yyval.tree_Enum_specifier) -> str_ID = (yyvsp[(2) - (5)].str_ID);
        (yyval.tree_Enum_specifier) -> enumerator_list = (yyvsp[(4) - (5)].tree_Enumerator_list);
        (yyval.tree_Enum_specifier) -> kind = ENUM_ID_enu_kind;
    }
    break;

  case 127:
#line 914 "ANSI.y"
    {
        (yyval.tree_Enum_specifier) = (struct Enum_specifier*) malloc(sizeof(struct Enum_specifier));
        (yyval.tree_Enum_specifier) -> str_ID = (yyvsp[(2) - (2)].str_ID);
        (yyval.tree_Enum_specifier) -> kind = ENUM_ID_kind;
    }
    break;

  case 128:
#line 922 "ANSI.y"
    {
        (yyval.tree_Enumerator_list) = (struct Enumerator_list*) malloc(sizeof(struct Enumerator_list));
        (yyval.tree_Enumerator_list) -> enumerator = (yyvsp[(1) - (1)].tree_Enumerator);
        (yyval.tree_Enumerator_list) -> kind = enumerator_kind;
    }
    break;

  case 129:
#line 927 "ANSI.y"
    {
        (yyval.tree_Enumerator_list) = (struct Enumerator_list*) malloc(sizeof(struct Enumerator_list));
        (yyval.tree_Enumerator_list) -> enumerator_list = (yyvsp[(1) - (3)].tree_Enumerator_list);
        (yyval.tree_Enumerator_list) -> enumerator = (yyvsp[(3) - (3)].tree_Enumerator);
        (yyval.tree_Enumerator_list) -> kind = enumerator_list_kind;
    }
    break;

  case 130:
#line 936 "ANSI.y"
    {
        (yyval.tree_Enumerator) = (struct Enumerator*) malloc(sizeof(struct Enumerator));
        (yyval.tree_Enumerator) -> str_ID = (yyvsp[(1) - (1)].str_ID);
        (yyval.tree_Enumerator) -> kind = ID_kind;
    }
    break;

  case 131:
#line 941 "ANSI.y"
    {
        (yyval.tree_Enumerator) = (struct Enumerator*) malloc(sizeof(struct Enumerator));
        (yyval.tree_Enumerator) -> str_ID = (yyvsp[(1) - (3)].str_ID);
        (yyval.tree_Enumerator) -> constant_expression = (yyvsp[(3) - (3)].tree_Constant_expression);
        (yyval.tree_Enumerator) -> kind = ID_EQUAL_kind;
    }
    break;

  case 132:
#line 950 "ANSI.y"
    {
        (yyval.tree_Type_qualifier) = (struct Type_qualifier*) malloc(sizeof(struct Type_qualifier));
        (yyval.tree_Type_qualifier) -> kind = CONST_kind;
    }
    break;

  case 133:
#line 954 "ANSI.y"
    {
        (yyval.tree_Type_qualifier) = (struct Type_qualifier*) malloc(sizeof(struct Type_qualifier));
        (yyval.tree_Type_qualifier) -> kind = VOLATILE_kind;
    }
    break;

  case 134:
#line 961 "ANSI.y"
    {
        (yyval.tree_Declarator) = (struct Declarator*) malloc(sizeof(struct Declarator));
        (yyval.tree_Declarator) -> pointer = (yyvsp[(1) - (2)].tree_Pointer);
        (yyval.tree_Declarator) -> direct_declarator = (yyvsp[(2) - (2)].tree_Direct_declarator);
        (yyval.tree_Declarator) -> kind = pointer_kind;
    }
    break;

  case 135:
#line 967 "ANSI.y"
    {
        (yyval.tree_Declarator) = (struct Declarator*) malloc(sizeof(struct Declarator));
        (yyval.tree_Declarator) -> direct_declarator = (yyvsp[(1) - (1)].tree_Direct_declarator);
        (yyval.tree_Declarator) -> kind = direct_declarator_kind;
    }
    break;

  case 136:
#line 975 "ANSI.y"
    {
        (yyval.tree_Direct_declarator) = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        (yyval.tree_Direct_declarator) -> str_ID = (yyvsp[(1) - (1)].str_ID);
        (yyval.tree_Direct_declarator) -> kind = ID_kind2;
    }
    break;

  case 137:
#line 980 "ANSI.y"
    {
        (yyval.tree_Direct_declarator) = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        (yyval.tree_Direct_declarator) -> declarator = (yyvsp[(2) - (3)].tree_Declarator);
        (yyval.tree_Direct_declarator) -> kind = declarator_kind2;
    }
    break;

  case 138:
#line 985 "ANSI.y"
    {
        (yyval.tree_Direct_declarator) = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        (yyval.tree_Direct_declarator) -> direct_declarator = (yyvsp[(1) - (4)].tree_Direct_declarator);
        (yyval.tree_Direct_declarator) -> constant_expression = (yyvsp[(3) - (4)].tree_Constant_expression);
        (yyval.tree_Direct_declarator) -> kind = dir_dec_con_kind;
    }
    break;

  case 139:
#line 991 "ANSI.y"
    {
        (yyval.tree_Direct_declarator) = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        (yyval.tree_Direct_declarator) -> direct_declarator = (yyvsp[(1) - (3)].tree_Direct_declarator);
        (yyval.tree_Direct_declarator) -> kind = dir_dec_kind;
    }
    break;

  case 140:
#line 996 "ANSI.y"
    {
        (yyval.tree_Direct_declarator) = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        (yyval.tree_Direct_declarator) -> direct_declarator = (yyvsp[(1) - (4)].tree_Direct_declarator);
        (yyval.tree_Direct_declarator) -> parameter_type_list = (yyvsp[(3) - (4)].tree_Parameter_type_list);
        (yyval.tree_Direct_declarator) -> kind = dir_dec_par_kind;
    }
    break;

  case 141:
#line 1002 "ANSI.y"
    {
        (yyval.tree_Direct_declarator) = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        (yyval.tree_Direct_declarator) -> direct_declarator = (yyvsp[(1) - (4)].tree_Direct_declarator);
        (yyval.tree_Direct_declarator) -> identifier_list = (yyvsp[(3) - (4)].tree_Identifier_list);
        (yyval.tree_Direct_declarator) -> kind = dir_dec_ide;
    }
    break;

  case 142:
#line 1008 "ANSI.y"
    {
        (yyval.tree_Direct_declarator) = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        (yyval.tree_Direct_declarator) -> direct_declarator = (yyvsp[(1) - (3)].tree_Direct_declarator);
        (yyval.tree_Direct_declarator) -> kind = dir_dec_kind2;
    }
    break;

  case 143:
#line 1016 "ANSI.y"
    {
        (yyval.tree_Pointer) = (struct Pointer*) malloc(sizeof(struct Pointer));
        (yyval.tree_Pointer) -> kind = P_kind;
    }
    break;

  case 144:
#line 1020 "ANSI.y"
    {
        (yyval.tree_Pointer) = (struct Pointer*) malloc(sizeof(struct Pointer));
        (yyval.tree_Pointer) -> type_qualifier_list = (yyvsp[(2) - (2)].tree_Type_qualifier_list);
        (yyval.tree_Pointer) -> kind = P_type_kind;
    }
    break;

  case 145:
#line 1025 "ANSI.y"
    {
        (yyval.tree_Pointer) = (struct Pointer*) malloc(sizeof(struct Pointer));
        (yyval.tree_Pointer) -> pointer = (yyvsp[(2) - (2)].tree_Pointer);
        (yyval.tree_Pointer) -> kind = P_pointer_kind;
    }
    break;

  case 146:
#line 1030 "ANSI.y"
    {
        (yyval.tree_Pointer) = (struct Pointer*) malloc(sizeof(struct Pointer));
        (yyval.tree_Pointer) -> type_qualifier_list = (yyvsp[(2) - (3)].tree_Type_qualifier_list);
        (yyval.tree_Pointer) -> pointer = (yyvsp[(3) - (3)].tree_Pointer);
        (yyval.tree_Pointer) -> kind = P_type_pointer_kind;
    }
    break;

  case 147:
#line 1039 "ANSI.y"
    {
        (yyval.tree_Type_qualifier_list) = (struct Type_qualifier_list*) malloc(sizeof(struct Type_qualifier_list));
        (yyval.tree_Type_qualifier_list) -> type_qualifier = (yyvsp[(1) - (1)].tree_Type_qualifier);
        (yyval.tree_Type_qualifier_list) -> kind = type_qualifier_kind2;
    }
    break;

  case 148:
#line 1044 "ANSI.y"
    {
        (yyval.tree_Type_qualifier_list) = (struct Type_qualifier_list*) malloc(sizeof(struct Type_qualifier_list));
        (yyval.tree_Type_qualifier_list) -> type_qualifier_list = (yyvsp[(1) - (2)].tree_Type_qualifier_list);
        (yyval.tree_Type_qualifier_list) -> type_qualifier = (yyvsp[(2) - (2)].tree_Type_qualifier);
        (yyval.tree_Type_qualifier_list) -> kind = type_qualifier_list_kind;
    }
    break;

  case 149:
#line 1053 "ANSI.y"
    {
        (yyval.tree_Parameter_type_list) = (struct Parameter_type_list*) malloc(sizeof(struct Parameter_type_list));
        (yyval.tree_Parameter_type_list) -> parameter_list = (yyvsp[(1) - (1)].tree_Parameter_list);
        (yyval.tree_Parameter_type_list) -> kind = parameter_list_kind;
    }
    break;

  case 150:
#line 1058 "ANSI.y"
    {
        (yyval.tree_Parameter_type_list) = (struct Parameter_type_list*) malloc(sizeof(struct Parameter_type_list));
        (yyval.tree_Parameter_type_list) -> parameter_list = (yyvsp[(1) - (3)].tree_Parameter_list);
        (yyval.tree_Parameter_type_list) -> kind = parameter_list_ELL_kind;
    }
    break;

  case 151:
#line 1066 "ANSI.y"
    {
        (yyval.tree_Parameter_list) = (struct Parameter_list*) malloc(sizeof(struct Parameter_list));
        (yyval.tree_Parameter_list) -> parameter_declaration = (yyvsp[(1) - (1)].tree_Parameter_declaration);
        (yyval.tree_Parameter_list) -> kind = parameter_declaration_kind;
    }
    break;

  case 152:
#line 1071 "ANSI.y"
    {
        (yyval.tree_Parameter_list) = (struct Parameter_list*) malloc(sizeof(struct Parameter_list));
        (yyval.tree_Parameter_list) -> parameter_list = (yyvsp[(1) - (3)].tree_Parameter_list);
        (yyval.tree_Parameter_list) -> parameter_declaration = (yyvsp[(3) - (3)].tree_Parameter_declaration);
        (yyval.tree_Parameter_list) -> kind = parameter_list_kind2;
    }
    break;

  case 153:
#line 1079 "ANSI.y"
    {
        (yyval.tree_Parameter_declaration) = (struct Parameter_declaration*) malloc(sizeof(struct Parameter_declaration));
        (yyval.tree_Parameter_declaration) -> declaration_specifiers = (yyvsp[(1) - (2)].tree_Declaration_specifiers);
        (yyval.tree_Parameter_declaration) -> declarator = (yyvsp[(2) - (2)].tree_Declarator);
        (yyval.tree_Parameter_declaration) -> kind = dec_dec_kind;
    }
    break;

  case 154:
#line 1085 "ANSI.y"
    {
        (yyval.tree_Parameter_declaration) = (struct Parameter_declaration*) malloc(sizeof(struct Parameter_declaration));
        (yyval.tree_Parameter_declaration) -> declaration_specifiers = (yyvsp[(1) - (2)].tree_Declaration_specifiers);
        (yyval.tree_Parameter_declaration) -> abstract_declarator = (yyvsp[(2) - (2)].tree_Abstract_declarator);
        (yyval.tree_Parameter_declaration) -> kind = dec_abs_kind;
    }
    break;

  case 155:
#line 1091 "ANSI.y"
    {
        (yyval.tree_Parameter_declaration) = (struct Parameter_declaration*) malloc(sizeof(struct Parameter_declaration));
        (yyval.tree_Parameter_declaration) -> declaration_specifiers = (yyvsp[(1) - (1)].tree_Declaration_specifiers);
        (yyval.tree_Parameter_declaration) -> kind = dec_kind2;
    }
    break;

  case 156:
#line 1099 "ANSI.y"
    {
        (yyval.tree_Identifier_list) = (struct Identifier_list*) malloc(sizeof(struct Identifier_list));
        (yyval.tree_Identifier_list) -> str_ID = (yyvsp[(1) - (1)].str_ID);
        (yyval.tree_Identifier_list) -> kind = ID_kind_in_identifier_list;
    }
    break;

  case 157:
#line 1104 "ANSI.y"
    {
        (yyval.tree_Identifier_list) = (struct Identifier_list*) malloc(sizeof(struct Identifier_list));
        (yyval.tree_Identifier_list) -> identifier_list = (yyvsp[(1) - (3)].tree_Identifier_list);
        (yyval.tree_Identifier_list) -> str_ID = (yyvsp[(3) - (3)].str_ID);
        (yyval.tree_Identifier_list) -> kind = identifier_list_ID_in_identifier_list;
    }
    break;

  case 158:
#line 1113 "ANSI.y"
    {
        (yyval.tree_Type_name) = (struct Type_name*) malloc(sizeof(struct Type_name));
        (yyval.tree_Type_name) -> specifier_qualifier_list = (yyvsp[(1) - (1)].tree_Specifier_qualifier_list);
        (yyval.tree_Type_name) -> kind = spe_kind;
    }
    break;

  case 159:
#line 1118 "ANSI.y"
    {
        (yyval.tree_Type_name) = (struct Type_name*) malloc(sizeof(struct Type_name));
        (yyval.tree_Type_name) -> specifier_qualifier_list = (yyvsp[(1) - (2)].tree_Specifier_qualifier_list);
        (yyval.tree_Type_name) -> abstract_declarator = (yyvsp[(2) - (2)].tree_Abstract_declarator);
        (yyval.tree_Type_name) -> kind = spe_abs_kind;
    }
    break;

  case 160:
#line 1127 "ANSI.y"
    {
        (yyval.tree_Abstract_declarator) = (struct Abstract_declarator*) malloc(sizeof(struct Abstract_declarator));
        (yyval.tree_Abstract_declarator) -> pointer = (yyvsp[(1) - (1)].tree_Pointer);
        (yyval.tree_Abstract_declarator) -> kind = poi_kind_in_abs; 
    }
    break;

  case 161:
#line 1132 "ANSI.y"
    {
        (yyval.tree_Abstract_declarator) = (struct Abstract_declarator*) malloc(sizeof(struct Abstract_declarator));
        (yyval.tree_Abstract_declarator) -> direct_abstract_declarator = (yyvsp[(1) - (1)].tree_Direct_abstract_declarator);
        (yyval.tree_Abstract_declarator) -> kind = dir_kind_in_abs;
    }
    break;

  case 162:
#line 1137 "ANSI.y"
    {
        (yyval.tree_Abstract_declarator) = (struct Abstract_declarator*) malloc(sizeof(struct Abstract_declarator));
        (yyval.tree_Abstract_declarator) -> pointer = (yyvsp[(1) - (2)].tree_Pointer);
        (yyval.tree_Abstract_declarator) -> direct_abstract_declarator = (yyvsp[(2) - (2)].tree_Direct_abstract_declarator);
        (yyval.tree_Abstract_declarator) -> kind = poi_dir_kind_in_abs;
    }
    break;

  case 163:
#line 1146 "ANSI.y"
    {
        (yyval.tree_Direct_abstract_declarator) = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        (yyval.tree_Direct_abstract_declarator) -> abstract_declarator = (yyvsp[(2) - (3)].tree_Abstract_declarator);
        (yyval.tree_Direct_abstract_declarator) -> kind = abs_kind;
    }
    break;

  case 164:
#line 1151 "ANSI.y"
    {
        (yyval.tree_Direct_abstract_declarator) = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        (yyval.tree_Direct_abstract_declarator) -> kind = NOT_kind;
    }
    break;

  case 165:
#line 1155 "ANSI.y"
    {
        (yyval.tree_Direct_abstract_declarator) = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        (yyval.tree_Direct_abstract_declarator) -> constant_expression = (yyvsp[(2) - (3)].tree_Constant_expression);
        (yyval.tree_Direct_abstract_declarator) -> kind = constant_expression_kind;
    }
    break;

  case 166:
#line 1160 "ANSI.y"
    {
        (yyval.tree_Direct_abstract_declarator) = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        (yyval.tree_Direct_abstract_declarator) -> direct_abstract_declarator = (yyvsp[(1) - (3)].tree_Direct_abstract_declarator);
        (yyval.tree_Direct_abstract_declarator) -> kind = dir_NOT_kind;
    }
    break;

  case 167:
#line 1165 "ANSI.y"
    {
        (yyval.tree_Direct_abstract_declarator) = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        (yyval.tree_Direct_abstract_declarator) -> direct_abstract_declarator = (yyvsp[(1) - (4)].tree_Direct_abstract_declarator);
        (yyval.tree_Direct_abstract_declarator) -> constant_expression = (yyvsp[(3) - (4)].tree_Constant_expression);
        (yyval.tree_Direct_abstract_declarator) -> kind = dir_con_kind;
    }
    break;

  case 168:
#line 1171 "ANSI.y"
    {
        (yyval.tree_Direct_abstract_declarator) = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        (yyval.tree_Direct_abstract_declarator) -> kind = NOT_kind2;
    }
    break;

  case 169:
#line 1175 "ANSI.y"
    {
        (yyval.tree_Direct_abstract_declarator) = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        (yyval.tree_Direct_abstract_declarator) -> parameter_type_list = (yyvsp[(2) - (3)].tree_Parameter_type_list);
        (yyval.tree_Direct_abstract_declarator) -> kind = par_kind;
    }
    break;

  case 170:
#line 1180 "ANSI.y"
    {
        (yyval.tree_Direct_abstract_declarator) = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        (yyval.tree_Direct_abstract_declarator) -> direct_abstract_declarator = (yyvsp[(1) - (3)].tree_Direct_abstract_declarator);
        (yyval.tree_Direct_abstract_declarator) -> kind = dir_NOT_kind3;
    }
    break;

  case 171:
#line 1185 "ANSI.y"
    {
        (yyval.tree_Direct_abstract_declarator) = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        (yyval.tree_Direct_abstract_declarator) -> direct_abstract_declarator = (yyvsp[(1) - (4)].tree_Direct_abstract_declarator);
        (yyval.tree_Direct_abstract_declarator) -> parameter_type_list = (yyvsp[(3) - (4)].tree_Parameter_type_list);
        (yyval.tree_Direct_abstract_declarator) -> kind = dir_par_kind;
    }
    break;

  case 172:
#line 1194 "ANSI.y"
    {
        (yyval.tree_Initializer) = (struct Initializer*) malloc(sizeof(struct Initializer));
        (yyval.tree_Initializer) -> assignment_expression = (yyvsp[(1) - (1)].tree_Assignment_expression);
        (yyval.tree_Initializer) -> kind = ass_exp_kind;
    }
    break;

  case 173:
#line 1199 "ANSI.y"
    {
        (yyval.tree_Initializer) = (struct Initializer*) malloc(sizeof(struct Initializer));
        (yyval.tree_Initializer) -> initializer_list = (yyvsp[(2) - (3)].tree_Initializer_list);
        (yyval.tree_Initializer) -> kind = ini_NOT;
    }
    break;

  case 174:
#line 1204 "ANSI.y"
    {
        (yyval.tree_Initializer) = (struct Initializer*) malloc(sizeof(struct Initializer));
        (yyval.tree_Initializer) -> initializer_list = (yyvsp[(2) - (4)].tree_Initializer_list);
        (yyval.tree_Initializer) -> kind = ini_KNM;
    }
    break;

  case 175:
#line 1212 "ANSI.y"
    {
        (yyval.tree_Initializer_list) = (struct Initializer_list*) malloc(sizeof(struct Initializer_list));
        (yyval.tree_Initializer_list) -> initializer = (yyvsp[(1) - (1)].tree_Initializer);
        (yyval.tree_Initializer_list) -> kind = ini_kind;
    }
    break;

  case 176:
#line 1217 "ANSI.y"
    {
        (yyval.tree_Initializer_list) = (struct Initializer_list*) malloc(sizeof(struct Initializer_list));
        (yyval.tree_Initializer_list) -> initializer_list = (yyvsp[(1) - (3)].tree_Initializer_list);
        (yyval.tree_Initializer_list) -> initializer = (yyvsp[(3) - (3)].tree_Initializer);
        (yyval.tree_Initializer_list) -> kind = ini_ini_kind;
    }
    break;

  case 177:
#line 1226 "ANSI.y"
    {
        (yyval.tree_Statement) = (struct Statement*) malloc(sizeof(struct Statement));
        (yyval.tree_Statement) -> labeled_statement = (yyvsp[(1) - (1)].tree_Labeled_statement);
        (yyval.tree_Statement) -> kind = label_kind;
    }
    break;

  case 178:
#line 1231 "ANSI.y"
    {
        (yyval.tree_Statement) = (struct Statement*) malloc(sizeof(struct Statement));
        (yyval.tree_Statement) -> compound_statement = (yyvsp[(1) - (1)].tree_Compound_statement);
        (yyval.tree_Statement) -> kind = compo_kind; 
    }
    break;

  case 179:
#line 1236 "ANSI.y"
    {
        (yyval.tree_Statement) = (struct Statement*) malloc(sizeof(struct Statement));
        (yyval.tree_Statement) -> expression_statement = (yyvsp[(1) - (1)].tree_Expression_statement);
        (yyval.tree_Statement) -> kind = expre_kind;
    }
    break;

  case 180:
#line 1241 "ANSI.y"
    {
        (yyval.tree_Statement) = (struct Statement*) malloc(sizeof(struct Statement));
        (yyval.tree_Statement) -> selection_statement = (yyvsp[(1) - (1)].tree_Selection_statement);
        (yyval.tree_Statement) -> kind = selec_kind;
    }
    break;

  case 181:
#line 1246 "ANSI.y"
    {
        (yyval.tree_Statement) = (struct Statement*) malloc(sizeof(struct Statement));
        (yyval.tree_Statement) -> iteration_statement = (yyvsp[(1) - (1)].tree_Iteration_statement);
        (yyval.tree_Statement) -> kind = itera_kind;
    }
    break;

  case 182:
#line 1251 "ANSI.y"
    {
        (yyval.tree_Statement) = (struct Statement*) malloc(sizeof(struct Statement));
        (yyval.tree_Statement) -> jump_statement = (yyvsp[(1) - (1)].tree_Jump_statement);
        (yyval.tree_Statement) -> kind = jump_kind;
    }
    break;

  case 183:
#line 1256 "ANSI.y"
    {
        (yyval.tree_Statement) = (struct Statement*) malloc(sizeof(struct Statement));
        (yyval.tree_Statement) -> declaration = (yyvsp[(1) - (1)].tree_Declaration);
        (yyval.tree_Statement) -> kind = decla_kind;
    }
    break;

  case 184:
#line 1264 "ANSI.y"
    {
        (yyval.tree_Labeled_statement) = (struct Labeled_statement*) malloc(sizeof(struct Labeled_statement));
        (yyval.tree_Labeled_statement) -> str_ID = (yyvsp[(1) - (3)].str_ID);
        (yyval.tree_Labeled_statement) -> statement = (yyvsp[(3) - (3)].tree_Statement);
        (yyval.tree_Labeled_statement) -> kind = ID_sta_kind;
    }
    break;

  case 185:
#line 1270 "ANSI.y"
    {
        (yyval.tree_Labeled_statement) = (struct Labeled_statement*) malloc(sizeof(struct Labeled_statement));
        (yyval.tree_Labeled_statement) -> constant_expression = (yyvsp[(2) - (4)].tree_Constant_expression);
        (yyval.tree_Labeled_statement) -> statement = (yyvsp[(4) - (4)].tree_Statement);
        (yyval.tree_Labeled_statement) -> kind = CASE_con_kind;
    }
    break;

  case 186:
#line 1276 "ANSI.y"
    {
        (yyval.tree_Labeled_statement) = (struct Labeled_statement*) malloc(sizeof(struct Labeled_statement));
        (yyval.tree_Labeled_statement) -> statement = (yyvsp[(3) - (3)].tree_Statement);
        (yyval.tree_Labeled_statement) -> kind = DEFAULT_sta_kind;
    }
    break;

  case 187:
#line 1284 "ANSI.y"
    {
        (yyval.tree_Compound_statement) = (struct Compound_statement*) malloc(sizeof(struct Compound_statement));
        (yyval.tree_Compound_statement) -> kind = NOT_kind3;
    }
    break;

  case 188:
#line 1288 "ANSI.y"
    {
        (yyval.tree_Compound_statement) = (struct Compound_statement*) malloc(sizeof(struct Compound_statement));
        (yyval.tree_Compound_statement) -> statement_list = (yyvsp[(2) - (3)].tree_Statement_list);
        (yyval.tree_Compound_statement) -> kind = statement_list_kind;
    }
    break;

  case 189:
#line 1298 "ANSI.y"
    {
        (yyval.tree_Declaration_list) = (struct Declaration_list*) malloc(sizeof(struct Declaration_list));
        (yyval.tree_Declaration_list) -> declaration = (yyvsp[(1) - (1)].tree_Declaration);
        (yyval.tree_Declaration_list) -> kind = declaration_kind;
    }
    break;

  case 190:
#line 1303 "ANSI.y"
    {
        (yyval.tree_Declaration_list) = (struct Declaration_list*) malloc(sizeof(struct Declaration_list));
        (yyval.tree_Declaration_list) -> declaration_list = (yyvsp[(1) - (2)].tree_Declaration_list);
        (yyval.tree_Declaration_list) -> declaration = (yyvsp[(2) - (2)].tree_Declaration);
        (yyval.tree_Declaration_list) -> kind = declaration_list_kind;
    }
    break;

  case 191:
#line 1312 "ANSI.y"
    {
        (yyval.tree_Statement_list) = (struct Statement_list*) malloc(sizeof(struct Statement_list));
        (yyval.tree_Statement_list) -> statement = (yyvsp[(1) - (1)].tree_Statement);
        (yyval.tree_Statement_list) -> kind = statement_kind;
    }
    break;

  case 192:
#line 1317 "ANSI.y"
    {
        (yyval.tree_Statement_list) = (struct Statement_list*) malloc(sizeof(struct Statement_list));
        (yyval.tree_Statement_list) -> statement_list = (yyvsp[(2) - (2)].tree_Statement_list);
        (yyval.tree_Statement_list) -> statement = (yyvsp[(1) - (2)].tree_Statement);
        (yyval.tree_Statement_list) -> kind = statement_list_kind2;
    }
    break;

  case 193:
#line 1327 "ANSI.y"
    {
        (yyval.tree_Expression_statement) = (struct Expression_statement*) malloc(sizeof(struct Expression_statement));
        (yyval.tree_Expression_statement) -> kind = SEMIC_kind;
    }
    break;

  case 194:
#line 1331 "ANSI.y"
    {
        (yyval.tree_Expression_statement) = (struct Expression_statement*) malloc(sizeof(struct Expression_statement));
        (yyval.tree_Expression_statement) -> expression = (yyvsp[(1) - (2)].tree_Expression);
        (yyval.tree_Expression_statement) -> kind = expression_SEMIC_kind;
    }
    break;

  case 195:
#line 1339 "ANSI.y"
    {
        (yyval.tree_Selection_statement) = (struct Selection_statement*) malloc(sizeof(struct Selection_statement));
        (yyval.tree_Selection_statement) -> expression = (yyvsp[(3) - (5)].tree_Expression);
        (yyval.tree_Selection_statement) -> statement = (yyvsp[(5) - (5)].tree_Statement);
        (yyval.tree_Selection_statement) -> kind = IF_expression_kind;
    }
    break;

  case 196:
#line 1345 "ANSI.y"
    {
        (yyval.tree_Selection_statement) = (struct Selection_statement*) malloc(sizeof(struct Selection_statement));
        (yyval.tree_Selection_statement) -> expression = (yyvsp[(3) - (7)].tree_Expression);
        (yyval.tree_Selection_statement) -> statement = (yyvsp[(5) - (7)].tree_Statement);
        (yyval.tree_Selection_statement) -> statement2 = (yyvsp[(7) - (7)].tree_Statement);
        (yyval.tree_Selection_statement) -> kind = IF_expression_ELSE_kind;
    }
    break;

  case 197:
#line 1352 "ANSI.y"
    {
        (yyval.tree_Selection_statement) = (struct Selection_statement*) malloc(sizeof(struct Selection_statement));
        (yyval.tree_Selection_statement) -> expression = (yyvsp[(3) - (5)].tree_Expression);
        (yyval.tree_Selection_statement) -> statement = (yyvsp[(5) - (5)].tree_Statement);
        (yyval.tree_Selection_statement) -> kind = SWITCH_kind;
    }
    break;

  case 198:
#line 1361 "ANSI.y"
    {
        (yyval.tree_Iteration_statement) = (struct Iteration_statement*) malloc(sizeof(struct Iteration_statement));
        (yyval.tree_Iteration_statement) -> expression = (yyvsp[(3) - (5)].tree_Expression);
        (yyval.tree_Iteration_statement) -> statement = (yyvsp[(5) - (5)].tree_Statement);
        (yyval.tree_Iteration_statement) -> kind = WHILE_kind;
    }
    break;

  case 199:
#line 1367 "ANSI.y"
    {
        (yyval.tree_Iteration_statement) = (struct Iteration_statement*) malloc(sizeof(struct Iteration_statement));
        (yyval.tree_Iteration_statement) -> statement = (yyvsp[(2) - (7)].tree_Statement);
        (yyval.tree_Iteration_statement) -> expression = (yyvsp[(5) - (7)].tree_Expression);
        (yyval.tree_Iteration_statement) -> kind = DO_kind;
    }
    break;

  case 200:
#line 1373 "ANSI.y"
    {
        (yyval.tree_Iteration_statement) = (struct Iteration_statement*) malloc(sizeof(struct Iteration_statement));
        (yyval.tree_Iteration_statement) -> expression_statement = (yyvsp[(3) - (6)].tree_Expression_statement);
        (yyval.tree_Iteration_statement) -> expression_statement2 = (yyvsp[(4) - (6)].tree_Expression_statement);
        (yyval.tree_Iteration_statement) -> statement = (yyvsp[(6) - (6)].tree_Statement);
        (yyval.tree_Iteration_statement) -> kind = FOR_two_kind;
    }
    break;

  case 201:
#line 1380 "ANSI.y"
    {
        (yyval.tree_Iteration_statement) = (struct Iteration_statement*) malloc(sizeof(struct Iteration_statement));
        (yyval.tree_Iteration_statement) -> expression_statement = (yyvsp[(3) - (7)].tree_Expression_statement);
        (yyval.tree_Iteration_statement) -> expression_statement2 = (yyvsp[(4) - (7)].tree_Expression_statement);
        (yyval.tree_Iteration_statement) -> expression = (yyvsp[(5) - (7)].tree_Expression);
        (yyval.tree_Iteration_statement) -> statement = (yyvsp[(7) - (7)].tree_Statement);
        (yyval.tree_Iteration_statement) -> kind = FOR_three_kind;
    }
    break;

  case 202:
#line 1391 "ANSI.y"
    {
        (yyval.tree_Jump_statement) = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        (yyval.tree_Jump_statement) -> str_ID = (yyvsp[(2) - (3)].str_ID);
        (yyval.tree_Jump_statement) -> kind = GOTO_kind;
    }
    break;

  case 203:
#line 1396 "ANSI.y"
    {
        (yyval.tree_Jump_statement) = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        (yyval.tree_Jump_statement) -> kind = CONTINUE_kind;
    }
    break;

  case 204:
#line 1400 "ANSI.y"
    {
        (yyval.tree_Jump_statement) = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        (yyval.tree_Jump_statement) -> kind = BREAK_kind;
    }
    break;

  case 205:
#line 1404 "ANSI.y"
    {
        (yyval.tree_Jump_statement) = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        (yyval.tree_Jump_statement) -> kind = RETURN_kind;
    }
    break;

  case 206:
#line 1408 "ANSI.y"
    {
        (yyval.tree_Jump_statement) = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        (yyval.tree_Jump_statement) -> expression = (yyvsp[(2) - (3)].tree_Expression);
        (yyval.tree_Jump_statement) -> kind = RETURN_expression_kind;
    }
    break;

  case 207:
#line 1416 "ANSI.y"
    {
        (yyval.tree_Translation_unit) = (struct Translation_unit*) malloc(sizeof(struct Translation_unit));
        (yyval.tree_Translation_unit) -> external_declaration = (yyvsp[(1) - (1)].tree_External_declaration);
        (yyval.tree_Translation_unit) -> kind = external_declaration_kind;
        tree_Translation_unit = (yyval.tree_Translation_unit);
    }
    break;

  case 208:
#line 1422 "ANSI.y"
    {
        (yyval.tree_Translation_unit) = (struct Translation_unit*) malloc(sizeof(struct Translation_unit));
        (yyval.tree_Translation_unit) -> translation_unit = (yyvsp[(1) - (2)].tree_Translation_unit);
        (yyval.tree_Translation_unit) -> external_declaration = (yyvsp[(2) - (2)].tree_External_declaration);
        (yyval.tree_Translation_unit) -> kind = translation_unit_kind;
        tree_Translation_unit = (yyval.tree_Translation_unit);
    }
    break;

  case 209:
#line 1432 "ANSI.y"
    {
        (yyval.tree_External_declaration) = (struct External_declaration*) malloc(sizeof(struct External_declaration));
        (yyval.tree_External_declaration) -> function_definition = (yyvsp[(1) - (1)].tree_Function_definition);
        (yyval.tree_External_declaration) -> kind = function_definition_kind;
    }
    break;

  case 210:
#line 1437 "ANSI.y"
    {
        (yyval.tree_External_declaration) = (struct External_declaration*) malloc(sizeof(struct External_declaration));
        (yyval.tree_External_declaration) -> declaration = (yyvsp[(1) - (1)].tree_Declaration);
        (yyval.tree_External_declaration) -> kind = declaration_kind_in_external_declaration;
    }
    break;

  case 211:
#line 1445 "ANSI.y"
    {
        (yyval.tree_Function_definition) = (struct Function_definition*) malloc(sizeof(struct Function_definition));
        (yyval.tree_Function_definition) -> declaration_specifiers = (yyvsp[(1) - (4)].tree_Declaration_specifiers);
        (yyval.tree_Function_definition) -> declarator = (yyvsp[(2) - (4)].tree_Declarator);
        (yyval.tree_Function_definition) -> declaration_list = (yyvsp[(3) - (4)].tree_Declaration_list);
        (yyval.tree_Function_definition) -> compound_statement = (yyvsp[(4) - (4)].tree_Compound_statement);
        (yyval.tree_Function_definition) -> kind = dec_dec_dec_kind;
    }
    break;

  case 212:
#line 1453 "ANSI.y"
    {
        (yyval.tree_Function_definition) = (struct Function_definition*) malloc(sizeof(struct Function_definition));
        (yyval.tree_Function_definition) -> declaration_specifiers = (yyvsp[(1) - (3)].tree_Declaration_specifiers);
        (yyval.tree_Function_definition) -> declarator = (yyvsp[(2) - (3)].tree_Declarator);
        (yyval.tree_Function_definition) -> compound_statement = (yyvsp[(3) - (3)].tree_Compound_statement);
        (yyval.tree_Function_definition) -> kind = dec_dec_com_kind;
    }
    break;

  case 213:
#line 1460 "ANSI.y"
    {
        (yyval.tree_Function_definition) = (struct Function_definition*) malloc(sizeof(struct Function_definition));
        (yyval.tree_Function_definition) -> declarator = (yyvsp[(1) - (3)].tree_Declarator);
        (yyval.tree_Function_definition) -> declaration_list = (yyvsp[(2) - (3)].tree_Declaration_list);
        (yyval.tree_Function_definition) -> compound_statement = (yyvsp[(3) - (3)].tree_Compound_statement);
        (yyval.tree_Function_definition) -> kind = declarator_dec_com_kind;
    }
    break;

  case 214:
#line 1467 "ANSI.y"
    {
        (yyval.tree_Function_definition) = (struct Function_definition*) malloc(sizeof(struct Function_definition));
        (yyval.tree_Function_definition) -> declarator = (yyvsp[(1) - (2)].tree_Declarator);
        (yyval.tree_Function_definition) -> compound_statement = (yyvsp[(2) - (2)].tree_Compound_statement);
        (yyval.tree_Function_definition) -> kind = declarator_com;
    }
    break;


/* Line 1267 of yacc.c.  */
#line 4012 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1476 "ANSI.y"


#include <stdio.h>
extern FILE *yyin;
#include <ctype.h>
extern char yytext[];
extern int column;

 

void yyerror(char *s )
{   

	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);


}

// メイン関数
int main(int argc, char *argv[]){  
    // for文ASTへのポインタを格納するためのリスト構造を作成している関数
#ifdef FOR_print
    ls = make_list();
#endif

#ifdef SYMBOL
    s_ls = make_symbol_list();
#endif

#ifdef BLOCK
    block_ls = make_basic_block_list();
#endif
    if(argv[1]!=NULL){
        yyin = fopen(argv[1], "r");
        if(yyparse()==0){
            printf("\nParsing complete\n");
            printf("コード出力開始\n");
            
//ソースコードをASTをたどって全て表示
                Sprint_Translation_unit(tree_Translation_unit);

//FOR文が出てくる文のポインタ集めてリストに格納する
#ifdef FOR_print
            // ASTをたどり、For構文が出てくるポインタを次々に格納する関数
            print_Translation_unit(tree_Translation_unit);
#endif
//シンボルテーブルの走査(ASTを辿りシンボルテーブルリストを作成する)
#ifdef SYMBOL  
            table_print_Translation_unit(tree_Translation_unit);
#endif
//基本ブロックの走査
#ifdef BLOCK  
            flow_Translation_unit(tree_Translation_unit);
#endif
        }
	    else
		    printf("\nParsing failed\n");
	    fclose(yyin);
    }else{
        printf("ready>>");
        yyparse();
    }
    
    // for文のみを出力
#ifdef FOR_print
    int i=0;
    Cell *cp = nth_cell(ls->top, 0);
    while(cp!=NULL){
        // statement列挙
        i++;    
        printf("\n\n%d個めのfor文\n\n",i);
        Sprint_Iteration_statement(cp->for_statement);
        
        Cell *temp = cp->next;
        cp = temp;
    }
    delete_list(ls);
#endif
    //  for文のみを出力 ここまで
    // シンボルテーブル
#ifdef SYMBOL
    int s=0;
    s_Cell *symbol_cp = nth_symbol_cell(s_ls->s_top, 0);
    // if(symbol_cp->type_ptr==NULL||symbol_cp==NULL){
    //    printf("先頭がNULLポインタ。\n");
    // }else{printf("ポインタは行っている\n");}
    // 
    while(symbol_cp!=NULL){
        s++;     
        printf("\n\n%d個めの変数定義文\n\n",s);
        // printf("ポインタmain=%p\n",symbol_cp->type_specifiers_ptr);
        Sprint_Type_specifier(symbol_cp->type_specifier_ptr);
        Sprint_Direct_declarator(symbol_cp->direct_declarator_ptr);
        // push(table_type_ptr, val_ptr);この関数でシンボルテーブル作りやってくれる
        s_Cell *symbol_temp = symbol_cp->symbol_next;
        symbol_cp = symbol_temp;
    }
    delete_symbol_list(s_ls);
    // Declaration_specifiers *type_ptr, struct Init_declarator_list *val_name_ptr
#endif
#ifdef BLOCK
    int b=0;
    b_block *block_cp = nth_basic_block_cell(block_ls->block_top, 0);
    while(block_cp!=NULL){
        // statement列挙
        b++;    
        printf("\n\n%d個めのstatement文---------------------------------------\n\n",b);
        printf("\nstart_st=\n");
        Sprint_Statement_list(block_cp->start);
        printf("\n---------------------------------------\nend_st=\n\n");
        Sprint_Statement_list(block_cp->end);
        b_block *temp_bl = block_cp->succ;
        block_cp = temp_bl;
        printf("---------------------------------------\n\n");
    }
    //delete_basic_block_list(block_ls);
#endif






    return 0;
}
