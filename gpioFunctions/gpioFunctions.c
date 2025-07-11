//**************************** gpioFunctions ***********************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : gpioFunctions.c
// Summary : Functions calling gpiod.h library functions.
// Note    : Header file included.
// Author  : Meenakshy G
// Date    : 08/JULY/2025
//******************************************************************************

//***************************** Include Files **********************************
#include <stdio.h>
#include <stdbool.h>
#include <gpiod.h>
#include "gpioFunctions.h"
#include "../common.h"

//***************************** Local Types ************************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//******************************************************************************
//***********************.GpioFunctionsInitialisation.**************************
// Purpose : To initialise the chip and gpio pin and set value.
// Inputs  : Pointers to the structs gpiod_chip and gpiod_line variable.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool GpioFunctionsInitialisation(struct gpiod_chip **pstChipValue, 
                                 struct gpiod_line **pstLineValue)
{
    *pstChipValue = gpiod_chip_open_by_name(GPIO_CHIP_NAME);

    if (!*pstChipValue) 
    {
        perror("Error: Open Chip Failed");
    }
    *pstLineValue = gpiod_chip_get_line(*pstChipValue, LED_PIN);

    if (!*pstLineValue) 
    {
        perror("Error: Get Line Failed");
        gpiod_chip_close(*pstChipValue);
    }

    return true;
}


//*************************.GpioFunctionsRequestOutput.*************************
// Purpose : To set the pin as output.
// Inputs  : Pointer to the pin (line) value.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool GpioFunctionsRequestOutput(struct gpiod_line **pstLineValue)
{
    if (ZERO > gpiod_line_request_output(*pstLineValue, "blink-led", 0)) 
    {
        perror("Request output failed\n");
        gpiod_line_release(*pstLineValue);
    }

    return true;
}

//*************************.GpioFunctionsOutput.********************************
// Purpose : To set the pin value high or low.
// Inputs  : Pointer to the line, value to be given to pin.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool GpioFunctionsOutput(struct gpiod_line **pstLineValue, bool blLedValue)
{
    if (ZERO > gpiod_line_set_value(*pstLineValue, blLedValue))
    {
        perror("Failed to set GPIO line Value");
    }

    return true;
}

//*************************.GpioFunctionsRelease.*******************************
// Purpose : To release the assigned chip and pin.
// Inputs  : Pointer to the variables of struct gpiod_chip and gpiod_line.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool GpioFunctionsRelease(struct gpiod_chip **pstChipValue, 
                          struct gpiod_line **pstLineValue)
{
    gpiod_line_release(*pstLineValue);
    gpiod_chip_close(*pstChipValue);

    return true;
}
//******************************************************************************
// EOF