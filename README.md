## **Timer App with LED Blink**

Project in c that displays the date and time in realtime for UTC IST and PST timezones and blinks and LED using Raspberry Pi. 
Date and time updated at every one second.
Prints the status of LED (ON or OFF) with time delays(840ms ON and 520ms OFF).
Blinks an LED connected to GPIO pin 23 of Raspberry Pi.
Cross-compilation of the project to run in Raspberry pi.

**Features**

* Source code organised in multiple directories.
* Separate **release** and **debug** builds.
* Cross-compilation support for Raspberry Pi (aarch64).

**Prerequisites**

* **CMake** ≥ 3.10
* **Make**
* **GCC** (for Linux build)
* **aarch64-linux-gnu-gcc** (for Raspberry Pi cross-compilation)

## Building with Make

### 1. All (Release)

$ make all

Output: release/APPTIMER

### 2. Debug (Debug)

$ make debug

Output: debug/APPTIMER_DEBUG

### 3. Raspberry Pi (Release, cross-compile)

$ make rpi

Output: release/rpi

### 6. Clean Build Artifacts

$ make clean

Removes all files from release/ and debug/ folders.

## Building with CMake

### 1. Build All
 
$ cmake -S. -B Build
$ cmake --build Build

### 2. Release Build
 
$ cmake -S. -B Build
$ cd Build && make RELEASE

### 3. Debug Build
 
$ cmake -S. -B Build
$ cd Build && make DEBUG

### 3. Build and Cross-compile
 
$ cmake -S. -B Build
$ cd Build && make RELEASE_RPI


