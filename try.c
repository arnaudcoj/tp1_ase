#include "try.h"

int try (struct ctx_s *pctx, func_t *f, int arg) {
  
  asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
       : "=r"(pctx->ctx_esp), "=r"(pctx->ctx_ebp)
       );
  
  return f(arg);
}


int throw (struct ctx_s *pctx, int val) {
  static int throw_val;
  throw_val = val;
  
  asm ("movl %0, %%esp" "\n\t" "movl %1, %%ebp"
       :
       : "r"(pctx->ctx_esp),"r"(pctx->ctx_ebp)
       );

  return throw_val;
}
