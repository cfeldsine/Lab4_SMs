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

enum states {init, press1, wait1, press2} state;
    
int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    
    unsigned char tmpA, tmpB, tmpC;

    state = init;
    while (1) {
	tmpA = PINA;
	switch(state){
	    case init:
		if (tmpA == 0x04){
		    state = press1;
		} else {
		    state = init;
		}
	    case press1:
		if (tmpA == 0x04){
		    state = press1;
		} else if (tmpA == 0x00) {
		    state = wait1;
		} else {
		    state = init;
		}
	    case wait1:
		if (tmpA == 0x02){
		    state = press2;
		} else if (tmpA == 0x00){
		    state = wait1;
		} else {
		    state = init;
		}
	    case press2:
		if (tmpA == 0x02 || tmpA == 0x00){
		    state = press2;
		} else {
		    state = init;
		}
	}

	switch (state) {
	    case init:
		tmpB = 0x00;
		tmpC = 0x00;
		break;
	    case press1:
		tmpC = 0x01;
		break;
	    case wait1:
		tmpC = 0x02;
		break;
	    case press2:
		tmpB = 0x01;
		tmpC = 0x03;
		break;
	    default:
		break;
	}
	
	PORTB = tmpB;
	PORTC = tmpC;	
    }
    return 1;
}
