#include <msp430.h> 
#include "RF.h"
#include "RF.c"
#include "Config.h"

/*
 * main.c
 */
void chase(void);

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer

	  P1DIR |= (LED0 + LED1 + LED2 + LED3 + LED4 + LED5);                            // Set all pins but RXD to output
	  P1OUT &= ~(LED0 + LED1 + LED2 + LED3 + LED4 + LED5);
	  P2DIR |= (LED6 + LED7 + LED8 + LED9 + TX + YellowLED);                            // Set all pins but RXD to output
	  P2OUT &= ~(LED6 + LED7 + LED8 + LED9 + TX + YellowLED);
	

	while(1)
	{
		P2OUT ^= YellowLED;
		chase();
	}
	}

void chase()
{
	 P1OUT |= LED0;
	 _delay_cycles(50000);

	 P1OUT |= LED1;
	 P1OUT &= ~(LED0);
	 _delay_cycles(50000);

	 P1OUT |= LED2;
	 P1OUT &= ~(LED1);
	 _delay_cycles(50000);

	 P1OUT |= LED3;
	 P1OUT &= ~(LED2);
	 _delay_cycles(50000);

	 P2OUT |= LED7;
	 P1OUT &= ~(LED3);
	 _delay_cycles(50000);

	 P1OUT |= LED4;
	 P2OUT &= ~(LED7);
	 _delay_cycles(50000);

	 P1OUT |= LED5;
	 P1OUT &= ~(LED4);
	 _delay_cycles(50000);

	 P2OUT |= LED6;
	 P1OUT &= ~(LED5);
	 _delay_cycles(50000);

	 P2OUT |= LED8;
	 P2OUT &= ~(LED6);
	 _delay_cycles(50000);

	 P2OUT |= LED9;
	 P2OUT &= ~(LED8);
	 _delay_cycles(50000);

	 P1OUT |= LED0;
	 P2OUT &= ~(LED9);
	 _delay_cycles(50000);
}
