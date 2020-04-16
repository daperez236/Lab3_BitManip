/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #3  Exercise #1
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
    DDRA = 0x00; PORTA = 0xFF; //port a input
    DDRB = 0x00; PORTB = 0xFF; //port b input
    DDRC = 0xFF; PORTC = 0x00; //port C output
	unsigned char tmpA = 0x00;
	unsigned char tmpB = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char countA = 0x00;
	unsigned char countB = 0x00;
	unsigned char i = 0x00;
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	countA = 0x00;
	countB = 0x00;
	for(i; i < 0x08; i = i + 0x01)
	{
		tmpC  = (tmpA >> i) & 0x01;
		if(tmpC == 0x01)
		{
			countA = countA + 0x01;
		}
	}
	i = 0x00;
	for(i; i < 0x08; i = i + 0x01)
	{
		tmpC = (tmpB >> i) & 0x01;
		if(tmpC == 0x01)
		{
			countB = countB + 0x01;
		}
	}
	PORTC = countA + countB;		
	i = 0x00;		
}
    return 1;
}
