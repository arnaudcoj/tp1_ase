#include "try.h"

static int throw_val;

int try (struct ctx_s *pctx, funct_t *f, int arg) {
  
  asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
       : "=r"(pctx->ctx_esp*),"=r"(pctx->ctx_ebp*)
       );
  
  return f(arg);
}


int throw (struct ctx_s *pctx, int val) {
  return ;
}
