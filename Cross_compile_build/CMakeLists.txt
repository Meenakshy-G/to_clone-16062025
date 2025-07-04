cmake_minimum_required(VERSION 3.10)
project(Cross C)

# The directories to look for header files are added.
include_directories(${CMAKE_SOURCE_DIR}/../appTimer ${CMAKE_SOURCE_DIR}/../ledStatus)
# file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/*.c" "${CMAKE_SOURCE_DIR}/appTimer/*.c" 
#                "${CMAKE_SOURCE_DIR}/ledStatus/*.c")

# For cross-compilation to Raspberry pi.
add_executable(TimerAppWithLED_RPI ${CMAKE_SOURCE_DIR}/../main.c
                    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
                    ${CMAKE_SOURCE_DIR}/../ledStatus/ledStatus.c)

