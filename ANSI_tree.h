#ifndef _tree_
#define _tree_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ANSI_print.h"
#include "ANSI_Sprint.h"
#include "ANSI_For_list.h"
#include "ANSI_tree.h"
// #include "ANSI_symbol_table.h" //エラーでる
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

#endif /* _tree_*/