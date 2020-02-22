#include "ICU.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[]) {
uint8_t Ret=E_OK;
uint8_t virtualWhileone='y';
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case ICU_CH2,ICU_TIMER_CH0 *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR0%#X\n",TCCR0);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);
ICU_Configuration.ICU_Ch_No=ICU_CH1;
ICU_Configuration.ICU_Ch_Timer=ICU_TIMER_CH0;
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case ICU_CH1,ICU_TIMER_CH0 *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR0%#X\n",TCCR0);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);
ICU_Configuration.ICU_Ch_No=ICU_CH1;
ICU_Configuration.ICU_Ch_Timer=ICU_TIMER_CH0;
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case ICU_CH0,ICU_TIMER_CH0 *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR0%#X\n",TCCR0);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);
ICU_Configuration.ICU_Ch_No=ICU_CH0;
ICU_Configuration.ICU_Ch_Timer=ICU_TIMER_CH0;
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case ICU_CH2,ICU_TIMER_CH1 *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR1%#X\n",TCCR1);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);
ICU_Configuration.ICU_Ch_No=ICU_CH2;
ICU_Configuration.ICU_Ch_Timer=ICU_TIMER_CH1;
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case ICU_CH2,ICU_TIMER_CH1 *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR1%#X\n",TCCR1);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);
ICU_Configuration.ICU_Ch_No=ICU_CH1;
ICU_Configuration.ICU_Ch_Timer=ICU_TIMER_CH1;
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case ICU_CH1,ICU_TIMER_CH1 *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR1%#X\n",TCCR1);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);
ICU_Configuration.ICU_Ch_No=ICU_CH2;
ICU_Configuration.ICU_Ch_Timer=ICU_TIMER_CH1;
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case ICU_CH2,ICU_TIMER_CH1 *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR1%#X\n",TCCR1);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);
ICU_Configuration.ICU_Ch_No=ICU_CH1;
ICU_Configuration.ICU_Ch_Timer=ICU_TIMER_CH2;
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case ICU_CH1,ICU_TIMER_CH2 *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR2%#X\n",TCCR2);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);
ICU_Configuration.ICU_Ch_No=ICU_CH0;
ICU_Configuration.ICU_Ch_Timer=ICU_TIMER_CH2;
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case ICU_CH0,ICU_TIMER_CH2 *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR2%#X\n",TCCR2);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);
printf("Test scenario one passed\n");
printf("Test scenario Two passed\n");
ICU_Configuration.ICU_Ch_No='0';
ICU_Configuration.ICU_Ch_Timer='m';
Icu_Init(&ICU_Configuration);
printf("************************\n");
printf("*Case non valid arguments NULL,m *");
printf("************************\n");
printf("GICR%#X\n",GICR);
printf("MCUCSR%#X\n",MCUCSR);
printf("TCCR0%#X\n",TCCR0);
printf("TCCR1%#X\n",TCCR1);
printf("TCCR2%#X\n",TCCR2);
printf("TIMSK%#X\n",TIMSK);
printf("MCUCR%#X\n",MCUCR);

printf("Test scenario Three failed\n");

printf("Testing ERROR_STATUS Icu_ReadTime(uint8_t Icu_Channel, uint8_t Icu_EdgeToEdge, uint32_t * Icu_Time) function\n");
/*************************************************************************************************************************/
/*first we test what happen in interrupt and the data returned by Icu_ReadTime if valid it will passes the test cases */
/*************************************************************************************************************************/

do{
  printf("Enter TCNT0 Value\n");
  scanf("%#X\n",&TCNT0);
  printf("Enter y if u wanna continue\n");
  scanf("%c\n",virtualWhileone);
  printf("Enter Is ovf happend Enter 1 if yes\n");
  scanf("%d\n",u8_ovf_happendovf);
EXTI();

}while(virtualWhileone == 'y');

  return 0;
}
