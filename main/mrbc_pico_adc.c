#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "mrbc_pico_adc.h"

/* Choose 'C' for Celsius or 'F' for Fahrenheit. */
#define TEMPERATURE_UNITS 'C'

// Input 0...3 are GPIOs 26...29 respectively
static void
mrbc_pico_adc_init(mrb_vm* vm, mrb_value* v, int argc)
{
  int pin   = GET_INT_ARG(1);
  int input = GET_INT_ARG(2);
  adc_init();  
  adc_gpio_init(pin);
  adc_select_input(input);
  SET_TRUE_RETURN();
}

static void
mrbc_pico_adc_read(mrb_vm* vm, mrb_value* v, int argc)
{
  const float conversionFactor = 3.3f / (1 << 12);
  float adc = (float)adc_read() * conversionFactor;
  SET_FLOAT_RETURN( adc );
}

// Input 4 is the onboard temperature sensor.
static void
mrbc_pico_adc_onboard_init(mrb_vm* vm, mrb_value* v, int argc)
{
  adc_init();  
  adc_set_temp_sensor_enabled(true);
  adc_select_input(4);
  SET_TRUE_RETURN();
}

static void
mrbc_pico_adc_onboard_read(mrb_vm* vm, mrb_value* v, int argc)
{
  const float conversionFactor = 3.3f / (1 << 12);
  float adc  = (float)adc_read() * conversionFactor;
  float temp = 27.0f - (adc - 0.706f) / 0.001721f; 
  printf("Onboard temperature = %.02f C\n", temp);
  SET_FLOAT_RETURN( temp );  
}

void
mrbc_pico_adc_gem_init(struct VM* vm)
{
  //メソッド定義
  mrbc_define_method(0, mrbc_class_object, "adc_init", mrbc_pico_adc_init);
  mrbc_define_method(0, mrbc_class_object, "adc_read", mrbc_pico_adc_read);
  mrbc_define_method(0, mrbc_class_object, "adc_onboard_init", mrbc_pico_adc_onboard_init);
  mrbc_define_method(0, mrbc_class_object, "adc_onboard_read", mrbc_pico_adc_onboard_read);
}
