%{
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
%}
%union{
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
%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token MPFI MPFR GMPFI

%type <str_CONST> CONSTANT
%type <str_STR> STRING_LITERAL
%type <str_ID> IDENTIFIER

%type <tree_Primary_expression> primary_expression
%type <tree_Postfix_expression> postfix_expression
%type <tree_Argument_expression_list> argument_expression_list
%type <tree_Unary_expression> unary_expression
%type <tree_Unary_operator> unary_operator
%type <tree_Cast_expression> cast_expression
%type <tree_Multiplicative_expression> multiplicative_expression
%type <tree_Additive_expression> additive_expression
%type <tree_Shift_expression> shift_expression
%type <tree_Relational_expression> relational_expression 
%type <tree_Equality_expression> equality_expression
%type <tree_And_expression> and_expression
%type <tree_Exclusive_or_expression> exclusive_or_expression
%type <tree_Inclusive_or_expression> inclusive_or_expression
%type <treeLogical_and_expression> logical_and_expression
%type <tree_Logical_or_expression> logical_or_expression
%type <tree_Conditional_expression> conditional_expression
%type <tree_Assignment_expression> assignment_expression
%type <tree_Assignment_operator> assignment_operator
%type <tree_Expression> expression
%type <tree_Constant_expression> constant_expression
%type <tree_Declaration> declaration
%type <tree_Declaration_specifiers> declaration_specifiers
%type <tree_Init_declarator_list> init_declarator_list
%type <tree_Init_declarator> init_declarator
%type <tree_Storage_class_specifier> storage_class_specifier
%type <tree_Type_specifier> type_specifier
%type <tree_Struct_or_union_specifier> struct_or_union_specifier
%type <tree_Struct_or_union> struct_or_union
%type <tree_Struct_declaration_list> struct_declaration_list
%type <tree_Struct_declaration> struct_declaration
%type <tree_Specifier_qualifier_list> specifier_qualifier_list
%type <tree_Struct_declarator_list> struct_declarator_list
%type <tree_Struct_declarator> struct_declarator
%type <tree_Enum_specifier> enum_specifier
%type <tree_Enumerator_list> enumerator_list
%type <tree_Enumerator> enumerator
%type <tree_Type_qualifier> type_qualifier
%type <tree_Declarator> declarator
%type <tree_Direct_declarator> direct_declarator
%type <tree_Pointer> pointer
%type <tree_Type_qualifier_list> type_qualifier_list 
%type <tree_Parameter_type_list> parameter_type_list
%type <tree_Parameter_list> parameter_list
%type <tree_Parameter_declaration> parameter_declaration
%type <tree_Identifier_list> identifier_list
%type <tree_Type_name> type_name
%type <tree_Abstract_declarator> abstract_declarator
%type <tree_Direct_abstract_declarator> direct_abstract_declarator
%type <tree_Initializer> initializer
%type <tree_Initializer_list> initializer_list
%type <tree_Statement> statement
%type <tree_Labeled_statement> labeled_statement
%type <tree_Compound_statement> compound_statement
%type <tree_Declaration_list> declaration_list
%type <tree_Statement_list> statement_list
%type <tree_Expression_statement> expression_statement
%type <tree_Selection_statement> selection_statement
%type <tree_Iteration_statement> iteration_statement
%type <tree_Jump_statement> jump_statement
%type <tree_Translation_unit> translation_unit
%type <tree_External_declaration> external_declaration
%type <tree_Function_definition> function_definition



%start translation_unit
%%

primary_expression
	: IDENTIFIER {
        $$ = (struct Primary_expression*) malloc(sizeof(struct Primary_expression));
        $$ -> str_ID = $1;
        $$ -> kind = IDENTIFIER_kind;
    }
	| CONSTANT {
        $$ = (struct Primary_expression*) malloc(sizeof(struct Primary_expression));
        $$ -> str_CONST = $1;
        $$ -> kind = CONSTANT_kind;
    }
	| STRING_LITERAL {
        $$ = (struct Primary_expression*) malloc(sizeof(struct Primary_expression));
        $$ -> str_STR = $1;
        $$ -> kind = STRING_LITERAL_kind;
    }
	| '(' expression ')' {
        $$ = (struct Primary_expression*) malloc(sizeof(struct Primary_expression));
        $$ -> expression = $2;
        $$ -> kind = expression_kind;
    }
	;

postfix_expression
	: primary_expression {
        $$ = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        $$ -> primary_expression = $1;
        $$ -> kind = primary_expression_kind;
    }
	| postfix_expression '[' expression ']' {
        $$ = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        $$ -> postfix_expression = $1;
        $$ -> expression = $3;
        $$ -> kind = postfix_expression_expression_kind;
    }
	| postfix_expression '(' ')' {
        $$ = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        $$ -> postfix_expression = $1;
        $$ -> kind = postfix_expression_not_kind;
    }
	| postfix_expression '(' argument_expression_list ')' {
        $$ = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        $$ -> postfix_expression = $1;
        $$ -> argument_expression_list = $3;
        $$ -> kind = postfix_expression_argument_kind;
    }
	| postfix_expression '.' IDENTIFIER {
        $$ = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        $$ -> postfix_expression = $1;
        $$ -> str_ID = $3;
        $$ -> kind = postfix_expression_IDENTIFIER_kind;

    }
	| postfix_expression PTR_OP IDENTIFIER {
        $$ = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        $$ -> postfix_expression = $1;
        $$ -> str_ID = $3;
        $$ -> kind = postfix_expression_PTR;
    }
	| postfix_expression INC_OP {
        $$ = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        $$ -> postfix_expression = $1;
        $$ -> kind = postfix_expression_INC;
    }
	| postfix_expression DEC_OP {
        $$ = (struct Postfix_expression*) malloc(sizeof(struct Postfix_expression));
        $$ -> postfix_expression = $1;
        $$ -> kind = postfix_expression_DEC;
    }
	;

argument_expression_list
	: assignment_expression {
        $$ = (struct Argument_expression_list*) malloc(sizeof(struct Argument_expression_list));
        $$ -> assignment_expression = $1;
        $$ -> kind = assignment_expression_kind;
    }
	| argument_expression_list ',' assignment_expression {
        $$ = (struct Argument_expression_list*) malloc(sizeof(struct Argument_expression_list));
        $$ -> argument_expression_list = $1;
        $$ -> assignment_expression = $3;
        $$ -> kind = argument_expression_list_kind;
    }
	;

unary_expression
	: postfix_expression {
        $$ = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        $$ -> postfix_expression = $1;
        $$ -> kind = postfix_expression_kind;
    }
	| INC_OP unary_expression {
        $$ = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        $$ -> unary_expression = $2;
        $$ -> kind = INC_OP_kind;
    }
	| DEC_OP unary_expression {
        $$ = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        $$ -> unary_expression = $2;
        $$ -> kind = DEC_OP_kind;
    }
	| unary_operator cast_expression {
        $$ = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        $$ -> unary_operator = $1;
        $$ -> cast_expression = $2;
        $$ -> kind = unary_operator_kind;
    }
	| SIZEOF unary_expression {
        $$ = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        $$ -> unary_expression = $2;
        $$ -> kind = SIZEOF_unary_expression_kind;
    }
	| SIZEOF '(' type_name ')' {
        $$ = (struct Unary_expression*) malloc(sizeof(struct Unary_expression));
        $$ -> type_name = $3;
        $$ -> kind = SIZEOF_type_name_kind;
    }
	;

unary_operator
	: '&' {
        $$ = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        $$ -> kind = AND_kind;
    }
	| '*' {
        $$ = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        $$ -> kind = MUL_kind;
    }
	| '+' {
        $$ = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        $$ -> kind = ADD_kind;
    }
	| '-' {
        $$ = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        $$ -> kind = SUB_kind;
    }
	| '~' {
        $$ = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        $$ -> kind = NAMI_kind;
    }
	| '!' {
        $$ = (struct Unary_operator*) malloc(sizeof(struct Unary_operator));
        $$ -> kind = BIKKURI_kind;
    }
	;

cast_expression
	: unary_expression {
        $$ = (struct Cast_expression*) malloc(sizeof(struct Cast_expression));
        $$ -> unary_expression = $1;
        $$ -> kind = unary_expression_kind;
    }
	| '(' type_name ')' cast_expression {
        $$ = (struct Cast_expression*) malloc(sizeof(struct Cast_expression));
        $$ -> type_name = $2;
        $$ -> cast_expression = $4;
        $$ -> kind = type_name_kind;
    }
	;

multiplicative_expression
	: cast_expression {
        $$ = (struct Multiplicative_expression*) malloc(sizeof(struct Multiplicative_expression));
        $$ -> cast_expression = $1;
        $$ -> kind = cast_expression_kind;
    }
	| multiplicative_expression '*' cast_expression {
        $$ = (struct Multiplicative_expression*) malloc(sizeof(struct Multiplicative_expression));
        $$ -> multiplicative_expression = $1;
        $$ -> cast_expression = $3;
        $$ -> kind = MUL_expression_kind;
    }
	| multiplicative_expression '/' cast_expression {
        $$ = (struct Multiplicative_expression*) malloc(sizeof(struct Multiplicative_expression));
        $$ -> multiplicative_expression = $1;
        $$ -> cast_expression = $3;
        $$ -> kind = DIV_expression_kind;
    }
	| multiplicative_expression '%' cast_expression {
        $$ = (struct Multiplicative_expression*) malloc(sizeof(struct Multiplicative_expression));
        $$ -> multiplicative_expression = $1;
        $$ -> cast_expression = $3;
        $$ -> kind = PCT_expression_kind;
    }
	;

additive_expression
	: multiplicative_expression {
        $$ = (struct Additive_expression*) malloc(sizeof(struct Additive_expression));
        $$ -> multiplicative_expression = $1;
        $$ -> kind = multiplicative_expression_kind;
    }
	| additive_expression '+' multiplicative_expression {
        $$ = (struct Additive_expression*) malloc(sizeof(struct Additive_expression));
        $$ -> additive_expression = $1;
        $$ -> multiplicative_expression = $3;
        $$ -> kind = ADD_expression_kind;
    }
	| additive_expression '-' multiplicative_expression {
        $$ = (struct Additive_expression*) malloc(sizeof(struct Additive_expression));
        $$ -> additive_expression = $1;
        $$ -> multiplicative_expression = $3;
        $$ -> kind = SUB_expression_kind;
    }
	;

shift_expression
	: additive_expression {
        $$ = (struct Shift_expression*) malloc(sizeof(struct Shift_expression));
        $$ -> additive_expression = $1;
        $$ -> kind = additive_expression_kind;
    }
	| shift_expression LEFT_OP additive_expression {
        $$ = (struct Shift_expression*) malloc(sizeof(struct Shift_expression));
        $$ -> shift_expression = $1;
        $$ -> additive_expression = $3;
        $$ -> kind = shift_LEFT_OP_kind;
    }
	| shift_expression RIGHT_OP additive_expression {
        $$ = (struct Shift_expression*) malloc(sizeof(struct Shift_expression));
        $$ -> shift_expression = $1;
        $$ -> additive_expression = $3;
        $$ -> kind = shift_RIGHT_OP_kind;
    }
	;

relational_expression
	: shift_expression {
        $$ = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        $$ -> shift_expression = $1;
        $$ -> kind = shift_expression_kind;
    }
	| relational_expression '<' shift_expression {
        $$ = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        $$ -> relational_expression = $1;
        $$ -> shift_expression = $3;
        $$ -> kind = relat_sho;
    }
	| relational_expression '>' shift_expression {
        $$ = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        $$ -> relational_expression = $1;
        $$ -> shift_expression = $3;
        $$ -> kind = relat_dai;
    }
	| relational_expression LE_OP shift_expression {
        $$ = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        $$ -> relational_expression = $1;
        $$ -> shift_expression = $3;
        $$ -> kind = relat_LE_OP;
    }
	| relational_expression GE_OP shift_expression {
        $$ = (struct Relational_expression*) malloc(sizeof(struct Relational_expression));
        $$ -> relational_expression = $1;
        $$ -> shift_expression = $3;
        $$ -> kind = relat_GE;
    }
	;

equality_expression
	: relational_expression {
        $$ = (struct Equality_expression*) malloc(sizeof(struct Equality_expression));
        $$ -> relational_expression = $1;
        $$ -> kind = relational_expression_kind;
    }
	| equality_expression EQ_OP relational_expression {
        $$ = (struct Equality_expression*) malloc(sizeof(struct Equality_expression));
        $$ -> equality_expression = $1;
        $$ -> relational_expression = $3;
        $$ -> kind = eq_EQ_OP;
    }
	| equality_expression NE_OP relational_expression {
        $$ = (struct Equality_expression*) malloc(sizeof(struct Equality_expression));
        $$ -> equality_expression = $1;
        $$ -> relational_expression = $3;
        $$ -> kind = eq_NE_OP;
    }
	;

and_expression
	: equality_expression {
        $$ = (struct And_expression*) malloc(sizeof(struct And_expression));
        $$ -> equality_expression = $1;
        $$ -> kind = equality_expression_kind;
    }
	| and_expression '&' equality_expression {
        $$ = (struct And_expression*) malloc(sizeof(struct And_expression));
        $$ -> and_expression = $1;
        $$ -> equality_expression = $3;
        $$ -> kind = and_expression_kind;
    }
	;

exclusive_or_expression
	: and_expression {
        $$ = (struct Exclusive_or_expression*) malloc(sizeof(struct Exclusive_or_expression));
        $$ -> and_expression = $1;
        $$ -> kind = and_expression_kind2;
    }
	| exclusive_or_expression '^' and_expression {
        $$ = (struct Exclusive_or_expression*) malloc(sizeof(struct Exclusive_or_expression));
        $$ -> exclusive_or_expression = $1;
        $$ -> and_expression = $3;
        $$ -> kind = exclusive_or_expression_kind;
    }
	;

inclusive_or_expression 
	: exclusive_or_expression {
        $$ = (struct Inclusive_or_expression*) malloc(sizeof(struct Inclusive_or_expression));
        $$ -> exclusive_or_expression = $1;
        $$ -> kind = exclusive_or_expression_kind2;
    }
	| inclusive_or_expression '|' exclusive_or_expression {
        $$ = (struct Inclusive_or_expression*) malloc(sizeof(struct Inclusive_or_expression));
        $$ -> inclusive_or_expression = $1;
        $$ -> exclusive_or_expression = $3;
        $$ -> kind = inclusive_or_expression_kind;
    }
	;

logical_and_expression
	: inclusive_or_expression {
        $$ = (struct Logical_and_expression*) malloc(sizeof(struct Logical_and_expression));
        $$ -> inclusive_or_expression = $1;
        $$ -> kind = inclusive_or_expression_kind2;
    }
	| logical_and_expression AND_OP inclusive_or_expression {
        $$ = (struct Logical_and_expression*) malloc(sizeof(struct Logical_and_expression));
        $$ -> logical_and_expression = $1;
        $$ -> inclusive_or_expression = $3;
        $$ -> kind = logical_and_expression_kind;
    }
	;

logical_or_expression
	: logical_and_expression {
        $$ = (struct Logical_or_expression*) malloc(sizeof(struct Logical_or_expression));
        $$ -> logical_and_expression = $1;
        $$ -> kind = logical_and_expression_kind2;
    }
	| logical_or_expression OR_OP logical_and_expression {
        $$ = (struct Logical_or_expression*) malloc(sizeof(struct Logical_or_expression));
        $$ -> logical_or_expression = $1;
        $$ -> logical_and_expression = $3;
        $$ -> kind = logical_or_expression_kind;
    }
	;

conditional_expression
	: logical_or_expression {
        $$ = (struct Conditional_expression*) malloc(sizeof(struct Conditional_expression));
        $$ -> logical_or_expression = $1;
        $$ -> kind = logical_or_expression_kind2;
    }
	| logical_or_expression '?' expression ':' conditional_expression {
        $$ = (struct Conditional_expression*) malloc(sizeof(struct Conditional_expression));
        $$ -> logical_or_expression = $1;
        $$ -> expression = $3;
        $$ -> conditional_expression = $5;
        $$ -> kind = logical_or_expression_expression_kind;
    }
	;

assignment_expression
	: conditional_expression {
        $$ = (struct Assignment_expression*) malloc(sizeof(struct Assignment_expression));
        $$ -> conditional_expression = $1;
        $$ -> kind = conditional_expression_kind2;
    }
	| unary_expression assignment_operator assignment_expression {
        $$ = (struct Assignment_expression*) malloc(sizeof(struct Assignment_expression));
        $$ -> unary_expression = $1;
        $$ -> assignment_operator = $2;
        $$ -> assignment_expression = $3;
        $$ -> kind = unary_expression_kind2;
    }
	;

assignment_operator
	: '=' {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = EQUAL_kind;
    }
	| MUL_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = MUL_ASSIGN_kind;
    }
	| DIV_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = DIV_ASSIGN_kind;
    }
	| MOD_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = MOD_ASSIGN_kind;
    }
	| ADD_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = ADD_ASSIGN_kind;
    }
	| SUB_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = SUB_ASSIGN_kind;
    }
	| LEFT_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = LEFT_ASSIGN;
    }
	| RIGHT_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = RIGHT_ASSIGN_kind;
    }
	| AND_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = AND_ASSIGN_kind;
    }
	| XOR_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = XOR_ASSIGN_kind;
    }
	| OR_ASSIGN {
        $$ = (struct Assignment_operator*) malloc(sizeof(struct Assignment_operator));
        $$ -> kind = OR_ASSIGN_kind;
    }
	;

