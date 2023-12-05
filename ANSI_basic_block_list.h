// 基本ブロックの構造体内のst_listがどのstatementにつながるか列挙している
#ifndef _block_
#define _block_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "ANSI_print.h"
#include "ANSI_Sprint.h"
#include "ANSI_For_list.h"
#include "ANSI_tree.h"
#include "ANSI_symbol_table.h"
enum kind_stlist{
	st_list,
	st,
	FOR_1st,
	FOR_2nd,
	FOR_3rd
}; 
//*startとか*endの中のポインタ先はこれを指している。マロックした後、->expressionとかして入れる
/* struct st_list{
	enum kind_basic_stlist kind;
	struct Statement_list *Statement_list;
	struct Statement *statement;
}; */
// st_listの構造体
//基本ブロックの構造体セル
typedef struct basic_block{
    enum   kind_stlist kind;//いる?
    struct Statement_list *start;
    struct Statement_list *end;
    struct basic_block *pred;//head//複数個ないとダメ
    struct basic_block *succ;//tail
}b_block;

//基本ブロックのリスト
struct basic_block_list{
    b_block *block_top;
}*block_ls;

// ポインタの型が一意に定まらない時どうしたらいい？全部の場合でやる？
b_block *make_basic_block_cell(struct Statement_list *startptr, struct Statement_list *endptr, b_block *cp);
struct basic_block_list *make_basic_block_list(void);
void delete_basic_block_cell(b_block *cp);
void delete_basic_block_list(struct basic_block_list *block_ls);
b_block *nth_basic_block_cell(b_block *cp, int n);
b_block *basic_block_nth(struct basic_block_list *block_ls, int n, bool *block_err);
bool insert_basic_block_nth(struct basic_block_list *block_ls, int n, struct Statement_list *startptr, struct Statement_list *endptr);
bool push_basic_block(struct basic_block_list *block_ls, struct Statement_list *startptr, struct Statement_list *endptr);
bool delete_basic_block_nth(struct basic_block_list *block_ls, int n);
b_block *pop_basic_block(struct basic_block_list *block_ls, bool *err);
#endif /* _block_ */