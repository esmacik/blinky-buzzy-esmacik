    .arch msp430g2553
    .p2align 1,0
    .text

    .global advance_red_led_state
advance_red_led_state:
    add #1, &red_led_state
    cmp #3, &red_led_state
    JNZ FI
    mov #0, &red_led_state
    FI:
    ret

    .global advance_green_led_state
advance_green_led_state:
    add #1, &green_led_state
    cmp #3, &green_led_state
    JNZ FI1
    mov #0, &green_led_state
    FI1:
    ret
    