expression
	: assignment_expression {
        $$ = (struct Expression*) malloc(sizeof(struct Expression));
        $$ -> assignment_expression = $1;
        $$ -> kind = assignment_expression_kind2;
    }
	| expression ',' assignment_expression {
        $$ = (struct Expression*) malloc(sizeof(struct Expression));
        $$ -> expression = $1;
        $$ -> assignment_expression = $3;
        $$ -> kind = expression_kind2;
    }
	;

constant_expression
	: conditional_expression {
        $$ = (struct Constant_expression*) malloc(sizeof(struct Constant_expression));
        $$ -> conditional_expression = $1;
        $$ -> kind = conditional_expression_kind3;
    }
	;

declaration
	: declaration_specifiers ';' {
        $$ = (struct Declaration*) malloc(sizeof(struct Declaration));
        $$ -> declaration_specifiers = $1;
        $$ -> kind = dec_spe_kind;
    }
	| declaration_specifiers init_declarator_list ';' {
        $$ = (struct Declaration*) malloc(sizeof(struct Declaration));
        $$ -> declaration_specifiers = $1;
        $$ -> init_declarator_list = $2;
        $$ -> kind = dec_spe_ini_kind;
    }
	;

declaration_specifiers
	: storage_class_specifier {
        $$ = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        $$ -> storage_class_specifier = $1;
        $$ -> kind = storage_class_specifier_kind;
    }
	| storage_class_specifier declaration_specifiers {
        $$ = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        $$ -> storage_class_specifier = $1;
        $$ -> declaration_specifiers = $2;
        $$ -> kind = storage_class_specifier_declaration_kind;
    }
	| type_specifier {
        $$ = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        $$ -> type_specifier = $1;
        $$ -> kind = type_specifier_kind;
    }
	| type_specifier declaration_specifiers {
        $$ = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        $$ -> type_specifier = $1;
        $$ -> declaration_specifiers = $2;
        $$ -> kind = type_specifier_declaration_kind;
    }
	| type_qualifier {
        $$ = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        $$ -> type_qualifier = $1;
        $$ -> kind = type_qualifier_kind;
    }
	| type_qualifier declaration_specifiers {
        $$ = (struct Declaration_specifiers*) malloc(sizeof(struct Declaration_specifiers));
        $$ -> type_qualifier = $1;
        $$ -> declaration_specifiers = $2;
        $$ -> kind = type_qualifier_declaration_kind;
    }
	;

