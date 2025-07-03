cmake_minimum_required(VERSION 3.10)
project(TIMERAPP C)

include_directories(${CMAKE_SOURCE_DIR}/appTimer ${CMAKE_SOURCE_DIR}/ledStatus)
file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/*.c" "${CMAKE_SOURCE_DIR}/appTimer/*.c" 
               "${CMAKE_SOURCE_DIR}/ledStatus/*.c")

add_executable(APPTIMER ${SRC_FILES})
target_compile_options(APPTIMER PRIVATE -Wall -Werror)
set_target_properties(APPTIMER PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/release)

add_executable(DEBUG_APPTIMER ${SRC_FILES})
target_compile_options(DEBUG_APPTIMER PRIVATE -Wall -Werror -g -O0)
set_target_properties(DEBUG_APPTIMER PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/debug)



