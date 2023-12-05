yacc -dv test.y  
lex test.l 
cc -o test y.tab.c lex.yy.c
./test 