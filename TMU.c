﻿/*
 * TMU.c
 *
 * Created: 24/02/2020 01:22:29 م
 *  Author: mo
 */

#include "TMU.h"
#include "../../MCAL/Interrupts/Interrupts.h"

#define Buffer_Size 3
void Tmu_excute(void);
uint8_t u8_Is_Intialized=0;
start_status start[Buffer_Size];
uint8_t u8_FUN_index=0;
Buffer_Request Buffer_Array[Buffer_Size];
volatile uint8_t u8Excution_to_be_done=0;
//static uint8_t u8_is_Started=0;
uint8_t Start_status[Buffer_Size];
ERROR_STATUS TMU_Init (const TMU_ConfigType * ConfigPtr )
{uint8_t u8_channel_ID;
uint8_t ret=E_OK;
/*************************************************************************/
/*			Intializ the required timer identified by the user			 */
/************************************************************************/
if(u8_Is_Intialized == 0)
{
	u8_Is_Intialized++;
if(ConfigPtr==NULL){ret=TMU_MODULE+NULL_PTR;}
else{
	u8_channel_ID=ConfigPtr->u8_Timer_channel;
switch(u8_channel_ID)
{
	case TIMER_CH0:
			G_interrupt_Enable();
			Timer_Init(&Timer_Configuration0);
				break;
	case TIMER_CH2:
		G_interrupt_Enable();
		Timer_Init(&Timer_Configuration2);
			break;
	default:
			ret+=E_NOK;
			break;
}


/*************************************************************************/
/*Intializ the required timer identified by the user using required prescaler  */
/************************************************************************/

switch(ConfigPtr->u8_resolution)
{
	case TIMER_RESOLUTION_1_MS:
	{
		switch(u8_channel_ID)
		{
			case TIMER_CH0 :
		Timer_Start(TIMER_CH0,250);

					break;
			case TIMER_CH2 :
				Timer_Start(TIMER_CH2,14);
					break;
			default:
				ret+=E_NOK;
					break;
		}
	break;
	}



	default:
	ret+=E_NOK;
	break;

}


}
/****************************************************************************/
/*      Deal with Errors  to be returned									*/
/***************************************************************************/
}else
{
	ret+=MULTIPLE_INIT;
}
return ret;
}



ERROR_STATUS TMU_DeInit( void )
{
	uint8_t ret=E_OK;
	/************************************************************************************************/
	/*1    	De_intialize the timer																	*/
	/*2		make sure this function is not called unless timer was intialized before by  TMU_INIT	*/
	/************************************************************************************************/
if (u8_Is_Intialized==1)
{/*Make the timer without a clk*/
	Timer_Init(&Timer_Deinit_Configuration0);

	u8_Is_Intialized=0;

}else if(u8_Is_Intialized>1){ret+=MULTIPLE_INIT;}
	else{
	ret=E_NOK;
	}


return ret;
}

ERROR_STATUS TMU_Start_Timer(ptr_to_Fun Function_Consumer,uint8_t  u8_Preodicity,uint8_t u8_function_index,uint16_t u16_Time_delay)
{uint8_t ret=E_OK;
	/*
	this enables interrupt and start the timer with the required configurations
	and provide the request to request buffer (ptr_to_func,delay) Dispatcher with the call back function needed(consumer)
	and make sure this function must not be excuted unless Init happened and De_init not happened
	*/
	if(Function_Consumer==NULL){ret=TMU_MODULE+NULL_PTR;}
	else{
	if(u8_Is_Intialized == 1)
	{
if(u8_Preodicity > 1){ret+=INVALID_PARM+TMU_MODULE;}
else{
	if(u8_function_index >= Buffer_Size){ret+=INVALID_PARM+TMU_MODULE;}
	else{
	(Buffer_Array[u8_function_index]).preodic=u8_Preodicity;
	(Buffer_Array[u8_function_index]).Fuction_consumer=Function_Consumer;
	(Buffer_Array[u8_function_index]).u16_time_delay=u16_Time_delay;
	(Buffer_Array[u8_function_index]).u8_flag_is_stopped=1;
			}
		}
	}
else if(u8_Is_Intialized>1){ret+=MULTIPLE_INIT;}else{
	ret+=NOT_INIT;
}
}
	return ret;
}

ERROR_STATUS TMU_Main_Function(void)
{	uint8_t ret=E_OK;
	/***********************************************************************/
	/*					LOOP upon Buffer Request						*/
	/*********************************************************************/
if (u8Excution_to_be_done==1)
{	u8Excution_to_be_done=0;

		for (u8_FUN_index=0;u8_FUN_index<3;u8_FUN_index++)
			{
/****************************************************************/
/* check if the event is stopped ... do nothing*/
		if((Buffer_Array[u8_FUN_index]).u8_flag_is_stopped==0){ret=E_OK;}
		else{
	/***************************************************************/
	/*if the timer started .. and condition met excute the consumer*/
	/***************************************************************/

	/********************************************/
	/*Count up when flag is set**/
	((Buffer_Array[u8_FUN_index]).u16_Counter)++;
	/*make the flag down*/


/*	u16Excution_to_be_done=100;  ISR*/
	if(((Buffer_Array[u8_FUN_index]).u16_time_delay) == ((Buffer_Array[u8_FUN_index]).u16_Counter) )
	{
		((Buffer_Array[u8_FUN_index]).Fuction_consumer)();
	/******************************************/
	/*Make it zero so that it will work the next time at the required time (to stop it of ovf)*/
		(Buffer_Array[u8_FUN_index]).u16_Counter=0;

	}

	/*********************************************************/
	/* if not preodic increment the index after excuteing	*/
	/*********************************************************/

	if((Buffer_Array[u8_FUN_index]).preodic==0)
	{
		/*to make it see the next event in the next time
		Also Status_flag =1 so that this function will be stopped
		*/
		(Buffer_Array[u8_FUN_index]).u8_flag_is_stopped=0;
	}


		}
	}
}
return ret;
}


ERROR_STATUS TMU_Stop_Timer(uint8_t u8_function_index)
{uint8_t ret=E_OK;
	if(u8_function_index >= Buffer_Size){ret+=INVALID_PARM+TMU_MODULE;}
	else{
	if (u8_Is_Intialized==1)
	{	(Buffer_Array[u8_function_index]).u8_flag_is_stopped=0;
		ret=E_OK;
	}
	else if(u8_Is_Intialized == 0 ){ret +=NOT_INIT+TMU_MODULE;}
	else if(u8_Is_Intialized>1){ret+=MULTIPLE_INIT;}
		/***************************************************/
	/*     Set the stop flag							*/
	/***************************************************/
}
return ret;
}

void Tmu_Fun(void);
void Tmu_For(void);
void Tmu_excute(void);

void timer_interrupt(void){
	u8Excution_to_be_done=1;
}
