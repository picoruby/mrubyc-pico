#include "mrbc_pico_pwm.h"
#include "hardware/pwm.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

const uint16_t divCounter = 10000; // max 2^16 = 65536
const uint16_t freqBase   = 125000000 / divCounter; // 125 MHz -> 12.5 kHz
const uint16_t fact = divCounter / 1024; // duty を 0--1023 に 

static void
mrbc_pico_pwm_init(mrb_vm* vm, mrb_value* v, int argc)
{
  int   pin = GET_INT_ARG(1);

  gpio_set_function(pin, GPIO_FUNC_PWM);
  uint slice_num = pwm_gpio_to_slice_num( pin );
  uint chan_num  = pwm_gpio_to_channel( pin );  
  
  pwm_set_wrap(slice_num, divCounter-1); 
  //  pwm_set_clkdiv(slice_num, div); 
  pwm_set_chan_level(slice_num, chan_num, 0);
  pwm_set_enabled(slice_num, true);
}

static void
mrbc_pico_pwm_set_freq(mrb_vm* vm, mrb_value* v, int argc)
{
  int   pin  = GET_INT_ARG(1);
  float freq = GET_INT_ARG(2);

  uint slice_num = pwm_gpio_to_slice_num( pin );
    
  float div  = freqBase / freq;
  pwm_set_clkdiv(slice_num, div); 
}

static void
mrbc_pico_pwm_set_duty(mrb_vm* vm, mrb_value* v, int argc)
{
  int pin = GET_INT_ARG(1);
  int lev = GET_INT_ARG(2);

  uint slice_num = pwm_gpio_to_slice_num( pin );
  uint chan_num  = pwm_gpio_to_channel( pin );  
  
  printf("duty %d %d -> %d\n", pin, lev, lev * fact);
  pwm_set_gpio_level(pin, (int)lev * fact );
  pwm_set_chan_level(slice_num, chan_num, (int)lev * fact );
}

void
mrbc_pico_pwm_gem_init(struct VM* vm)
{
  //メソッド定義
  mrbc_define_method(0, mrbc_class_object, "pwm_init", mrbc_pico_pwm_init);
  mrbc_define_method(0, mrbc_class_object, "pwm_set_freq", mrbc_pico_pwm_set_freq);
  mrbc_define_method(0, mrbc_class_object, "pwm_set_duty", mrbc_pico_pwm_set_duty);
}

/*

#include "pico/stdlib.h"
#include <stdio.h>
#include "pico/time.h"
#include "hardware/pwm.h"

int main() {

    // Tell the LED pin that the PWM is in charge of its value.
    gpio_set_function(25, GPIO_FUNC_PWM);
    gpio_set_function(27, GPIO_FUNC_PWM);

    // Figure out which slice we just connected to the LED pin
    //uint slice_num = pwm_gpio_to_slice_num(25);
    //uint slice_num2 = pwm_gpio_to_slice_num(27);
    uint slice_num = 4;
    uint slice_num2 = 5;

    pwm_set_wrap(slice_num,  1023);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 512);
    pwm_set_enabled(slice_num, true);

    //https://qiita.com/jamjam/items/368e40f55302528c3050
    uint16_t divCounter = 10000; // max 2^16 = 65536
    uint16_t freqBase   = 125000000 / divCounter; //
    
    freq = 261.626;
    div  = freqBase / freq;
    pwm_set_wrap(slice_num2, divCounter-1); 
    pwm_set_clkdiv(slice_num2, div); 
    pwm_set_chan_level(slice_num2, PWM_CHAN_B, (int)divCounter*0.5);
    pwm_set_enabled(slice_num2, true);
    
    //////////////////////////////////////
    pwm_set_gpio_level(25, 1024);

    sleep_ms(500);

    pwm_set_gpio_level(25, 0);

    freq = 293.665;
    div  = freqBase / freq;
    pwm_set_clkdiv(slice_num2, div);

    sleep_ms(500);

    freq = 329.628;
    div  = freqBase / freq;
    pwm_set_clkdiv(slice_num2, div);

    sleep_ms(500);

    pwm_set_gpio_level(25, 256);
    pwm_set_gpio_level(27, 0);

    sleep_ms(2000);
    pwm_set_gpio_level(25, 512);
    sleep_ms(2000);
    pwm_set_gpio_level(25, 0);
}

*/
