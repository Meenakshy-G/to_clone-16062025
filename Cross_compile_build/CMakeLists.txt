cmake_minimum_required(VERSION 3.10)
project(Cross C)

# The directories to look for header files are added.
include_directories(${CMAKE_SOURCE_DIR}/../appTimer 
                    ${CMAKE_SOURCE_DIR}/../ledStatus)

# For cross-compilation to Raspberry pi.
add_executable(TimerAppWithLED_RPI ${CMAKE_SOURCE_DIR}/../main.c
                    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
                    ${CMAKE_SOURCE_DIR}/../ledStatus/ledStatus.c)

target_compile_definitions(TimerAppWithLED_RPI PRIVATE -DRUN_ON_PI)

target_include_directories(TimerAppWithLED_RPI PRIVATE 
                           ${CMAKE_SOURCE_DIR}/../rpi64-sysroot/usr/include)
target_link_directories(TimerAppWithLED_RPI PRIVATE 
                        ${CMAKE_SOURCE_DIR}/../rpi64-sysroot/usr/lib)
target_link_libraries(TimerAppWithLED_RPI PRIVATE 
                      ${CMAKE_SOURCE_DIR}/../rpi64-sysroot/usr/lib/libgpiod.so)