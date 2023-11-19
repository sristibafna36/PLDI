#include <stdio.h>
#include "lex.yy.c"
#include "y.tab.h"
#include "y.tab.c"
#include "parser.h"
// int yyparse(void);

int main()
{
    printf("\nGrammar Stuff:\n\n");
    yyin = fopen("./A4_13.nc", "r");
    yyparse();
    print_symbol_table();
    print_quad_table();
    print_tac();
}