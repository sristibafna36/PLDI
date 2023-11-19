all:
		gcc -c parser.c
		yacc -dtv A4_13.y
		flex A4_13.l
		gcc -c  lex.yy.c
		gcc -c y.tab.c 
		gcc parser.o lex.yy.o y.tab.o -ll
		gcc -c A4_13.c
		gcc parser.o A4_13.o -o A4_13
		./A4_13