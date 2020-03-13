#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "music.h"

#define ONE_BEAT 250

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
    //LEDs are on 1/5th of the time while in the dim state
    if (red_led_state == 2 || green_led_state == 2) dim_status = (dim_status+1) % 6;
    led_update();
}
