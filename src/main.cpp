#include <avr/io.h>
#define F_CPU 16000000UL
#include "util/delay.h"
#define delayTime 600 // millisecond delay
// 0b for binary
// 0x for hexadecimal

int main(void) {
    DDRD = 0xFF; // Set data register for PORTD FF is 255

    while (1) {
        // Pattern 1
        // Shift left to right
        for (int i = 0; i < 8; i++) {
            PORTD = 1 << i; // Shifts '1' to the left 'i' times
            _delay_ms(delayTime);
            PORTD = 0;
        }
        // Pattern 2
        // Shift right to left
        for (int i = 7; i >= 0; i--) {
            PORTD = 1 << i; // Shifts '1' to the left 'i' times
            _delay_ms(delayTime);
            PORTD = 0;
        }
        // Pattern 3
        // Shift left to right 2 each time
        for (int i = 0; i < 7; i++) {
          PORTD = 0b11 << i;
          _delay_ms(delayTime);
          PORTD = 0;
        }
        // Pattern 4
        // Shift left to right by even numbers
        for (int i = 0; i < 8; i+=2) {
          PORTD = 1 << (i+1);
          _delay_ms(delayTime);
          PORTD = 0;
        }
        // Shift left to right odd numbers
        for (int i = 0; i < 8; i+=2) {
          PORTD = 1 << i;
          _delay_ms(delayTime);
          PORTD = 0;
        }
    }
}