/*
 * car_sm.c
 *
 * Created: 19/02/2020 07:30:03 ص
 *  Author: mo
 */ 

#include "car_sm.h"
extern uint16_t Distance;
ERROR_STATUS Car_SM_Init(void)
{

Steering_Init();
Us_Init();

}


ERROR_STATUS Car_SM_Update(void)
{
Us_Trigger();
Us_GetDistance(&Distance);

if(Distance <= 30)
{
	
	Steering_SteerCar(CAR_RIGHT,50);
}else
{
	Steering_SteerCar(CAR_FORWARD,50);
}
}	


