#ifndef _print_
#define _print_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ANSI_print.h"
#include "ANSI_Sprint.h"
#include "ANSI_For_list.h"
#include "ANSI_tree.h"
#include "ANSI_symbol_table.h"
//For文が出現するときのiterarayionポインタ取得関数
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
#endif /*_print_*/