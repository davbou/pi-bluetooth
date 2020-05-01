cmake_minimum_required(VERSION 3.0)
project(BLUETOOTH_CLIENT)

set(SOURCE_CLIENT Bluetooth_Client.c)

SET(GCC_WARNING_FLAGS "-Wall -Wextra -Wpedantic -Wduplicated-cond -Wlogical-op -Wnull-dereference -Wjump-misses-init -Wshadow")
SET(GCC_ADDRESS_SANITIZER_FLAGS "-fno-omit-frame-pointer") # -fsanitize=address")
add_definitions("${GCC_WARNING_FLAGS} ${GCC_ADDRESS_SANITIZER_FLAGS}")

add_executable(tp5bluetooth ${SOURCE_CLIENT})
target_link_libraries(tp5bluetooth bluetooth)
