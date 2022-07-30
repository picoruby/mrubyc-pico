#include "mrbc_pico_gpio.h"
#include "hardware/gpio.h"

//      GPIO_IN          0b000 (defined in the SDK)
#define GPIO_IN_PULLUP   0b010
#define GPIO_IN_PULLDOWN 0b110
//      GPIO_OUT         0b001 (defined in the SDK)
#define GPIO_OUT_LO      0b011
#define GPIO_OUT_HI      0b101

/*
void c_led_init(mrb_vm *vm, mrb_value *v, int argc) {
    int pin = GET_INT_ARG(1);
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
}

void c_led_write(mrb_vm *vm, mrb_value *v, int argc) {
    int pin = GET_INT_ARG(1);
    int val = GET_INT_ARG(2);
    gpio_put(pin, val);
}
*/

static void
mrbc_pico_gpio_mode_input(mrb_vm* vm, mrb_value* v, int argc)
{
  int pin = GET_INT_ARG(1);
  gpio_init(pin);
  gpio_set_dir(pin, GPIO_IN);
}

static void
mrbc_pico_gpio_mode_output(mrb_vm* vm, mrb_value* v, int argc)
{
  int pin = GET_INT_ARG(1);
  gpio_init(pin);
  gpio_set_dir(pin, GPIO_OUT);
}

static void
mrbc_pico_gpio_set_level(mrb_vm* vm, mrb_value* v, int argc)
{
  int pin   = GET_INT_ARG(1);
  int level = GET_INT_ARG(2);
  gpio_put(pin, level);
}

static void
mrbc_pico_gpio_get_level(mrb_vm* vm, mrb_value* v, int argc)
{
  int pin = GET_INT_ARG(1);
  SET_INT_RETURN(gpio_get(pin));
}

void
mrbc_pico_gpio_gem_init(struct VM* vm)
{
  //メソッド定義
  mrbc_define_method(0, mrbc_class_object, "gpio_mode_input", mrbc_pico_gpio_mode_input);
  mrbc_define_method(0, mrbc_class_object, "gpio_mode_output", mrbc_pico_gpio_mode_output);
  mrbc_define_method(0, mrbc_class_object, "gpio_set_level", mrbc_pico_gpio_set_level);
  mrbc_define_method(0, mrbc_class_object, "gpio_get_level", mrbc_pico_gpio_get_level);
}
