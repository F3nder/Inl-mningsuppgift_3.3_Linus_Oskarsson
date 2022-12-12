/************************************************************************/
/* setup.c: Initierar mikrodatorn och aktiverar avbrott.                */
/************************************************************************/
#include "headder.h"

/* Funktionsdefinitioner */
static inline void init_ports(void);
static inline void init_interupts(void);

/************************************************************************/
/* setup: Initierar I/O-portar och aktiverar avbrott.                   */
/************************************************************************/
void setup(void)
{
	init_ports();
	init_interupts();
	return;
}

/************************************************************************/
/* init_ports: Initierar I/O-portar.                                    */
/************************************************************************/
static inline void init_ports(void)
{
	DDRB = ((1 << LED_1) | (1 << LED_2) | (1 << LED_3));
	PORTB = (1 << BUTTON_1);
	return;
}

/************************************************************************/
/* init_interrups: Aktiverar avbrott.                                   */
/************************************************************************/
static inline void init_interupts(void)
{
	asm("SEI");
	PCICR = (1 << PCIE0);
	PCMSK0 = (1 << BUTTON_1);
	return;
}