init_declarator_list
	: init_declarator {
        $$ = (struct Init_declarator_list*) malloc(sizeof(struct Init_declarator_list));
        $$ -> init_declarator = $1;
        $$ -> kind = init_declarator_kind;
    }
	| init_declarator_list ',' init_declarator {
        $$ = (struct Init_declarator_list*) malloc(sizeof(struct Init_declarator_list));
        $$ -> init_declarator_list = $1;
        $$ -> init_declarator = $3;
        $$ -> kind = init_declarator_list_kind;
    }
	;

init_declarator
	: declarator {
        $$ = (struct Init_declarator*) malloc(sizeof(struct Init_declarator));
        $$ -> declarator = $1;
        $$ -> kind = declarator_kind;
    }
	| declarator '=' initializer {
        $$ = (struct Init_declarator*) malloc(sizeof(struct Init_declarator));
        $$ -> declarator = $1;
        $$ -> initializer = $3;
        $$ -> kind = declarator_EQUAL_kind;
    }
	;

storage_class_specifier
	: TYPEDEF {
        $$ = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        $$ -> kind = TYPEDEF_kind;
    }
	| EXTERN {
        $$ = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        $$ -> kind = EXTERN_kind;
    }
	| STATIC {
        $$ = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        $$ -> kind = STATIC_kind;
    }
	| AUTO {
        $$ = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        $$ -> kind = AUTO_kind;
    }
	| REGISTER {
        $$ = (struct Storage_class_specifier*) malloc(sizeof(struct Storage_class_specifier));
        $$ -> kind = REGISTER_kind;
    }
	;

