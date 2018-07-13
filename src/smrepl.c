#include <stdio.h>

/* Declare a bounded buffer to store  user input. */
static char input[2048];

int main( int argc, char** argv ) {
    puts("SM Lispy Version 0.0.1\n");
    puts("Press ctrc-C to exit \n");

    /** Loop forever until user presses ctrl-c */
    while(1) {
        fputs("lispy> ",stdout);
        /** Read a line of user input from the terminal. */
        fgets(input, 2048, stdin);
        /** Echo the input back to the user. */
        printf("You entered:%s\n ", input);
    }
    return 0;

}

