#include <stdio.h>
#include <stdlib.h>

void q1 (int param1, int param2);
void f1 (int param1, int param2);
void f2 (int param1, int param2);

int main (void) {
  q1(32, 67);
  return 0;
}

void q1 (int param1, int param2) {
  unsigned int esp = 0;
  unsigned int ebp = 0;

  asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
       : "=r"(esp),"=r"(ebp)
       :
       :);

  printf("esp = %u\nebp = %u\n", esp, ebp);
  printf("&esp = %u\n&ebp = %u\n", &esp, &ebp);
  printf("&param1 = %u\n&param2 = %u\n", &param1, &param2);

  f1(12, 42);
  
  return;
}

void f1 (int param1, int param2) {
  unsigned int esp = 0;
  unsigned int ebp = 0;
  
  asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
       :"=r"(esp),"=r"(ebp)
       :
       :);

  printf("\tesp = %u\n\tebp = %u\n", esp, ebp);
  printf("\t&esp = %u\n\t&ebp = %u\n", &esp, &ebp);
  printf("\t&param1 = %u\n\t&param2 = %u\n", &param1, &param2);
  f2(64, 3);
  return ;
}

void f2 (int param1, int param2) {

  unsigned int esp = 0;
  unsigned int ebp = 0;
  
  asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
       : "=r"(esp),"=r"(ebp)
       :
       :);

  printf("\t\tesp = %u\n\t\tebp = %u\n", esp, ebp);
  printf("\t\t&esp = %u\n\t\t&ebp = %u\n", &esp, &ebp);
  printf("\t\t&param1 = %u\n\t\t&param2 = %u\n", &param1, &param2);
  return ;
}
