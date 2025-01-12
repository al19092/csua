#include <stdio.h>
#include <stdlib.h>
#include "csua.h"
int statement_list_group = 0;

int main(int argc, char* argv[]) {

    extern int yyparse(void);
    extern FILE *yyin;
    
    if (argc == 1) {
        printf("Usage ./prst dir/filename.cs\n");
        return 1;
    }

//    yyin = fopen("tests/prog1.cs", "r");
    yyin = fopen(argv[1], "r");    
    if (yyin == NULL) {
        fprintf(stderr, "cannot open file\n");
        exit(1);
    }

    CS_create_compiler();
    
    if (yyparse()) {
        fprintf(stderr, "Parse Error\n");
        exit(1);
    }
    

    fclose(yyin);
    
    fprintf(stderr, "prase OK\n");
    return 0;
}