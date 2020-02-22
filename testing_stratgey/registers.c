#include "std_types.h"
/*
 * General Registers
 */
uint8_t MCUCR	= 0 ;
uint8_t MCUCSR	= 0 ;
uint8_t GICR  = 0 ;
uint8_t GIFR	= 0;
uint8_t SREG	= 0 ;
/*
 * PORTx registers
 */

uint8_t PORTA_DATA	= 0 ;
uint8_t PORTA_DIR		= 0 ;
uint8_t PORTA_PIN		= 0 ;


uint8_t PORTB_DATA	= 0 ;
uint8_t PORTB_DIR	 = 0;
uint8_t PORTB_PIN		= 0 ;

uint8_t PORTC_DATA	= 0 ;
uint8_t PORTC_DIR		= 0 ;
uint8_t PORTC_PIN		= 0 ;


uint8_t PORTD_DATA	=  0 ;
uint8_t PORTD_DIR		= 0 ;
uint8_t PORTD_PIN		= 0 ;


/*
 * General Timer registers
 */
uint8_t TIMSK		=0;
uint8_t TIFR		=0;

/*
 * Timer 0 Registers
 */

uint8_t TCCR0			= 0;
uint8_t TCNT0			= 0;
uint8_t OCR0			= 0;
/*
 * Timer 1 Registers
 */

uint8_t TCCR1A	=0;
uint8_t TCCR1B		=0;
uint16_t TCCR1		=0;

uint8_t TCNT1H		=0;
uint8_t TCNT1L		=0;
uint16_t TCNT1		=0;


uint8_t OCR1AH			=0;
uint8_t OCR1AL			=0;
uint8_t OCR1A				=0;

uint8_t OCR1BH		=0;
uint8_t OCR1BL		=0;
uint8_t OCR1B			=0;

uint8_t ICR1H		=0;
uint8_t ICR1L		=0;
uint16_t ICR1		=0;


/*
 * Timer 2 Registers
 */
uint8_t TCCR2				=0;
uint8_t TCNT2			=0;
uint8_t OCR2			=0;
uint8_t ASSR      =0;
