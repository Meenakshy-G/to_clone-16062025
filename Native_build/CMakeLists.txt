cmake_minimum_required(VERSION 3.10)
project(Native C)

# The directories to look for header files are added.
include_directories(${CMAKE_SOURCE_DIR}/../appTimer ${CMAKE_SOURCE_DIR}/../ledStatus)

# The normal executable.
add_executable(TimerAppWithLED ${CMAKE_SOURCE_DIR}/../main.c
                    ${CMAKE_SOURCE_DIR}/../appTimer/appTimer.c
                    ${CMAKE_SOURCE_DIR}/../ledStatus/ledStatus.c)



