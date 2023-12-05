%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define YYERROR_VERBOSE
    int yylex();
    void yyerror(char *s);



enum kind_primary_expression{
    IDENTIFIER_kind,
    CONSTANT_kind,
    STRING_LITERAL_kind,
    expression_kind
};
struct Primary_expression{
	enum kind_primary_expression kind;
	struct Expression *expression;
	char *str_ID;
	char *str_STR;
    char *str_CONST;
}*tree_Primary_expression;

enum kind_postfix_expression{
    primary_expression_kind,
    postfix_expression_expression_kind,
    postfix_expression_not_kind,
    postfix_expression_argument_kind,
    postfix_expression_IDENTIFIER_kind,
    postfix_expression_PTR,
    postfix_expression_INC,
    postfix_expression_DEC
};
struct Postfix_expression{
	enum kind_postfix_expression kind;
	struct Expression *expression;
    struct Primary_expression *primary_expression;
    struct Postfix_expression *postfix_expression;
    struct Argument_expression_list *argument_expression_list;
    char *str_ID;
}*tree_Postfix_expression;

enum kind_argument_expression_list{
    assignment_expression_kind,
    argument_expression_list_kind
};
struct Argument_expression_list{
    enum kind_argument_expression_list kind;
    struct Assignment_expression *assignment_expression;
    struct Argument_expression_list *argument_expression_list;
}*tree_Argument_expression_list;

enum kind_unary_expression{
    postfix_expression_kind,
	INC_OP_kind,
	DEC_OP_kind,
	unary_operator_kind,
	SIZEOF_unary_expression_kind,
	SIZEOF_type_name_kind
};
struct Unary_expression{
    enum kind_unary_expression kind;
    struct Postfix_expression *postfix_expression;
    struct Unary_expression *unary_expression;
    struct Unary_operator *unary_operator;
    struct Cast_expression *cast_expression;
    struct Type_name *type_name;
}*tree_Unary_expression;

enum kind_unary_operator{
    AND_kind,
    MUL_kind,
    ADD_kind,
    SUB_kind,
    NAMI_kind,
    BIKKURI_kind
};
struct Unary_operator{
    enum kind_unary_operator kind;
}*tree_Unary_operator;

enum kind_cast_expression{
    unary_expression_kind,
    type_name_kind
};
struct Cast_expression{
    enum kind_cast_expression kind;
    struct Unary_expression *unary_expression;
    struct Type_name *type_name;
    struct Cast_expression *cast_expression;
}*tree_Cast_expression;

enum kind_multiplicative_expression{
    cast_expression_kind,
    MUL_expression_kind,
    DIV_expression_kind,
    PCT_expression_kind
};
struct Multiplicative_expression{
    enum kind_multiplicative_expression kind;
    struct Cast_expression *cast_expression;
    struct Multiplicative_expression *multiplicative_expression;
}*tree_Multiplicative_expression;

enum kind_additive_expression{
    multiplicative_expression_kind,
    ADD_expression_kind,
    SUB_expression_kind
};
struct Additive_expression{
    enum kind_additive_expression kind;
    struct Multiplicative_expression *multiplicative_expression;
    struct Additive_expression *additive_expression;
}*tree_Additive_expression;

enum kind_shift_expression{
    additive_expression_kind,
    shift_LEFT_OP_kind,
    shift_RIGHT_OP_kind
};
struct Shift_expression{
    enum kind_shift_expression kind;
    struct Additive_expression *additive_expression;
    struct Shift_expression *shift_expression;
}*tree_Shift_expression;

enum kind_relational_expression{
    shift_expression_kind,
    relat_sho,
    relat_dai,
    relat_LE_OP,
    relat_GE
};
struct Relational_expression{
    enum kind_relational_expression kind;
    struct Shift_expression *shift_expression;
    struct Relational_expression *relational_expression;
}*tree_Relational_expression;

enum kind_equality_expression{
    relational_expression_kind,
    eq_EQ_OP,
    eq_NE_OP
};
struct Equality_expression{
    enum kind_equality_expression kind;
    struct Relational_expression *relational_expression;
    struct Equality_expression *equality_expression;
}*tree_Equality_expression;

enum kind_and_expression{
    equality_expression_kind,
    and_expression_kind
};
struct And_expression{
    enum kind_and_expression kind;
    struct Equality_expression *equality_expression;
    struct And_expression *and_expression;
}*tree_And_expression;

enum kind_exclusive_or_expression{
    and_expression_kind2,
    exclusive_or_expression_kind
};
struct Exclusive_or_expression{
    enum kind_exclusive_or_expression kind;
    struct And_expression *and_expression;
    struct Exclusive_or_expression *exclusive_or_expression;
}*tree_Exclusive_or_expression;

enum kind_inclusive_or_expression{
    exclusive_or_expression_kind2,
    inclusive_or_expression_kind
};
struct Inclusive_or_expression{
    enum kind_inclusive_or_expression kind;
    struct Exclusive_or_expression *exclusive_or_expression;
    struct Inclusive_or_expression *inclusive_or_expression;
}*tree_Inclusive_or_expression;

enum kind_logical_and_expression{
    inclusive_or_expression_kind2,
    logical_and_expression_kind
};
struct Logical_and_expression{
    enum kind_logical_and_expression kind;
    struct Inclusive_or_expression *inclusive_or_expression;
    struct Logical_and_expression *logical_and_expression;
}*treeLogical_and_expression;

enum kind_logical_or_expression{
    logical_and_expression_kind2,
    logical_or_expression_kind
};
struct Logical_or_expression{
    enum kind_logical_or_expression kind;
    struct Logical_and_expression *logical_and_expression;
    struct Logical_or_expression *logical_or_expression;
}*tree_Logical_or_expression;

enum kind_conditional_expression{
    logical_or_expression_kind2,
    logical_or_expression_expression_kind
};
struct Conditional_expression{
    enum kind_conditional_expression kind;
    struct Logical_or_expression *logical_or_expression;
    struct Expression *expression;
    struct Conditional_expression *conditional_expression;
}*tree_Conditional_expression;

enum kind_assignment_expression{
    conditional_expression_kind2,
    unary_expression_kind2
};
struct Assignment_expression{
    enum kind_assignment_expression kind;
    struct Conditional_expression *conditional_expression;
    struct Unary_expression *unary_expression;
    struct Assignment_operator *assignment_operator;
    struct Assignment_expression *assignment_expression;
}*tree_Assignment_expression;

enum kind_assignment_operator{
    EQUAL_kind,
    MUL_ASSIGN_kind,
    DIV_ASSIGN_kind,
	MOD_ASSIGN_kind,
	ADD_ASSIGN_kind,
	SUB_ASSIGN_kind,
	LEFT_ASSIGN_kind,
	RIGHT_ASSIGN_kind,
	AND_ASSIGN_kind,
	XOR_ASSIGN_kind,
	OR_ASSIGN_kind
};
struct Assignment_operator{
    enum kind_assignment_operator kind;
}*tree_Assignment_operator;

enum kind_expression{
    assignment_expression_kind2,
    expression_kind2
};
struct Expression{
    enum kind_expression kind;
    struct Assignment_expression *assignment_expression;
    struct Expression *expression;
}*tree_Expression;

enum kind_constant_expression{
    conditional_expression_kind3
};
struct Constant_expression{
    enum kind_constant_expression kind;
    struct Conditional_expression *conditional_expression;
}*tree_Constant_expression;

enum kind_declaration{
    dec_spe_kind,
    dec_spe_ini_kind
};
struct Declaration{
    enum kind_declaration kind;
    struct Declaration_specifiers *declaration_specifiers;
    struct Init_declarator_list *init_declarator_list;
}*tree_Declaration;


enum kind_declaration_specifiers{
    storage_class_specifier_kind,
    storage_class_specifier_declaration_kind,
    type_specifier_kind,
    type_specifier_declaration_kind,
    type_qualifier_kind,
    type_qualifier_declaration_kind
};
struct Declaration_specifiers{
    enum kind_declaration_specifiers kind;
    struct Storage_class_specifier *storage_class_specifier;
    struct Declaration_specifiers *declaration_specifiers;
    struct Type_specifier *type_specifier;
    struct Type_qualifier *type_qualifier;
}*tree_Declaration_specifiers;

enum kind_init_declarator_list{
    init_declarator_kind,
    init_declarator_list_kind
};
struct Init_declarator_list{
    enum kind_init_declarator_list kind;
    struct Init_declarator *init_declarator;
    struct Init_declarator_list *init_declarator_list;
}*tree_Init_declarator_list;

enum kind_init_declarator{
    declarator_kind,
    declarator_EQUAL_kind
};
struct Init_declarator{
    enum kind_init_declarator kind;
    struct Declarator *declarator;
    struct Initializer *initializer;
}*tree_Init_declarator;

enum kind_storage_class_specifier{
    TYPEDEF_kind,
    EXTERN_kind,
    STATIC_kind,
    AUTO_kind,
    REGISTER_kind
};
struct Storage_class_specifier{
    enum kind_storage_class_specifier kind;
}*tree_Storage_class_specifier;

