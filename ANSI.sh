#!/bin/bash
#yacc example.y 
#lex example.l
#gcc y.tab.c -ll -ly
#./a.out 

yacc -d ANSI.y 
lex ANSI.l
cc lex.yy.c y.tab.c ANSI_print.c ANSI_Sprint.c ANSI_For_list.c ANSI_symbol_table.c ANSI_symbol_table_list.c ANSI_flow_graph.c ANSI_basic_block_list.c -ly -ll -Wall
#./a.out mytest.txt