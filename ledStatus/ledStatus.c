//**************************** LedStatus ***************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : ledStatus.c
// Summary : Function of TimerApp to blink LED and display the status of LED.
// Note    : Header file included.
// Author  : Meenakshy G
// Date    : 27/JUNE/2025
//******************************************************************************

//***************************** Include Files **********************************
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <gpiod.h>
#include "ledStatus.h"
#include "gpioFunctions.h"
#include "../common.h"

//***************************** Local Types ************************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//******************************************************************************
//******************************.LedStatusDisplay.******************************
// Purpose : To blink the LED if cross compilation chosen.
// Inputs  : pointer to the pin (line) value.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
#ifdef RUN_ON_PI
bool LedStatusDisplay(struct gpiod_line **pstLineValue)
{
    static bool sblLed = false;

    if (sblLed)
    {
        GpioFunctionsOutput(pstLineValue, true);
        sblLed = false;
        printf("LED ON\n");
        usleep(ON_TIME);
    }
    else
    {
        GpioFunctionsOutput(pstLineValue, false);
        sblLed = true;
        printf("LED OFF\n");
        usleep(OFF_TIME);
    }

    return true;
}
#else
//******************************.LedStatusPrint.********************************
// Purpose : To print status of led ON or OFF.
// Inputs  : None
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool LedStatusPrint(void)
{
    static bool sblLedStatus = false;

    if (sblLedStatus)
    {
        printf("LED ON\n");
        sblLedStatus = false;
        usleep(ON_TIME);
    }
    else
    {
        printf("LED OFF\n");
        sblLedStatus = true;
        usleep(OFF_TIME);
    }

    return true;
}
#endif
//******************************************************************************
// EOF