/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 245 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

