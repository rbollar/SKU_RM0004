#include "st7735.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

int i2cd;
int show_hostname = 1; // 1 = show hostname, 0 = show IP address

// Function to get the IP address
char* get_ip_address_new() {
    static char ip_address[20];
    int fd;
    struct ifreq ifr;

    // Get IP address associated with the network interface (e.g., "eth0" or "wlan0")
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    ifr.ifr_addr.sa_family = AF_INET;
    strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);  // Replace "eth0" with your active interface if needed

    ioctl(fd, SIOCGIFADDR, &ifr);
    close(fd);

    // Convert the IP address to a string
    snprintf(ip_address, sizeof(ip_address), "%s", inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr));

    return ip_address;
}

// Function to initialize the display
uint8_t lcd_begin(void)
{
    uint8_t count = 0;
    uint8_t buffer[20] = {0};
    uint8_t i2c[20] = "/dev/i2c-1";
    // I2C Init
    i2cd = open(i2c, O_RDWR); // "/dev/i2c-1"
    if (i2cd < 0)
    {
        fprintf(stderr, "Device I2C-1 failed to initialize\n");
        return 1;
    }
    if (ioctl(i2cd, I2C_SLAVE_FORCE, I2C_ADDRESS) < 0)
    {
        return 1;
    }
    return 0;
}

// Function to display hostname
void lcd_display_hostname(void) {
    char hostname[128] = {0};
    gethostname(hostname, sizeof(hostname));

    lcd_fill_screen(ST7735_BLACK);
    lcd_write_string(0, 0, "Host:", Font_8x16, ST7735_WHITE, ST7735_BLACK);
    lcd_write_string(40, 0, hostname, Font_8x16, ST7735_WHITE, ST7735_BLACK);
}

// Function to display IP address
void lcd_display_ip(void) {
    char iPSource[20] = {0};
    strcpy(iPSource, get_ip_address_new());  // Get the IP address

    lcd_fill_screen(ST7735_BLACK);
    lcd_write_string(0, 0, "IP:", Font_8x16, ST7735_WHITE, ST7735_BLACK);
    lcd_write_string(24, 0, iPSource, Font_8x16, ST7735_WHITE, ST7735_BLACK);
}

int main() {
    // Initialize the display
    if (lcd_begin() != 0) {
        fprintf(stderr, "Failed to initialize LCD\n");
        return 1;
    }

    while (1) {
        // Toggle between hostname and IP address every 15 seconds
        if (show_hostname) {
            lcd_display_hostname(); // Function to display hostname
        } else {
            lcd_display_ip(); // Function to display IP address
        }

        show_hostname = !show_hostname; // Toggle the flag
        sleep(15); // Wait 15 seconds before switching
    }

    return 0;
}
