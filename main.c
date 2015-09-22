#include <stdio.h>
#include <stdlib.h>

void q1 (int useless1, int useless2);
void f1 (int useless1, int useless2);
void f2 (int useless1, int useless2);

int main (void) {



  
  /*q1(32, 67);*/
  return 0;
}

void q1 (int useless1, int useless2) {
  int esp = 0;
  int ebp = 0;

  asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
       : "=r"(esp),"=r"(ebp)
       );

  printf("esp = %d\nebp = %d\n", esp, ebp);
  printf("&esp = %d\n&ebp = %d\n", &esp, &ebp);
  printf("&param1 = %d\n&param2 = %d\n", &useless1, &useless2);

  f1(12, 42);
  
  return;
}

void f1 (int useless1, int useless2) {
  int esp = 0;
  int ebp = 0;
  
  asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
       : "=r"(esp),"=r"(ebp)
       );

  printf("\tesp = %d\n\tebp = %d\n", esp, ebp);
  printf("\t&esp = %d\n\t&ebp = %d\n", &esp, &ebp);
  printf("\t&param1 = %d\n\t&param2 = %d\n", &useless1, &useless2);
  f2(64, 3);
  return ;
}

void f2 (int useless1, int useless2) {

  int esp = 0;
  int ebp = 0;
  
  asm ("movl %%esp, %0" "\n\t" "movl %%ebp, %1"
       : "=r"(esp),"=r"(ebp)
       );

  printf("\t\tesp = %d\n\t\tebp = %d\n", esp, ebp);
  printf("\t\t&esp = %d\n\t\t&ebp = %d\n", &esp, &ebp);
  printf("\t\t&param1 = %d\n\t\t&param2 = %d\n", &useless1, &useless2);
  return ;
}
