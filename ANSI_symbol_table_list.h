#ifndef _symbol_list_
#define _symbol_list_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ANSI_print.h"
#include "ANSI_Sprint.h"
#include "ANSI_For_list.h"
#include "ANSI_tree.h"
#include "ANSI_symbol_table.h"
//--ここでFor部分のポインタ連結リスト
//セル
enum symbol_kind{
    Array,
    Not_Array,
    func_call
};
typedef struct symbol_cell{
    enum symbol_kind kind;
    struct Type_specifier *type_specifier_ptr;
    struct Direct_declarator *direct_declarator_ptr;
    struct symbol_cell *symbol_next;
}s_Cell;

//リスト
struct symbol_List{
    s_Cell *s_top;
}*s_ls;
//For部分のポインタ連結リスト--
// ここがリスト関連の関数のプロトタイプ宣言
s_Cell *make_symbol_cell(struct Type_specifier *type_specifier_arg, struct Direct_declarator *direct_declarator_arg, s_Cell *symbol_cp);
struct symbol_List *make_symbol_list(void);
void delete_symbol_cell(s_Cell *symbol_cp);
void delete_symbol_list(struct symbol_List *s_ls);
s_Cell *nth_symbol_cell(s_Cell *symbol_cp, int n);
s_Cell *nth_symbol(struct symbol_List *s_ls, int n, bool *err_symbol);
bool insert_nth_symbol(struct symbol_List *s_ls, int n, struct Type_specifier *type_specifier_arg, struct Direct_declarator *direct_declarator_arg);
bool push_symbol(struct symbol_List *s_ls, struct Declaration_specifiers *type_ptr, struct Init_declarator_list *val_name_ptr);
bool delete_nth_symbol(struct symbol_List *s_ls, int n);
s_Cell *pop_symbol(struct symbol_List *s_ls, bool *err_symbol);
#endif /* _symbol_list_ */