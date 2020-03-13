#include <msp430.h>
#include "led.h"
#include "buzzer.h"
#include "music.h"

#define ONE_BEAT 250

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
    /*
    static char note_count = 0;
    if (++note_count < HALF_SEC) buzzer_set_period(3804);
    else buzzer_set_period(3592);
    */
    
    //LEDs are on 1/5th of the time whil in the dim state
    if (red_led_state == 2) red_dim_status = (red_dim_status+1) % 5;
    if (green_led_state == 2) green_dim_status = (green_dim_status+1) % 5;
    led_update();
}
