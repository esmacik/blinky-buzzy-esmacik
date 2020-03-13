#ifndef switches_included
#define switches_included

#define SW1 BIT0		/* switch1 is p1.3 */
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3
#define SWITCHES (SW1|SW2|SW3|SW4)		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down;
extern char switch_state_changed;

extern char SW1_state_changed; /* effectively boolean */
extern char SW2_state_changed;

extern char SW1_down;
extern char SW2_down;
extern char SW3_down;
extern char SW4_down;

extern char SW1_toggle;
extern char SW2_toggle;
extern char SW3_toggle;
extern char SW4_toggle;

#endif // included
