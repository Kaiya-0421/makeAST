#ifndef _For_list_
#define _For_list_
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
typedef struct For_cell{
    struct Iteration_statement *for_statement;
    struct For_cell *next;
}Cell;
//リスト
struct List{
    Cell *top;
}*ls;
//For部分のポインタ連結リスト--
// ここがリスト関連の関数のプロトタイプ宣言
Cell *make_cell(struct Iteration_statement *for_statement, Cell *cp);
struct List *make_list(void);
void delete_cell(Cell *cp);
void delete_list(struct List *ls);
Cell *nth_cell(Cell *cp, int n);
Cell *nth(struct List *ls, int n, bool *err);
bool insert_nth(struct List *ls, int n, struct Iteration_statement *for_statement);
bool push(struct List *ls, struct Iteration_statement *for_statement);
bool delete_nth(struct List *ls, int n);
Cell *pop(struct List *ls, bool *err);
#endif /* _For_list_ */