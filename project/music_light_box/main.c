#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void main(void) 
{ 
  configureClocks();
  switch_init();
  led_init();
  buzzer_init();
  
  enableWDTInterrupts(); // interupts periodically through time
  
  or_sr(0x18);  // CPU off, GIE on
} 

/* I worked with Cynthia Sustaita and Alex Vasquez in order to understand code in the demos.
   Once we had some understanding of the demos we then brainstormed how to determine when a
   button was pressed down only. We also brainstormed how to utilize the wdInterruptHandler
   in order to make the leds dim.*/
