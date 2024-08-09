#include "st7735.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Removed `main` and `get_ip_address_new` to avoid conflicts

// Function to display hostname
void lcd_display_hostname(void) {
    char hostname[128] = {0};
    gethostname(hostname, sizeof(hostname));

    lcd_fill_screen(ST7735_BLACK);  // Ensure this function is properly defined somewhere in your project
    lcd_write_string(0, 0, "Host:", Font_8x16, ST7735_WHITE, ST7735_BLACK);
    lcd_write_string(40, 0, hostname, Font_8x16, ST7735_WHITE, ST7735_BLACK);
}

// Function to display IP address
void lcd_display_ip(void) {
    char iPSource[20] = {0};
    strcpy(iPSource, get_ip_address_new());  // Use the function from rpiInfo.c

    lcd_fill_screen(ST7735_BLACK);  // Ensure this function is properly defined somewhere in your project
    lcd_write_string(0, 0, "IP:", Font_8x16, ST7735_WHITE, ST7735_BLACK);
    lcd_write_string(24, 0, iPSource, Font_8x16, ST7735_WHITE, ST7735_BLACK);
}