type_specifier
	: VOID {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = VOID_kind;
    }
	| CHAR {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = CHAR_kind;
    }
	| SHORT {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = SHORT_kind;
    }
	| INT {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = INT_kind;
    }
	| LONG {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = LONG_kind;
    }
	| FLOAT {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = FLOAT_kind;
    }
	| DOUBLE {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = DOUBLE_kind;
    }
	| SIGNED {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = SIGNED_kind;
    }
	| UNSIGNED {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = UNSIGNED_kind;
    }
	| struct_or_union_specifier {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> struct_or_union_specifier = $1;
        $$ -> kind = struct_or_union_specifier_kind;
    }
	| enum_specifier {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> enum_specifier = $1;
        $$ -> kind = enum_specifier_kind;
    }
	| TYPE_NAME {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = TYPE_NAME_kind;
    }
    | MPFI {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = MPFI_kind;
    }
    | GMPFI {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = GMPFI_kind;
    }
    | MPFR {
        $$ = (struct Type_specifier*) malloc(sizeof(struct Type_specifier));
        $$ -> kind = MPFR_kind;
    }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}' {
        $$ = (struct Struct_or_union_specifier*) malloc(sizeof(struct Struct_or_union_specifier));
        $$ -> struct_or_union = $1;
        $$ -> str_ID = $2;
        $$ -> struct_declaration_list = $4;
        $$ -> kind = struct_ID_struct_kind;
    }
	| struct_or_union '{' struct_declaration_list '}' {
        $$ = (struct Struct_or_union_specifier*) malloc(sizeof(struct Struct_or_union_specifier));
        $$ -> struct_or_union = $1;
        $$ -> struct_declaration_list = $3;
        $$ -> kind = struct_struct;
    }
	| struct_or_union IDENTIFIER {
        $$ = (struct Struct_or_union_specifier*) malloc(sizeof(struct Struct_or_union_specifier));
        $$ -> struct_or_union = $1;
        $$ -> str_ID = $2;
        $$ -> kind = struct_ID;
    }
	;

