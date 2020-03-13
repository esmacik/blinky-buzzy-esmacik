#include <msp430.h>
#include "led.h"
#include "switches.h"

char red_dim_status;
char green_dim_status;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  //SW1_state_changed = 1;
  //SW2_state_changed = 1;
  led_update();
}

void led_update(){
    char ledFlags = 0; /* by default, no LEDs on */
    
    /*
     * For red_led_state and green_led_state:
     * 0 - on
     * 1 - off
     * 2 - dim
    */
        
    switch (red_led_state){
        case 0:
            ledFlags |= LED_RED;
            break;
        case 1:
            ledFlags |= 0;
            break;
        case 2:
            ledFlags |= (red_dim_status == 0) ? LED_RED: 0;
            break;
    }
    switch (green_led_state){
        case 0:
            ledFlags |= LED_GREEN;
            break;
        case 1:
            ledFlags |= 0;
            break;
        case 2:
            ledFlags |= (green_dim_status == 0) ? LED_GREEN: 0;
            break;
    }
    
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
    
    
  switch_state_changed = 0;
}

