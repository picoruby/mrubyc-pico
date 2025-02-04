#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <mrubyc.h>
#include "main_task.c"

#define HEAP_SIZE (1024*100)
static uint8_t memory_pool[HEAP_SIZE];

#define LED_PIN 25 /* Raspberry Pi Pico's on-board LED */

static void
c_led_write(mrbc_vm *vm, mrbc_value v[], int argc)
{
  int value = GET_INT_ARG(1);
  gpio_put(LED_PIN, value);
}

int
main(void)
{
  stdio_init_all();
  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);
  mrbc_init(memory_pool, HEAP_SIZE);
  mrbc_define_method(0, mrbc_class_object, "led_write", c_led_write);
  mrbc_create_task(main_task, 0);
  mrbc_run();
  return 0;
}
