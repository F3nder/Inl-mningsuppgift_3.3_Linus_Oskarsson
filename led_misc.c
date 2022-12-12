/************************************************************************/
/* led_misc.c: Innehåller funktioer för blinkning av lysdioder. 
			   Samt funktion för att generera delay i millisekunder.    */
/************************************************************************/
#include "headder.h"

static volatile bool leds_blink_direction;
static uint16_t speed_ms = 0;

/************************************************************************/
/* led_change_direction: Togglar lysdioderna blinknings ordning.        */
/************************************************************************/
void led_change_direction(void)
{
	leds_blink_direction = !leds_blink_direction;
	speed_ms = 0;
	return;
}

/************************************************************************/
/* leds_blink: Bestämmer vilket håll lysdioderna skall blinka.

               -blink_speed_ms: Anger vilken hastighet lysdioderna 
			                    skall blinka i millisekunder.           */
/************************************************************************/
void leds_blink(uint16_t blink_speed_ms)
{
	speed_ms = blink_speed_ms;
	if (leds_blink_direction)
	{
		leds_blink_sequenc_forward(&speed_ms);
	}
	else if (!leds_blink_direction)
	{
		led_blink_sequenc_reverse(&speed_ms);
	}
	return;
}

/************************************************************************/
/* leds_blink_sequenc_forward: Definerar ena hållet som lysdiderna
                               skall blinka "LED_1" till LED_3.
							   
							   -blink_speed_ms: Anger vilken hastighet 
							                    lysdioderna skall blinka 
												i millisekunder.        */
/************************************************************************/
void leds_blink_sequenc_forward(uint16_t* blink_speed_ms)
{
	LED_1_ON;
	LED_2_OFF;
	LED_3_OFF;
	ms_delay(blink_speed_ms);
		
	LED_1_OFF;
	LED_2_ON;
	LED_3_OFF;
	ms_delay(blink_speed_ms);
		
	LED_1_OFF;
	LED_2_OFF;
	LED_3_ON;
	ms_delay(blink_speed_ms);
		
	LEDS_OFF;
	
	return;
}

/************************************************************************/
/* leds_blink_sequenc_forward: Definerar andra hållet som lysdiderna
                               skall blinka "LED_3" till LED_1.
							   
							   -blink_speed_ms: Anger vilken hastighet 
							                    lysdioderna skall blinka 
												i millisekunder.        */
/************************************************************************/
void led_blink_sequenc_reverse(uint16_t* blink_speed_ms)
{
		LED_1_OFF;
		LED_2_OFF;
		LED_3_ON;
		ms_delay(blink_speed_ms);
			
		LED_1_OFF;
		LED_2_ON;
		LED_3_OFF;
		ms_delay(blink_speed_ms);
			
		LED_1_ON;
		LED_2_OFF;
		LED_3_OFF;
		ms_delay(blink_speed_ms);
			
		LEDS_OFF;
		return;
}

/************************************************************************/
/* ms_delay: Genererar delay i millisekunder.
            
			 -blik_speed_ms: Angiven delay i millisekunder.             */
/************************************************************************/
void ms_delay(uint16_t* blink_speed_ms)
{
	for (uint16_t i = 0; i < *blink_speed_ms; i++)
	{
		_delay_ms(1);
	}
	return;
}