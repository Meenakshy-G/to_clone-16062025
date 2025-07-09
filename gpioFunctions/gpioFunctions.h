//**************************** gpioFunctions ***********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
// Summary : Contains all forward declarations and macros.
// Note    : None
//****************************************************************************** 
#ifndef _GPIO_FUNCTIONS_H
#define _GPIO_FUNCTIONS_H

//******************************* Include Files ******************************** 
#include <time.h>
#include "../common.h"
#include <gpiod.h>

//******************************* Global Types *********************************

//***************************** Global Constants ******************************* 
#define GPIO_CHIP_NAME  "gpiochip0"
#define LED_PIN         (23)
#define ON_TIME         (840000)
#define OFF_TIME        (532000)
#define ZERO            (0)

//***************************** Global Variables *******************************

//**************************** Forward Declarations **************************** 
bool GpioFunctionsInitialisation(struct gpiod_chip **pstChipValue, 
                        struct gpiod_line **pstLineValue);
bool GpioFunctionsRelease(struct gpiod_chip **pstChipValue, 
                 struct gpiod_line **pstLineValue);
bool GpioFunctionsRequestOutput(struct gpiod_line **pstLineValue);
bool GpioFunctionsOutput(struct gpiod_line **pstLineValue, bool blLedValue);

//*********************** Inline Method Implementations ************************ 
//******************************************************************************

#endif // _GPIO_FUNCTIONS_H 
// EOF 