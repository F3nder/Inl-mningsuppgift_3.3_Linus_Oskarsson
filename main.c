/************************************************************************/
/* main.c: Program för att skifta lysdioders blinknings ordning efter
           5 knapptryck.                                                */
/************************************************************************/
#include "headder.h"

int main(void)
{
	setup();
	
	while (1)
	{
		leds_blink(100);
	}
}