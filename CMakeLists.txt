cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
project(master C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

#add_compile_options(-D MRBC_NO_TIMER)
add_compile_options(-DMRBC_USE_HAL_RP2040 -DMRBC_REQUIRE_32BIT_ALIGNMENT -DMAX_REGS_SIZE=256 -DMAX_SYMBOLS_COUNT=500)
add_executable(master
  main/main.c
  main/mrblib.c
  main/mrbc_pico_gpio.c
  main/mrbc_pico_adc.c
  main/mrbc_pico_pwm.c
  components/mrubyc/src/alloc.c
  components/mrubyc/src/c_array.c
  components/mrubyc/src/c_hash.c
  components/mrubyc/src/c_math.c
  components/mrubyc/src/c_numeric.c
  components/mrubyc/src/c_object.c
  components/mrubyc/src/c_range.c
  components/mrubyc/src/c_string.c
  components/mrubyc/src/class.c
  components/mrubyc/src/console.c
  components/mrubyc/src/error.c
  components/mrubyc/src/global.c
  components/mrubyc/src/keyvalue.c
  components/mrubyc/src/load.c
  components/mrubyc/src/mrblib.c
  components/mrubyc/src/rrt0.c
  components/mrubyc/src/symbol.c
  components/mrubyc/src/value.c
  components/mrubyc/src/vm.c
  components/mrubyc/src/hal_rp2040/hal.c
)

add_dependencies(master
  mrubyc
  mymaster
  mymrblib
)

add_custom_target(mrubyc
  COMMAND make distclean all
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/components/mrubyc/mrblib
)
add_custom_target(mymaster
  COMMAND mrbc -B master -o main/master.h src/master.rb
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
add_custom_target(mymrblib
  COMMAND mrbc -B myclass_bytecode --remove-lv -o ../main/mrblib.c *rb
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/mrblib
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(master pico_stdlib hardware_pwm hardware_adc)

# enable usb output, disable uart output
pico_enable_stdio_usb(master 1)
pico_enable_stdio_uart(master 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(master)