struct_or_union
	: STRUCT {
        $$ = (struct Struct_or_union*) malloc(sizeof(struct Struct_or_union));
        $$ -> kind = STRUCT_kind;
    }
	| UNION {
        $$ = (struct Struct_or_union*) malloc(sizeof(struct Struct_or_union));
        $$ -> kind = UNION_kind;
    }
	;

struct_declaration_list
	: struct_declaration {
        $$ = (struct Struct_declaration_list*) malloc(sizeof(struct Struct_declaration_list));
        $$ -> struct_declaration = $1;
        $$ -> kind = struct_declaration_kind;
    }
	| struct_declaration_list struct_declaration {
        $$ = (struct Struct_declaration_list*) malloc(sizeof(struct Struct_declaration_list));
        $$ -> struct_declaration_list = $1;
        $$ -> struct_declaration = $2;
        $$ -> kind = struct_declaration_list_kind;
    }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {
        $$ = (struct Struct_declaration*) malloc(sizeof(struct Struct_declaration));
        $$ -> specifier_qualifier_list = $1;
        $$ -> struct_declarator_list = $2;
        $$ -> kind = specifier_qualifier_list_kind;
    }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {
        $$ = (struct Specifier_qualifier_list*) malloc(sizeof(struct Specifier_qualifier_list));
        $$ -> type_specifier = $1;
        $$ -> specifier_qualifier_list = $2;
        $$ -> kind = type_spe_spe_kind;
    }
	| type_specifier {
        $$ = (struct Specifier_qualifier_list*) malloc(sizeof(struct Specifier_qualifier_list));
        $$ -> type_specifier = $1;
        $$ -> kind = type_spe_kind;
    }
	| type_qualifier specifier_qualifier_list {
        $$ = (struct Specifier_qualifier_list*) malloc(sizeof(struct Specifier_qualifier_list));
        $$ -> type_qualifier = $1;
        $$ -> specifier_qualifier_list = $2;
        $$ -> kind = type_qua_spe_kind;
    }
	| type_qualifier {
        $$ = (struct Specifier_qualifier_list*) malloc(sizeof(struct Specifier_qualifier_list));
        $$ -> type_qualifier = $1;
        $$ -> kind = type_qua_kind;
    }
	;

struct_declarator_list
	: struct_declarator {
        $$ = (struct Struct_declarator_list*) malloc(sizeof(struct Struct_declarator_list));
        $$ -> struct_declarator = $1;
        $$ -> kind = struct_declarator_kind;
    }
	| struct_declarator_list ',' struct_declarator { 
        $$ = (struct Struct_declarator_list*) malloc(sizeof(struct Struct_declarator_list));
        $$ -> struct_declarator_list = $1;
        $$ -> struct_declarator = $3;
        $$ -> kind = struct_declarator_list_kind;
    }
	;

struct_declarator
	: declarator {
        $$ = (struct Struct_declarator*) malloc(sizeof(struct Struct_declarator));
        $$ -> declarator = $1;
        $$ -> kind = dec_kind;
    }
	| ':' constant_expression {
        $$ = (struct Struct_declarator*) malloc(sizeof(struct Struct_declarator));
        $$ -> constant_expression = $2;
        $$ -> kind = con_kind;
    }
	| declarator ':' constant_expression {
        $$ = (struct Struct_declarator*) malloc(sizeof(struct Struct_declarator));
        $$ -> declarator = $1;
        $$ -> constant_expression = $3;
        $$ -> kind = dec_con_kind;
    }
	;

enum_specifier
	: ENUM '{' enumerator_list '}' {
        $$ = (struct Enum_specifier*) malloc(sizeof(struct Enum_specifier));
        $$ -> enumerator_list = $3;
        $$ -> kind = ENUM_enu_kind;
    }
	| ENUM IDENTIFIER '{' enumerator_list '}' {
        $$ = (struct Enum_specifier*) malloc(sizeof(struct Enum_specifier));
        $$ -> str_ID = $2;
        $$ -> enumerator_list = $4;
        $$ -> kind = ENUM_ID_enu_kind;
    }
	| ENUM IDENTIFIER {
        $$ = (struct Enum_specifier*) malloc(sizeof(struct Enum_specifier));
        $$ -> str_ID = $2;
        $$ -> kind = ENUM_ID_kind;
    }
	;

enumerator_list
	: enumerator {
        $$ = (struct Enumerator_list*) malloc(sizeof(struct Enumerator_list));
        $$ -> enumerator = $1;
        $$ -> kind = enumerator_kind;
    }
	| enumerator_list ',' enumerator {
        $$ = (struct Enumerator_list*) malloc(sizeof(struct Enumerator_list));
        $$ -> enumerator_list = $1;
        $$ -> enumerator = $3;
        $$ -> kind = enumerator_list_kind;
    }
	;

enumerator
	: IDENTIFIER {
        $$ = (struct Enumerator*) malloc(sizeof(struct Enumerator));
        $$ -> str_ID = $1;
        $$ -> kind = ID_kind;
    }
	| IDENTIFIER '=' constant_expression {
        $$ = (struct Enumerator*) malloc(sizeof(struct Enumerator));
        $$ -> str_ID = $1;
        $$ -> constant_expression = $3;
        $$ -> kind = ID_EQUAL_kind;
    }
	;

type_qualifier
	: CONST {
        $$ = (struct Type_qualifier*) malloc(sizeof(struct Type_qualifier));
        $$ -> kind = CONST_kind;
    }
	| VOLATILE {
        $$ = (struct Type_qualifier*) malloc(sizeof(struct Type_qualifier));
        $$ -> kind = VOLATILE_kind;
    }
	;

