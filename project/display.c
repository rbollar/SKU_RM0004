/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/
#include <stdio.h>
#include "st7735.h"
#include "time.h"
#include <unistd.h>

// Add this declaration if it's not in st7735.h
void lcd_display_by_time(void);

int main(void) 
{
    if(lcd_begin())  // LCD Screen initialization
    {
        return 0;
    }
    sleep(1);

    while(1)
    {
        lcd_display_by_time();  // Update the screen based on the current time

        // Sleep for 1 second before checking the time again
        sleep(1);
    }

    return 0;
}
