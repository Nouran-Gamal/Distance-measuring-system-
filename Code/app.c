 /******************************************************************************
 *
 * File Name: app.c
 *
 * Description: Application layer
 *
 * Author: Nouran Gamal
 *
 *******************************************************************************/

#include "ultrasonic.h"
#include "lcd.h"

#include<avr/interrupt.h> /* to use sei function */
#include<util/delay.h>    /* to use delay function */


int main(){

	sei();  /* Enable I-Bit */

	/* initialization */
	LCD_init();
	Ultrasonic_init();

    uint16 distance=0;  /* variable used to store value measured from ultrasonic */


	LCD_displayString("Distance=     cm");

	while(1){

		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 10);
		LCD_intgerToString(distance);
		if(distance<100)
			LCD_displayCharacter(' ');
		/*
		 * delay between every trigger to make ultrasonic able to produce echo for every trigger
		 * if i don't make delay ,not all triggers produce echo
		 * (so i save power consumption) and benefit from every trigger
	     */
		_delay_ms(100);
	}

}