declarator
	: pointer direct_declarator {
        $$ = (struct Declarator*) malloc(sizeof(struct Declarator));
        $$ -> pointer = $1;
        $$ -> direct_declarator = $2;
        $$ -> kind = pointer_kind;
    }
	| direct_declarator {
        $$ = (struct Declarator*) malloc(sizeof(struct Declarator));
        $$ -> direct_declarator = $1;
        $$ -> kind = direct_declarator_kind;
    }
	;

direct_declarator
	: IDENTIFIER {
        $$ = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        $$ -> str_ID = $1;
        $$ -> kind = ID_kind2;
    }
	| '(' declarator ')' {
        $$ = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        $$ -> declarator = $2;
        $$ -> kind = declarator_kind2;
    }
	| direct_declarator '[' constant_expression ']' {
        $$ = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        $$ -> direct_declarator = $1;
        $$ -> constant_expression = $3;
        $$ -> kind = dir_dec_con_kind;
    }
	| direct_declarator '[' ']' {
        $$ = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        $$ -> direct_declarator = $1;
        $$ -> kind = dir_dec_kind;
    }
	| direct_declarator '(' parameter_type_list ')' {
        $$ = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        $$ -> direct_declarator = $1;
        $$ -> parameter_type_list = $3;
        $$ -> kind = dir_dec_par_kind;
    }
	| direct_declarator '(' identifier_list ')' {
        $$ = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        $$ -> direct_declarator = $1;
        $$ -> identifier_list = $3;
        $$ -> kind = dir_dec_ide;
    }
	| direct_declarator '(' ')' {
        $$ = (struct Direct_declarator*) malloc(sizeof(struct Direct_declarator));
        $$ -> direct_declarator = $1;
        $$ -> kind = dir_dec_kind2;
    }
	;

pointer
	: '*' {
        $$ = (struct Pointer*) malloc(sizeof(struct Pointer));
        $$ -> kind = P_kind;
    }
	| '*' type_qualifier_list {
        $$ = (struct Pointer*) malloc(sizeof(struct Pointer));
        $$ -> type_qualifier_list = $2;
        $$ -> kind = P_type_kind;
    }
	| '*' pointer {
        $$ = (struct Pointer*) malloc(sizeof(struct Pointer));
        $$ -> pointer = $2;
        $$ -> kind = P_pointer_kind;
    }
	| '*' type_qualifier_list pointer {
        $$ = (struct Pointer*) malloc(sizeof(struct Pointer));
        $$ -> type_qualifier_list = $2;
        $$ -> pointer = $3;
        $$ -> kind = P_type_pointer_kind;
    }
	;

type_qualifier_list
	: type_qualifier {
        $$ = (struct Type_qualifier_list*) malloc(sizeof(struct Type_qualifier_list));
        $$ -> type_qualifier = $1;
        $$ -> kind = type_qualifier_kind2;
    }
	| type_qualifier_list type_qualifier {
        $$ = (struct Type_qualifier_list*) malloc(sizeof(struct Type_qualifier_list));
        $$ -> type_qualifier_list = $1;
        $$ -> type_qualifier = $2;
        $$ -> kind = type_qualifier_list_kind;
    }
	;

parameter_type_list
	: parameter_list {
        $$ = (struct Parameter_type_list*) malloc(sizeof(struct Parameter_type_list));
        $$ -> parameter_list = $1;
        $$ -> kind = parameter_list_kind;
    }
	| parameter_list ',' ELLIPSIS {
        $$ = (struct Parameter_type_list*) malloc(sizeof(struct Parameter_type_list));
        $$ -> parameter_list = $1;
        $$ -> kind = parameter_list_ELL_kind;
    }
	;

parameter_list
	: parameter_declaration {
        $$ = (struct Parameter_list*) malloc(sizeof(struct Parameter_list));
        $$ -> parameter_declaration = $1;
        $$ -> kind = parameter_declaration_kind;
    }
	| parameter_list ',' parameter_declaration {
        $$ = (struct Parameter_list*) malloc(sizeof(struct Parameter_list));
        $$ -> parameter_list = $1;
        $$ -> parameter_declaration = $3;
        $$ -> kind = parameter_list_kind2;
    }
	;
parameter_declaration
	: declaration_specifiers declarator {
        $$ = (struct Parameter_declaration*) malloc(sizeof(struct Parameter_declaration));
        $$ -> declaration_specifiers = $1;
        $$ -> declarator = $2;
        $$ -> kind = dec_dec_kind;
    }
	| declaration_specifiers abstract_declarator {
        $$ = (struct Parameter_declaration*) malloc(sizeof(struct Parameter_declaration));
        $$ -> declaration_specifiers = $1;
        $$ -> abstract_declarator = $2;
        $$ -> kind = dec_abs_kind;
    }
	| declaration_specifiers {
        $$ = (struct Parameter_declaration*) malloc(sizeof(struct Parameter_declaration));
        $$ -> declaration_specifiers = $1;
        $$ -> kind = dec_kind2;
    }
	;

identifier_list
	: IDENTIFIER {
        $$ = (struct Identifier_list*) malloc(sizeof(struct Identifier_list));
        $$ -> str_ID = $1;
        $$ -> kind = ID_kind_in_identifier_list;
    }
	| identifier_list ',' IDENTIFIER {
        $$ = (struct Identifier_list*) malloc(sizeof(struct Identifier_list));
        $$ -> identifier_list = $1;
        $$ -> str_ID = $3;
        $$ -> kind = identifier_list_ID_in_identifier_list;
    }
	;

type_name
	: specifier_qualifier_list {
        $$ = (struct Type_name*) malloc(sizeof(struct Type_name));
        $$ -> specifier_qualifier_list = $1;
        $$ -> kind = spe_kind;
    }
	| specifier_qualifier_list abstract_declarator {
        $$ = (struct Type_name*) malloc(sizeof(struct Type_name));
        $$ -> specifier_qualifier_list = $1;
        $$ -> abstract_declarator = $2;
        $$ -> kind = spe_abs_kind;
    }
	;

