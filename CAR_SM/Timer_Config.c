/*
 * Timers_Config.c
 *
 * Created: 14/02/2020 04:58:23 ص
 *  Author: mo
 */
 /*INCLUDES**/
#include "Timer_Config.h"

Timer_cfg_s Timer_Configuration =
{
TIMER_CH2,
TIMER_MODE,
TIMER_POLLING_MODE,
TIMER_PRESCALER_1024,/*it will not start untill we call timer start function*/
};
