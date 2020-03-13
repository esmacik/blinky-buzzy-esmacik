#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "music.h"

char switch_state_changed;

char SW1_state_changed; /* effectively boolean */
char SW2_state_changed;

char SW1_down;
char SW2_down;
char SW3_down;
char SW4_down;

char SW1_toggle;
char SW2_toggle;
char SW3_toggle;
char SW4_toggle;

unsigned char green_led_state;
unsigned char red_led_state;

char speaker_on;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
    char p2val = switch_update_interrupt_sense();
    SW1_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up, etc */
    SW2_down = (p2val & SW2) ? 0 : 1;
    SW3_down = (p2val & SW3) ? 0 : 1;
    SW4_down = (p2val & SW4) ? 0 : 1;

    /* toggles the value of SWn_toggle when each button is pressed down, ie action only when button is pressed down */
    if (SW1_down) SW1_toggle = ~SW1_toggle; 
    if (SW2_down) SW2_toggle = ~SW2_toggle;
    if (SW3_down) SW3_toggle = ~SW3_toggle;
    if (SW4_down) SW4_toggle = ~SW4_toggle;

    if (SW1_down){
        SW1_state_changed = 1;
        red_led_state = (red_led_state+1) % 3;
    }

    if (SW2_down){
        SW2_state_changed = 1;
        green_led_state = (green_led_state+1) % 3;
    }

    if (SW3_down) play_up(); 

    if (SW4_down) play_lalaland();
    
    switch_state_changed = 1;
}
