#include <stdio.h>
#include <stdlib.h>

/** Requires libedit installation on Linux. */
#include <editline/readline.h>

#define RED  "\033[1;31m"

int main( int argc, char** argv ) {
    printf(RED);
    puts("SM Lispy Version 0.0.1\n");
    puts("Press ctrc-C to exit \n");
     printf("\033[0m;");

    /** Loop forever until user presses ctrl-c */
    while(1) {
        //Out prompt and get input from console
        char*  input = readline("lispy:> ");
        //Add input to history
        add_history(input);
        //Echo back the input
        printf("You entered:%s\n ", input);
        free(input);
    }
    return 0;

}

