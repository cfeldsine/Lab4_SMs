/*	Author: cfeld005
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x01;

    unsigned char tmpB = 0x01;

    enum SM1_STATES {SM1_S1, SM1_S2} SM1_STATE;
    
    SM1_STATE = SM1_S1;

    /* Insert your solution below */
    while (1) {
	switch(SM1_STATE){
	    case SM1_S1:
		printf("got here");
		if (PINA == 0x01){
		    SM1_STATE = SM1_S2;
		}
		break;
	    case SM1_S2:
		if (PINA == 0x01){
		    SM1_STATE = SM1_S1;
		}
		break;
	    default:
		SM1_STATE = SM1_S1;
		break;
	}
	
	switch(SM1_STATE){
	    case SM1_S1:
		tmpB = 0x01;
		break;
	    case SM1_S2:
		tmpB = 0x02;
		break;
	    default:
		tmpB = 0x00;
		break;
	}
	PORTB = tmpB;
    }
    return 1;
}
