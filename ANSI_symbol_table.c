#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ANSI_print.h"
#include "ANSI_Sprint.h"
#include "ANSI_For_list.h"
#include "ANSI_tree.h"
#include "ANSI_symbol_table.h"
#include "ANSI_symbol_table_list.h"
/*

push_symbol(symbol_ls,typenameへのポインタ,変数名へのポインタ);

このpush_symbol()先でtypenameポインタからタイプをもらい、変数目へのポインタでchar *str_IDを受け取るようにしたい。
*/

void table_print_Primary_expression(struct Primary_expression *tree_Primary_expression){
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
        table_print_Expression(tree_Primary_expression->expression);
    }else{printf("構文木エラー--primary_expression--");}
}
void table_print_Postfix_expression(struct Postfix_expression *tree_Postfix_expression){
    if(tree_Postfix_expression->kind==primary_expression_kind){
        table_print_Primary_expression(tree_Postfix_expression->primary_expression);
    }else if(tree_Postfix_expression->kind==postfix_expression_expression_kind){
        table_print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("[");
        table_print_Expression(tree_Postfix_expression->expression);
        //printf("]");
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_not_kind){
        
        table_print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("(");
        //printf(")");
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_argument_kind){
        table_print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("(");
        table_print_Argument_expression_list(tree_Postfix_expression->argument_expression_list);
        //printf(")");
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_IDENTIFIER_kind){
        table_print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf(".%s",tree_Postfix_expression->str_ID);
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_PTR){
        table_print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("->");
        //printf("%s",tree_Postfix_expression->str_ID);
    }else 
    if(tree_Postfix_expression->kind==postfix_expression_INC){
        table_print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("++");

    }else 
    if(tree_Postfix_expression->kind==postfix_expression_DEC){
        table_print_Postfix_expression(tree_Postfix_expression->postfix_expression);
        //printf("--");
    }else {printf("構文木エラー--Postfix_expression--");}

}
void table_print_Argument_expression_list(struct Argument_expression_list *tree_Argument_expression_list){
    if(tree_Argument_expression_list->kind==assignment_expression_kind){
        table_print_Assignment_expression(tree_Argument_expression_list->assignment_expression);
    }else
    if(tree_Argument_expression_list->kind==argument_expression_list_kind){
        table_print_Argument_expression_list(tree_Argument_expression_list->argument_expression_list);
        //printf(",");
        table_print_Assignment_expression(tree_Argument_expression_list->assignment_expression);
    }else 
    {printf("構文木エラー--Argument_expression_list--");}
}
void table_print_Unary_expression(struct Unary_expression *tree_Unary_expression){
    if(tree_Unary_expression->kind==postfix_expression_kind){
        table_print_Postfix_expression(tree_Unary_expression->postfix_expression);
    }else
    if(tree_Unary_expression->kind==INC_OP_kind){
        //printf("++");
        table_print_Unary_expression(tree_Unary_expression->unary_expression);
    }else
    if(tree_Unary_expression->kind==DEC_OP_kind){
        //printf("--");
        table_print_Unary_expression(tree_Unary_expression->unary_expression);
    }else
    if(tree_Unary_expression->kind==unary_operator_kind){
        table_print_Unary_operator(tree_Unary_expression->unary_operator);
        table_print_Cast_expression(tree_Unary_expression->cast_expression);
    }else
    if(tree_Unary_expression->kind==SIZEOF_unary_expression_kind){
        //printf("sizeof");
        table_print_Unary_expression(tree_Unary_expression->unary_expression);
    }else
    if(tree_Unary_expression->kind==SIZEOF_type_name_kind){
        //printf("sizeof(");
        table_print_Type_name(tree_Unary_expression->type_name);
        //printf(")");
    }else
    {printf("構文木エラー--Unary_expression--");}
}
void table_print_Unary_operator(struct Unary_operator *tree_Unary_operator){
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
void table_print_Cast_expression(struct Cast_expression *tree_Cast_expression){
    if(tree_Cast_expression->kind==unary_expression_kind){
        table_print_Unary_expression(tree_Cast_expression->unary_expression);
        
    }else
    if(tree_Cast_expression->kind==type_name_kind){
        //printf("(");
        table_print_Type_name(tree_Cast_expression->type_name);
        //printf(")");
        table_print_Cast_expression(tree_Cast_expression->cast_expression);
    }else {printf("構文木エラー--Cast_expression--");}
}
void table_print_Multiplicative_expression(struct Multiplicative_expression *tree_Multiplicative_expression){
    if(tree_Multiplicative_expression->kind==cast_expression_kind){
        table_print_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else
    if(tree_Multiplicative_expression->kind==MUL_expression_kind){
        table_print_Multiplicative_expression(tree_Multiplicative_expression->multiplicative_expression);
        //printf("*");
        table_print_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else
    if(tree_Multiplicative_expression->kind==DIV_expression_kind){
        table_print_Multiplicative_expression(tree_Multiplicative_expression->multiplicative_expression);
        //printf("/");
        table_print_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else
    if(tree_Multiplicative_expression->kind==PCT_expression_kind){
        table_print_Multiplicative_expression(tree_Multiplicative_expression->multiplicative_expression);
        //printf("%%");
        table_print_Cast_expression(tree_Multiplicative_expression->cast_expression);
    }else { printf("構文木エラー--Multiplicative_expression--");}
}
void table_print_Additive_expression(struct Additive_expression *tree_Additive_expression){
    if(tree_Additive_expression->kind==multiplicative_expression_kind){
        table_print_Multiplicative_expression(tree_Additive_expression->multiplicative_expression);
    }else
    if(tree_Additive_expression->kind==ADD_expression_kind){
        table_print_Additive_expression(tree_Additive_expression->additive_expression);
        //printf("+");
        table_print_Multiplicative_expression(tree_Additive_expression->multiplicative_expression);
    }else
    if(tree_Additive_expression->kind==SUB_expression_kind){
        table_print_Additive_expression(tree_Additive_expression->additive_expression);
        //printf("-");
        table_print_Multiplicative_expression(tree_Additive_expression->multiplicative_expression);
    }else { printf("構文木エラー--Additive_expression--");}
}
void table_print_Shift_expression(struct Shift_expression *tree_Shift_expression){
    if(tree_Shift_expression->kind==additive_expression_kind){
        table_print_Additive_expression(tree_Shift_expression->additive_expression);
    }else
    if(tree_Shift_expression->kind==shift_LEFT_OP_kind){
        table_print_Shift_expression(tree_Shift_expression->shift_expression);
        //printf("<<");
        table_print_Additive_expression(tree_Shift_expression->additive_expression);
    }else
    if(tree_Shift_expression->kind==shift_RIGHT_OP_kind){
        table_print_Shift_expression(tree_Shift_expression->shift_expression);
        //printf(">>");
        table_print_Additive_expression(tree_Shift_expression->additive_expression);
    }else
    { printf("構文木エラー--Shift_expression--");}
}
void table_print_Relational_expression(struct Relational_expression *tree_Relational_expression){
    if(tree_Relational_expression->kind==shift_expression_kind){
        table_print_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_sho){
        table_print_Relational_expression(tree_Relational_expression->relational_expression);
        //printf("<");
        table_print_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_dai){
        table_print_Relational_expression(tree_Relational_expression->relational_expression);
        //printf(">");
        table_print_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_LE_OP){
        table_print_Relational_expression(tree_Relational_expression->relational_expression);
        //printf("<=");
        table_print_Shift_expression(tree_Relational_expression->shift_expression);
    }else
    if(tree_Relational_expression->kind==relat_GE){
        table_print_Relational_expression(tree_Relational_expression->relational_expression);
        //printf(">=");
        table_print_Shift_expression(tree_Relational_expression->shift_expression);
    }else { printf("構文木エラー--Relational_expression--");}
}
void table_print_Equality_expression(struct Equality_expression *tree_Equality_expression){
    if(tree_Equality_expression->kind==relational_expression_kind){
        table_print_Relational_expression(tree_Equality_expression->relational_expression);
        
    }else
    if(tree_Equality_expression->kind==eq_EQ_OP){
        table_print_Equality_expression(tree_Equality_expression->equality_expression);
        //printf("==");
        table_print_Relational_expression(tree_Equality_expression->relational_expression);
    }else
    if(tree_Equality_expression->kind==eq_NE_OP){
        table_print_Equality_expression(tree_Equality_expression->equality_expression);
        //printf("!=");
        table_print_Relational_expression(tree_Equality_expression->relational_expression);
    }else { printf("構文木エラー--Equality_expression--");}
}
void table_print_And_expression(struct And_expression *tree_And_expression){
    if(tree_And_expression->kind==equality_expression_kind){
        table_print_Equality_expression(tree_And_expression->equality_expression);
        
    }else 
    if(tree_And_expression->kind==and_expression_kind){
        table_print_And_expression(tree_And_expression->and_expression);
        //printf(" &");
        table_print_Equality_expression(tree_And_expression->equality_expression);
    }else { printf("構文木エラー--And_expression--");}
}
void table_print_Exclusive_or_expression(struct Exclusive_or_expression *tree_Exclusive_or_expression){
    if(tree_Exclusive_or_expression->kind==and_expression_kind2){
        table_print_And_expression(tree_Exclusive_or_expression->and_expression);
    }else
    if(tree_Exclusive_or_expression->kind==exclusive_or_expression_kind){
        table_print_Exclusive_or_expression(tree_Exclusive_or_expression->exclusive_or_expression);
        //printf("^");
        table_print_And_expression(tree_Exclusive_or_expression->and_expression);
    }else { printf("構文木エラー--tree_Exclusive_or_expression--");}
}
void table_print_Inclusive_or_expression(struct Inclusive_or_expression *tree_Inclusive_or_expression){
    if(tree_Inclusive_or_expression->kind==exclusive_or_expression_kind2){
        table_print_Exclusive_or_expression(tree_Inclusive_or_expression->exclusive_or_expression);
        
    }else
    if(tree_Inclusive_or_expression->kind==inclusive_or_expression_kind){
        table_print_Inclusive_or_expression(tree_Inclusive_or_expression->inclusive_or_expression);
        //printf("|");
        table_print_Exclusive_or_expression(tree_Inclusive_or_expression->exclusive_or_expression);
    }else { printf("構文木エラー--tree_Inclusive_or_expression--");}
}
void table_print_Logical_and_expression(struct Logical_and_expression *tree_Logical_and_expression){
    if(tree_Logical_and_expression->kind==inclusive_or_expression_kind2){
        table_print_Inclusive_or_expression(tree_Logical_and_expression->inclusive_or_expression);
        
    }else
    if(tree_Logical_and_expression->kind==logical_and_expression_kind){
        table_print_Logical_and_expression(tree_Logical_and_expression->logical_and_expression);
        //printf(" &&");
        table_print_Inclusive_or_expression(tree_Logical_and_expression->inclusive_or_expression);

    }else { printf("構文木エラー--tree_Logical_and_expression--");}
    
}
void table_print_Logical_or_expression(struct Logical_or_expression *tree_Logical_or_expression){
    if(tree_Logical_or_expression->kind==logical_and_expression_kind2){
        table_print_Logical_and_expression(tree_Logical_or_expression->logical_and_expression);
        
    }else 
    if(tree_Logical_or_expression->kind==logical_or_expression_kind){
        table_print_Logical_or_expression(tree_Logical_or_expression->logical_or_expression);
        table_print_Logical_and_expression(tree_Logical_or_expression->logical_and_expression);
        

    }else { printf("構文木エラー--tree_Logical_or_expression--");}
    
}
void table_print_Conditional_expression(struct Conditional_expression *tree_Conditional_expression){
    if(tree_Conditional_expression->kind==logical_or_expression_kind2){
        table_print_Logical_or_expression(tree_Conditional_expression->logical_or_expression);
        
    }else
    if(tree_Conditional_expression->kind==logical_or_expression_expression_kind){
        table_print_Logical_or_expression(tree_Conditional_expression->logical_or_expression);
        //printf("?");
        table_print_Expression(tree_Conditional_expression->expression);
        //printf(":");
        table_print_Conditional_expression(tree_Conditional_expression->conditional_expression);
    }else { printf("構文木エラー--tree_Conditional_expression--");}
}
void table_print_Assignment_expression(struct Assignment_expression *tree_Assignment_expression){
    if(tree_Assignment_expression->kind==conditional_expression_kind2){
        table_print_Conditional_expression(tree_Assignment_expression->conditional_expression);
    }else
    if(tree_Assignment_expression->kind==unary_expression_kind2){
        table_print_Unary_expression(tree_Assignment_expression->unary_expression);
        table_print_Assignment_operator(tree_Assignment_expression->assignment_operator);
        table_print_Assignment_expression(tree_Assignment_expression->assignment_expression);
    }else { printf("構文木エラー--tree_Assignment_expression--");}
}
void table_print_Assignment_operator(struct Assignment_operator *tree_Assignment_operator){
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
void table_print_Expression(struct Expression *tree_Expression){
    if(tree_Expression->kind==assignment_expression_kind2){
        table_print_Assignment_expression(tree_Expression->assignment_expression);
    
    }else
    if(tree_Expression->kind==expression_kind2){
        table_print_Expression(tree_Expression->expression);
        //printf(",");
        table_print_Assignment_expression(tree_Expression->assignment_expression);
    }else{ printf("構文木エラー--tree_Expression--");}
}
void table_print_Constant_expression(struct Constant_expression *tree_Constant_expression){
    if(tree_Constant_expression->kind==conditional_expression_kind3){
        table_print_Conditional_expression(tree_Constant_expression->conditional_expression);
    }else{ printf("構文木エラー--tree_Constant_expression--");}
}
void table_print_Declaration(struct Declaration *tree_Declaration){
    if(tree_Declaration->kind==dec_spe_kind){
        table_print_Declaration_specifiers(tree_Declaration->declaration_specifiers);
        //printf(";\n");
    }else
    if(tree_Declaration->kind==dec_spe_ini_kind){
        table_print_Declaration_specifiers(tree_Declaration->declaration_specifiers);
        table_print_Init_declarator_list(tree_Declaration->init_declarator_list);
        //Sprint_Declaration_specifiers(tree_Declaration->declaration_specifiers);
        //Sprint_Init_declarator_list(tree_Declaration->init_declarator_list);
        
        //printf(";\n");
        // ここでpushだめ
        //if(tree_Declaration->declaration_specifiers->enumが対応ネームだったら){}
        //push_symbol(s_ls,tree_Declaration->declaration_specifiers,tree_Declaration->init_declarator_list);
    }else { printf("構文木エラー--tree_Declaration--");}
}
void table_print_Declaration_specifiers(struct Declaration_specifiers *tree_Declaration_specifiers){
    if(tree_Declaration_specifiers->kind==storage_class_specifier_kind){
        table_print_Storage_class_specifier(tree_Declaration_specifiers->storage_class_specifier);
    }else
    if(tree_Declaration_specifiers->kind==storage_class_specifier_declaration_kind){
        table_print_Storage_class_specifier(tree_Declaration_specifiers->storage_class_specifier);
        table_print_Declaration_specifiers(tree_Declaration_specifiers->declaration_specifiers);
    
    }else
    if(tree_Declaration_specifiers->kind==type_specifier_kind){
        table_print_Type_specifier(tree_Declaration_specifiers->type_specifier);
    
    }else
    if(tree_Declaration_specifiers->kind==type_specifier_declaration_kind){
        table_print_Type_specifier(tree_Declaration_specifiers->type_specifier);
        table_print_Declaration_specifiers(tree_Declaration_specifiers->declaration_specifiers);
    
    }else
    if(tree_Declaration_specifiers->kind==type_qualifier_kind){
        table_print_Type_qualifier(tree_Declaration_specifiers->type_qualifier);
    }else
    if(tree_Declaration_specifiers->kind==type_qualifier_declaration_kind){
        table_print_Type_qualifier(tree_Declaration_specifiers->type_qualifier);
        table_print_Declaration_specifiers(tree_Declaration_specifiers->declaration_specifiers);
    }else { printf("構文木エラー--tree_Declaration_specifiers--");}
}
void table_print_Init_declarator_list(struct Init_declarator_list *tree_Init_declarator_list){
    if(tree_Init_declarator_list->kind==init_declarator_kind){
        table_print_Init_declarator(tree_Init_declarator_list->init_declarator);
        
    }else
    if(tree_Init_declarator_list->kind==init_declarator_list_kind){
        table_print_Init_declarator_list(tree_Init_declarator_list->init_declarator_list);
        //printf(",");
        table_print_Init_declarator(tree_Init_declarator_list->init_declarator);
    }else{ printf("構文木エラー--tree_Init_declarator_list--");}
}
void table_print_Init_declarator(struct Init_declarator *tree_Init_declarator){
    if(tree_Init_declarator->kind==declarator_kind){
        table_print_Declarator(tree_Init_declarator->declarator);
    }else
    if(tree_Init_declarator->kind==declarator_EQUAL_kind){
        table_print_Declarator(tree_Init_declarator->declarator);
        //printf(" =");
        table_print_Initializer(tree_Init_declarator->initializer);
    }else{ printf("構文木エラー--tree_Init_declarator--");}
}
void table_print_Storage_class_specifier(struct Storage_class_specifier *tree_Storage_class_specifier){
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
void table_print_Type_specifier(struct Type_specifier *tree_Type_specifier){
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
        table_print_Struct_or_union_specifier(tree_Type_specifier->struct_or_union_specifier);
    }else
    if(tree_Type_specifier->kind==enum_specifier_kind){
        table_print_Enum_specifier(tree_Type_specifier->enum_specifier);
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
void table_print_Struct_or_union_specifier(struct Struct_or_union_specifier *tree_Struct_or_union_specifier){
    if(tree_Struct_or_union_specifier->kind==struct_ID_struct_kind){
        table_print_Struct_or_union(tree_Struct_or_union_specifier->struct_or_union);
        //printf(" %s{",tree_Struct_or_union_specifier->str_ID);
        table_print_Struct_declaration_list(tree_Struct_or_union_specifier->struct_declaration_list);
        //printf("}");
    }else 
    if(tree_Struct_or_union_specifier->kind==struct_struct){
        table_print_Struct_or_union(tree_Struct_or_union_specifier->struct_or_union);
        //printf("{");
        table_print_Struct_declaration_list(tree_Struct_or_union_specifier->struct_declaration_list);
        //printf("}");
    }else
    if(tree_Struct_or_union_specifier->kind==struct_ID){
        table_print_Struct_or_union(tree_Struct_or_union_specifier->struct_or_union);
        //printf(" %s",tree_Struct_or_union_specifier->str_ID);
    }else
    {printf("構文木エラー--tree_Struct_or_union_specifier--");}
    
}
void table_print_Struct_or_union(struct Struct_or_union *tree_Struct_or_union){
    if(tree_Struct_or_union->kind==STRUCT_kind){
        //printf("struct ");
    }else 
    if(tree_Struct_or_union->kind==UNION_kind){
        //printf("union" );
    }else
    {printf("構文木エラー--tree_Struct_or_union--");}
}
void table_print_Struct_declaration_list(struct Struct_declaration_list *tree_Struct_declaration_list){
    if(tree_Struct_declaration_list->kind==struct_declaration_kind){
        table_print_Struct_declaration(tree_Struct_declaration_list->struct_declaration);
        
    }else 
    if(tree_Struct_declaration_list->kind==struct_declaration_list_kind){
        table_print_Struct_declaration_list(tree_Struct_declaration_list->struct_declaration_list);
        table_print_Struct_declaration(tree_Struct_declaration_list->struct_declaration);
    }else
    {printf("構文木エラー--tree_Struct_declaration_list--");}
}
void table_print_Struct_declaration(struct Struct_declaration *tree_Struct_declaration){
    if(tree_Struct_declaration->kind==specifier_qualifier_list_kind){
        table_print_Specifier_qualifier_list(tree_Struct_declaration->specifier_qualifier_list);
        table_print_Struct_declarator_list(tree_Struct_declaration->struct_declarator_list);
        //printf(";\n");
    }else {printf("構文木エラー--tree_Struct_declaration--");}
}
void table_print_Specifier_qualifier_list(struct Specifier_qualifier_list *tree_Specifier_qualifier_list){
    if(tree_Specifier_qualifier_list->kind==type_spe_spe_kind){
        table_print_Type_specifier(tree_Specifier_qualifier_list->type_specifier);
        table_print_Specifier_qualifier_list(tree_Specifier_qualifier_list->specifier_qualifier_list);
        
    }else
    if(tree_Specifier_qualifier_list->kind==type_spe_kind){
        table_print_Type_specifier(tree_Specifier_qualifier_list->type_specifier);
    }else
    if(tree_Specifier_qualifier_list->kind==type_qua_spe_kind){
        table_print_Type_qualifier(tree_Specifier_qualifier_list->type_qualifier);
        table_print_Specifier_qualifier_list(tree_Specifier_qualifier_list->specifier_qualifier_list);
        
    }else 
    if(tree_Specifier_qualifier_list->kind==type_qua_kind){
        table_print_Type_qualifier(tree_Specifier_qualifier_list->type_qualifier);
    }else{printf("構文木エラー--tree_Specifier_qualifier_list--");}
    
}
void table_print_Struct_declarator_list(struct Struct_declarator_list *tree_Struct_declarator_list){
    if(tree_Struct_declarator_list->kind==struct_declarator_kind){
        table_print_Struct_declarator(tree_Struct_declarator_list->struct_declarator);
    }else
    if(tree_Struct_declarator_list->kind==struct_declarator_list_kind){
        table_print_Struct_declarator_list(tree_Struct_declarator_list->struct_declarator_list);
        //printf(",");
        table_print_Struct_declarator(tree_Struct_declarator_list->struct_declarator);

    }else{printf("構文木エラー--tree_Struct_declarator_list--");}
}
void table_print_Struct_declarator(struct Struct_declarator *tree_Struct_declarator){
    if(tree_Struct_declarator->kind==dec_kind){
        table_print_Declarator(tree_Struct_declarator->declarator);
    }else
    if(tree_Struct_declarator->kind==con_kind){
        //printf(":");
        table_print_Constant_expression(tree_Struct_declarator->constant_expression);
    }else
    if(tree_Struct_declarator->kind==dec_con_kind){
        table_print_Declarator(tree_Struct_declarator->declarator);
        //printf(":");
        table_print_Constant_expression(tree_Struct_declarator->constant_expression);
    }
    else{printf("構文木エラー--tree_Struct_declarator--");}
    
}
void table_print_Enum_specifier(struct Enum_specifier *tree_Enum_specifier){
    if(tree_Enum_specifier->kind==ENUM_enu_kind){
        //printf("enum {");
        table_print_Enumerator_list(tree_Enum_specifier->enumerator_list);
        //printf("}");

    }else if(tree_Enum_specifier->kind==ENUM_ID_enu_kind){
        //printf("enum ");
        //printf("%s ",tree_Enum_specifier->str_ID);
        //printf("{");
        table_print_Enumerator_list(tree_Enum_specifier->enumerator_list);
        //printf("}");
    }else
    if(tree_Enum_specifier->kind==ENUM_ID_kind){
        //printf("enum ");
        //printf("%s ",tree_Enum_specifier->str_ID);
    }else{printf("構文木エラー--tree_Enum_specifier--");}

    
}
void table_print_Enumerator_list(struct Enumerator_list *tree_Enumerator_list){
    if(tree_Enumerator_list->kind==enumerator_kind){
        table_print_Enumerator(tree_Enumerator_list->enumerator);
    }else 
    if(tree_Enumerator_list->kind==enumerator_list_kind){
        table_print_Enumerator_list(tree_Enumerator_list->enumerator_list);
        //printf(",");
        table_print_Enumerator(tree_Enumerator_list->enumerator);
    }else
    {printf("構文木エラー--tree_Enumerator_list--");}
}
void table_print_Enumerator(struct Enumerator *tree_Enumerator){
    if(tree_Enumerator->kind==ID_kind){
        //printf(" %s",tree_Enumerator->str_ID);
    }else 
    if(tree_Enumerator->kind==ID_EQUAL_kind){
        //printf(" %s",tree_Enumerator->str_ID);
        table_print_Constant_expression(tree_Enumerator->constant_expression);
    }else
    {printf("構文木エラー--tree_Enumerator--");}
    
}
void table_print_Type_qualifier(struct Type_qualifier *tree_Type_qualifier){
    if(tree_Type_qualifier->kind==CONST_kind){
        //printf("const ");
    }else
    if(tree_Type_qualifier->kind==VOLATILE_kind){
        //printf("volatile ");
    }else
    {printf("構文木エラー--tree_Type_qualifier--");}
    
}
void table_print_Declarator(struct Declarator *tree_Declarator){
    if(tree_Declarator->kind==pointer_kind){
        table_print_Pointer(tree_Declarator->pointer);
        table_print_Direct_declarator(tree_Declarator->direct_declarator);
        
    }else
    if(tree_Declarator->kind==direct_declarator_kind){
        table_print_Direct_declarator(tree_Declarator->direct_declarator);
    }else  {printf("構文木エラー--tree_Declarator--");}
    
}
void table_print_Direct_declarator(struct Direct_declarator *tree_Direct_declarator){
    if(tree_Direct_declarator->kind==ID_kind2){
        //printf(" %s ",tree_Direct_declarator->str_ID);
    }else 
    if(tree_Direct_declarator->kind==declarator_kind2){
        //printf("(");
        table_print_Declarator(tree_Direct_declarator->declarator);
        //printf(")");
    }else
    if(tree_Direct_declarator->kind==dir_dec_con_kind){
        table_print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("[");
        table_print_Constant_expression(tree_Direct_declarator->constant_expression);
        //printf("]");
    }else
    if(tree_Direct_declarator->kind==dir_dec_kind){
        table_print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("[ ]");
    }else
    if(tree_Direct_declarator->kind==dir_dec_par_kind){
        table_print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("(");
        table_print_Parameter_type_list(tree_Direct_declarator->parameter_type_list);
        //printf(")");
    }else
    if(tree_Direct_declarator->kind==dir_dec_ide){
        table_print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("(");
        table_print_Identifier_list(tree_Direct_declarator->identifier_list);
        //printf(")");
    }else
    if(tree_Direct_declarator->kind==dir_dec_kind2){
        table_print_Direct_declarator(tree_Direct_declarator->direct_declarator);
        //printf("( )");
    }else
    {printf("構文木エラー--tree_Direct_declarator--");}
}
void table_print_Pointer(struct Pointer *tree_Pointer){
    if(tree_Pointer->kind==P_kind){
        //printf("*");
        
    }else 
    if(tree_Pointer->kind==P_type_kind){
        //printf("*");
        table_print_Type_qualifier_list(tree_Pointer->type_qualifier_list);
    }else 
    if(tree_Pointer->kind==P_pointer_kind){
        //printf("*");
        table_print_Pointer(tree_Pointer->pointer);
    }else 
    if(tree_Pointer->kind==P_type_pointer_kind){
        //printf("*");
        table_print_Type_qualifier_list(tree_Pointer->type_qualifier_list);
        table_print_Pointer(tree_Pointer->pointer);
    }else 
    {printf("構文木エラー--tree_Pointer--");}
    
}
void table_print_Type_qualifier_list(struct Type_qualifier_list *tree_Type_qualifier_list){
    if(tree_Type_qualifier_list->kind==type_qualifier_kind2){
        table_print_Type_qualifier(tree_Type_qualifier_list->type_qualifier);
    }else 
    if(tree_Type_qualifier_list->kind==type_qualifier_list_kind){
        table_print_Type_qualifier_list(tree_Type_qualifier_list->type_qualifier_list);
        table_print_Type_qualifier(tree_Type_qualifier_list->type_qualifier);
    }else 
    {printf("構文木エラー--tree_Type_qualifier_list--");}
}
void table_print_Parameter_type_list(struct Parameter_type_list *tree_Parameter_type_list){
    if(tree_Parameter_type_list->kind==parameter_list_kind){
        table_print_Parameter_list(tree_Parameter_type_list->parameter_list);
    }else 
    if(tree_Parameter_type_list->kind==parameter_list_ELL_kind){
        table_print_Parameter_list(tree_Parameter_type_list->parameter_list);
        //printf(" , ...");
    }else 
    {printf("構文木エラー--tree_Parameter_type_list--");}
    
}
void table_print_Parameter_list(struct Parameter_list *tree_Parameter_list){
    if(tree_Parameter_list->kind==parameter_declaration_kind){
        table_print_Parameter_declaration(tree_Parameter_list->parameter_declaration);
    }else 
    if(tree_Parameter_list->kind==parameter_list_kind2){
        table_print_Parameter_list(tree_Parameter_list->parameter_list);
        //printf(", ");
        table_print_Parameter_declaration(tree_Parameter_list->parameter_declaration);
    }else 
    {printf("構文木エラー--tree_Parameter_list--");}
}
void table_print_Parameter_declaration(struct Parameter_declaration *tree_Parameter_declaration){
    if(tree_Parameter_declaration->kind==dec_dec_kind){
        table_print_Declaration_specifiers(tree_Parameter_declaration->declaration_specifiers);
        table_print_Declarator(tree_Parameter_declaration->declarator);
    }else 
    if(tree_Parameter_declaration->kind==dec_abs_kind){
        table_print_Declaration_specifiers(tree_Parameter_declaration->declaration_specifiers);
        table_print_Abstract_declarator(tree_Parameter_declaration->abstract_declarator);
    }else 
    if(tree_Parameter_declaration->kind==dec_kind2){
        table_print_Declaration_specifiers(tree_Parameter_declaration->declaration_specifiers);
    }else {printf("構文木エラー--tree_Parameter_declaration--");}
    
}
void table_print_Identifier_list(struct Identifier_list *tree_Identifier_list){
    if(tree_Identifier_list->kind==ID_kind_in_identifier_list){
        //printf("%s",tree_Identifier_list->str_ID);
    }else 
    if(tree_Identifier_list->kind==identifier_list_ID_in_identifier_list){
        table_print_Identifier_list(tree_Identifier_list->identifier_list);
        //printf(", %s",tree_Identifier_list->str_ID);
    }else 
    {printf("構文木エラー--tree_Identifier_list--");}
}
void table_print_Type_name(struct Type_name *tree_Type_name){
    if(tree_Type_name->kind==spe_kind){
        table_print_Specifier_qualifier_list(tree_Type_name->specifier_qualifier_list);
        
    }else
    if(tree_Type_name->kind==spe_abs_kind){
        table_print_Specifier_qualifier_list(tree_Type_name->specifier_qualifier_list);
        table_print_Abstract_declarator(tree_Type_name->abstract_declarator);
    }else{printf("構文木エラー--tree_Type_name--");}
}
void table_print_Abstract_declarator(struct Abstract_declarator *tree_Abstract_declarator){
    if(tree_Abstract_declarator->kind==poi_kind_in_abs){
        table_print_Pointer(tree_Abstract_declarator->pointer);
    }else 
    if(tree_Abstract_declarator->kind==dir_kind_in_abs){
        table_print_Direct_abstract_declarator(tree_Abstract_declarator->direct_abstract_declarator);
    }else 
    if(tree_Abstract_declarator->kind==poi_dir_kind_in_abs){
        table_print_Pointer(tree_Abstract_declarator->pointer);
        table_print_Direct_abstract_declarator(tree_Abstract_declarator->direct_abstract_declarator);
    }else {printf("構文木エラー--tree_Abstract_declarator--");}
}
void table_print_Direct_abstract_declarator(struct Direct_abstract_declarator *tree_Direct_abstract_declarator){
    if(tree_Direct_abstract_declarator->kind==abs_kind){
        table_print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
    }else 
    if(tree_Direct_abstract_declarator->kind==NOT_kind){
        //printf("[ ]");
    }else 
    if(tree_Direct_abstract_declarator->kind==constant_expression_kind){
        //printf("[");
        table_print_Constant_expression(tree_Direct_abstract_declarator->constant_expression);
        //printf("]");
    }else 
    if(tree_Direct_abstract_declarator->kind==dir_NOT_kind){
        table_print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        //printf("[ ]");
    }else 
    if(tree_Direct_abstract_declarator->kind==dir_con_kind){
        table_print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
       // printf("[");
        table_print_Constant_expression(tree_Direct_abstract_declarator->constant_expression);
        //printf("]");
    }else 
    if(tree_Direct_abstract_declarator->kind==NOT_kind2){
        //printf("( )");
    }else 
    if(tree_Direct_abstract_declarator->kind==par_kind){
        //printf("(");
        table_print_Parameter_type_list(tree_Direct_abstract_declarator->parameter_type_list);
        //printf(")");
    }else 
    if(tree_Direct_abstract_declarator->kind==dir_NOT_kind3){
        table_print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        //printf("( )");
    }else
    if(tree_Direct_abstract_declarator->kind==dir_par_kind){
        table_print_Direct_abstract_declarator(tree_Direct_abstract_declarator->direct_abstract_declarator);
        //printf("( ");
        table_print_Parameter_type_list(tree_Direct_abstract_declarator->parameter_type_list);
        //printf(" )");
    }else
    {printf("構文木エラー--tree_Direct_abstract_declarator--");}
    
}
void table_print_Initializer(struct Initializer *tree_Initializer){
    if(tree_Initializer->kind==ass_exp_kind){
        table_print_Assignment_expression(tree_Initializer->assignment_expression);
        
    }else 
    if(tree_Initializer->kind==ini_NOT){
        //printf("{");
        table_print_Initializer_list(tree_Initializer->initializer_list);
        //printf("}");

    }else 
    if(tree_Initializer->kind==ini_KNM){
        //printf("{");
        table_print_Initializer_list(tree_Initializer->initializer_list);
        //printf(",");
        //printf("}");
    }else {printf("構文木エラー--tree_Initializer--");}
    
}
void table_print_Initializer_list(struct Initializer_list *tree_Initializer_list){
    if(tree_Initializer_list->kind==ini_kind){
        table_print_Initializer(tree_Initializer_list->initializer);
        
    }else 
    if(tree_Initializer_list->kind==ini_ini_kind){
        table_print_Initializer_list(tree_Initializer_list->initializer_list);
        //printf(",");
        table_print_Initializer(tree_Initializer_list->initializer);
    }else {printf("構文木エラー--tree_Initializer_list--");}
    
    
}
void table_print_Statement (struct Statement *tree_Statement){
    if(tree_Statement->kind==label_kind){
        table_print_Labeled_statement(tree_Statement->labeled_statement);
        
    }else 
    if(tree_Statement->kind==compo_kind){
        table_print_Compound_statement(tree_Statement->compound_statement);
    }else 
    if(tree_Statement->kind==expre_kind){
        table_print_Expression_statement(tree_Statement->expression_statement);
    }else 
    if(tree_Statement->kind==selec_kind){
        table_print_Selection_statement(tree_Statement->selection_statement);
    }else 
    if(tree_Statement->kind==itera_kind){
        table_print_Iteration_statement(tree_Statement->iteration_statement);
    }else 
    if(tree_Statement->kind==jump_kind){
        table_print_Jump_statement(tree_Statement->jump_statement);
    }else 
    if(tree_Statement->kind==decla_kind){
        table_print_Declaration(tree_Statement->declaration);
        // Sprint_Declaration(tree_Statement->declaration);

        /*
        もしこの先についているのがこれなら〜
        ここでシンボルプッシュしている。
        */
        if(tree_Statement->declaration->kind==dec_spe_ini_kind){
            
            //printf("ポインタpush前=%p\n",tree_Statement->declaration->init_declarator_list);
            // Sprint_Declaration(tree_Statement->declaration);
            //　呼ぶべき場所
            push_symbol(s_ls,tree_Statement->declaration->declaration_specifiers, tree_Statement->declaration->init_declarator_list); 
        }
        
    }else {printf("構文木エラー--tree_Statement--");}
    
    
}
void table_print_Labeled_statement(struct Labeled_statement *tree_Labeled_statement){
    if(tree_Labeled_statement->kind==ID_sta_kind){
        //printf("%s :",tree_Labeled_statement->str_ID);
        table_print_Statement(tree_Labeled_statement->statement);
    }else 
    if(tree_Labeled_statement->kind==CASE_con_kind){
        //printf("case ");
        table_print_Constant_expression(tree_Labeled_statement->constant_expression);
        //printf(" : ");
        table_print_Statement(tree_Labeled_statement->statement);
    }else 
    if(tree_Labeled_statement->kind==DEFAULT_sta_kind){
        //printf("default :");
        table_print_Statement(tree_Labeled_statement->statement);
    }else {printf("構文木エラー--tree_Labeled_statement--");}
    
}
void table_print_Compound_statement(struct Compound_statement *tree_Compound_statement){
    if(tree_Compound_statement->kind==NOT_kind3){
        //printf("{ \n }");
    }else 
    if(tree_Compound_statement->kind==statement_list_kind){
        //printf("{\n");
        table_print_Statement_list(tree_Compound_statement->statement_list);
        //printf("\n}");
    }else{printf("構文木エラー--tree_Compound_statement--");}
    
}
void table_print_Declaration_list(struct Declaration_list *tree_Declaration_list){
    if(tree_Declaration_list->kind==declaration_kind){
        table_print_Declaration(tree_Declaration_list->declaration);
        
    } else
    if(tree_Declaration_list->kind==declaration_list_kind){
        table_print_Declaration_list(tree_Declaration_list->declaration_list);
        table_print_Declaration(tree_Declaration_list->declaration);
    } else
    {printf("構文木エラー--tree_Declaration_list--");}
    
}
void table_print_Statement_list(struct Statement_list *tree_Statement_list){
    if(tree_Statement_list->kind==statement_kind){
        table_print_Statement(tree_Statement_list->statement);
        
    }else 
    if(tree_Statement_list->kind==statement_list_kind2){
        table_print_Statement(tree_Statement_list->statement);
        table_print_Statement_list(tree_Statement_list->statement_list);
        
    }else
    {printf("構文木エラー--tree_Statement_list--");}
    
}
void table_print_Expression_statement(struct Expression_statement *tree_Expression_statement){
    if(tree_Expression_statement->kind==SEMIC_kind){
        //printf(";\n");
    }else 
    if(tree_Expression_statement->kind==expression_SEMIC_kind){
        table_print_Expression(tree_Expression_statement->expression);
        //printf(";\n");
    }else {printf("構文木エラー--tree_Expression_statement--");}
    
}
void table_print_Selection_statement(struct Selection_statement *tree_Selection_statement){
    if(tree_Selection_statement->kind==IF_expression_kind){
        
        //printf("if(");
        table_print_Expression(tree_Selection_statement->expression);
        //printf(")");
        table_print_Statement(tree_Selection_statement->statement);
        
    }else 
    if(tree_Selection_statement->kind==IF_expression_ELSE_kind){
        //printf("if(");
        table_print_Expression(tree_Selection_statement->expression);
        //printf(")");
        table_print_Statement(tree_Selection_statement->statement);
        
        //printf(" else ");
        
        table_print_Statement(tree_Selection_statement->statement2);
        
    }else 
    if(tree_Selection_statement->kind==SWITCH_kind){
        //printf("switch (");
        table_print_Expression(tree_Selection_statement->expression);
        //printf(")");
        table_print_Statement(tree_Selection_statement->statement);
    }else {printf("構文木エラー--tree_Selection_statement--");}
    
}
void table_print_Iteration_statement(struct Iteration_statement *tree_Iteration_statement){
    if(tree_Iteration_statement->kind==WHILE_kind){
        //printf("while(");
        table_print_Expression(tree_Iteration_statement->expression);
        //printf(")\n");
        table_print_Statement(tree_Iteration_statement->statement);
    }else 
    if(tree_Iteration_statement->kind==DO_kind){
        //printf("do ");
        table_print_Statement(tree_Iteration_statement->statement);
        //printf("while(");
        table_print_Expression(tree_Iteration_statement->expression);
        //printf(");\n");
    }else 
    if(tree_Iteration_statement->kind==FOR_two_kind){
        //printf("for( ");
        table_print_Expression_statement(tree_Iteration_statement->expression_statement);
        table_print_Expression_statement(tree_Iteration_statement->expression_statement2);
        //printf(")\n");
        table_print_Statement(tree_Iteration_statement->statement);
        // ここでリストに入れる関数
        
    }else 
    if(tree_Iteration_statement->kind==FOR_three_kind){
        //printf("for( ");
        table_print_Expression_statement(tree_Iteration_statement->expression_statement);
        table_print_Expression_statement(tree_Iteration_statement->expression_statement2);
        table_print_Expression(tree_Iteration_statement->expression);
        //printf(")\n");
        table_print_Statement(tree_Iteration_statement->statement);
        // ここでリストに入れる関数
        //printf("before_push_tree_iteraration_ptr\n");
        //printf("after_push_tree_iteraration_ptr\n");
        
    }else {printf("構文木エラー--tree_Iteration_statement--");}
    
}

void table_print_Jump_statement(struct Jump_statement *tree_Jump_statement){
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
        table_print_Expression(tree_Jump_statement->expression);
        //printf(";\n");

    }else {printf("構文木エラー--tree_Jump_statement--");}
}
void table_print_Translation_unit(struct Translation_unit *tree_Translation_unit){
    if(tree_Translation_unit->kind==external_declaration_kind){
        table_print_External_declaration(tree_Translation_unit->external_declaration);
    }else 
    if(tree_Translation_unit->kind==translation_unit_kind){
        table_print_Translation_unit(tree_Translation_unit->translation_unit);
        table_print_External_declaration(tree_Translation_unit->external_declaration);
    }else {printf("構文木エラー--tree_Translation_unit--");}
    
}
void table_print_External_declaration(struct External_declaration *tree_External_declaration){
    if(tree_External_declaration->kind==function_definition_kind){
        table_print_Function_definition(tree_External_declaration->function_definition);
    }else 
    if(tree_External_declaration->kind==declaration_kind_in_external_declaration){
        
        if(tree_External_declaration->declaration->kind==dec_spe_ini_kind){
            //Sprint_Declaration(tree_External_declaration->declaration);
            //printf("pushした_external\n");
            //呼ぶべき場所
            //push_symbol(s_ls,tree_External_declaration->declaration->declaration_specifiers, tree_External_declaration->declaration->init_declarator_list);
        }
    }else 
    {printf("構文木エラー--tree_External_declaration--");}
    
}
void table_print_Function_definition(struct Function_definition *tree_Function_definition){
    if(tree_Function_definition->kind==dec_dec_dec_kind){
        table_print_Declaration_specifiers(tree_Function_definition->declaration_specifiers);
        table_print_Declarator(tree_Function_definition->declarator);
        table_print_Declaration_list(tree_Function_definition->declaration_list);
        table_print_Compound_statement(tree_Function_definition->compound_statement);
    }else
    if(tree_Function_definition->kind==dec_dec_com_kind){
        table_print_Declaration_specifiers(tree_Function_definition->declaration_specifiers);
        table_print_Declarator(tree_Function_definition->declarator);
        table_print_Compound_statement(tree_Function_definition->compound_statement);
    }else
    if(tree_Function_definition->kind==declarator_dec_com_kind){
        table_print_Declarator(tree_Function_definition->declarator);
        table_print_Declaration_list(tree_Function_definition->declaration_list);
        table_print_Compound_statement(tree_Function_definition->compound_statement);
    }else
    if(tree_Function_definition->kind==declarator_com){
        table_print_Declarator(tree_Function_definition->declarator);
        table_print_Compound_statement(tree_Function_definition->compound_statement);
    }else{printf("構文木エラー--tree_Function_definition--");}
    
}
