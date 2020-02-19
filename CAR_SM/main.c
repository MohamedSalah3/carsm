/*
 * CAR_SM.c
 *
 * Created: 19/02/2020 07:27:08 ص
 *  Author: mo
 */ 


#include "car_sm.h"
uint32_t Distance=0;
int main(void)
{
 Car_SM_Init();
    while(1)
    {
        Car_SM_Update();
		//TODO:: Please write your application code 
    }
}