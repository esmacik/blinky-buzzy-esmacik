#include <msp430.h>
#include "music.h"

#define BEAT 4000000

int up[20] = {F3, A3, F3, E3, F3, A3, E3, D3, D3, F3, D3, C3,
              D3, A3, G3, D3, A3, G3, F3, D3};

void play_up(){
    for (int i = 0; i < 20; i++){
        buzzer_set_period(up[i]);
        switch (i){
            case 13:
            case 16:
            case 17:
            case 18:
                __delay_cycles(BEAT*2);
                break;
            case 7:
                __delay_cycles(BEAT*2.5);
                break;
            case 14:
                __delay_cycles(BEAT*3);
                break;
            case 11:
            case 19:
                __delay_cycles(BEAT*4);
                break;
            case 3:
                __delay_cycles(BEAT*8);
                break;
            default:
                __delay_cycles(BEAT);
                break;
        }
    }
    buzzer_set_period(0);
}

int lalaland[28] = {C2sh, F2sh, G2sh, A2, G2sh, F2sh, D2,
                    D2, F2sh, G2sh, A2, G2sh, F2sh, C2sh,
                    C2sh, F2sh, G2sh, A2, G2sh, F2sh, D2,
                    B2, A2, G2sh, A2, G2sh, F2sh, C2sh};

void play_lalaland(){
    for (int i = 0; i < 28; i++){
        buzzer_set_period(lalaland[i]);
        switch (i){
            case 6:
            case 13:
            case 20: 
                __delay_cycles(BEAT*6);
                break;
            case 27:
                __delay_cycles(BEAT*4);
                break;
            default:
                __delay_cycles(BEAT);
                break;
        }
    }
    buzzer_set_period(0);
}
