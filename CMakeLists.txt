cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)
project(mrubyc C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(PICO_EXAMPLES_PATH ${PROJECT_SOURCE_DIR})

# Initialize the SDK
pico_sdk_init()

#add_compile_options(-D MRBC_NO_TIMER)

add_executable(mrubyc
        main.c
        src/alloc.c
	src/c_array.c
	src/c_hash.c
	src/c_math.c
	src/c_numeric.c
	src/c_range.c
	src/c_string.c
	src/class.c
	src/console.c
	src/error.c
	src/global.c
	src/keyvalue.c
	src/load.c
	src/mrblib.c
	src/rrt0.c
	src/static.c
	src/symbol.c
	src/value.c
	src/vm.c
	src/hal/hal.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(mrubyc pico_stdlib)

# enable usb output, disable uart output
pico_enable_stdio_usb(mrubyc 1)
pico_enable_stdio_uart(mrubyc 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(mrubyc)
