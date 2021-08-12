cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
project(l-chika C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

#add_compile_options(-D MRBC_NO_TIMER)
add_compile_options(-DMRBC_USE_HAL_RP2040 -DMRBC_REQUIRE_32BIT_ALIGNMENT -DMAX_REGS_SIZE=256 -DMAX_SYMBOLS_COUNT=500)

add_executable(l-chika
  main.c
  mrubyc/src/alloc.c
  mrubyc/src/c_array.c
  mrubyc/src/c_hash.c
  mrubyc/src/c_math.c
  mrubyc/src/c_numeric.c
  mrubyc/src/c_object.c
  mrubyc/src/c_range.c
  mrubyc/src/c_string.c
  mrubyc/src/class.c
  mrubyc/src/console.c
  mrubyc/src/error.c
  mrubyc/src/global.c
  mrubyc/src/keyvalue.c
  mrubyc/src/load.c
  mrubyc/src/mrblib.c
  mrubyc/src/rrt0.c
  mrubyc/src/symbol.c
  mrubyc/src/value.c
  mrubyc/src/vm.c
  mrubyc/src/hal_rp2040/hal.c
)

add_dependencies(l-chika
  mrubyc
)

add_custom_target(mrubyc
  COMMAND make distclean all
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/mrubyc/mrblib
)

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(l-chika pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(l-chika 1)
pico_enable_stdio_uart(l-chika 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(l-chika)
