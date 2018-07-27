#include "mpc.h"

/*
 * Evaluates an expression which contains  tokens
 * that can be evaluated.
 *
 */
long eval_operator(long x, char* op, long);

/*
 *  Now  traverse the tree and eval simple expressions.
 */
long eval(mpc_ast_t* t);
