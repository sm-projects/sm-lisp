#include "mpc.h"

/* Declare a new lval struct in order to handle eval errors. */
typedef struct {
    int type;
    long num;
    int err;
}lval;

/* enum for lval types. */
enum { LVAL_NUM, LVAL_ERR};

/* error types. */
enum { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM };

/* Two functions to create lval struct. */
lval create_num(long x);
lval create_err(int x);

/* fucntions for printing the lval struct. */
void lval_print(lval v);

/** Print the lval followed by a newline. */
void lval_println(lval v);

/*
 * Evaluates an expression which contains  tokens
 * that can be evaluated.
 *
 */
lval eval_operator(lval x, char* op, lval);

/*
 *  Now  traverse the tree and eval simple expressions.
 */
lval  eval(mpc_ast_t* t);