enum kind_type_specifier{
    VOID_kind,
    CHAR_kind,
    SHORT_kind,
	INT_kind,
	LONG_kind,
	FLOAT_kind,
	DOUBLE_kind,
	SIGNED_kind,
	UNSIGNED_kind,
	struct_or_union_specifier_kind,
	enum_specifier_kind,
	TYPE_NAME_kind,
    MPFI_kind,
    GMPFI_kind,
    MPFR_kind
};
struct Type_specifier{
    enum kind_type_specifier kind;
    struct Struct_or_union_specifier *struct_or_union_specifier;
    struct Enum_specifier *enum_specifier;
}*tree_Type_specifier;

enum kind_struct_or_union_specifier{
    struct_ID_struct_kind,
    struct_struct,
    struct_ID
};

struct Struct_or_union_specifier{
    enum kind_struct_or_union_specifier kind;
    struct Struct_or_union *struct_or_union;
    struct Struct_declaration_list *struct_declaration_list;
    char *str_ID;
}*tree_Struct_or_union_specifier;

enum kind_struct_or_union{
    STRUCT_kind,
    UNION_kind
};
struct Struct_or_union{
    enum kind_struct_or_union kind;
}*tree_Struct_or_union;

enum kind_struct_declaration_list{
    struct_declaration_kind,
    struct_declaration_list_kind
};
struct Struct_declaration_list{
    enum kind_struct_declaration_list kind;
    struct Struct_declaration *struct_declaration;
    struct Struct_declaration_list *struct_declaration_list;
}*tree_Struct_declaration_list;

enum kind_struct_declaration{
    specifier_qualifier_list_kind
};
struct Struct_declaration{
    enum kind_struct_declaration kind; 
    struct Specifier_qualifier_list *specifier_qualifier_list;
    struct Struct_declarator_list *struct_declarator_list;
}*tree_Struct_declaration;

enum kind_specifier_qualifier_list{
    type_spe_spe_kind,
    type_spe_kind,
    type_qua_spe_kind,
    type_qua_kind
};
struct Specifier_qualifier_list{
    enum kind_specifier_qualifier_list kind;
    struct Type_specifier *type_specifier;
    struct Specifier_qualifier_list *specifier_qualifier_list;
    struct Type_qualifier *type_qualifier;
}*tree_Specifier_qualifier_list;

enum kind_struct_declarator_list{
    struct_declarator_kind,
    struct_declarator_list_kind
};
struct Struct_declarator_list{
    enum kind_struct_declarator_list kind;
    struct Struct_declarator *struct_declarator;
    struct Struct_declarator_list *struct_declarator_list;
}*tree_Struct_declarator_list;

enum kind_struct_declarator{
    dec_kind,
    con_kind,
    dec_con_kind
};
struct Struct_declarator{
    enum kind_struct_declarator kind;
    struct Declarator *declarator;
    struct Constant_expression *constant_expression;
}*tree_Struct_declarator;

enum kind_enum_specifier{
    ENUM_enu_kind,
    ENUM_ID_enu_kind,
    ENUM_ID_kind
};
struct Enum_specifier{
    enum kind_enum_specifier kind;
    struct Enumerator_list *enumerator_list;
    char *str_ID;
}*tree_Enum_specifier;

enum kind_enumerator_list{
    enumerator_kind,
    enumerator_list_kind
};
struct Enumerator_list{
    enum kind_enumerator_list kind;
    struct Enumerator *enumerator;
    struct Enumerator_list *enumerator_list;
}*tree_Enumerator_list;

enum kind_enumerator{
    ID_kind,
    ID_EQUAL_kind
};
struct Enumerator{
    enum kind_enumerator kind;
    struct Constant_expression *constant_expression;
    char *str_ID;
}*tree_Enumerator;

enum kind_type_qualifier{
    CONST_kind,
    VOLATILE_kind
};
struct Type_qualifier{
    enum kind_type_qualifier kind;
}*tree_Type_qualifier;

enum kind_declarator{
    pointer_kind,
    direct_declarator_kind
};
struct Declarator{
    enum kind_declarator kind;
    struct Pointer *pointer;
    struct Direct_declarator *direct_declarator;
}*tree_Declarator;

enum kind_direct_declarator{
    ID_kind2,
    declarator_kind2,
    dir_dec_con_kind,
    dir_dec_kind,
    dir_dec_par_kind,
    dir_dec_ide,
    dir_dec_kind2
};
struct Direct_declarator{
    enum kind_direct_declarator kind;
    struct Direct_declarator *direct_declarator;
    struct Declarator *declarator;
    struct Constant_expression *constant_expression;
    struct Parameter_type_list *parameter_type_list;
    struct Identifier_list *identifier_list;
    char *str_ID;
}*tree_Direct_declarator;

enum kind_pointer{
    P_kind,
    P_type_kind,
    P_pointer_kind,
    P_type_pointer_kind
};
struct Pointer{
    enum kind_pointer kind;
    struct Type_qualifier_list *type_qualifier_list;
    struct Pointer *pointer;
}*tree_Pointer;

enum kind_type_qualifier_list{
    type_qualifier_kind2,
    type_qualifier_list_kind
};
struct Type_qualifier_list{
    enum kind_type_qualifier_list kind;
    struct Type_qualifier *type_qualifier;
    struct Type_qualifier_list *type_qualifier_list;
}*tree_Type_qualifier_list;

enum kind_parameter_type_list{
    parameter_list_kind,
    parameter_list_ELL_kind
};
struct Parameter_type_list{
    enum kind_parameter_type_list kind;
    struct Parameter_list *parameter_list;
}*tree_Parameter_type_list;

enum kind_parameter_list{
    parameter_declaration_kind,
    parameter_list_kind2
};
struct Parameter_list{
    enum kind_parameter_list kind;
    struct Parameter_declaration *parameter_declaration;
    struct Parameter_list *parameter_list;
}*tree_Parameter_list;

enum kind_parameter_declaration{
    dec_dec_kind,
    dec_abs_kind,
    dec_kind2
};
struct Parameter_declaration{
    enum kind_parameter_declaration kind;
    struct Declaration_specifiers *declaration_specifiers;
    struct Declarator *declarator;
    struct Abstract_declarator *abstract_declarator;
}*tree_Parameter_declaration;

enum kind_identifier_list{
    ID_kind_in_identifier_list,
    identifier_list_ID_in_identifier_list
};
struct Identifier_list{
    enum kind_identifier_list kind;
    struct Identifier_list *identifier_list;
    char *str_ID;
}*tree_Identifier_list;

enum kind_type_name{
    spe_kind,
    spe_abs_kind
};
struct Type_name{
    enum kind_type_name kind;
    struct Specifier_qualifier_list *specifier_qualifier_list;
    struct Abstract_declarator *abstract_declarator;
}*tree_Type_name;

enum kind_abstract_declarator{
    poi_kind_in_abs,
    dir_kind_in_abs,
    poi_dir_kind_in_abs
};
struct Abstract_declarator{
    enum kind_abstract_declarator kind;
    struct Pointer *pointer;
    struct Direct_abstract_declarator *direct_abstract_declarator;
}*tree_Abstract_declarator;

enum kind_direct_abstract_declarator{
    abs_kind,
    NOT_kind,
    constant_expression_kind,
    dir_NOT_kind,
    dir_con_kind,
    NOT_kind2,
    par_kind,
    dir_NOT_kind3,
    dir_par_kind
};
struct Direct_abstract_declarator{
    enum kind_direct_abstract_declarator kind;
    struct Abstract_declarator *abstract_declarator;
    struct Constant_expression *constant_expression;
    struct Direct_abstract_declarator *direct_abstract_declarator;
    struct Parameter_type_list *parameter_type_list;
}*tree_Direct_abstract_declarator;

enum kind_initializer{
    ass_exp_kind,
    ini_NOT,
    ini_KNM
};
struct Initializer{
    enum kind_initializer kind;
    struct Assignment_expression *assignment_expression;
    struct Initializer_list *initializer_list;
}*tree_Initializer;


enum kind_initializer_list{
    ini_kind,
    ini_ini_kind
};
struct Initializer_list{
    enum kind_initializer_list kind;
    struct Initializer *initializer;
    struct Initializer_list *initializer_list;
}*tree_Initializer_list;

enum kind_statement{
    label_kind,
    compo_kind,
    expre_kind,
    selec_kind,
    itera_kind,
    jump_kind,
    decla_kind
};
struct Statement{
    enum kind_statement kind;
    struct Labeled_statement *labeled_statement;
    struct Compound_statement *compound_statement;
    struct Expression_statement *expression_statement;
    struct Selection_statement *selection_statement;
    struct Iteration_statement *iteration_statement;
    struct Jump_statement *jump_statement;
    struct Declaration *declaration;
}*tree_Statement;

