#include "hal.h"

struct repeating_timer timer;

bool alarm_irq(struct repeating_timer *t) {
    mrbc_tick();
}

void hal_init(void){
    add_repeating_timer_ms(1, alarm_irq, NULL, &timer);
    clocks_hw->sleep_en0 = 0x0;
    clocks_hw->sleep_en1 = CLOCKS_SLEEP_EN1_CLK_SYS_TIMER_BITS;
}