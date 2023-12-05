// ここでリストの関数を定義する
// シンボルテーブルリスト
// セルの生成
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ANSI_print.h"
#include "ANSI_Sprint.h"
#include "ANSI_For_list.h"
#include "ANSI_tree.h"
#include "ANSI_symbol_table_list.h"
//#include "ANSI_symbol_table.h"
bool err_symbol;

s_Cell *make_symbol_cell(struct Type_specifier *type_specifier_arg, struct Direct_declarator *direct_declarator_arg, s_Cell *symbol_cp)
{

  s_Cell *newcp = malloc(sizeof(s_Cell));
  if (newcp != NULL) {
    //printf("ポインタmakecell前=%p\n",tree_Declaration_specifiers);
    newcp-> type_specifier_ptr = type_specifier_arg;
    newcp-> direct_declarator_ptr = direct_declarator_arg;
    newcp-> symbol_next = symbol_cp;
    //printf("ポインタmakecellあと=%p\n",newcp-> val_name_ptr);
  }
  return newcp;
}
// リストの生成
struct symbol_List *make_symbol_list(void)
{
  struct symbol_List *s_ls = malloc(sizeof(struct symbol_List));
  if (s_ls != NULL) {
    s_ls->s_top = make_symbol_cell(0,0 ,NULL);  // ヘッダセルをセット
    if (s_ls->s_top == NULL) {
      free(s_ls);
      return NULL;
    }
  }
  return s_ls;
}
// セルの削除
void delete_symbol_cell(s_Cell *symbol_cp)
{
  while (symbol_cp != NULL) {
    s_Cell *s_temp = symbol_cp->symbol_next;
    free(symbol_cp);
    symbol_cp = s_temp;
  }
}

// リストの削除
void delete_symbol_list(struct symbol_List *s_ls)
{
  delete_symbol_cell(s_ls->s_top);
  free(s_ls);
}

// n 番目のセルを返す
s_Cell *nth_symbol_cell(s_Cell *symbol_cp, int n)
{
    //printf("in_nth_cell_n=%d\n",n);
  for (int i = -1; symbol_cp != NULL; i++, symbol_cp = symbol_cp->symbol_next){
    //printf("in_ntn_cell__%d\n",i);
    if (i == n) break;
  }
  return symbol_cp;
}

s_Cell *nth_symbol(struct symbol_List *s_ls, int n, bool *err_symbol)
{
  s_Cell *symbol_cp = nth_symbol_cell(s_ls->s_top, n);
  if (symbol_cp == NULL) {
    *err_symbol = false;
    return NULL;
  }
  *err_symbol = true;
  return symbol_cp;
}

// データの挿入
bool insert_nth_symbol(struct symbol_List *s_ls, int n, struct Type_specifier *type_specifier_arg, struct Direct_declarator *direct_declarator_arg)
{
    //Sprint_Iteration_statement(for_statement);//デバッグ用
    //printf("n=%d\n",n);
    //printf("ポインタinsert_nth_symbol=%p\n",val_name_ptr);
    //printf("in_insert_nth_before_nth_cell_function\n");
    //printf("insert_nth_ls=%p\n",ls);
  s_Cell *symbol_cp = nth_symbol_cell(s_ls->s_top, n - 1);
    

  //printf("in_insert_nth_after_nth_cell_function\n");
  if (symbol_cp == NULL) return false;
  //printf("in_insert_nth_before_make_cell_function\n");
  symbol_cp->symbol_next = make_symbol_cell(type_specifier_arg,direct_declarator_arg , symbol_cp -> symbol_next);
  //printf("ポインタinsert_nth_symbolアフター=%p\n",val_name_ptr);
  //printf("in_insert_nth_after_make_cell_function\n");
  return true;
}

// 先頭に追加
bool push_symbol(struct symbol_List *s_ls, struct Declaration_specifiers *type_ptr, struct Init_declarator_list *val_name_ptr)
{
  //printf("ポインタpush関数=%p\n",val_name_ptr);
  //printf("ポインタlsの%p\n",s_ls);
  bool push_bool;

  /*
  ifで格納を変える
  temp_ptrを使って操作する。
  
  */
  // struct Type_specifiers *type_specifiers_arg, struct Direct_declarator *direct_declarator_arg
  //printf("errot_in_push_function\n");
struct Type_specifier *temp_type ;
  // typeネームへのポインタ
  if(type_ptr->kind==type_specifier_kind){
      temp_type = type_ptr-> type_specifier;
  }else if(type_ptr->kind==type_specifier_declaration_kind){
    if(type_ptr->declaration_specifiers->kind==type_specifier_kind){
      temp_type = type_ptr-> declaration_specifiers ->type_specifier;
    }
  }
  // typeネームへのポインタ
struct  Init_declarator_list *temp_ini=val_name_ptr;
struct  Direct_declarator *temp_dir;
  // initへのポインタ
  while(1){
  // initへのポインタ
      if(temp_ini->kind==init_declarator_kind){
        temp_dir=temp_ini->init_declarator->declarator->direct_declarator;
        push_bool = insert_nth_symbol(s_ls, 0, temp_type,temp_dir);     
        break;
      }else{
        temp_dir=temp_ini->init_declarator->declarator->direct_declarator;
        push_bool = insert_nth_symbol(s_ls, 0, temp_type,temp_dir); 
        //まだ先にinit_listポインタがあるので更新
        temp_ini=temp_ini->init_declarator_list;
      }
  }
  
  //printf("errot_in_push_function_after_insert_nth_function\n");
  return push_bool;
}

// n 番目の要素を削除
bool delete_nth_symbol(struct symbol_List *s_ls, int n)
{
  s_Cell *symbol_cp = nth_symbol_cell(s_ls->s_top, n - 1);
  if (symbol_cp == NULL || symbol_cp->symbol_next == NULL) return false;
  s_Cell *temp = symbol_cp->symbol_next;
  symbol_cp->symbol_next = symbol_cp->symbol_next->symbol_next;
  free(temp);
  return true;
}

// 先頭から要素を取り出す
s_Cell *pop_symbol(struct symbol_List *s_ls, bool *err_symbol)
{   
  s_Cell *symbol_cp = nth_symbol_cell(s_ls->s_top, 0);
    if (symbol_cp == NULL) {
    *err_symbol = false;
    return 0;
    }
  symbol_cp = nth_symbol(s_ls, 0, err_symbol);
  if (*err_symbol) delete_nth_symbol(s_ls, 0);
  return symbol_cp;
}

