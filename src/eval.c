#include "eval.h"

long  eval_operator(long x, char* op, long y) {

  if (strcmp(op,"+")==0) {return x + y;}
  if (strcmp(op,"-")==0) {return x - y;}
  if (strcmp(op,"*")==0) {return x * y;}
  if (strcmp(op,"/")==0) {return x / y;}
  return 0;
}

long eval(mpc_ast_t* t){
    if(strcmp(t->tag,"number")) {
        return atoi(t->contents);
    }

    /* The second child must be the operator, see mpc structure. */
    char* op = t->children[1]->contents;
    /* Wlak through the third child. */
    long  x = eval(t->children[2]);

    /* Now walk through the remaining tree and combine. */
    int i =3;
    while(strstr(t->children[i]->tag, "expr")) {
        x = eval_operator(x,op,eval(t->children[i]));
        i++;
    }
    return x;

}
