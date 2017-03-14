/*******************************************************************************
* gpiodemo.c
* 
* A very simple demo of using the GPIO sysfs interface under Linux by using 
* gpiolib library from Technologic Systems.  This can be applied generically to
* any computer utilizing the GPIO sysfs interface.  This specific code block was
* written on a TS-7970, where gpio_pin #59 is connected to a breadboard LED. One
* could also use `gcc -D CTL gpiolib.c -o gpioctl` or `make` to bypass the need
* for this file and use ./gpioctl instead for scripting or use from the shell 
* (see gpioctl --help).
* 
* Functions provided by gpiolib:
*   - int gpio_export(int gpio);
*   - int gpio_direction(int gpio, int dir);
*   - void gpio_unexport(int gpio);
*   - int gpio_read(int gpio);
*   - int gpio_write(int gpio, int val);
*   - int gpio_setedge(int gpio, int rising, int falling);
*   - int gpio_select(int gpio);
*   - int gpio_getfd(int gpio);
* 
* Sources:
*   - https://github.com/embeddedarm/ts4900-utils/blob/master/src/gpiolib.h
*   - https://github.com/embeddedarm/ts4900-utils/blob/master/src/gpiolib.c
*   - http://wiki.embeddedarm.com/wiki/TS-7970#GPIO
*   - https://www.kernel.org/doc/Documentation/gpio/sysfs.txt
* *******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "gpiolib.h"

int main(int argc, char **argv)  {
    int gpio_pin = 59;

    gpio_export(gpio_pin);    
    gpio_direction(gpio_pin, 1);

    for(int i = 0; i < 5; i++) {
        printf(">> GPIO %d ON\n", gpio_pin);
        gpio_write(gpio_pin, 1);

        sleep(1);

        printf(">> GPIO %d OFF\n", gpio_pin);
        gpio_write(gpio_pin, 0);

        sleep(1);
    }
    
    return 0;
}
