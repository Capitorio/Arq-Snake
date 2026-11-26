#include <stdio.h>
#include <stdlib.h>

//DEFINES DE LEDS
#define LED_MATRIX_0_BASE (0xf0000000)
#define LED_MATRIX_0_SIZE (0xdac)
#define LED_MATRIX_0_WIDTH (0x23)
#define LED_MATRIX_0_HEIGHT (0x19)


//DEFINES DEL DPAD
#define D_PAD_0_BASE (0xf0000dac)
#define D_PAD_0_SIZE (0x10)
#define D_PAD_0_UP_OFFSET (0x0)
#define D_PAD_0_UP (0xf0000dac)
#define D_PAD_0_DOWN_OFFSET (0x4)
#define D_PAD_0_DOWN (0xf0000db0)
#define D_PAD_0_LEFT_OFFSET (0x8)
#define D_PAD_0_LEFT (0xf0000db4)
#define D_PAD_0_RIGHT_OFFSET (0xc)
#define D_PAD_0_RIGHT (0xf0000db8)
//FUNCIONES DPAD
unsigned int leer_dpad(){
    volatile unsigned int* ptr_dpad=(volatile unsigned int*)D_PAD_0_BASE;
    return *ptr_dpad;
}


//FUNCIONES LEDS
void prender_led(int x, int y, unsigned int color) {
    volatile unsigned int* xy_led = (volatile unsigned int*)LED_MATRIX_0_BASE;
    xy_led+=y+(x*LED_MATRIX_0_WIDTH);
    *xy_led=color;

}


int main() {
    volatile unsigned  int* led_matrix = (volatile unsigned int*)LED_MATRIX_0_BASE;
    *led_matrix=0x00FF0000;


    prender_led(5,2,0x000000FF);
    prender_led(3,8,0x00FFFF00);
    prender_led(9,6,0x0000FF00);

    while (1)
    {
    }
    
    return 0;
}