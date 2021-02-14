#include "hal.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "hardware/structs/scb.h"
#include "hardware/sync.h"
#include "../mrubyc.h"

static volatile bool alarm_fired;

void alarm_irq(void) {
    hw_clear_bits(&timer_hw->intr, 1u << ALARM_NUM);
    mrbc_tick();
}
void hal_init(void){
    irq_set_exclusive_handler(ALARM_IRQ, alarm_irq);
    clocks_hw->sleep_en0 = 0x0;
    clocks_hw->sleep_en1 = CLOCKS_SLEEP_EN1_CLK_SYS_TIMER_BITS;
}


void hal_idle_cpu(void)
{
    hw_set_bits(&timer_hw->inte, 1u << ALARM_NUM);
    scb_hw->scr |= M0PLUS_SCR_SLEEPDEEP_BITS;
    timer_hw->alarm[ALARM_NUM] = timer_hw->timerawl + 1000;
    __wfi();
}

void hal_enable_irq(void){
    irq_set_enabled(ALARM_IRQ, true);
}

void hal_disable_irq(void){
    irq_set_enabled(ALARM_IRQ, false);
}