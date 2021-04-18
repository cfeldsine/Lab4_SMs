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
    unsigned char tmpA;
    
    enum SM1_STATES {SM1_Wait1, SM1_Press2,  SM1_Wait2, SM1_Press1} SM1_STATE;
    
    SM1_STATE = SM1_Wait1;
    
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	switch(SM1_STATE){
	    case SM1_Wait1:
		if (tmpA == 0x01){
		    SM1_STATE = SM1_Press2;
		}
		break;
	    case SM1_Press2:
		if (tmpA == 0x00){
		    SM1_STATE = SM1_Wait2;
		}
		break;
	    case SM1_Wait2:
		if (tmpA == 0x01){
		    SM1_STATE = SM1_Press1;
		}
		break;
	    case SM1_Press1:
		if (tmpA == 0x00){
		    SM1_STATE = SM1_Wait1;
		}
		break;
	    default:
		SM1_STATE = SM1_Wait1;
		break;
	}
	
	switch(SM1_STATE){
	    case SM1_Wait1:
		tmpB = 0x01;
		break;
	    case SM1_Press2:
		tmpB = 0x02;
		break;
	    case SM1_Wait2:
		tmpB = 0x02;
		break;
	    case SM1_Press1:
		tmpB = 0x01;
		break;
	    default:
		tmpB = 0x00;
		break;
	}
	PORTB = tmpB;
    }
    return 1;
}
