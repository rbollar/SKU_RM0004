#include "st7735.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

extern char* get_ip_address_new(void);

uint8_t lcd_begin(void) {
    // Example initialization logic
    printf("LCD Initialized\n");
    return 0; // Return 0 on success
}

void lcd_display_cpuLoad(void) {
    // Implementation for displaying CPU load
    printf("Displaying CPU Load\n");
    // Add your display logic here
}

void lcd_display_ram(void) {
    // Implementation for displaying RAM usage
    printf("Displaying RAM Usage\n");
    // Add your display logic here
}

void lcd_display_temp(void) {
    // Implementation for displaying Temperature
    printf("Displaying Temperature\n");
    // Add your display logic here
}

void lcd_display_disk(void) {
    // Implementation for displaying Disk usage
    printf("Displaying Disk Usage\n");
    // Add your display logic here
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
