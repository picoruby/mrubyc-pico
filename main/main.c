#include "pico/stdlib.h"
#include "../components/mrubyc/src/mrubyc.h"
#include "master.h"
#include "mrbc_pico_gpio.h"
#include "mrbc_pico_adc.h"
#include "mrbc_pico_pwm.h"

#define MEMORY_SIZE (1024*100)

static uint8_t memory_pool[MEMORY_SIZE];

int main() {
    stdio_init_all();
    mrbc_init(memory_pool, MEMORY_SIZE);

    // C 側のクラス・メソッド定義
    mrbc_pico_gpio_gem_init(0);
    mrbc_pico_adc_gem_init(0);
    mrbc_pico_pwm_gem_init(0);
    
    // Ruby 側のクラス・メソッド定義
    extern const uint8_t myclass_bytecode[];
    mrbc_run_mrblib(myclass_bytecode);
    
    // Ruby 側のメイン関数
    mrbc_create_task( master, 0 );
    
    // 実行
    mrbc_run();
    return 1;
}

