#include "ICU.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
Icu_Init(&ICU_Configuration);
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR0%#X\n",TCCR0);
printf("TIMSK%#X\n",TIMSK);

  return 0;
}
