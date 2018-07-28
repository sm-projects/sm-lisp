#include <stdio.h>
#include <stdlib.h>

/** Requires libedit installation on Linux. */
#include <editline/readline.h>

#include "mpc.h"
#include "eval.h"

#define RED  "\033[1;31m"

/* Displays the prompt for the repl. */
int display_prompt();

int main( int argc, char** argv ) {

     /* Print the repl prompt. */
    display_prompt();

    /** Create the calculator language parse. */
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr = mpc_new("expr");
    mpc_parser_t* Lispy = mpc_new("lispy");

    /** Define the lispy calculator language. */
    mpca_lang(MPCA_LANG_DEFAULT,
        "                                                            \
              number      : /-?[0-9]+/ ;                             \
              operator    : '+' | '-' | '*' | '/' ;                  \
              expr        :  <number> | '(' <operator> <expr>+ ')' ; \
              lispy       :  /^/ <operator> <expr>+ /$/ ;            \
        ",
        Number,Operator, Expr, Lispy);

    /** Loop forever until user presses ctrl-c */
    while(1) {
        //Out prompt and get input from console
        char*  input = readline("smlispy:> ");
        //Add input to history
        add_history(input);

        /** Now parse the user input for lispy calculator. */
        mpc_result_t r;
        if (mpc_parse("<stdin>",input,Lispy,&r)) {
            lval result = eval(r.output);
            lval_println(result);
            //On sucess print and delete the AST
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        } else {
            printf("DEBUG: Reached here.\n");
            mpc_err_print(r.output);
            printf("DEBUG: Reached here.\n");
            mpc_ast_delete(r.output);


        }
        //Echo back the input
        //printf("smlispy:%s\n ", input);
        free(input);
    }
    mpc_cleanup(4,Number,Operator,Expr,Lispy);
    return 0;
}

int display_prompt() {
    printf(RED);
    puts("SM Lispy Version 0.0.1\n");
    puts("Press ctrc-C to exit \n");
     printf("\033[0m");
     return 0;
}
