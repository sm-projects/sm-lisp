/********************************************************************
* FILE NAME:eval.c
*
* PURPOSE: Contains all evaluation logic for the compiler's AST
*
* FILE REFERENCES: eval.h
*
* Name
*
* Description
*
* -------------------------------------------------------------------------------------------------------------------------
* ABNORMAL TERMINATION CONDITIONS, ERROR AND WARNING MESSAGES:
*
*
*
* ASSUMPTIONS, CONSTRAINTS, RESTRICTIONS:
*
*
*
* NOTES:
*
*
*
* REQUIREMENTS/FUNCTIONAL SPECIFICATIONS REFERENCES:
*
*
*
* DEVELOPMENT HISTORY:
*
*----------------------------------------------------------------------------------------------------------------------
* Date
* Author
* Change Id
* Release
* Description Of Change
*******************************************************************/
#include "eval.h"

lval create_num(long x) {
    lval v;
    v.type = LVAL_NUM;
    v.num = x;
    return v;
}

lval create_err(int x) {
    lval v;
    v.type = LVAL_ERR;
    v.err = x;
    return v;
}

void lval_print(lval v) {
    switch(v.type) {
        //if type is of NUM then print it
        case LVAL_NUM:
            printf("%li\n", v.num);
            break;
        case LVAL_ERR:
            if (v.err == LERR_DIV_ZERO){
                printf("ERROR: Division by zero.\n");
            }
            if (v.err == LERR_BAD_OP){
                printf("ERROR: Invalid operator, only +,-,*, / operators are allowed.\n");
            }
            if (v.err == LERR_BAD_NUM){
                printf("ERROR: invalid number. \n");
            }
            break;
         default:
            break;
    }
}

void lval_println(lval v) {
    lval_print(v);
    putchar('\n');
}

lval eval_operator(lval x, char* op, lval y) {

  //check for error types
  if (x.type == LVAL_ERR) {return x;}
  if (y.type == LVAL_ERR) {return y;}

  if (strcmp(op,"+")==0) {return create_num(x.num + y.num);}
  if (strcmp(op,"-")==0) {return create_num(x.num - y.num);}
  if (strcmp(op,"*")==0) {return create_num(x.num * y.num);}

  if (strcmp(op,"/")==0) {
      return (y.num == 0
          ? create_err(LERR_DIV_ZERO)
          : create_num(x.num / y.num));
  }
  return create_err(LERR_BAD_OP);
}

lval eval(mpc_ast_t* t){
    int errno;
    if(strstr(t->tag,"number")) {
        errno = 0;
        long x = strtol(t->contents,NULL,10);
        return errno != ERANGE ? create_num(x) : create_err(LERR_BAD_NUM);
    }
    /* The second child must be the operator, see mpc structure. */
    char* op = t->children[1]->contents;
    /* Wlak through the third child. */
    lval  x = eval(t->children[2]);

    /* Now walk through the remaining tree and combine. */
    int i =3;
    while(strstr(t->children[i]->tag, "expr")) {
        x = eval_operator(x,op,eval(t->children[i]));
        i++;
    }
    return x;

}