enum kind_labeled_statement{
    ID_sta_kind,
    CASE_con_kind,
    DEFAULT_sta_kind
};
struct Labeled_statement{
    enum kind_labeled_statement kind;
    struct Statement *statement;
    struct Constant_expression *constant_expression;
    char *str_ID;
}*tree_Labeled_statement;

enum kind_compound_statement{
    NOT_kind3,
    statement_list_kind
};
struct Compound_statement{
    enum kind_compound_statement kind;
    struct Statement_list *statement_list;
}*tree_Compound_statement;

enum kind_declaration_list{
    declaration_kind,
    declaration_list_kind
};
struct Declaration_list{
    enum kind_declaration_list kind;
    struct Declaration *declaration;
    struct Declaration_list *declaration_list;
}*tree_Declaration_list;

enum kind_statement_list{
    statement_kind,
    statement_list_kind2
};
struct Statement_list{
    enum kind_statement_list kind;
    struct Statement *statement; 
    struct Statement_list *statement_list;
}*tree_Statement_list;

enum kind_expression_statement{
    SEMIC_kind,
    expression_SEMIC_kind
};
struct Expression_statement{
    enum kind_expression_statement kind;
    struct Expression *expression;
}*tree_Expression_statement;

enum kind_selection_statement{
    IF_expression_kind,
    IF_expression_ELSE_kind,
    SWITCH_kind
};
struct Selection_statement{
    enum kind_selection_statement kind;
    struct Expression *expression;
    struct Statement *statement;
    struct Statement *statement2;
}*tree_Selection_statement;

enum kind_iteration_statement{
    WHILE_kind,
    DO_kind,
    FOR_two_kind,
    FOR_three_kind
};
struct Iteration_statement{
    enum kind_iteration_statement kind;
    struct Expression *expression;
    struct Statement *statement;
    struct Expression_statement  *expression_statement;
    struct Expression_statement  *expression_statement2;
}*tree_Iteration_statement;

enum kind_jump_statement{
    GOTO_kind,
    CONTINUE_kind,
    BREAK_kind,
    RETURN_kind,
    RETURN_expression_kind
};
struct Jump_statement{
    enum kind_jump_statement kind;
    char *str_ID;
    struct Expression *expression ;
}*tree_Jump_statement;

enum kind_translation_unit{
    external_declaration_kind,
    translation_unit_kind
};
struct Translation_unit{
    enum kind_translation_unit kind;
    struct External_declaration *external_declaration;
    struct Translation_unit *translation_unit;
}*tree_Translation_unit;

enum kind_external_declaration{
    function_definition_kind,
    declaration_kind_in_external_declaration
};
struct External_declaration{
    enum kind_external_declaration kind;
    struct Function_definition *function_definition;
    struct Declaration *declaration;
}*tree_External_declaration;

