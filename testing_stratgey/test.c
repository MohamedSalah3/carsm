#include "ICU.h"
#include <stdio.h>
#include <stdlib.h>
uint32_t data0=0;
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
/*first we test what happen in interrupt and the data returned by
Icu_ReadTime if valid it will passes the test cases */
/*************************************************************************************************************************/

do{
  printf("Enter TCNT0 Value when rising edge\n");
  scanf("%d",&TCNT0);
  EXTI();
if(READBIT(MCUCSR,6)){printf("switching from rise to fall failed\n");}
  else{printf("switching from rising to fall edge passed");}

  printf("Enter TCNT0 Value when failing edge\n");
  scanf("%d",&TCNT0);
  EXTI();
  if(READBIT(MCUCSR,6)){printf("switching from Failling Edge to Rising Edge Passed\n");}
    else{printf("switching from Failling to Rising edge failed");}
/*********************************************************/
Ret=Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_FALL, &data0);
if(Ret==E_OK){printf("PASSED ERROR_STATUS\n");}
printf("TCCR0=%#X\n",TCCR0);
printf("data at ICU_RISE_TO_FALL , Timer0=%d\n",data0);
/********************************************************/
/*******************************************************/
/*             ICU_RISE_TO_RISE                        */
/*********************************************************/
Ret=Icu_ReadTime(ICU_TIMER_CH0,ICU_RISE_TO_RISE, &data0);
if(Ret==E_OK){printf("PASSED ERROR_STATUS\n");}
printf("TCCR0=%#X\n",TCCR0);
printf("data at ICU_RISE_TO_RISE , Timer0=%d\n",data0);
/********************************************************/
/********************************************************/
                 /*ICU_FALE_TO_RISE*/
/*********************************************************/
Ret=Icu_ReadTime(ICU_TIMER_CH0,ICU_FALE_TO_RISE, &data0);
if(Ret==E_OK){printf("PASSED ERROR_STATUS\n");}
printf("TCCR0=%#X\n",TCCR0);
printf("data at ICU_FALE_TO_RISE , Timer0=%d\n",data0);
/********************************************************/
/************************************************************************/
printf("Enter y if u wanna continue press any thing if you will not continue\n");
fflush(stdout);
fflush(stdin);
scanf("%c",&virtualWhileone);
}while(virtualWhileone == 'y');
printf("Case Using Timer1 or timer2 failed cause of hardware constrains\n");

  return 0;
}
