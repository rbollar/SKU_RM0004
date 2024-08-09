#include "st7735.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Function declarations for external use
extern char* get_ip_address_new(void);

uint8_t lcd_begin(void) {
    // Implement your initialization logic here
    // For example, initializing I2C or setting up the display parameters
    printf("LCD Initialized\n");
    return 0; // Return 0 on success
}

void lcd_display(uint8_t symbol) {
    switch (symbol) {
        case 0:
            lcd_display_cpuLoad();
            break;
        case 1:
            lcd_display_ram();
            break;
        case 2:
            lcd_display_temp();
            break;
        case 3:
            lcd_display_disk();
            break;
        default:
            break;
    }
}

// Assume other display functions are implemented here as discussed earlier
