cmake_minimum_required(VERSION 3.10)
project(TIMER_APP C)
include(ExternalProject)

ExternalProject_Add(RELEASE
SOURCE_DIR ${CMAKE_SOURCE_DIR}/Native_build
BINARY_DIR ${CMAKE_BINARY_DIR}/Release_folder
CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release
INSTALL_COMMAND ""
)
ExternalProject_Add(DEBUG
SOURCE_DIR ${CMAKE_SOURCE_DIR}/Native_build
BINARY_DIR ${CMAKE_BINARY_DIR}/Debug_folder
CMAKE_ARGS -DCMAKE_BUILD_TYPE=Debug
INSTALL_COMMAND ""
)
ExternalProject_Add(RELEASE_RPI
SOURCE_DIR ${CMAKE_SOURCE_DIR}/Cross_compile_build
BINARY_DIR ${CMAKE_BINARY_DIR}/Release_rpi_folder
CMAKE_ARGS -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=aarch64-linux-gnu-gcc 
INSTALL_COMMAND ""
)
