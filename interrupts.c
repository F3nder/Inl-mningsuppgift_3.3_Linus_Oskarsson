/************************************************************************/
/* interrupts.c: Inneh�ller avbrottsrutin f�r tryckknapp.               */
/************************************************************************/
#include "headder.h"

/************************************************************************/
/* ISR: Avbrottsrutin f�r n�r tryckknappen sl�pps upp.
       
	    -counter: R�knar antalet knapptryck.                            */
/************************************************************************/
ISR (PCINT0_vect)
{
	static volatile uint8_t counter = 0;
	if (!BUTTON_1_IS_PRESSED)
	{
		if (counter == 5)
		{
			led_change_direction();
		}
		else if (counter >= 10)
		{
			led_change_direction();
			counter = 0;
		}
		counter++;
	}
}