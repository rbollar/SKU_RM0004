/******
Demo for ssd1306 i2c driver for  Raspberry Pi 
******/
#include <stdio.h>
#include "st7735.h"
#include "time.h"
#include <unistd.h>



int main(void) 
{
    uint8_t symbol = 0;
    
    if(lcd_begin())      //LCD Screen initialization
    {
        return 0;
    }
    sleep(1);
    while(1)
    {
        lcd_display(symbol);
        sleep(2); // Keep the sleep time as you prefer, increased to 2 seconds for better readability
        symbol++;
        if(symbol==5)  // We now have 5 screens (CPU, RAM, Temp, Disk, IP)
        {
          symbol=0;
        }
    }
    return 0;
}
