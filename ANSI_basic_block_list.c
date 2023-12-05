//　リスト構造の操作
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ANSI_basic_block_list.h"
bool block_err;

b_block *make_basic_block_cell(struct Statement_list *startptr, struct Statement_list *endptr, b_block *cp){
    printf("make_basic_block_cellに入った瞬間\n");
    b_block *newcp = malloc(sizeof(b_block));
    if(newcp!=NULL){
        //newcp-> for_statement = tree_Iteration_statement;
        //enumによって格納を変える?
        newcp -> start = startptr;
        newcp -> end   = endptr;
        newcp -> succ  = cp;
    }
    return  newcp;
}

//
struct basic_block_list *make_basic_block_list(void){
    printf("make_basic_block_list\n");
    struct basic_block_list *block_ls = malloc(sizeof(struct basic_block_list));
    if (block_ls != NULL) {
        block_ls->block_top = make_basic_block_cell(0,0 ,NULL);  // ヘッダセルをセット
        if (block_ls->block_top == NULL) {
            free(block_ls);
            return NULL;
        }
    }
    return block_ls;
}

//この関数多分違う
void delete_basic_block_cell(b_block *cp){
    while (cp != NULL) {
        if(cp->pred != NULL){
            b_block *s_temp_pred = cp->pred;
            free(cp);
            delete_basic_block_cell(s_temp_pred);
            cp = s_temp_pred;
        }
        if(cp->succ != NULL){
            b_block *s_temp_succ = cp->succ;
            delete_basic_block_cell(s_temp_succ);
            cp = s_temp_succ;
        }
        free(cp);
       
    }
}
void delete_basic_block_list(struct basic_block_list *block_ls){
    delete_basic_block_cell(block_ls->block_top);
    free(block_ls);
}

//これも違うかも
b_block *nth_basic_block_cell(b_block *cp, int n){
    for (int i = -1; cp != NULL; i++, cp = cp->succ){
    //printf("in_ntn_cell__%d\n",i);
        if (i == n) break;
    }
    printf("test_aa\n");
    
    ///
    //predからでもなんこめのせるかどうかわからないといけない
    ///
    //for (int i = -1; cp != NULL; i++, cp = cp->pred){
    //printf("in_ntn_cell__%d\n",i);
    //    if (i == n) break;
    //}
    return cp;
}
b_block *basic_block_nth(struct basic_block_list *block_ls, int n, bool *block_err){
    b_block *cp = nth_basic_block_cell(block_ls->block_top, n);
    if (cp == NULL) {
        *block_err = false;
        return NULL;
    }
    *block_err = true;
    return cp;

}
bool insert_basic_block_nth(struct basic_block_list *block_ls, int n, struct Statement_list *startptr, struct Statement_list *endptr){
    b_block *cp = nth_basic_block_cell(block_ls->block_top, n - 1);
    //printf("in_insert_nth_after_nth_cell_function\n");
    if (cp == NULL) return false;
    //printf("in_insert_nth_before_make_cell_function\n");
    cp->succ = make_basic_block_cell(startptr,endptr , cp -> succ);
    //printf("ポインタinsert_nth_symbolアフター=%p\n",val_name_ptr);
    //printf("in_insert_nth_after_make_cell_function\n");
    return true;
}
//リストポインタと、start _statement、end_statementへのポインタの3つの引数
bool push_basic_block(struct basic_block_list *block_ls, struct Statement_list *startptr, struct Statement_list *endptr){
    bool push_bool;
    //printf("errot_in_push_function\n");
    push_bool = insert_basic_block_nth(block_ls, 0, startptr, endptr);
    //printf("errot_in_push_function_after_insert_nth_function\n");
    return push_bool;
}
bool delete_basic_block_nth(struct basic_block_list *block_ls, int n){
    printf("delete_basic_block_nth未実装\n");
    exit(1);
    return true;
    
}
b_block *pop_basic_block(struct basic_block_list *block_ls, bool *block_err){
    printf("pop_basic_block未実装\n");
    exit(1);
    return NULL;
}

// start = (struct st_list*) malloc(sizeof(struct st_list));
// end = (struct st_list*) malloc(sizeof(struct st_list));