abstract_declarator
	: pointer {
        $$ = (struct Abstract_declarator*) malloc(sizeof(struct Abstract_declarator));
        $$ -> pointer = $1;
        $$ -> kind = poi_kind_in_abs; 
    }
	| direct_abstract_declarator {
        $$ = (struct Abstract_declarator*) malloc(sizeof(struct Abstract_declarator));
        $$ -> direct_abstract_declarator = $1;
        $$ -> kind = dir_kind_in_abs;
    }
	| pointer direct_abstract_declarator {
        $$ = (struct Abstract_declarator*) malloc(sizeof(struct Abstract_declarator));
        $$ -> pointer = $1;
        $$ -> direct_abstract_declarator = $2;
        $$ -> kind = poi_dir_kind_in_abs;
    }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' {
        $$ = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        $$ -> abstract_declarator = $2;
        $$ -> kind = abs_kind;
    }
	| '[' ']' {
        $$ = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        $$ -> kind = NOT_kind;
    }
	| '[' constant_expression ']' {
        $$ = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        $$ -> constant_expression = $2;
        $$ -> kind = constant_expression_kind;
    }
	| direct_abstract_declarator '[' ']' {
        $$ = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        $$ -> direct_abstract_declarator = $1;
        $$ -> kind = dir_NOT_kind;
    }
	| direct_abstract_declarator '[' constant_expression ']' {
        $$ = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        $$ -> direct_abstract_declarator = $1;
        $$ -> constant_expression = $3;
        $$ -> kind = dir_con_kind;
    }
	| '(' ')' {
        $$ = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        $$ -> kind = NOT_kind2;
    }
	| '(' parameter_type_list ')' {
        $$ = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        $$ -> parameter_type_list = $2;
        $$ -> kind = par_kind;
    }
	| direct_abstract_declarator '(' ')' {
        $$ = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        $$ -> direct_abstract_declarator = $1;
        $$ -> kind = dir_NOT_kind3;
    }
	| direct_abstract_declarator '(' parameter_type_list ')' {
        $$ = (struct Direct_abstract_declarator*) malloc(sizeof(struct Direct_abstract_declarator));
        $$ -> direct_abstract_declarator = $1;
        $$ -> parameter_type_list = $3;
        $$ -> kind = dir_par_kind;
    }
	;

initializer
	: assignment_expression {
        $$ = (struct Initializer*) malloc(sizeof(struct Initializer));
        $$ -> assignment_expression = $1;
        $$ -> kind = ass_exp_kind;
    }
	| '{' initializer_list '}' {
        $$ = (struct Initializer*) malloc(sizeof(struct Initializer));
        $$ -> initializer_list = $2;
        $$ -> kind = ini_NOT;
    }
	| '{' initializer_list ',' '}' {
        $$ = (struct Initializer*) malloc(sizeof(struct Initializer));
        $$ -> initializer_list = $2;
        $$ -> kind = ini_KNM;
    }
	;

initializer_list
	: initializer {
        $$ = (struct Initializer_list*) malloc(sizeof(struct Initializer_list));
        $$ -> initializer = $1;
        $$ -> kind = ini_kind;
    }
	| initializer_list ',' initializer {
        $$ = (struct Initializer_list*) malloc(sizeof(struct Initializer_list));
        $$ -> initializer_list = $1;
        $$ -> initializer = $3;
        $$ -> kind = ini_ini_kind;
    }
	;

statement
	: labeled_statement {
        $$ = (struct Statement*) malloc(sizeof(struct Statement));
        $$ -> labeled_statement = $1;
        $$ -> kind = label_kind;
    }
	| compound_statement {
        $$ = (struct Statement*) malloc(sizeof(struct Statement));
        $$ -> compound_statement = $1;
        $$ -> kind = compo_kind; 
    }
	| expression_statement {
        $$ = (struct Statement*) malloc(sizeof(struct Statement));
        $$ -> expression_statement = $1;
        $$ -> kind = expre_kind;
    }
	| selection_statement {
        $$ = (struct Statement*) malloc(sizeof(struct Statement));
        $$ -> selection_statement = $1;
        $$ -> kind = selec_kind;
    }
	| iteration_statement {
        $$ = (struct Statement*) malloc(sizeof(struct Statement));
        $$ -> iteration_statement = $1;
        $$ -> kind = itera_kind;
    }
	| jump_statement {
        $$ = (struct Statement*) malloc(sizeof(struct Statement));
        $$ -> jump_statement = $1;
        $$ -> kind = jump_kind;
    }
    | declaration {
        $$ = (struct Statement*) malloc(sizeof(struct Statement));
        $$ -> declaration = $1;
        $$ -> kind = decla_kind;
    }
	;

labeled_statement
	: IDENTIFIER ':' statement {
        $$ = (struct Labeled_statement*) malloc(sizeof(struct Labeled_statement));
        $$ -> str_ID = $1;
        $$ -> statement = $3;
        $$ -> kind = ID_sta_kind;
    }
	| CASE constant_expression ':' statement {
        $$ = (struct Labeled_statement*) malloc(sizeof(struct Labeled_statement));
        $$ -> constant_expression = $2;
        $$ -> statement = $4;
        $$ -> kind = CASE_con_kind;
    }
	| DEFAULT ':' statement {
        $$ = (struct Labeled_statement*) malloc(sizeof(struct Labeled_statement));
        $$ -> statement = $3;
        $$ -> kind = DEFAULT_sta_kind;
    }
	;

compound_statement
	: '{' '}' {
        $$ = (struct Compound_statement*) malloc(sizeof(struct Compound_statement));
        $$ -> kind = NOT_kind3;
    }
	| '{' statement_list '}' {
        $$ = (struct Compound_statement*) malloc(sizeof(struct Compound_statement));
        $$ -> statement_list = $2;
        $$ -> kind = statement_list_kind;
    }
//	| '{' declaration_list '}'
//	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration {
        $$ = (struct Declaration_list*) malloc(sizeof(struct Declaration_list));
        $$ -> declaration = $1;
        $$ -> kind = declaration_kind;
    }
	| declaration_list declaration {
        $$ = (struct Declaration_list*) malloc(sizeof(struct Declaration_list));
        $$ -> declaration_list = $1;
        $$ -> declaration = $2;
        $$ -> kind = declaration_list_kind;
    }
	;

