#include <stdio.h>
#include "st7735.h"
#include <unistd.h>

extern int show_hostname;  // Declare the global flag

int main(void) {
    uint8_t symbol = 0;

    if(lcd_begin()) {  // LCD Screen initialization
        return 0;
    }

    while(1) {
        // Toggle between hostname and IP address
        show_hostname = !show_hostname;

        // Display based on the current symbol
        lcd_display(symbol);

        // Cycle through symbols
        symbol++;
        if(symbol == 4) {
            symbol = 0;
        }

        sleep(2);  // Wait 2 seconds before updating
    }
    return 0;
}
