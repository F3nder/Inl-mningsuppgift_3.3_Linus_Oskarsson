/************************************************************************/
/* interrupts.c: Innehåller avbrottsrutin för tryckknapp.               */
/************************************************************************/
#include "headder.h"

/************************************************************************/
/* ISR: Avbrottsrutin för när tryckknappen släpps upp.
       
	    -counter: Räknar antalet knapptryck.                            */
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