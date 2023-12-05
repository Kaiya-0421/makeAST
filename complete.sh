#!/bin/bash
#yacc example.y 
#lex example.l
#gcc y.tab.c -ll -ly
#./a.out 

yacc -d parser.y 
lex lexer.l
cc lex.yy.c y.tab.c -ly -ll
#./a.out mytest.txt