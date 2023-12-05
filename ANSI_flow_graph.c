#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ANSI_print.h"
#include "ANSI_Sprint.h"
#include "ANSI_For_list.h"
#include "ANSI_tree.h"
#include "ANSI_symbol_table.h"
#include "ANSI_flow_graph.h"
#include "ANSI_basic_block_list.h"

void flow_Primary_expression(struct Primary_expression *tree_Primary_expression){
    if(tree_Primary_expression->kind==IDENTIFIER_kind){
        //printf("%s", tree_Primary_expression-> str_ID);
    }
    else if(tree_Primary_expression->kind==CONSTANT_kind){
        //printf("%s", tree_Primary_expression-> str_CONST);
    }
    else if(tree_Primary_expression->kind==STRING_LITERAL_kind){
        //printf("%s", tree_Primary_expression-> str_STR);
    }
    else if(tree_Primary_expression->kind==expression_kind){
        flow_Expression(tree_Primary_expression->expression);
    }else{printf("構文木エラー--primary_expression--");}
}
void flow_Postfix_expression(struct Postfix_expression *tree_Postfix_expression){
    if(tree_Postfix_expression->kind==primary_expression_kind){
        flow_Primary_expression(tree_Postfix_expression->primary_expression);
    }else if(tree_Postfix_expression->kind==postfix_expression_expression_kind){
        flow_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("[");
        flow_Expression(tree_Postfix_expression->expression);
        //printf("]");
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_not_kind){
        
        flow_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("(");
        //printf(")");
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_argument_kind){
        flow_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("(");
        flow_Argument_expression_list(tree_Postfix_expression->argument_expression_list);
        //printf(")");
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_IDENTIFIER_kind){
        flow_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf(".%s",tree_Postfix_expression->str_ID);
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_PTR){
        flow_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("->");
        //printf("%s",tree_Postfix_expression->str_ID);
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_INC){
        flow_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("++");

    }else 
    if(tree_Postfix_expression->kind==postfix_expression_DEC){
        flow_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("--");
    }else {printf("構文木エラー--Postfix_expression--");}

}
void flow_Argument_expression_list(struct Argument_expression_list *tree_Argument_expression_list){
    if(tree_Argument_expression_list->kind==assignment_expression_kind){
        flow_Assignment_expression(tree_Argument_expression_list->assignment_expression);
    }else
    if(tree_Argument_expression_list->kind==argument_expression_list_kind){
        flow_Argument_expression_list(tree_Argument_expression_list->argument_expression_list);
        //printf(",");
        flow_Assignment_expression(tree_Argument_expression_list->assignment_expression);
    }else 
    {printf("構文木エラー--Argument_expression_list--");}
}
void flow_Unary_expression(struct Unary_expression *tree_Unary_expression){
    if(tree_Unary_expression->kind==postfix_expression_kind){
        flow_Postfix_expression(tree_Unary_expression->postfix_expression);
    }else
    if(tree_Unary_expression->kind==INC_OP_kind){
        //printf("++");
        flow_Unary_expression(tree_Unary_expression->unary_expression);
    }else
    if(tree_Unary_expression->kind==DEC_OP_kind){
        //printf("--");
        flow_Unary_expression(tree_Unary_expression->unary_expression);
    }else
    if(tree_Unary_expression->kind==unary_operator_kind){
        flow_Unary_operator(tree_Unary_expression->unary_operator);
        flow_Cast_expression(tree_Unary_expression->cast_expression);
    }else
    if(tree_Unary_expression->kind==SIZEOF_unary_expression_kind){
        //printf("sizeof");
        flow_Unary_expression(tree_Unary_expression->unary_expression);
    }else
    if(tree_Unary_expression->kind==SIZEOF_type_name_kind){
        //printf("sizeof(");
        flow_Type_name(tree_Unary_expression->type_name);
        //printf(")");
    }else
    {printf("構文木エラー--Unary_expression--");}
}
void flow_Unary_operator(struct Unary_operator *tree_Unary_operator){
    if(tree_Unary_operator->kind==AND_kind){
        //printf(" &");
    }else
    if(tree_Unary_operator->kind==MUL_kind){
        //printf(" *");
    }else
    if(tree_Unary_operator->kind==ADD_kind){
        //printf(" +");
    }else
    if(tree_Unary_operator->kind==SUB_kind){
        //printf(" -");
    }else
    if(tree_Unary_operator->kind==NAMI_kind){
        //printf(" ~");
    }else
    if(tree_Unary_operator->kind==BIKKURI_kind){
        //printf(" !");
    }else
    {printf("構文木エラー--Unary_operator--");}
}
void flow_Cast_expression(struct Cast_expression *tree_Cast_expression){
    if(tree_Cast_expression->kind==unary_expression_kind){
        flow_Unary_expression(tree_Cast_expression->unary_expression);
        
    }else
    if(tree_Cast_expression->kind==type_name_kind){
        //printf("(");
        flow_Type_name(tree_Cast_expression->type_name);
        //printf(")");
        flow_Cast_expression(tree_Cast_expression->cast_expression);
    }else {printf("構文木エラー--Cast_expression--");}
}
void flow_Multiplicative_expression(struct Multiplicative_expression *tree_Multiplicative_expression){
    if(tree_Multiplicative_expression->kind==cast_expression_kind){
        flow_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else
    if(tree_Multiplicative_expression->kind==MUL_expression_kind){
        flow_Multiplicative_expression(tree_Multiplicative_expression->multiplicative_expression);
        //printf("*");
        flow_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else
    if(tree_Multiplicative_expression->kind==DIV_expression_kind){
        flow_Multiplicative_expression(tree_Multiplicative_expression->multiplicative_expression);
        //printf("/");
        flow_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else
    if(tree_Multiplicative_expression->kind==PCT_expression_kind){
        flow_Multiplicative_expression(tree_Multiplicative_expression->multiplicative_expression);
        //printf("%%");
        flow_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else { printf("構文木エラー--Multiplicative_expression--");}
}
void flow_Additive_expression(struct Additive_expression *tree_Additive_expression){
    if(tree_Additive_expression->kind==multiplicative_expression_kind){
        flow_Multiplicative_expression(tree_Additive_expression->multiplicative_expression);
    }else
    if(tree_Additive_expression->kind==ADD_expression_kind){
        flow_Additive_expression(tree_Additive_expression->additive_expression);
        //printf("+");
        flow_Multiplicative_expression(tree_Additive_expression->multiplicative_expression);
    }else
    if(tree_Additive_expression->kind==SUB_expression_kind){
        flow_Additive_expression(tree_Additive_expression->additive_expression);
        //printf("-");
        flow_Multiplicative_expression(tree_Additive_expression->multiplicative_expression);
    }else { printf("構文木エラー--Additive_expression--");}
}
void flow_Shift_expression(struct Shift_expression *tree_Shift_expression){
    if(tree_Shift_expression->kind==additive_expression_kind){
        flow_Additive_expression(tree_Shift_expression->additive_expression);
    }else
    if(tree_Shift_expression->kind==shift_LEFT_OP_kind){
        flow_Shift_expression(tree_Shift_expression->shift_expression);
        //printf("<<");
        flow_Additive_expression(tree_Shift_expression->additive_expression);
    }else
    if(tree_Shift_expression->kind==shift_RIGHT_OP_kind){
        flow_Shift_expression(tree_Shift_expression->shift_expression);
        //printf(">>");
        flow_Additive_expression(tree_Shift_expression->additive_expression);
    }else
    { printf("構文木エラー--Shift_expression--");}
}
void flow_Relational_expression(struct Relational_expression *tree_Relational_expression){
    if(tree_Relational_expression->kind==shift_expression_kind){
        flow_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_sho){
        flow_Relational_expression(tree_Relational_expression->relational_expression);
        //printf("<");
        flow_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_dai){
        flow_Relational_expression(tree_Relational_expression->relational_expression);
        //printf(">");
        flow_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_LE_OP){
        flow_Relational_expression(tree_Relational_expression->relational_expression);
        //printf("<=");
        flow_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_GE){
        flow_Relational_expression(tree_Relational_expression->relational_expression);
        //printf(">=");
        flow_Shift_expression(tree_Relational_expression->shift_expression);
    }else { printf("構文木エラー--Relational_expression--");}
}
void flow_Equality_expression(struct Equality_expression *tree_Equality_expression){
    if(tree_Equality_expression->kind==relational_expression_kind){
        flow_Relational_expression(tree_Equality_expression->relational_expression);
        
    }else
    if(tree_Equality_expression->kind==eq_EQ_OP){
        flow_Equality_expression(tree_Equality_expression->equality_expression);
        //printf("==");
        flow_Relational_expression(tree_Equality_expression->relational_expression);
    }else
    if(tree_Equality_expression->kind==eq_NE_OP){
        flow_Equality_expression(tree_Equality_expression->equality_expression);
        //printf("!=");
        flow_Relational_expression(tree_Equality_expression->relational_expression);
    }else { printf("構文木エラー--Equality_expression--");}
}
void flow_And_expression(struct And_expression *tree_And_expression){
    if(tree_And_expression->kind==equality_expression_kind){
        flow_Equality_expression(tree_And_expression->equality_expression);
        
    }else 
    if(tree_And_expression->kind==and_expression_kind){
        flow_And_expression(tree_And_expression->and_expression);
        //printf(" &");
        flow_Equality_expression(tree_And_expression->equality_expression);
    }else { printf("構文木エラー--And_expression--");}
}
void flow_Exclusive_or_expression(struct Exclusive_or_expression *tree_Exclusive_or_expression){
    if(tree_Exclusive_or_expression->kind==and_expression_kind2){
        flow_And_expression(tree_Exclusive_or_expression->and_expression);
    }else
    if(tree_Exclusive_or_expression->kind==exclusive_or_expression_kind){
        flow_Exclusive_or_expression(tree_Exclusive_or_expression->exclusive_or_expression);
        //printf("^");
        flow_And_expression(tree_Exclusive_or_expression->and_expression);
    }else { printf("構文木エラー--tree_Exclusive_or_expression--");}
}
void flow_Inclusive_or_expression(struct Inclusive_or_expression *tree_Inclusive_or_expression){
    if(tree_Inclusive_or_expression->kind==exclusive_or_expression_kind2){
        flow_Exclusive_or_expression(tree_Inclusive_or_expression->exclusive_or_expression);
        
    }else
    if(tree_Inclusive_or_expression->kind==inclusive_or_expression_kind){
        flow_Inclusive_or_expression(tree_Inclusive_or_expression->inclusive_or_expression);
        //printf("|");
        flow_Exclusive_or_expression(tree_Inclusive_or_expression->exclusive_or_expression);
    }else { printf("構文木エラー--tree_Inclusive_or_expression--");}
}
void flow_Logical_and_expression(struct Logical_and_expression *tree_Logical_and_expression){
    if(tree_Logical_and_expression->kind==inclusive_or_expression_kind2){
        flow_Inclusive_or_expression(tree_Logical_and_expression->inclusive_or_expression);
        
    }else
    if(tree_Logical_and_expression->kind==logical_and_expression_kind){
        flow_Logical_and_expression(tree_Logical_and_expression->logical_and_expression);
        //printf(" &&");
        flow_Inclusive_or_expression(tree_Logical_and_expression->inclusive_or_expression);

    }else { printf("構文木エラー--tree_Logical_and_expression--");}
    
}
void flow_Logical_or_expression(struct Logical_or_expression *tree_Logical_or_expression){
    if(tree_Logical_or_expression->kind==logical_and_expression_kind2){
        flow_Logical_and_expression(tree_Logical_or_expression->logical_and_expression);
        
    }else 
    if(tree_Logical_or_expression->kind==logical_or_expression_kind){
        flow_Logical_or_expression(tree_Logical_or_expression->logical_or_expression);
        flow_Logical_and_expression(tree_Logical_or_expression->logical_and_expression);
        

    }else { printf("構文木エラー--tree_Logical_or_expression--");}
    
}
void flow_Conditional_expression(struct Conditional_expression *tree_Conditional_expression){
    if(tree_Conditional_expression->kind==logical_or_expression_kind2){
        flow_Logical_or_expression(tree_Conditional_expression->logical_or_expression);
        
    }else
    if(tree_Conditional_expression->kind==logical_or_expression_expression_kind){
        flow_Logical_or_expression(tree_Conditional_expression->logical_or_expression);
        //printf("?");
        flow_Expression(tree_Conditional_expression->expression);
        //printf(":");
        flow_Conditional_expression(tree_Conditional_expression->conditional_expression);
    }else { printf("構文木エラー--tree_Conditional_expression--");}
}
void flow_Assignment_expression(struct Assignment_expression *tree_Assignment_expression){
    if(tree_Assignment_expression->kind==conditional_expression_kind2){
        flow_Conditional_expression(tree_Assignment_expression->conditional_expression);
    }else
    if(tree_Assignment_expression->kind==unary_expression_kind2){
        flow_Unary_expression(tree_Assignment_expression->unary_expression);
        flow_Assignment_operator(tree_Assignment_expression->assignment_operator);
        flow_Assignment_expression(tree_Assignment_expression->assignment_expression);
    }else { printf("構文木エラー--tree_Assignment_expression--");}
}
void flow_Assignment_operator(struct Assignment_operator *tree_Assignment_operator){
    if(tree_Assignment_operator->kind==EQUAL_kind){
        //printf(" =");
    }else
    if(tree_Assignment_operator->kind==MUL_ASSIGN_kind){
        //printf(" *=");
    }else
    if(tree_Assignment_operator->kind==DIV_ASSIGN_kind){
        //printf(" /=");
    }else
    if(tree_Assignment_operator->kind==MOD_ASSIGN_kind){
        //printf(" %%=");
    }else
    if(tree_Assignment_operator->kind==ADD_ASSIGN_kind){
        //printf(" +=");
    }else
    if(tree_Assignment_operator->kind==SUB_ASSIGN_kind){
        //printf(" -=");
    }else
    if(tree_Assignment_operator->kind==LEFT_ASSIGN_kind){
        //printf(" <<=");
    }else
    if(tree_Assignment_operator->kind==RIGHT_ASSIGN_kind){
        //printf(" >>=");
    }else
    if(tree_Assignment_operator->kind==AND_ASSIGN_kind){
        //printf(" &=");
    }else
    if(tree_Assignment_operator->kind==XOR_ASSIGN_kind){
        //printf(" ^=");
    }else
    if(tree_Assignment_operator->kind==OR_ASSIGN_kind){
        //printf(" |=");
    }else { printf("構文木エラー--tree_Assignment_operator--");}

    
}
void flow_Expression(struct Expression *tree_Expression){
    if(tree_Expression->kind==assignment_expression_kind2){
        flow_Assignment_expression(tree_Expression->assignment_expression);
    
    }else
    if(tree_Expression->kind==expression_kind2){
        flow_Expression(tree_Expression->expression);
        //printf(",");
        flow_Assignment_expression(tree_Expression->assignment_expression);
    }else{ printf("構文木エラー--tree_Expression--");}
}
void flow_Constant_expression(struct Constant_expression *tree_Constant_expression){
    if(tree_Constant_expression->kind==conditional_expression_kind3){
        flow_Conditional_expression(tree_Constant_expression->conditional_expression);
    }else{ printf("構文木エラー--tree_Constant_expression--");}
}
void flow_Declaration(struct Declaration *tree_Declaration){
    if(tree_Declaration->kind==dec_spe_kind){
        flow_Declaration_specifiers(tree_Declaration->declaration_specifiers);
        //printf(";\n");
    }else
    if(tree_Declaration->kind==dec_spe_ini_kind){
        flow_Declaration_specifiers(tree_Declaration->declaration_specifiers);
        flow_Init_declarator_list(tree_Declaration->init_declarator_list);
        //printf(";\n");
    }else { printf("構文木エラー--tree_Declaration--");}
}
void flow_Declaration_specifiers(struct Declaration_specifiers *tree_Declaration_specifiers){
    if(tree_Declaration_specifiers->kind==storage_class_specifier_kind){
        flow_Storage_class_specifier(tree_Declaration_specifiers->storage_class_specifier);
    }else
    if(tree_Declaration_specifiers->kind==storage_class_specifier_declaration_kind){
        flow_Storage_class_specifier(tree_Declaration_specifiers->storage_class_specifier);
        flow_Declaration_specifiers(tree_Declaration_specifiers->declaration_specifiers);
    
    }else
    if(tree_Declaration_specifiers->kind==type_specifier_kind){
        flow_Type_specifier(tree_Declaration_specifiers->type_specifier);
    
    }else
    if(tree_Declaration_specifiers->kind==type_specifier_declaration_kind){
        flow_Type_specifier(tree_Declaration_specifiers->type_specifier);
        flow_Declaration_specifiers(tree_Declaration_specifiers->declaration_specifiers);
    
    }else
    if(tree_Declaration_specifiers->kind==type_qualifier_kind){
        flow_Type_qualifier(tree_Declaration_specifiers->type_qualifier);
    }else
    if(tree_Declaration_specifiers->kind==type_qualifier_declaration_kind){
        flow_Type_qualifier(tree_Declaration_specifiers->type_qualifier);
        flow_Declaration_specifiers(tree_Declaration_specifiers->declaration_specifiers);
    }else { printf("構文木エラー--tree_Declaration_specifiers--");}
}
void flow_Init_declarator_list(struct Init_declarator_list *tree_Init_declarator_list){
    if(tree_Init_declarator_list->kind==init_declarator_kind){
        flow_Init_declarator(tree_Init_declarator_list->init_declarator);
        
    }else
    if(tree_Init_declarator_list->kind==init_declarator_list_kind){
        flow_Init_declarator_list(tree_Init_declarator_list->init_declarator_list);
        //printf(",");
        flow_Init_declarator(tree_Init_declarator_list->init_declarator);
    }else{ printf("構文木エラー--tree_Init_declarator_list--");}
}
void flow_Init_declarator(struct Init_declarator *tree_Init_declarator){
    if(tree_Init_declarator->kind==declarator_kind){
        flow_Declarator(tree_Init_declarator->declarator);
    }else
    if(tree_Init_declarator->kind==declarator_EQUAL_kind){
        flow_Declarator(tree_Init_declarator->declarator);
        //printf(" =");
        flow_Initializer(tree_Init_declarator->initializer);
    }else{ printf("構文木エラー--tree_Init_declarator--");}
}
void flow_Storage_class_specifier(struct Storage_class_specifier *tree_Storage_class_specifier){
    if(tree_Storage_class_specifier->kind==TYPEDEF_kind){
        //printf("typdef ");
    }else
    if(tree_Storage_class_specifier->kind==EXTERN_kind){
        //printf("extern ");
    }else
    if(tree_Storage_class_specifier->kind==STATIC_kind){
        //printf("static ");
    }else
    if(tree_Storage_class_specifier->kind==AUTO_kind){
        //printf("auto ");
    }else
    if(tree_Storage_class_specifier->kind==REGISTER_kind){
        //printf("register");
    }else
    { printf("構文木エラー--tree_Storage_class_specifier--");}
}
void flow_Type_specifier(struct Type_specifier *tree_Type_specifier){
    if(tree_Type_specifier->kind==VOID_kind){
        //printf("void ");
    }else
    if(tree_Type_specifier->kind==CHAR_kind){
        //printf("char ");
    }else
    if(tree_Type_specifier->kind==SHORT_kind){
        //printf("short ");
    }else
    if(tree_Type_specifier->kind==INT_kind){
        //printf("int ");
    }else
    if(tree_Type_specifier->kind==LONG_kind){
        //printf("long ");
    }else
    if(tree_Type_specifier->kind==FLOAT_kind){
        //printf("float ");
    }else
    if(tree_Type_specifier->kind==DOUBLE_kind){
        //printf("double ");
    }else
    if(tree_Type_specifier->kind==SIGNED_kind){
        //printf("signed ");
    }else
    if(tree_Type_specifier->kind==UNSIGNED_kind){
        //printf("unsigned ");
    }else
    if(tree_Type_specifier->kind==struct_or_union_specifier_kind){
        flow_Struct_or_union_specifier(tree_Type_specifier->struct_or_union_specifier);
    }else
    if(tree_Type_specifier->kind==enum_specifier_kind){
        flow_Enum_specifier(tree_Type_specifier->enum_specifier);
    }else
    if(tree_Type_specifier->kind==TYPE_NAME_kind){
        //printf("type_name ");
    }else
    if(tree_Type_specifier->kind==MPFI_kind){
        //printf("mpfi_t ");
    }else
    if(tree_Type_specifier->kind==GMPFI_kind){
        //printf("gmpfi_t ");
    }else
    if(tree_Type_specifier->kind==MPFR_kind){
        //printf("mpfr_t ");
    }else
    { printf("構文木エラー--tree_Type_specifier--");}
}
void flow_Struct_or_union_specifier(struct Struct_or_union_specifier *tree_Struct_or_union_specifier){
    if(tree_Struct_or_union_specifier->kind==struct_ID_struct_kind){
        flow_Struct_or_union(tree_Struct_or_union_specifier->struct_or_union);
        //printf(" %s{",tree_Struct_or_union_specifier->str_ID);
        flow_Struct_declaration_list(tree_Struct_or_union_specifier->struct_declaration_list);
        //printf("}");
    }else 
    if(tree_Struct_or_union_specifier->kind==struct_struct){
        flow_Struct_or_union(tree_Struct_or_union_specifier->struct_or_union);
        //printf("{");
        flow_Struct_declaration_list(tree_Struct_or_union_specifier->struct_declaration_list);
        //printf("}");
    }else
    if(tree_Struct_or_union_specifier->kind==struct_ID){
        flow_Struct_or_union(tree_Struct_or_union_specifier->struct_or_union);
        //printf(" %s",tree_Struct_or_union_specifier->str_ID);
    }else
    {printf("構文木エラー--tree_Struct_or_union_specifier--");}
    
}
void flow_Struct_or_union(struct Struct_or_union *tree_Struct_or_union){
    if(tree_Struct_or_union->kind==STRUCT_kind){
        //printf("struct ");
    }else 
    if(tree_Struct_or_union->kind==UNION_kind){
        //printf("union" );
    }else
    {printf("構文木エラー--tree_Struct_or_union--");}
}
void flow_Struct_declaration_list(struct Struct_declaration_list *tree_Struct_declaration_list){
    if(tree_Struct_declaration_list->kind==struct_declaration_kind){
        flow_Struct_declaration(tree_Struct_declaration_list->struct_declaration);
        
    }else 
    if(tree_Struct_declaration_list->kind==struct_declaration_list_kind){
        flow_Struct_declaration_list(tree_Struct_declaration_list->struct_declaration_list);
        flow_Struct_declaration(tree_Struct_declaration_list->struct_declaration);
    }else
    {printf("構文木エラー--tree_Struct_declaration_list--");}
}
void flow_Struct_declaration(struct Struct_declaration *tree_Struct_declaration){
    if(tree_Struct_declaration->kind==specifier_qualifier_list_kind){
        flow_Specifier_qualifier_list(tree_Struct_declaration->specifier_qualifier_list);
        flow_Struct_declarator_list(tree_Struct_declaration->struct_declarator_list);
        //printf(";\n");
    }else {printf("構文木エラー--tree_Struct_declaration--");}
}
void flow_Specifier_qualifier_list(struct Specifier_qualifier_list *tree_Specifier_qualifier_list){
    if(tree_Specifier_qualifier_list->kind==type_spe_spe_kind){
        flow_Type_specifier(tree_Specifier_qualifier_list->type_specifier);
        flow_Specifier_qualifier_list(tree_Specifier_qualifier_list->specifier_qualifier_list);
        
    }else
    if(tree_Specifier_qualifier_list->kind==type_spe_kind){
        flow_Type_specifier(tree_Specifier_qualifier_list->type_specifier);
    }else
    if(tree_Specifier_qualifier_list->kind==type_qua_spe_kind){
        flow_Type_qualifier(tree_Specifier_qualifier_list->type_qualifier);
        flow_Specifier_qualifier_list(tree_Specifier_qualifier_list->specifier_qualifier_list);
        
    }else 
    if(tree_Specifier_qualifier_list->kind==type_qua_kind){
        flow_Type_qualifier(tree_Specifier_qualifier_list->type_qualifier);
    }else{printf("構文木エラー--tree_Specifier_qualifier_list--");}
    
}
void flow_Struct_declarator_list(struct Struct_declarator_list *tree_Struct_declarator_list){
    if(tree_Struct_declarator_list->kind==struct_declarator_kind){
        flow_Struct_declarator(tree_Struct_declarator_list->struct_declarator);
    }else
    if(tree_Struct_declarator_list->kind==struct_declarator_list_kind){
        flow_Struct_declarator_list(tree_Struct_declarator_list->struct_declarator_list);
        //printf(",");
        flow_Struct_declarator(tree_Struct_declarator_list->struct_declarator);

    }else{printf("構文木エラー--tree_Struct_declarator_list--");}
}
void flow_Struct_declarator(struct Struct_declarator *tree_Struct_declarator){
    if(tree_Struct_declarator->kind==dec_kind){
        flow_Declarator(tree_Struct_declarator->declarator);
    }else
    if(tree_Struct_declarator->kind==con_kind){
        //printf(":");
        flow_Constant_expression(tree_Struct_declarator->constant_expression);
    }else
    if(tree_Struct_declarator->kind==dec_con_kind){
        flow_Declarator(tree_Struct_declarator->declarator);
        //printf(":");
        flow_Constant_expression(tree_Struct_declarator->constant_expression);
    }
    else{printf("構文木エラー--tree_Struct_declarator--");}
    
}
void flow_Enum_specifier(struct Enum_specifier *tree_Enum_specifier){
    if(tree_Enum_specifier->kind==ENUM_enu_kind){
        //printf("enum {");
        flow_Enumerator_list(tree_Enum_specifier->enumerator_list);
        //printf("}");

    }else if(tree_Enum_specifier->kind==ENUM_ID_enu_kind){
        //printf("enum ");
        //printf("%s ",tree_Enum_specifier->str_ID);
        //printf("{");
        flow_Enumerator_list(tree_Enum_specifier->enumerator_list);
        //printf("}");
    }else
    if(tree_Enum_specifier->kind==ENUM_ID_kind){
        //printf("enum ");
        //printf("%s ",tree_Enum_specifier->str_ID);
    }else{printf("構文木エラー--tree_Enum_specifier--");}

    
}
void flow_Enumerator_list(struct Enumerator_list *tree_Enumerator_list){
    if(tree_Enumerator_list->kind==enumerator_kind){
        flow_Enumerator(tree_Enumerator_list->enumerator);
    }else 
    if(tree_Enumerator_list->kind==enumerator_list_kind){
        flow_Enumerator_list(tree_Enumerator_list->enumerator_list);
        //printf(",");
        flow_Enumerator(tree_Enumerator_list->enumerator);
    }else
    {printf("構文木エラー--tree_Enumerator_list--");}
}
void flow_Enumerator(struct Enumerator *tree_Enumerator){
    if(tree_Enumerator->kind==ID_kind){
        //printf(" %s",tree_Enumerator->str_ID);
    }else 
    if(tree_Enumerator->kind==ID_EQUAL_kind){
        //printf(" %s",tree_Enumerator->str_ID);
        flow_Constant_expression(tree_Enumerator->constant_expression);
    }else
    {printf("構文木エラー--tree_Enumerator--");}
    
}
void flow_Type_qualifier(struct Type_qualifier *tree_Type_qualifier){
    if(tree_Type_qualifier->kind==CONST_kind){
        //printf("const ");
    }else
    if(tree_Type_qualifier->kind==VOLATILE_kind){
        //printf("volatile ");
    }else
    {printf("構文木エラー--tree_Type_qualifier--");}
    
}
void flow_Declarator(struct Declarator *tree_Declarator){
    if(tree_Declarator->kind==pointer_kind){
        flow_Pointer(tree_Declarator->pointer);
        flow_Direct_declarator(tree_Declarator->direct_declarator);
        
    }else
    if(tree_Declarator->kind==direct_declarator_kind){
        flow_Direct_declarator(tree_Declarator->direct_declarator);
    }else  {printf("構文木エラー--tree_Declarator--");}
    
}
void flow_Direct_declarator(struct Direct_declarator *tree_Direct_declarator){
    if(tree_Direct_declarator->kind==ID_kind2){
        //printf(" %s ",tree_Direct_declarator->str_ID);
    }else 
    if(tree_Direct_declarator->kind==declarator_kind2){
        //printf("(");
        flow_Declarator(tree_Direct_declarator->declarator);
        //printf(")");
    }else
    if(tree_Direct_declarator->kind==dir_dec_con_kind){
        flow_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("[");
        flow_Constant_expression(tree_Direct_declarator->constant_expression);
        //printf("]");
    }else
    if(tree_Direct_declarator->kind==dir_dec_kind){
        flow_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("[ ]");
    }else
    if(tree_Direct_declarator->kind==dir_dec_par_kind){
        flow_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("(");
        flow_Parameter_type_list(tree_Direct_declarator->parameter_type_list);
        //printf(")");
    }else
    if(tree_Direct_declarator->kind==dir_dec_ide){
        flow_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("(");
        flow_Identifier_list(tree_Direct_declarator->identifier_list);
        //printf(")");
    }else
    if(tree_Direct_declarator->kind==dir_dec_kind2){
        flow_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("( )");
    }else
    {printf("構文木エラー--tree_Direct_declarator--");}
}
void flow_Pointer(struct Pointer *tree_Pointer){
    if(tree_Pointer->kind==P_kind){
        //printf("*");
        
    }else 
    if(tree_Pointer->kind==P_type_kind){
        //printf("*");
        flow_Type_qualifier_list(tree_Pointer->type_qualifier_list);
    }else 
    if(tree_Pointer->kind==P_pointer_kind){
        //printf("*");
        flow_Pointer(tree_Pointer->pointer);
    }else 
    if(tree_Pointer->kind==P_type_pointer_kind){
        //printf("*");
        flow_Type_qualifier_list(tree_Pointer->type_qualifier_list);
        flow_Pointer(tree_Pointer->pointer);
    }else 
    {printf("構文木エラー--tree_Pointer--");}
    
}
void flow_Type_qualifier_list(struct Type_qualifier_list *tree_Type_qualifier_list){
    if(tree_Type_qualifier_list->kind==type_qualifier_kind2){
        flow_Type_qualifier(tree_Type_qualifier_list->type_qualifier);
    }else 
    if(tree_Type_qualifier_list->kind==type_qualifier_list_kind){
        flow_Type_qualifier_list(tree_Type_qualifier_list->type_qualifier_list);
        flow_Type_qualifier(tree_Type_qualifier_list->type_qualifier);
    }else 
    {printf("構文木エラー--tree_Type_qualifier_list--");}
}
void flow_Parameter_type_list(struct Parameter_type_list *tree_Parameter_type_list){
    if(tree_Parameter_type_list->kind==parameter_list_kind){
        flow_Parameter_list(tree_Parameter_type_list->parameter_list);
    }else 
    if(tree_Parameter_type_list->kind==parameter_list_ELL_kind){
        flow_Parameter_list(tree_Parameter_type_list->parameter_list);
        //printf(" , ...");
    }else 
    {printf("構文木エラー--tree_Parameter_type_list--");}
    
}
void flow_Parameter_list(struct Parameter_list *tree_Parameter_list){
    if(tree_Parameter_list->kind==parameter_declaration_kind){
        flow_Parameter_declaration(tree_Parameter_list->parameter_declaration);
    }else 
    if(tree_Parameter_list->kind==parameter_list_kind2){
        flow_Parameter_list(tree_Parameter_list->parameter_list);
        //printf(", ");
        flow_Parameter_declaration(tree_Parameter_list->parameter_declaration);
    }else 
    {printf("構文木エラー--tree_Parameter_list--");}
}
void flow_Parameter_declaration(struct Parameter_declaration *tree_Parameter_declaration){
    if(tree_Parameter_declaration->kind==dec_dec_kind){
        flow_Declaration_specifiers(tree_Parameter_declaration->declaration_specifiers);
        flow_Declarator(tree_Parameter_declaration->declarator);
    }else 
    if(tree_Parameter_declaration->kind==dec_abs_kind){
        flow_Declaration_specifiers(tree_Parameter_declaration->declaration_specifiers);
        flow_Abstract_declarator(tree_Parameter_declaration->abstract_declarator);
    }else 
    if(tree_Parameter_declaration->kind==dec_kind2){
        flow_Declaration_specifiers(tree_Parameter_declaration->declaration_specifiers);
    }else {printf("構文木エラー--tree_Parameter_declaration--");}
    
}
void flow_Identifier_list(struct Identifier_list *tree_Identifier_list){
    if(tree_Identifier_list->kind==ID_kind_in_identifier_list){
        //printf("%s",tree_Identifier_list->str_ID);
    }else 
    if(tree_Identifier_list->kind==identifier_list_ID_in_identifier_list){
        flow_Identifier_list(tree_Identifier_list->identifier_list);
        //printf(", %s",tree_Identifier_list->str_ID);
    }else 
    {printf("構文木エラー--tree_Identifier_list--");}
}
void flow_Type_name(struct Type_name *tree_Type_name){
    if(tree_Type_name->kind==spe_kind){
        flow_Specifier_qualifier_list(tree_Type_name->specifier_qualifier_list);
        
    }else
    if(tree_Type_name->kind==spe_abs_kind){
        flow_Specifier_qualifier_list(tree_Type_name->specifier_qualifier_list);
         flow_Abstract_declarator(tree_Type_name->abstract_declarator);
    }else{printf("構文木エラー--tree_Type_name--");}
}
void flow_Abstract_declarator(struct Abstract_declarator *tree_Abstract_declarator){
    if(tree_Abstract_declarator->kind==poi_kind_in_abs){
        flow_Pointer(tree_Abstract_declarator->pointer);
    }else 
    if(tree_Abstract_declarator->kind==dir_kind_in_abs){
        flow_Direct_abstract_declarator(tree_Abstract_declarator->direct_abstract_declarator);
    }else 
    if(tree_Abstract_declarator->kind==poi_dir_kind_in_abs){
        flow_Pointer(tree_Abstract_declarator->pointer);
        flow_Direct_abstract_declarator(tree_Abstract_declarator->direct_abstract_declarator);
    }else {printf("構文木エラー--tree_Abstract_declarator--");}
}
void flow_Direct_abstract_declarator(struct Direct_abstract_declarator *tree_Direct_abstract_declarator){
    if(tree_Direct_abstract_declarator->kind==abs_kind){
        flow_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
    }else 
    if(tree_Direct_abstract_declarator->kind==NOT_kind){
        //printf("[ ]");
    }else 
    if(tree_Direct_abstract_declarator->kind==constant_expression_kind){
        //printf("[");
        flow_Constant_expression(tree_Direct_abstract_declarator->constant_expression);
        //printf("]");
    }else 
    if(tree_Direct_abstract_declarator->kind==dir_NOT_kind){
        flow_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        //printf("[ ]");
    }else 
    if(tree_Direct_abstract_declarator->kind==dir_con_kind){
        flow_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
       // printf("[");
        flow_Constant_expression(tree_Direct_abstract_declarator->constant_expression);
        //printf("]");
    }else 
    if(tree_Direct_abstract_declarator->kind==NOT_kind2){
        //printf("( )");
    }else 
    if(tree_Direct_abstract_declarator->kind==par_kind){
        //printf("(");
        flow_Parameter_type_list(tree_Direct_abstract_declarator->parameter_type_list);
        //printf(")");
    }else 
    if(tree_Direct_abstract_declarator->kind==dir_NOT_kind3){
        flow_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        //printf("( )");
    }else
    if(tree_Direct_abstract_declarator->kind==dir_par_kind){
        flow_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        //printf("( ");
        flow_Parameter_type_list(tree_Direct_abstract_declarator->parameter_type_list);
        //printf(" )");
    }else
    {printf("構文木エラー--tree_Direct_abstract_declarator--");}
    
}
void flow_Initializer(struct Initializer *tree_Initializer){
    if(tree_Initializer->kind==ass_exp_kind){
        flow_Assignment_expression(tree_Initializer->assignment_expression);
        
    }else 
    if(tree_Initializer->kind==ini_NOT){
        //printf("{");
        flow_Initializer_list(tree_Initializer->initializer_list);
        //printf("}");

    }else 
    if(tree_Initializer->kind==ini_KNM){
        //printf("{");
        flow_Initializer_list(tree_Initializer->initializer_list);
        //printf(",");
        //printf("}");
    }else {printf("構文木エラー--tree_Initializer--");}
    
}
void flow_Initializer_list(struct Initializer_list *tree_Initializer_list){
    if(tree_Initializer_list->kind==ini_kind){
        flow_Initializer(tree_Initializer_list->initializer);
        
    }else 
    if(tree_Initializer_list->kind==ini_ini_kind){
        flow_Initializer_list(tree_Initializer_list->initializer_list);
        //printf(",");
        flow_Initializer(tree_Initializer_list->initializer);
    }else {printf("構文木エラー--tree_Initializer_list--");}
    
    
}
void flow_Statement (struct Statement *tree_Statement){
    if(tree_Statement->kind==label_kind){
        flow_Labeled_statement(tree_Statement->labeled_statement);
        
    }else 
    if(tree_Statement->kind==compo_kind){
        flow_Compound_statement(tree_Statement->compound_statement);
    }else 
    if(tree_Statement->kind==expre_kind){
        flow_Expression_statement(tree_Statement->expression_statement);
    }else 
    if(tree_Statement->kind==selec_kind){
        flow_Selection_statement(tree_Statement->selection_statement);
    }else 
    if(tree_Statement->kind==itera_kind){
        flow_Iteration_statement(tree_Statement->iteration_statement);
    }else 
    if(tree_Statement->kind==jump_kind){
        flow_Jump_statement(tree_Statement->jump_statement);
    }else 
    if(tree_Statement->kind==decla_kind){
        flow_Declaration(tree_Statement->declaration);
    }else {printf("構文木エラー--tree_Statement--");}
    
    
}
void flow_Labeled_statement(struct Labeled_statement *tree_Labeled_statement){
    if(tree_Labeled_statement->kind==ID_sta_kind){
        //printf("%s :",tree_Labeled_statement->str_ID);
        flow_Statement(tree_Labeled_statement->statement);
    }else 
    if(tree_Labeled_statement->kind==CASE_con_kind){
        //printf("case ");
        flow_Constant_expression(tree_Labeled_statement->constant_expression);
        //printf(" : ");
        flow_Statement(tree_Labeled_statement->statement);
    }else 
    if(tree_Labeled_statement->kind==DEFAULT_sta_kind){
        //printf("default :");
        flow_Statement(tree_Labeled_statement->statement);
    }else {printf("構文木エラー--tree_Labeled_statement--");}
    
}
void flow_Compound_statement(struct Compound_statement *tree_Compound_statement){
    if(tree_Compound_statement->kind==NOT_kind3){
        //printf("{ \n }");
    }else 
    if(tree_Compound_statement->kind==statement_list_kind){
        //printf("{\n");
        flow_Statement_list(tree_Compound_statement->statement_list);
        //printf("\n}");
    }else{printf("構文木エラー--tree_Compound_statement--");}
    
}
void flow_Declaration_list(struct Declaration_list *tree_Declaration_list){
    if(tree_Declaration_list->kind==declaration_kind){
        flow_Declaration(tree_Declaration_list->declaration);
        
    } else
    if(tree_Declaration_list->kind==declaration_list_kind){
        flow_Declaration_list(tree_Declaration_list->declaration_list);
        flow_Declaration(tree_Declaration_list->declaration);
    } else
    {printf("構文木エラー--tree_Declaration_list--");}
    
}
bool statement_flag=true;//startに入れたら移動statementが出現するまでfalse

struct Statement_list *temp_st_start;//これに最初のやつを入れるとstatement_flagをfalseにする。
struct Statement_list *temp_st_end;//これにendstatementポインタを入れていく。もし次が移動するやつなら移動statementの直前ポインタを入れて、pushする。
void flow_Statement_list(struct Statement_list *tree_Statement_list){
    if(tree_Statement_list->kind==statement_kind){ //st_list: st
        //移動しないやつはtree_Statement_list->kind=decla_kindまたはexpre_kind,label_kind,
        //もしst_listの先のstが後に移動するやつなら、push
        if(statement_flag==true){//st_kindの場合は1行しかない時のための対処かな？
            temp_st_start=tree_Statement_list;
            statement_flag=false;//移動statementが出るまでfalseつまりは移動までstartポインタを固定
        }//OK
        /*if(tree_Statement_list->statement->kind != ((decla_kind || label_kind) || expre_kind)){
            push_basic_block(block_ls,temp_st_start,temp_st_end);
            statement_flag=true;
        */
        //printf("-----\n");
        //Sprint_Statement(tree_Statement_list->statement);
        //printf("\n-----");
        temp_st_end=tree_Statement_list;//endを更新
        push_basic_block(block_ls,temp_st_start,temp_st_end);
        statement_flag=true;
        flow_Statement(tree_Statement_list->statement);
    }else if(tree_Statement_list->kind==statement_list_kind2){  //st_list:  st st_list
        if(statement_flag==true){
            temp_st_start=tree_Statement_list;
            statement_flag=false;//移動statementが出るまでfalseつまりは移動までstartポインタを固定
        }//OK
        //もし移動系なら(移動しないやつじゃないなら)
        if((tree_Statement_list->statement->kind != decla_kind) &&  (tree_Statement_list->statement->kind != label_kind) && (tree_Statement_list->statement->kind != expre_kind)){
            push_basic_block(block_ls,temp_st_start,temp_st_end);
            statement_flag=true;
        }else{
            temp_st_end=tree_Statement_list;
            //printf("-----\n");
            //Sprint_Statement_list(tree_Statement_list);
            //printf("\n-----");
        }
        
        flow_Statement(tree_Statement_list->statement);
        flow_Statement_list(tree_Statement_list->statement_list);
        
    }else {printf("構文木エラー--tree_Statement_list--");}
    
}
void flow_Expression_statement(struct Expression_statement *tree_Expression_statement){
    if(tree_Expression_statement->kind==SEMIC_kind){
        //printf(";\n");
    }else 
    if(tree_Expression_statement->kind==expression_SEMIC_kind){
        flow_Expression(tree_Expression_statement->expression);
        //printf(";\n");
    }else {printf("構文木エラー--tree_Expression_statement--");}
    
}
void flow_Selection_statement(struct Selection_statement *tree_Selection_statement){
    if(tree_Selection_statement->kind==IF_expression_kind){
        
        //printf("if(");
        flow_Expression(tree_Selection_statement->expression);
        //printf(")");
        flow_Statement(tree_Selection_statement->statement);
        
    }else 
    if(tree_Selection_statement->kind==IF_expression_ELSE_kind){
        //printf("if(");
        flow_Expression(tree_Selection_statement->expression);
        //printf(")");
        flow_Statement(tree_Selection_statement->statement);
        
        //printf(" else ");
        
        flow_Statement(tree_Selection_statement->statement2);
        
    }else 
    if(tree_Selection_statement->kind==SWITCH_kind){
        //printf("switch (");
        flow_Expression(tree_Selection_statement->expression);
        //printf(")");
        flow_Statement(tree_Selection_statement->statement);
    }else {printf("構文木エラー--tree_Selection_statement--");}
    
}
void flow_Iteration_statement(struct Iteration_statement *tree_Iteration_statement){
    if(tree_Iteration_statement->kind==WHILE_kind){
        //printf("while(");
        flow_Expression(tree_Iteration_statement->expression);
        //printf(")\n");
        flow_Statement(tree_Iteration_statement->statement);
    }else 
    if(tree_Iteration_statement->kind==DO_kind){
        //printf("do ");
        flow_Statement(tree_Iteration_statement->statement);
        //printf("while(");
        flow_Expression(tree_Iteration_statement->expression);
        //printf(");\n");
    }else 
    if(tree_Iteration_statement->kind==FOR_two_kind){
        //printf("for( ");
        flow_Expression_statement(tree_Iteration_statement->expression_statement);
        flow_Expression_statement(tree_Iteration_statement->expression_statement2);
        //printf(")\n");
    
        // ここでリストに入れる関数
        
    }else 
    if(tree_Iteration_statement->kind==FOR_three_kind){
        //printf("for( ");
        flow_Expression_statement(tree_Iteration_statement->expression_statement);
        flow_Expression_statement(tree_Iteration_statement->expression_statement2);
        flow_Expression(tree_Iteration_statement->expression);
        //printf(")\n");
        //printf("pushしたポインタFORsssls=%p\n",ls);
        // ここでリストに入れる関数
        //printf("before_push_tree_iteraration_ptr\n");

        
        //printf("after_push_tree_iteraration_ptr\n");
        
    }else {printf("構文木エラー--tree_Iteration_statement--");}
    
}

void flow_Jump_statement(struct Jump_statement *tree_Jump_statement){
    if(tree_Jump_statement->kind==GOTO_kind){
        //printf("goto %s ;\n",tree_Jump_statement->str_ID);
    }else 
    if(tree_Jump_statement->kind==CONTINUE_kind){
        //printf("continue ;\n");
    }else 
    if(tree_Jump_statement->kind==BREAK_kind){
        //printf("break ;\n");
    }else 
    if(tree_Jump_statement->kind==RETURN_kind){
        //printf("return ;\n");
    }else 
    if(tree_Jump_statement->kind==RETURN_expression_kind){
        //printf("return ");
        flow_Expression(tree_Jump_statement->expression);
        //printf(";\n");

    }else {printf("構文木エラー--tree_Jump_statement--");}
}
void flow_Translation_unit(struct Translation_unit *tree_Translation_unit){
    if(tree_Translation_unit->kind==external_declaration_kind){
        flow_External_declaration(tree_Translation_unit->external_declaration);
    }else 
    if(tree_Translation_unit->kind==translation_unit_kind){
        flow_Translation_unit(tree_Translation_unit->translation_unit);
        flow_External_declaration(tree_Translation_unit->external_declaration);
    }else {printf("構文木エラー--tree_Translation_unit--");}
    
}
void flow_External_declaration(struct External_declaration *tree_External_declaration){
    if(tree_External_declaration->kind==function_definition_kind){
        flow_Function_definition(tree_External_declaration->function_definition);
    }else 
    if(tree_External_declaration->kind==declaration_kind_in_external_declaration){
        flow_Declaration(tree_External_declaration->declaration);
        // ここで代入
        //struct statemnt_list *start = malloc(sizeof(struct statemnt_list));
        //struct statemnt_list *end = malloc(sizeof(struct statemnt_list));
        //push(struct basic_block *start);
        //struct st_list->declaration=tree_External_declaration->declaration;
    }else 
    {printf("構文木エラー--tree_External_declaration--");}
    
}
void flow_Function_definition(struct Function_definition *tree_Function_definition){
    if(tree_Function_definition->kind==dec_dec_dec_kind){
        flow_Declaration_specifiers(tree_Function_definition->declaration_specifiers);
        flow_Declarator(tree_Function_definition->declarator);
        flow_Declaration_list(tree_Function_definition->declaration_list);
        flow_Compound_statement(tree_Function_definition->compound_statement);
    }else
    if(tree_Function_definition->kind==dec_dec_com_kind){
        flow_Declaration_specifiers(tree_Function_definition->declaration_specifiers);
        flow_Declarator(tree_Function_definition->declarator);
        flow_Compound_statement(tree_Function_definition->compound_statement);
    }else
    if(tree_Function_definition->kind==declarator_dec_com_kind){
        flow_Declarator(tree_Function_definition->declarator);
        flow_Declaration_list(tree_Function_definition->declaration_list);
        flow_Compound_statement(tree_Function_definition->compound_statement);
    }else
    if(tree_Function_definition->kind==declarator_com){
        flow_Declarator(tree_Function_definition->declarator);
        flow_Compound_statement(tree_Function_definition->compound_statement);
    }else{printf("構文木エラー--tree_Function_definition--");}
    
}


// /////////////// //////// ///////////////////