statement_list
	: statement {
        $$ = (struct Statement_list*) malloc(sizeof(struct Statement_list));
        $$ -> statement = $1;
        $$ -> kind = statement_kind;
    }
	| statement statement_list  {
        $$ = (struct Statement_list*) malloc(sizeof(struct Statement_list));
        $$ -> statement_list = $2;
        $$ -> statement = $1;
        $$ -> kind = statement_list_kind2;
    }
	;


expression_statement
	: ';' {
        $$ = (struct Expression_statement*) malloc(sizeof(struct Expression_statement));
        $$ -> kind = SEMIC_kind;
    }
	| expression ';' {
        $$ = (struct Expression_statement*) malloc(sizeof(struct Expression_statement));
        $$ -> expression = $1;
        $$ -> kind = expression_SEMIC_kind;
    }
	;

selection_statement
	: IF '(' expression ')' statement {
        $$ = (struct Selection_statement*) malloc(sizeof(struct Selection_statement));
        $$ -> expression = $3;
        $$ -> statement = $5;
        $$ -> kind = IF_expression_kind;
    }
	| IF '(' expression ')' statement ELSE statement {
        $$ = (struct Selection_statement*) malloc(sizeof(struct Selection_statement));
        $$ -> expression = $3;
        $$ -> statement = $5;
        $$ -> statement2 = $7;
        $$ -> kind = IF_expression_ELSE_kind;
    }
	| SWITCH '(' expression ')' statement {
        $$ = (struct Selection_statement*) malloc(sizeof(struct Selection_statement));
        $$ -> expression = $3;
        $$ -> statement = $5;
        $$ -> kind = SWITCH_kind;
    }
	;

iteration_statement
	: WHILE '(' expression ')' statement {
        $$ = (struct Iteration_statement*) malloc(sizeof(struct Iteration_statement));
        $$ -> expression = $3;
        $$ -> statement = $5;
        $$ -> kind = WHILE_kind;
    }
	| DO statement WHILE '(' expression ')' ';' {
        $$ = (struct Iteration_statement*) malloc(sizeof(struct Iteration_statement));
        $$ -> statement = $2;
        $$ -> expression = $5;
        $$ -> kind = DO_kind;
    }
	| FOR '(' expression_statement expression_statement ')' statement {
        $$ = (struct Iteration_statement*) malloc(sizeof(struct Iteration_statement));
        $$ -> expression_statement = $3;
        $$ -> expression_statement2 = $4;
        $$ -> statement = $6;
        $$ -> kind = FOR_two_kind;
    }
	| FOR '(' expression_statement expression_statement expression ')' statement {
        $$ = (struct Iteration_statement*) malloc(sizeof(struct Iteration_statement));
        $$ -> expression_statement = $3;
        $$ -> expression_statement2 = $4;
        $$ -> expression = $5;
        $$ -> statement = $7;
        $$ -> kind = FOR_three_kind;
    }
	;

jump_statement
	: GOTO IDENTIFIER ';' {
        $$ = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        $$ -> str_ID = $2;
        $$ -> kind = GOTO_kind;
    }
	| CONTINUE ';' {
        $$ = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        $$ -> kind = CONTINUE_kind;
    }
	| BREAK ';' {
        $$ = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        $$ -> kind = BREAK_kind;
    }
	| RETURN ';' {
        $$ = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        $$ -> kind = RETURN_kind;
    }
	| RETURN expression ';' {
        $$ = (struct Jump_statement*) malloc(sizeof(struct Jump_statement));
        $$ -> expression = $2;
        $$ -> kind = RETURN_expression_kind;
    }
	;

translation_unit
	: external_declaration {
        $$ = (struct Translation_unit*) malloc(sizeof(struct Translation_unit));
        $$ -> external_declaration = $1;
        $$ -> kind = external_declaration_kind;
        tree_Translation_unit = $$;
    }
	| translation_unit external_declaration {
        $$ = (struct Translation_unit*) malloc(sizeof(struct Translation_unit));
        $$ -> translation_unit = $1;
        $$ -> external_declaration = $2;
        $$ -> kind = translation_unit_kind;
        tree_Translation_unit = $$;
    }
	;

external_declaration
	: function_definition {
        $$ = (struct External_declaration*) malloc(sizeof(struct External_declaration));
        $$ -> function_definition = $1;
        $$ -> kind = function_definition_kind;
    }
	| declaration {
        $$ = (struct External_declaration*) malloc(sizeof(struct External_declaration));
        $$ -> declaration = $1;
        $$ -> kind = declaration_kind_in_external_declaration;
    }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {
        $$ = (struct Function_definition*) malloc(sizeof(struct Function_definition));
        $$ -> declaration_specifiers = $1;
        $$ -> declarator = $2;
        $$ -> declaration_list = $3;
        $$ -> compound_statement = $4;
        $$ -> kind = dec_dec_dec_kind;
    }
	| declaration_specifiers declarator compound_statement {
        $$ = (struct Function_definition*) malloc(sizeof(struct Function_definition));
        $$ -> declaration_specifiers = $1;
        $$ -> declarator = $2;
        $$ -> compound_statement = $3;
        $$ -> kind = dec_dec_com_kind;
    }
	| declarator declaration_list compound_statement {
        $$ = (struct Function_definition*) malloc(sizeof(struct Function_definition));
        $$ -> declarator = $1;
        $$ -> declaration_list = $2;
        $$ -> compound_statement = $3;
        $$ -> kind = declarator_dec_com_kind;
    }
	| declarator compound_statement {
        $$ = (struct Function_definition*) malloc(sizeof(struct Function_definition));
        $$ -> declarator = $1;
        $$ -> compound_statement = $2;
        $$ -> kind = declarator_com;
    }
    ;


%%

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