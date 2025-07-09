//**************************** gpioWrapper *************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : gpioWrapper.c
// Summary : Function wrappers for gpiod.h library functions.
// Note    : Header file included.
// Author  : Meenakshy G
// Date    : 08/JULY/2025
//******************************************************************************

//***************************** Include Files **********************************
#include <stdio.h>
#include <stdbool.h>
#include <gpiod.h>
#include "gpioWrapper.h"
#include "../common.h"

//***************************** Local Types ************************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************
bool GpioRequestOutput(struct gpiod_line *pstLineValue);
bool GpioSetLedValue(struct gpiod_line *pstLineValue, bool blLedValue);
bool GpioRelease(struct gpiod_chip *pstChipValue, 
                 struct gpiod_line *pstLineValue);

//******************************************************************************
//******************************.GpioSetValue.**********************************
// Purpose : To initialise the chip and gpio pin and set value.
// Inputs  : Pointers to the structs gpiod_chip and gpiod_line variable.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool GpioSetValue(bool blValue)
{
    struct gpiod_chip *pstChip = NULL;
    struct gpiod_line *pstLine = NULL;

    pstChip = gpiod_chip_open_by_name(GPIO_CHIP_NAME);

    if (!pstChip) 
    {
        perror("Error: Open Chip Failed");
    }
    pstLine = gpiod_chip_get_line(pstChip, LED_PIN);

    if (!pstLine) 
    {
        perror("Error: Get Line Failed");
        gpiod_chip_close(pstChip);
    }
    GpioRequestOutput(pstLine);
    GpioSetLedValue(pstLine, blValue);
    GpioRelease(pstChip, pstLine);

    return true;
}

//******************************.GpioRequestOutput.*****************************
// Purpose : To set the pin as output.
// Inputs  : Pointer to the pin value.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool GpioRequestOutput(struct gpiod_line *pstLineValue)
{
    if (ZERO > gpiod_line_request_output(pstLineValue, "blink-led", 0)) 
    {
        perror("Request output failed\n");
        gpiod_line_release(pstLineValue);
    }

    return true;
}

//******************************.GpioSetLedValue.*******************************
// Purpose : To set the pin value high or low.
// Inputs  : Pointer to the line, value to be given to pin.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool GpioSetLedValue(struct gpiod_line *pstLineValue, bool blLedValue)
{
    if (ZERO > gpiod_line_set_value(pstLineValue, blLedValue))
    {
        perror("Failed to set GPIO line Value");
    }

    return true;
}

//******************************.GpioRelease.***********************************
// Purpose : To release the assigned chip and pin.
// Inputs  : Pointer to the variables of struct gpiod_chip and gpiod_line.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool GpioRelease(struct gpiod_chip *pstChipValue, 
                 struct gpiod_line *pstLineValue)
{
    gpiod_line_release(pstLineValue);
    gpiod_chip_close(pstChipValue);

    return true;
}
//******************************************************************************
// EOF