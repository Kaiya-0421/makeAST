// ここでリストの関数を定義する
//今は For限定
// セルの生成
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ANSI_print.h"
#include "ANSI_Sprint.h"
#include "ANSI_For_list.h"
#include "ANSI_tree.h"
//#include "ANSI_symbol_table.h"
bool err;
Cell *make_cell(struct Iteration_statement *tree_Iteration_statement, Cell *cp)
{
  Cell *newcp = malloc(sizeof(Cell));
  if (newcp != NULL) {
    newcp-> for_statement = tree_Iteration_statement;
    newcp->next = cp;
  }
  return newcp;
}
// リストの生成
struct List *make_list(void)
{
  struct List *ls = malloc(sizeof(struct List));
  if (ls != NULL) {
    ls->top = make_cell(0, NULL);  // ヘッダセルをセット
    if (ls->top == NULL) {
      free(ls);
      return NULL;
    }
  }
  return ls;
}
// セルの削除
void delete_cell(Cell *cp)
{
  while (cp != NULL) {
    Cell *temp = cp->next;
    free(cp);
    cp = temp;
  }
}

// リストの削除
void delete_list(struct List *ls)
{
  delete_cell(ls->top);
  free(ls);
}

// n 番目のセルを返す
Cell *nth_cell(Cell *cp, int n)
{
    //printf("in_nth_cell_n=%d\n",n);
  for (int i = -1; cp != NULL; i++, cp = cp->next){
    //printf("in_ntn_cell__%d\n",i);
    if (i == n) break;
  }
  return cp;
}

Cell *nth(struct List *ls, int n, bool *err)
{
  Cell *cp = nth_cell(ls->top, n);
  if (cp == NULL) {
    *err = false;
    return NULL;
  }
  *err = true;
  return cp;
}

// データの挿入
bool insert_nth(struct List *ls, int n, struct Iteration_statement *for_statement)
{
  Cell *cp = nth_cell(ls->top, n - 1);
  //printf("in_insert_nth_after_nth_cell_function\n");
  if (cp == NULL) return false;
  //printf("in_insert_nth_before_make_cell_function\n");
  cp->next = make_cell(for_statement, cp->next);
  //printf("in_insert_nth_after_make_cell_function\n");
  return true;
}

// 先頭に追加
bool push(struct List *ls, struct Iteration_statement *for_statement)
{
    bool push_bool;
  //printf("errot_in_push_function\n");
  push_bool = insert_nth(ls, 0, for_statement);
  //printf("errot_in_push_function_after_insert_nth_function\n");
  return push_bool;
}

// n 番目の要素を削除
bool delete_nth(struct List *ls, int n)
{
  Cell *cp = nth_cell(ls->top, n - 1);
  if (cp == NULL || cp->next == NULL) return false;
  Cell *temp = cp->next;
  cp->next = cp->next->next;
  free(temp);
  return true;
}

// 先頭から要素を取り出す
Cell *pop(struct List *ls, bool *err)
{   
  Cell *cp = nth_cell(ls->top, 0);
    if (cp == NULL) {
    *err = false;
    return 0;
    }
  cp = nth(ls, 0, err);
  if (*err) delete_nth(ls, 0);
  return cp;
}