enum kind_function_definition{
    dec_dec_dec_kind,
    dec_dec_com_kind,
    declarator_dec_com_kind,
    declarator_com
};
struct Function_definition{
    enum kind_function_definition kind;
    struct Declaration_specifiers *declaration_specifiers;
    struct Declaration_list *declaration_list;
    struct Declarator *declarator;
    struct Compound_statement *compound_statement;
}*tree_Function_definition;



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
	| statement_list statement {
        $$ = (struct Statement_list*) malloc(sizeof(struct Statement_list));
        $$ -> statement_list = $1;
        $$ -> statement = $2;
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

//構文木表示関数
void print_Primary_expression(struct Primary_expression *tree_Primary_expression);
void print_Postfix_expression(struct Postfix_expression *tree_Postfix_expression);
void print_Argument_expression_list(struct Argument_expression_list *tree_Argument_expression_list);
void print_Unary_expression(struct Unary_expression *tree_Unary_expression);
void print_Unary_operator(struct Unary_operator *tree_Unary_operator);
void print_Cast_expression(struct Cast_expression *tree_Cast_expression);
void print_Multiplicative_expression(struct Multiplicative_expression *tree_Multiplicative_expression);
void print_Additive_expression(struct Additive_expression *tree_Additive_expression);
void print_Shift_expression(struct Shift_expression *tree_Shift_expression);
void print_Relational_expression(struct Relational_expression *tree_Relational_expression);
void print_Equality_expression(struct Equality_expression *tree_Equality_expression);
void print_And_expression(struct And_expression *tree_And_expression);
void print_Exclusive_or_expression(struct Exclusive_or_expression *tree_Exclusive_or_expression);
void print_Inclusive_or_expression(struct Inclusive_or_expression *tree_Inclusive_or_expression);
void print_Logical_and_expression(struct Logical_and_expression *tree_Logical_and_expression);
void print_Logical_or_expression(struct Logical_or_expression *tree_Logical_or_expression);
void print_Conditional_expression(struct Conditional_expression *tree_Conditional_expression);
void print_Assignment_expression(struct Assignment_expression *tree_Assignment_expression);
void print_Assignment_operator(struct Assignment_operator *tree_Assignment_operator);
void print_Expression(struct Expression *tree_Expression);
void print_Constant_expression(struct Constant_expression *tree_Constant_expression);
void print_Declaration(struct Declaration *tree_Declaration);
void print_Declaration_specifiers(struct Declaration_specifiers *tree_Declaration_specifiers);
void print_Init_declarator_list(struct Init_declarator_list *tree_Init_declarator_list);
void print_Init_declarator(struct Init_declarator *tree_Init_declarator);
void print_Storage_class_specifier(struct Storage_class_specifier *tree_Storage_class_specifier);
void print_Type_specifier(struct Type_specifier *tree_Type_specifier);
void print_Struct_or_union_specifier(struct Struct_or_union_specifier *tree_Struct_or_union_specifier);
void print_Struct_or_union(struct Struct_or_union *tree_Struct_or_union);
void print_Struct_declaration_list(struct Struct_declaration_list *tree_Struct_declaration_list);
void print_Struct_declaration(struct Struct_declaration *tree_Struct_declaration);
void print_Specifier_qualifier_list(struct Specifier_qualifier_list *tree_Specifier_qualifier_list);
void print_Struct_declarator_list(struct Struct_declarator_list *tree_Struct_declarator_list);
void print_Struct_declarator(struct Struct_declarator *tree_Struct_declarator);
void print_Enum_specifier(struct Enum_specifier *tree_Enum_specifier);
void print_Enumerator_list(struct Enumerator_list *tree_Enumerator_list);
void print_Enumerator(struct Enumerator *tree_Enumerator);
void print_Type_qualifier(struct Type_qualifier *tree_Type_qualifier);
void print_Declarator(struct Declarator *tree_Declarator);
void print_Direct_declarator(struct Direct_declarator *tree_Direct_declarator);
void print_Pointer(struct Pointer *tree_Pointer);
void print_Type_qualifier_list(struct Type_qualifier_list *tree_Type_qualifier_list);
void print_Parameter_type_list(struct Parameter_type_list *tree_Parameter_type_list);
void print_Parameter_list(struct Parameter_list *tree_Parameter_list);
void print_Parameter_declaration(struct Parameter_declaration *tree_Parameter_declaration);
void print_Identifier_list(struct Identifier_list *tree_Identifier_list);
void print_Type_name(struct Type_name *tree_Type_name);
void print_Abstract_declarator(struct Abstract_declarator *tree_Abstract_declarator);
void print_Direct_abstract_declarator(struct Direct_abstract_declarator *tree_Direct_abstract_declarator);
void print_Initializer(struct Initializer *tree_Initializer);
void print_Initializer_list(struct Initializer_list *tree_Initializer_list);
void print_Statement (struct Statement *tree_Statement);
void print_Labeled_statement(struct Labeled_statement *tree_Labeled_statement);
void print_Compound_statement(struct Compound_statement *tree_Compound_statement);
void print_Declaration_list(struct Declaration_list *tree_Declaration_list);
void print_Statement_list(struct Statement_list *tree_Statement_list);
void print_Expression_statement(struct Expression_statement *tree_Expression_statement);
void print_Selection_statement(struct Selection_statement *tree_Selection_statement);
void print_Iteration_statement(struct Iteration_statement *tree_Iteration_statement);
void print_Jump_statement(struct Jump_statement *tree_Jump_statement);
void print_Translation_unit(struct Translation_unit *tree_Translation_unit);
void print_External_declaration(struct External_declaration *tree_External_declaration);
void print_Function_definition(struct Function_definition *tree_Function_definition);








extern char yytext[];
extern int column;

void yyerror(char *s )
{   
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
    
	
}
int main(int argc, char *argv[]){   
    if(argv[1]!=NULL){
        yyin = fopen(argv[1], "r");
        if(yyparse()==0){
		    
            printf("\nParsing complete\n");
            printf("コード開始\n");
            print_Translation_unit(tree_Translation_unit);
        }
	    else
		    printf("\nParsing failed\n");
	    fclose(yyin);
    }else{
        printf("ready>>");
        yyparse();
    }
    return 0;
}


void print_Primary_expression(struct Primary_expression *tree_Primary_expression){
    if(tree_Primary_expression->kind==IDENTIFIER_kind){
        printf("%s", tree_Primary_expression-> str_ID);
    }
    else if(tree_Primary_expression->kind==CONSTANT_kind){
        printf("%s", tree_Primary_expression-> str_CONST);
    }
    else if(tree_Primary_expression->kind==STRING_LITERAL_kind){
        printf("%s", tree_Primary_expression-> str_STR);
    }
    else if(tree_Primary_expression->kind==expression_kind){
        print_Expression(tree_Primary_expression->expression);
    }else{printf("構文木エラー--primary_expression--");}
}
void print_Postfix_expression(struct Postfix_expression *tree_Postfix_expression){
    if(tree_Postfix_expression->kind==primary_expression_kind){
        print_Primary_expression(tree_Postfix_expression->primary_expression);
    }else if(tree_Postfix_expression->kind==postfix_expression_expression_kind){
        print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        printf("[");
        print_Expression(tree_Postfix_expression->expression);
        printf("]");
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_not_kind){
        
        print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        printf("(");
        printf(")");
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_argument_kind){
        print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        printf("(");
        print_Argument_expression_list(tree_Postfix_expression->argument_expression_list);
        printf(")");
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_IDENTIFIER_kind){
        print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        printf(".%s",tree_Postfix_expression->str_ID);
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_PTR){
        print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        printf("->");
        printf("%s",tree_Postfix_expression->str_ID);
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_INC){
        print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        printf("++");

    }else 
    if(tree_Postfix_expression->kind==postfix_expression_DEC){
        print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        printf("--");
    }else {printf("構文木エラー--Postfix_expression--");}

}
void print_Argument_expression_list(struct Argument_expression_list *tree_Argument_expression_list){
    if(tree_Argument_expression_list->kind==assignment_expression_kind){
        print_Assignment_expression(tree_Argument_expression_list->assignment_expression);
    }else
    if(tree_Argument_expression_list->kind==argument_expression_list_kind){
        print_Argument_expression_list(tree_Argument_expression_list->argument_expression_list);
        printf(",");
        print_Assignment_expression(tree_Argument_expression_list->assignment_expression);
    }else 
    {printf("構文木エラー--Argument_expression_list--");}
}
void print_Unary_expression(struct Unary_expression *tree_Unary_expression){
    if(tree_Unary_expression->kind==postfix_expression_kind){
        print_Postfix_expression(tree_Unary_expression->postfix_expression);
    }else
    if(tree_Unary_expression->kind==INC_OP_kind){
        printf("++");
        print_Unary_expression(tree_Unary_expression->unary_expression);
    }else
    if(tree_Unary_expression->kind==DEC_OP_kind){
        printf("--");
        print_Unary_expression(tree_Unary_expression->unary_expression);
    }else
    if(tree_Unary_expression->kind==unary_operator_kind){
        print_Unary_operator(tree_Unary_expression->unary_operator);
        print_Cast_expression(tree_Unary_expression->cast_expression);
    }else
    if(tree_Unary_expression->kind==SIZEOF_unary_expression_kind){
        printf("sizeof");
        print_Unary_expression(tree_Unary_expression->unary_expression);
    }else
    if(tree_Unary_expression->kind==SIZEOF_type_name_kind){
        printf("sizeof(");
        print_Type_name(tree_Unary_expression->type_name);
        printf(")");
    }else
    {printf("構文木エラー--Unary_expression--");}
}
void print_Unary_operator(struct Unary_operator *tree_Unary_operator){
    if(tree_Unary_operator->kind==AND_kind){
        printf(" &");
    }else
    if(tree_Unary_operator->kind==MUL_kind){
        printf(" *");
    }else
    if(tree_Unary_operator->kind==ADD_kind){
        printf(" +");
    }else
    if(tree_Unary_operator->kind==SUB_kind){
        printf(" -");
    }else
    if(tree_Unary_operator->kind==NAMI_kind){
        printf(" ~");
    }else
    if(tree_Unary_operator->kind==BIKKURI_kind){
        printf(" !");
    }else
    {printf("構文木エラー--Unary_operator--");}
}
void print_Cast_expression(struct Cast_expression *tree_Cast_expression){
    if(tree_Cast_expression->kind==unary_expression_kind){
        print_Unary_expression(tree_Cast_expression->unary_expression);
        
    }else
    if(tree_Cast_expression->kind==type_name_kind){
        printf("(");
        print_Type_name(tree_Cast_expression->type_name);
        printf(")");
        print_Cast_expression(tree_Cast_expression->cast_expression);
    }else {printf("構文木エラー--Cast_expression--");}
}
void print_Multiplicative_expression(struct Multiplicative_expression *tree_Multiplicative_expression){
    if(tree_Multiplicative_expression->kind==cast_expression_kind){
        print_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else
    if(tree_Multiplicative_expression->kind==MUL_expression_kind){
        print_Multiplicative_expression(tree_Multiplicative_expression->multiplicative_expression);
        printf("*");
        print_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else
    if(tree_Multiplicative_expression->kind==DIV_expression_kind){
        print_Multiplicative_expression(tree_Multiplicative_expression->multiplicative_expression);
        printf("/");
        print_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else
    if(tree_Multiplicative_expression->kind==PCT_expression_kind){
        print_Multiplicative_expression(tree_Multiplicative_expression->multiplicative_expression);
        printf("%%");
        print_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else { printf("構文木エラー--Multiplicative_expression--");}
}
void print_Additive_expression(struct Additive_expression *tree_Additive_expression){
    if(tree_Additive_expression->kind==multiplicative_expression_kind){
        print_Multiplicative_expression(tree_Additive_expression->multiplicative_expression);
    }else
    if(tree_Additive_expression->kind==ADD_expression_kind){
        print_Additive_expression(tree_Additive_expression->additive_expression);
        printf("+");
        print_Multiplicative_expression(tree_Additive_expression->multiplicative_expression);
    }else
    if(tree_Additive_expression->kind==SUB_expression_kind){
        print_Additive_expression(tree_Additive_expression->additive_expression);
        printf("-");
        print_Multiplicative_expression(tree_Additive_expression->multiplicative_expression);
    }else { printf("構文木エラー--Additive_expression--");}
}
void print_Shift_expression(struct Shift_expression *tree_Shift_expression){
    if(tree_Shift_expression->kind==additive_expression_kind){
        print_Additive_expression(tree_Shift_expression->additive_expression);
    }else
    if(tree_Shift_expression->kind==shift_LEFT_OP_kind){
        print_Shift_expression(tree_Shift_expression->shift_expression);
        printf("<<");
        print_Additive_expression(tree_Shift_expression->additive_expression);
    }else
    if(tree_Shift_expression->kind==shift_RIGHT_OP_kind){
        print_Shift_expression(tree_Shift_expression->shift_expression);
        printf(">>");
        print_Additive_expression(tree_Shift_expression->additive_expression);
    }else
    { printf("構文木エラー--Shift_expression--");}
}
void print_Relational_expression(struct Relational_expression *tree_Relational_expression){
    if(tree_Relational_expression->kind==shift_expression_kind){
        print_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_sho){
        print_Relational_expression(tree_Relational_expression->relational_expression);
        printf("<");
        print_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_dai){
        print_Relational_expression(tree_Relational_expression->relational_expression);
        printf(">");
        print_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_LE_OP){
        print_Relational_expression(tree_Relational_expression->relational_expression);
        printf("<=");
        print_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_GE){
        print_Relational_expression(tree_Relational_expression->relational_expression);
        printf(">=");
        print_Shift_expression(tree_Relational_expression->shift_expression);
    }else { printf("構文木エラー--Relational_expression--");}
}
void print_Equality_expression(struct Equality_expression *tree_Equality_expression){
    if(tree_Equality_expression->kind==relational_expression_kind){
        print_Relational_expression(tree_Equality_expression->relational_expression);
        
    }else
    if(tree_Equality_expression->kind==eq_EQ_OP){
        print_Equality_expression(tree_Equality_expression->equality_expression);
        printf("==");
        print_Relational_expression(tree_Equality_expression->relational_expression);
    }else
    if(tree_Equality_expression->kind==eq_NE_OP){
        print_Equality_expression(tree_Equality_expression->equality_expression);
        printf("!=");
        print_Relational_expression(tree_Equality_expression->relational_expression);
    }else { printf("構文木エラー--Equality_expression--");}
}
void print_And_expression(struct And_expression *tree_And_expression){
    if(tree_And_expression->kind==equality_expression_kind){
        print_Equality_expression(tree_And_expression->equality_expression);
        
    }else 
    if(tree_And_expression->kind==and_expression_kind){
        print_And_expression(tree_And_expression->and_expression);
        printf(" &");
        print_Equality_expression(tree_And_expression->equality_expression);
    }else { printf("構文木エラー--And_expression--");}
}
void print_Exclusive_or_expression(struct Exclusive_or_expression *tree_Exclusive_or_expression){
    if(tree_Exclusive_or_expression->kind==and_expression_kind2){
        print_And_expression(tree_Exclusive_or_expression->and_expression);
    }else
    if(tree_Exclusive_or_expression->kind==exclusive_or_expression_kind){
        print_Exclusive_or_expression(tree_Exclusive_or_expression->exclusive_or_expression);
        printf("^");
        print_And_expression(tree_Exclusive_or_expression->and_expression);
    }else { printf("構文木エラー--tree_Exclusive_or_expression--");}
}
void print_Inclusive_or_expression(struct Inclusive_or_expression *tree_Inclusive_or_expression){
    if(tree_Inclusive_or_expression->kind==exclusive_or_expression_kind2){
        print_Exclusive_or_expression(tree_Inclusive_or_expression->exclusive_or_expression);
        
    }else
    if(tree_Inclusive_or_expression->kind==inclusive_or_expression_kind){
        print_Inclusive_or_expression(tree_Inclusive_or_expression->inclusive_or_expression);
        printf("|");
        print_Exclusive_or_expression(tree_Inclusive_or_expression->exclusive_or_expression);
    }else { printf("構文木エラー--tree_Inclusive_or_expression--");}
}
void print_Logical_and_expression(struct Logical_and_expression *tree_Logical_and_expression){
    if(tree_Logical_and_expression->kind==inclusive_or_expression_kind2){
        print_Inclusive_or_expression(tree_Logical_and_expression->inclusive_or_expression);
        
    }else
    if(tree_Logical_and_expression->kind==logical_and_expression_kind){
        print_Logical_and_expression(tree_Logical_and_expression->logical_and_expression);
        printf(" &&");
        print_Inclusive_or_expression(tree_Logical_and_expression->inclusive_or_expression);

    }else { printf("構文木エラー--tree_Logical_and_expression--");}
    
}
void print_Logical_or_expression(struct Logical_or_expression *tree_Logical_or_expression){
    if(tree_Logical_or_expression->kind==logical_and_expression_kind2){
        print_Logical_and_expression(tree_Logical_or_expression->logical_and_expression);
        
    }else 
    if(tree_Logical_or_expression->kind==logical_or_expression_kind){
        print_Logical_or_expression(tree_Logical_or_expression->logical_or_expression);
        print_Logical_and_expression(tree_Logical_or_expression->logical_and_expression);
        

    }else { printf("構文木エラー--tree_Logical_or_expression--");}
    
}
void print_Conditional_expression(struct Conditional_expression *tree_Conditional_expression){
    if(tree_Conditional_expression->kind==logical_or_expression_kind2){
        print_Logical_or_expression(tree_Conditional_expression->logical_or_expression);
        
    }else
    if(tree_Conditional_expression->kind==logical_or_expression_expression_kind){
        print_Logical_or_expression(tree_Conditional_expression->logical_or_expression);
        printf("?");
        print_Expression(tree_Conditional_expression->expression);
        printf(":");
        print_Conditional_expression(tree_Conditional_expression->conditional_expression);
    }else { printf("構文木エラー--tree_Conditional_expression--");}
}
void print_Assignment_expression(struct Assignment_expression *tree_Assignment_expression){
    if(tree_Assignment_expression->kind==conditional_expression_kind2){
        print_Conditional_expression(tree_Assignment_expression->conditional_expression);
    }else
    if(tree_Assignment_expression->kind==unary_expression_kind2){
        print_Unary_expression(tree_Assignment_expression->unary_expression);
        print_Assignment_operator(tree_Assignment_expression->assignment_operator);
        print_Assignment_expression(tree_Assignment_expression->assignment_expression);
    }else { printf("構文木エラー--tree_Assignment_expression--");}
}
void print_Assignment_operator(struct Assignment_operator *tree_Assignment_operator){
    if(tree_Assignment_operator->kind==EQUAL_kind){
        printf(" =");
    }else
    if(tree_Assignment_operator->kind==MUL_ASSIGN_kind){
        printf(" *=");
    }else
    if(tree_Assignment_operator->kind==DIV_ASSIGN_kind){
        printf(" /=");
    }else
    if(tree_Assignment_operator->kind==MOD_ASSIGN_kind){
        printf(" %%=");
    }else
    if(tree_Assignment_operator->kind==ADD_ASSIGN_kind){
        printf(" +=");
    }else
    if(tree_Assignment_operator->kind==SUB_ASSIGN_kind){
        printf(" -=");
    }else
    if(tree_Assignment_operator->kind==LEFT_ASSIGN_kind){
        printf(" <<=");
    }else
    if(tree_Assignment_operator->kind==RIGHT_ASSIGN_kind){
        printf(" >>=");
    }else
    if(tree_Assignment_operator->kind==AND_ASSIGN_kind){
        printf(" &=");
    }else
    if(tree_Assignment_operator->kind==XOR_ASSIGN_kind){
        printf(" ^=");
    }else
    if(tree_Assignment_operator->kind==OR_ASSIGN_kind){
        printf(" |=");
    }else { printf("構文木エラー--tree_Assignment_operator--");}

    
}
void print_Expression(struct Expression *tree_Expression){
    if(tree_Expression->kind==assignment_expression_kind2){
        print_Assignment_expression(tree_Expression->assignment_expression);
    
    }else
    if(tree_Expression->kind==expression_kind2){
        print_Expression(tree_Expression->expression);
        printf(",");
        print_Assignment_expression(tree_Expression->assignment_expression);
    }else{ printf("構文木エラー--tree_Expression--");}
}
void print_Constant_expression(struct Constant_expression *tree_Constant_expression){
    if(tree_Constant_expression->kind==conditional_expression_kind3){
        print_Conditional_expression(tree_Constant_expression->conditional_expression);
    }else{ printf("構文木エラー--tree_Constant_expression--");}
}
void print_Declaration(struct Declaration *tree_Declaration){
    if(tree_Declaration->kind==dec_spe_kind){
        print_Declaration_specifiers(tree_Declaration->declaration_specifiers);
        printf(";\n");
    }else
    if(tree_Declaration->kind==dec_spe_ini_kind){
        print_Declaration_specifiers(tree_Declaration->declaration_specifiers);
        print_Init_declarator_list(tree_Declaration->init_declarator_list);
        printf(";\n");
    }else { printf("構文木エラー--tree_Declaration--");}
}
void print_Declaration_specifiers(struct Declaration_specifiers *tree_Declaration_specifiers){
    if(tree_Declaration_specifiers->kind==storage_class_specifier_kind){
        print_Storage_class_specifier(tree_Declaration_specifiers->storage_class_specifier);
    }else
    if(tree_Declaration_specifiers->kind==storage_class_specifier_declaration_kind){
        print_Storage_class_specifier(tree_Declaration_specifiers->storage_class_specifier);
        print_Declaration_specifiers(tree_Declaration_specifiers->declaration_specifiers);
    
    }else
    if(tree_Declaration_specifiers->kind==type_specifier_kind){
        print_Type_specifier(tree_Declaration_specifiers->type_specifier);
    
    }else
    if(tree_Declaration_specifiers->kind==type_specifier_declaration_kind){
        print_Type_specifier(tree_Declaration_specifiers->type_specifier);
        print_Declaration_specifiers(tree_Declaration_specifiers->declaration_specifiers);
    
    }else
    if(tree_Declaration_specifiers->kind==type_qualifier_kind){
        print_Type_qualifier(tree_Declaration_specifiers->type_qualifier);
    }else
    if(tree_Declaration_specifiers->kind==type_qualifier_declaration_kind){
        print_Type_qualifier(tree_Declaration_specifiers->type_qualifier);
        print_Declaration_specifiers(tree_Declaration_specifiers->declaration_specifiers);
    }else { printf("構文木エラー--tree_Declaration_specifiers--");}
}
void print_Init_declarator_list(struct Init_declarator_list *tree_Init_declarator_list){
    if(tree_Init_declarator_list->kind==init_declarator_kind){
        print_Init_declarator(tree_Init_declarator_list->init_declarator);
        
    }else
    if(tree_Init_declarator_list->kind==init_declarator_list_kind){
        print_Init_declarator_list(tree_Init_declarator_list->init_declarator_list);
        printf(",");
        print_Init_declarator(tree_Init_declarator_list->init_declarator);
    }else{ printf("構文木エラー--tree_Init_declarator_list--");}
}
void print_Init_declarator(struct Init_declarator *tree_Init_declarator){
    if(tree_Init_declarator->kind==declarator_kind){
        print_Declarator(tree_Init_declarator->declarator);
    }else
    if(tree_Init_declarator->kind==declarator_EQUAL_kind){
        print_Declarator(tree_Init_declarator->declarator);
        printf(" =");
        print_Initializer(tree_Init_declarator->initializer);
    }else{ printf("構文木エラー--tree_Init_declarator--");}
}
void print_Storage_class_specifier(struct Storage_class_specifier *tree_Storage_class_specifier){
    if(tree_Storage_class_specifier->kind==TYPEDEF_kind){
        printf("typdef ");
    }else
    if(tree_Storage_class_specifier->kind==EXTERN_kind){
        printf("extern ");
    }else
    if(tree_Storage_class_specifier->kind==STATIC_kind){
        printf("static ");
    }else
    if(tree_Storage_class_specifier->kind==AUTO_kind){
        printf("auto ");
    }else
    if(tree_Storage_class_specifier->kind==REGISTER_kind){
        printf("register");
    }else
    { printf("構文木エラー--tree_Storage_class_specifier--");}
}
void print_Type_specifier(struct Type_specifier *tree_Type_specifier){
    if(tree_Type_specifier->kind==VOID_kind){
        printf("void ");
    }else
    if(tree_Type_specifier->kind==CHAR_kind){
        printf("char ");
    }else
    if(tree_Type_specifier->kind==SHORT_kind){
        printf("short ");
    }else
    if(tree_Type_specifier->kind==INT_kind){
        printf("int ");
    }else
    if(tree_Type_specifier->kind==LONG_kind){
        printf("long ");
    }else
    if(tree_Type_specifier->kind==FLOAT_kind){
        printf("float ");
    }else
    if(tree_Type_specifier->kind==DOUBLE_kind){
        printf("double ");
    }else
    if(tree_Type_specifier->kind==SIGNED_kind){
        printf("signed ");
    }else
    if(tree_Type_specifier->kind==UNSIGNED_kind){
        printf("unsigned ");
    }else
    if(tree_Type_specifier->kind==struct_or_union_specifier_kind){
        print_Struct_or_union_specifier(tree_Type_specifier->struct_or_union_specifier);
    }else
    if(tree_Type_specifier->kind==enum_specifier_kind){
        print_Enum_specifier(tree_Type_specifier->enum_specifier);
    }else
    if(tree_Type_specifier->kind==TYPE_NAME_kind){
        printf("type_name ");
    }else
    if(tree_Type_specifier->kind==MPFI_kind){
        printf("mpfi_t ");
    }else
    if(tree_Type_specifier->kind==GMPFI_kind){
        printf("gmpfi_t ");
    }else
    if(tree_Type_specifier->kind==MPFR_kind){
        printf("mpfr_t ");
    }else
    { printf("構文木エラー--tree_Type_specifier--");}
}
void print_Struct_or_union_specifier(struct Struct_or_union_specifier *tree_Struct_or_union_specifier){
    if(tree_Struct_or_union_specifier->kind==struct_ID_struct_kind){
        print_Struct_or_union(tree_Struct_or_union_specifier->struct_or_union);
        printf(" %s{",tree_Struct_or_union_specifier->str_ID);
        print_Struct_declaration_list(tree_Struct_or_union_specifier->struct_declaration_list);
        printf("}");
    }else 
    if(tree_Struct_or_union_specifier->kind==struct_struct){
        print_Struct_or_union(tree_Struct_or_union_specifier->struct_or_union);
        printf("{");
        print_Struct_declaration_list(tree_Struct_or_union_specifier->struct_declaration_list);
        printf("}");
    }else
    if(tree_Struct_or_union_specifier->kind==struct_ID){
        print_Struct_or_union(tree_Struct_or_union_specifier->struct_or_union);
        printf(" %s",tree_Struct_or_union_specifier->str_ID);
    }else
    {printf("構文木エラー--tree_Struct_or_union_specifier--");}
    
}
void print_Struct_or_union(struct Struct_or_union *tree_Struct_or_union){
    if(tree_Struct_or_union->kind==STRUCT_kind){
        printf("struct ");
    }else 
    if(tree_Struct_or_union->kind==UNION_kind){
        printf("union" );
    }else
    {printf("構文木エラー--tree_Struct_or_union--");}
}
void print_Struct_declaration_list(struct Struct_declaration_list *tree_Struct_declaration_list){
    if(tree_Struct_declaration_list->kind==struct_declaration_kind){
        print_Struct_declaration(tree_Struct_declaration_list->struct_declaration);
        
    }else 
    if(tree_Struct_declaration_list->kind==struct_declaration_list_kind){
        print_Struct_declaration_list(tree_Struct_declaration_list->struct_declaration_list);
        print_Struct_declaration(tree_Struct_declaration_list->struct_declaration);
    }else
    {printf("構文木エラー--tree_Struct_declaration_list--");}
}
void print_Struct_declaration(struct Struct_declaration *tree_Struct_declaration){
    if(tree_Struct_declaration->kind==specifier_qualifier_list_kind){
        print_Specifier_qualifier_list(tree_Struct_declaration->specifier_qualifier_list);
        print_Struct_declarator_list(tree_Struct_declaration->struct_declarator_list);
        printf(";\n");
    }else {printf("構文木エラー--tree_Struct_declaration--");}
}
void print_Specifier_qualifier_list(struct Specifier_qualifier_list *tree_Specifier_qualifier_list){
    if(tree_Specifier_qualifier_list->kind==type_spe_spe_kind){
        print_Type_specifier(tree_Specifier_qualifier_list->type_specifier);
        print_Specifier_qualifier_list(tree_Specifier_qualifier_list->specifier_qualifier_list);
        
    }else
    if(tree_Specifier_qualifier_list->kind==type_spe_kind){
        print_Type_specifier(tree_Specifier_qualifier_list->type_specifier);
    }else
    if(tree_Specifier_qualifier_list->kind==type_qua_spe_kind){
        print_Type_qualifier(tree_Specifier_qualifier_list->type_qualifier);
        print_Specifier_qualifier_list(tree_Specifier_qualifier_list->specifier_qualifier_list);
        
    }else 
    if(tree_Specifier_qualifier_list->kind==type_qua_kind){
        print_Type_qualifier(tree_Specifier_qualifier_list->type_qualifier);
    }else{printf("構文木エラー--tree_Specifier_qualifier_list--");}
    
}
void print_Struct_declarator_list(struct Struct_declarator_list *tree_Struct_declarator_list){
    if(tree_Struct_declarator_list->kind==struct_declarator_kind){
        print_Struct_declarator(tree_Struct_declarator_list->struct_declarator);
    }else
    if(tree_Struct_declarator_list->kind==struct_declarator_list_kind){
        print_Struct_declarator_list(tree_Struct_declarator_list->struct_declarator_list);
        printf(",");
        print_Struct_declarator(tree_Struct_declarator_list->struct_declarator);

    }else{printf("構文木エラー--tree_Struct_declarator_list--");}
}
void print_Struct_declarator(struct Struct_declarator *tree_Struct_declarator){
    if(tree_Struct_declarator->kind==dec_kind){
        print_Declarator(tree_Struct_declarator->declarator);
    }else
    if(tree_Struct_declarator->kind==con_kind){
        printf(":");
        print_Constant_expression(tree_Struct_declarator->constant_expression);
    }else
    if(tree_Struct_declarator->kind==dec_con_kind){
        print_Declarator(tree_Struct_declarator->declarator);
        printf(":");
        print_Constant_expression(tree_Struct_declarator->constant_expression);
    }
    else{printf("構文木エラー--tree_Struct_declarator--");}
    
}
void print_Enum_specifier(struct Enum_specifier *tree_Enum_specifier){
    if(tree_Enum_specifier->kind==ENUM_enu_kind){
        printf("enum {");
        print_Enumerator_list(tree_Enum_specifier->enumerator_list);
        printf("}");

    }else if(tree_Enum_specifier->kind==ENUM_ID_enu_kind){
        printf("enum ");
        printf("%s ",tree_Enum_specifier->str_ID);
        printf("{");
        print_Enumerator_list(tree_Enum_specifier->enumerator_list);
        printf("}");
    }else
    if(tree_Enum_specifier->kind==ENUM_ID_kind){
        printf("enum ");
        printf("%s ",tree_Enum_specifier->str_ID);
    }else{printf("構文木エラー--tree_Enum_specifier--");}

    
}
void print_Enumerator_list(struct Enumerator_list *tree_Enumerator_list){
    if(tree_Enumerator_list->kind==enumerator_kind){
        print_Enumerator(tree_Enumerator_list->enumerator);
    }else 
    if(tree_Enumerator_list->kind==enumerator_list_kind){
        print_Enumerator_list(tree_Enumerator_list->enumerator_list);
        printf(",");
        print_Enumerator(tree_Enumerator_list->enumerator);
    }else
    {printf("構文木エラー--tree_Enumerator_list--");}
}
void print_Enumerator(struct Enumerator *tree_Enumerator){
    if(tree_Enumerator->kind==ID_kind){
        printf(" %s",tree_Enumerator->str_ID);
    }else 
    if(tree_Enumerator->kind==ID_EQUAL_kind){
        printf(" %s",tree_Enumerator->str_ID);
        print_Constant_expression(tree_Enumerator->constant_expression);
    }else
    {printf("構文木エラー--tree_Enumerator--");}
    
}
void print_Type_qualifier(struct Type_qualifier *tree_Type_qualifier){
    if(tree_Type_qualifier->kind==CONST_kind){
        printf("const ");
    }else
    if(tree_Type_qualifier->kind==VOLATILE_kind){
        printf("volatile ");
    }else
    {printf("構文木エラー--tree_Type_qualifier--");}
    
}
void print_Declarator(struct Declarator *tree_Declarator){
    if(tree_Declarator->kind==pointer_kind){
        print_Pointer(tree_Declarator->pointer);
        print_Direct_declarator(tree_Declarator->direct_declarator);
        
    }else
    if(tree_Declarator->kind==direct_declarator_kind){
        print_Direct_declarator(tree_Declarator->direct_declarator);
    }else  {printf("構文木エラー--tree_Declarator--");}
    
}
void print_Direct_declarator(struct Direct_declarator *tree_Direct_declarator){
    if(tree_Direct_declarator->kind==ID_kind2){
        printf(" %s ",tree_Direct_declarator->str_ID);
    }else 
    if(tree_Direct_declarator->kind==declarator_kind2){
        printf("(");
        print_Declarator(tree_Direct_declarator->declarator);
        printf(")");
    }else
    if(tree_Direct_declarator->kind==dir_dec_con_kind){
        print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        printf("[");
        print_Constant_expression(tree_Direct_declarator->constant_expression);
        printf("]");
    }else
    if(tree_Direct_declarator->kind==dir_dec_kind){
        print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        printf("[ ]");
    }else
    if(tree_Direct_declarator->kind==dir_dec_par_kind){
        print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        printf("(");
        print_Parameter_type_list(tree_Direct_declarator->parameter_type_list);
        printf(")");
    }else
    if(tree_Direct_declarator->kind==dir_dec_ide){
        print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        printf("(");
        print_Identifier_list(tree_Direct_declarator->identifier_list);
        printf(")");
    }else
    if(tree_Direct_declarator->kind==dir_dec_kind2){
        print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        printf("( )");
    }else
    {printf("構文木エラー--tree_Direct_declarator--");}
}
void print_Pointer(struct Pointer *tree_Pointer){
    if(tree_Pointer->kind==P_kind){
        printf("*");
        
    }else 
    if(tree_Pointer->kind==P_type_kind){
        printf("*");
        print_Type_qualifier_list(tree_Pointer->type_qualifier_list);
    }else 
    if(tree_Pointer->kind==P_pointer_kind){
        printf("*");
        print_Pointer(tree_Pointer->pointer);
    }else 
    if(tree_Pointer->kind==P_type_pointer_kind){
        printf("*");
        print_Type_qualifier_list(tree_Pointer->type_qualifier_list);
        print_Pointer(tree_Pointer->pointer);
    }else 
    {printf("構文木エラー--tree_Pointer--");}
    
}
void print_Type_qualifier_list(struct Type_qualifier_list *tree_Type_qualifier_list){
    if(tree_Type_qualifier_list->kind==type_qualifier_kind2){
        print_Type_qualifier(tree_Type_qualifier_list->type_qualifier);
    }else 
    if(tree_Type_qualifier_list->kind==type_qualifier_list_kind){
        print_Type_qualifier_list(tree_Type_qualifier_list->type_qualifier_list);
        print_Type_qualifier(tree_Type_qualifier_list->type_qualifier);
    }else 
    {printf("構文木エラー--tree_Type_qualifier_list--");}
}
void print_Parameter_type_list(struct Parameter_type_list *tree_Parameter_type_list){
    if(tree_Parameter_type_list->kind==parameter_list_kind){
        print_Parameter_list(tree_Parameter_type_list->parameter_list);
    }else 
    if(tree_Parameter_type_list->kind==parameter_list_ELL_kind){
        print_Parameter_list(tree_Parameter_type_list->parameter_list);
        printf(" , ...");
    }else 
    {printf("構文木エラー--tree_Parameter_type_list--");}
    
}
void print_Parameter_list(struct Parameter_list *tree_Parameter_list){
    if(tree_Parameter_list->kind==parameter_declaration_kind){
        print_Parameter_declaration(tree_Parameter_list->parameter_declaration);
    }else 
    if(tree_Parameter_list->kind==parameter_list_kind2){
        print_Parameter_list(tree_Parameter_list->parameter_list);
        printf(", ");
        print_Parameter_declaration(tree_Parameter_list->parameter_declaration);
    }else 
    {printf("構文木エラー--tree_Parameter_list--");}
}
void print_Parameter_declaration(struct Parameter_declaration *tree_Parameter_declaration){
    if(tree_Parameter_declaration->kind==dec_dec_kind){
        print_Declaration_specifiers(tree_Parameter_declaration->declaration_specifiers);
        print_Declarator(tree_Parameter_declaration->declarator);
    }else 
    if(tree_Parameter_declaration->kind==dec_abs_kind){
        print_Declaration_specifiers(tree_Parameter_declaration->declaration_specifiers);
        print_Abstract_declarator(tree_Parameter_declaration->abstract_declarator);
    }else 
    if(tree_Parameter_declaration->kind==dec_kind2){
        print_Declaration_specifiers(tree_Parameter_declaration->declaration_specifiers);
    }else {printf("構文木エラー--tree_Parameter_declaration--");}
    
}
void print_Identifier_list(struct Identifier_list *tree_Identifier_list){
    if(tree_Identifier_list->kind==ID_kind_in_identifier_list){
        printf("%s",tree_Identifier_list->str_ID);
    }else 
    if(tree_Identifier_list->kind==identifier_list_ID_in_identifier_list){
        print_Identifier_list(tree_Identifier_list->identifier_list);
        printf(", %s",tree_Identifier_list->str_ID);
    }else 
    {printf("構文木エラー--tree_Identifier_list--");}
}
void print_Type_name(struct Type_name *tree_Type_name){
    if(tree_Type_name->kind==spe_kind){
        print_Specifier_qualifier_list(tree_Type_name->specifier_qualifier_list);
        
    }else
    if(tree_Type_name->kind==spe_abs_kind){
        print_Specifier_qualifier_list(tree_Type_name->specifier_qualifier_list);
         print_Abstract_declarator(tree_Type_name->abstract_declarator);
    }else{printf("構文木エラー--tree_Type_name--");}
}
void print_Abstract_declarator(struct Abstract_declarator *tree_Abstract_declarator){
    if(tree_Abstract_declarator->kind==poi_kind_in_abs){
        print_Pointer(tree_Abstract_declarator->pointer);
    }else 
    if(tree_Abstract_declarator->kind==dir_kind_in_abs){
        print_Direct_abstract_declarator(tree_Abstract_declarator->direct_abstract_declarator);
    }else 
    if(tree_Abstract_declarator->kind==poi_dir_kind_in_abs){
        print_Pointer(tree_Abstract_declarator->pointer);
        print_Direct_abstract_declarator(tree_Abstract_declarator->direct_abstract_declarator);
    }else {printf("構文木エラー--tree_Abstract_declarator--");}
}
void print_Direct_abstract_declarator(struct Direct_abstract_declarator *tree_Direct_abstract_declarator){
    if(tree_Direct_abstract_declarator->kind==abs_kind){
        print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
    }else 
    if(tree_Direct_abstract_declarator->kind==NOT_kind){
        printf("[ ]");
    }else 
    if(tree_Direct_abstract_declarator->kind==constant_expression_kind){
        printf("[");
        print_Constant_expression(tree_Direct_abstract_declarator->constant_expression);
        printf("]");
    }else 
    if(tree_Direct_abstract_declarator->kind==dir_NOT_kind){
        print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        printf("[ ]");
    }else 
    if(tree_Direct_abstract_declarator->kind==dir_con_kind){
        print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        printf("[");
        print_Constant_expression(tree_Direct_abstract_declarator->constant_expression);
        printf("]");
    }else 
    if(tree_Direct_abstract_declarator->kind==NOT_kind2){
        printf("( )");
    }else 
    if(tree_Direct_abstract_declarator->kind==par_kind){
        printf("(");
        print_Parameter_type_list(tree_Direct_abstract_declarator->parameter_type_list);
        printf(")");
    }else 
    if(tree_Direct_abstract_declarator->kind==dir_NOT_kind3){
        print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        printf("( )");
    }else
    if(tree_Direct_abstract_declarator->kind==dir_par_kind){
        print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        printf("( ");
        print_Parameter_type_list(tree_Direct_abstract_declarator->parameter_type_list);
        printf(" )");
    }else
    {printf("構文木エラー--tree_Direct_abstract_declarator--");}
    
}
void print_Initializer(struct Initializer *tree_Initializer){
    if(tree_Initializer->kind==ass_exp_kind){
        print_Assignment_expression(tree_Initializer->assignment_expression);
        
    }else 
    if(tree_Initializer->kind==ini_NOT){
        printf("{");
        print_Initializer_list(tree_Initializer->initializer_list);
        printf("}");

    }else 
    if(tree_Initializer->kind==ini_KNM){
        printf("{");
        print_Initializer_list(tree_Initializer->initializer_list);
        printf(",");
        printf("}");
    }else {printf("構文木エラー--tree_Initializer--");}
    
}
void print_Initializer_list(struct Initializer_list *tree_Initializer_list){
    if(tree_Initializer_list->kind==ini_kind){
        print_Initializer(tree_Initializer_list->initializer);
        
    }else 
    if(tree_Initializer_list->kind==ini_ini_kind){
        print_Initializer_list(tree_Initializer_list->initializer_list);
        printf(",");
        print_Initializer(tree_Initializer_list->initializer);
    }else {printf("構文木エラー--tree_Initializer_list--");}
    
    
}
void print_Statement (struct Statement *tree_Statement){
    if(tree_Statement->kind==label_kind){
        print_Labeled_statement(tree_Statement->labeled_statement);
        
    }else 
    if(tree_Statement->kind==compo_kind){
        print_Compound_statement(tree_Statement->compound_statement);
    }else 
    if(tree_Statement->kind==expre_kind){
        print_Expression_statement(tree_Statement->expression_statement);
    }else 
    if(tree_Statement->kind==selec_kind){
        print_Selection_statement(tree_Statement->selection_statement);
    }else 
    if(tree_Statement->kind==itera_kind){
        print_Iteration_statement(tree_Statement->iteration_statement);
    }else 
    if(tree_Statement->kind==jump_kind){
        print_Jump_statement(tree_Statement->jump_statement);
    }else 
    if(tree_Statement->kind==decla_kind){
        print_Declaration(tree_Statement->declaration);
    }else {printf("構文木エラー--tree_Statement--");}
    
    
}
void print_Labeled_statement(struct Labeled_statement *tree_Labeled_statement){
    if(tree_Labeled_statement->kind==ID_sta_kind){
        printf("%s :",tree_Labeled_statement->str_ID);
        print_Statement(tree_Labeled_statement->statement);
    }else 
    if(tree_Labeled_statement->kind==CASE_con_kind){
        printf("case ");
        print_Constant_expression(tree_Labeled_statement->constant_expression);
        printf(" : ");
        print_Statement(tree_Labeled_statement->statement);
    }else 
    if(tree_Labeled_statement->kind==DEFAULT_sta_kind){
        printf("default :");
        print_Statement(tree_Labeled_statement->statement);
    }else {printf("構文木エラー--tree_Labeled_statement--");}
    
}
void print_Compound_statement(struct Compound_statement *tree_Compound_statement){
    if(tree_Compound_statement->kind==NOT_kind3){
        printf("{ \n }");
    }else 
    if(tree_Compound_statement->kind==statement_list_kind){
        printf("{\n");
        print_Statement_list(tree_Compound_statement->statement_list);
        printf("\n}");
    }else{printf("構文木エラー--tree_Compound_statement--");}
    
}
void print_Declaration_list(struct Declaration_list *tree_Declaration_list){
    if(tree_Declaration_list->kind==declaration_kind){
        print_Declaration(tree_Declaration_list->declaration);
        
    } else
    if(tree_Declaration_list->kind==declaration_list_kind){
        print_Declaration_list(tree_Declaration_list->declaration_list);
        print_Declaration(tree_Declaration_list->declaration);
    } else
    {printf("構文木エラー--tree_Declaration_list--");}
    
}
void print_Statement_list(struct Statement_list *tree_Statement_list){
    if(tree_Statement_list->kind==statement_kind){
        print_Statement(tree_Statement_list->statement);
        
    }else 
    if(tree_Statement_list->kind==statement_list_kind2){
        print_Statement_list(tree_Statement_list->statement_list);
        print_Statement(tree_Statement_list->statement);
    }else
    {printf("構文木エラー--tree_Statement_list--");}
    
}
void print_Expression_statement(struct Expression_statement *tree_Expression_statement){
    if(tree_Expression_statement->kind==SEMIC_kind){
        printf(";\n");
    }else 
    if(tree_Expression_statement->kind==expression_SEMIC_kind){
        print_Expression(tree_Expression_statement->expression);
        printf(";\n");
    }else {printf("構文木エラー--tree_Expression_statement--");}
    
}
void print_Selection_statement(struct Selection_statement *tree_Selection_statement){
    if(tree_Selection_statement->kind==IF_expression_kind){
        
        printf("if(");
        print_Expression(tree_Selection_statement->expression);
        printf(")");
        printf("[");
        print_Statement(tree_Selection_statement->statement);
        printf("]");
    }else 
    if(tree_Selection_statement->kind==IF_expression_ELSE_kind){
        printf("if(");
        print_Expression(tree_Selection_statement->expression);
        printf(")");
        printf("$[");
        print_Statement(tree_Selection_statement->statement);
        printf("]$");
        printf(" else ");
        printf("&[");
        print_Statement(tree_Selection_statement->statement2);
        printf("]&");
    }else 
    if(tree_Selection_statement->kind==SWITCH_kind){
        printf("switch (");
        print_Expression(tree_Selection_statement->expression);
        printf(")");
        print_Statement(tree_Selection_statement->statement);
    }else {printf("構文木エラー--tree_Selection_statement--");}
    
}
void print_Iteration_statement(struct Iteration_statement *tree_Iteration_statement){
    if(tree_Iteration_statement->kind==WHILE_kind){
        printf("while(");
        print_Expression(tree_Iteration_statement->expression);
        printf(")\n");
        print_Statement(tree_Iteration_statement->statement);
    }else 
    if(tree_Iteration_statement->kind==DO_kind){
        printf("do ");
        print_Statement(tree_Iteration_statement->statement);
        printf("while(");
        print_Expression(tree_Iteration_statement->expression);
        printf(");\n");
    }else 
    if(tree_Iteration_statement->kind==FOR_two_kind){
        
        printf("for( ");
        print_Expression_statement(tree_Iteration_statement->expression_statement);
        print_Expression_statement(tree_Iteration_statement->expression_statement2);
        printf(")\n");
        print_Statement(tree_Iteration_statement->statement);
        
    }else 
    if(tree_Iteration_statement->kind==FOR_three_kind){
        
        printf("for( ");
        print_Expression_statement(tree_Iteration_statement->expression_statement);
        print_Expression_statement(tree_Iteration_statement->expression_statement2);
        print_Expression(tree_Iteration_statement->expression);
        printf(")\n");
        print_Statement(tree_Iteration_statement->statement);
        
    }else {printf("構文木エラー--tree_Iteration_statement--");}
    
}
void print_Jump_statement(struct Jump_statement *tree_Jump_statement){
    if(tree_Jump_statement->kind==GOTO_kind){
        printf("goto %s ;\n",tree_Jump_statement->str_ID);
    }else 
    if(tree_Jump_statement->kind==CONTINUE_kind){
        printf("continue ;\n");
    }else 
    if(tree_Jump_statement->kind==BREAK_kind){
        printf("break ;\n");
    }else 
    if(tree_Jump_statement->kind==RETURN_kind){
        printf("return ;\n");
    }else 
    if(tree_Jump_statement->kind==RETURN_expression_kind){
        printf("return ");
        print_Expression(tree_Jump_statement->expression);
        printf(";\n");

    }else {printf("構文木エラー--tree_Jump_statement--");}
}
void print_Translation_unit(struct Translation_unit *tree_Translation_unit){
    if(tree_Translation_unit->kind==external_declaration_kind){
        print_External_declaration(tree_Translation_unit->external_declaration);
    }else 
    if(tree_Translation_unit->kind==translation_unit_kind){
        print_Translation_unit(tree_Translation_unit->translation_unit);
        print_External_declaration(tree_Translation_unit->external_declaration);
    }else {printf("構文木エラー--tree_Translation_unit--");}
    
}
void print_External_declaration(struct External_declaration *tree_External_declaration){
    if(tree_External_declaration->kind==function_definition_kind){
        print_Function_definition(tree_External_declaration->function_definition);
    }else 
    if(tree_External_declaration->kind==declaration_kind_in_external_declaration){
        print_Declaration(tree_External_declaration->declaration);
    }else 
    {printf("構文木エラー--tree_External_declaration--");}
    
}
void print_Function_definition(struct Function_definition *tree_Function_definition){
    if(tree_Function_definition->kind==dec_dec_dec_kind){
        print_Declaration_specifiers(tree_Function_definition->declaration_specifiers);
        print_Declarator(tree_Function_definition->declarator);
        print_Declaration_list(tree_Function_definition->declaration_list);
        print_Compound_statement(tree_Function_definition->compound_statement);
    }else
    if(tree_Function_definition->kind==dec_dec_com_kind){
        print_Declaration_specifiers(tree_Function_definition->declaration_specifiers);
        print_Declarator(tree_Function_definition->declarator);
        print_Compound_statement(tree_Function_definition->compound_statement);
    }else
    if(tree_Function_definition->kind==declarator_dec_com_kind){
        print_Declarator(tree_Function_definition->declarator);
        print_Declaration_list(tree_Function_definition->declaration_list);
        print_Compound_statement(tree_Function_definition->compound_statement);
    }else
    if(tree_Function_definition->kind==declarator_com){
        print_Declarator(tree_Function_definition->declarator);
        print_Compound_statement(tree_Function_definition->compound_statement);
    }else{printf("構文木エラー--tree_Function_definition--");}
    
}