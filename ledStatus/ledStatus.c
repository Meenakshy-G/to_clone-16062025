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
#include "ledStatus.h"
#include "gpioWrapper.h"
#include <unistd.h>
#include <gpiod.h>
#include "../common.h"

//***************************** Local Types ************************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************

//******************************************************************************
//******************************.LedStatusDisplay.******************************
// Purpose : To print the status of LED and blink the LED.
// Inputs  : None
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool LedStatusDisplay(void)
{
    #ifdef RUN_ON_PI
    static bool sblLed = false;

    if (sblLed)
    {
        GpioSetValue(true);
        sblLed = false;
        printf("LED ON\n");
        usleep(ON_TIME);
    }
    else
    {
        GpioSetValue(false);
        sblLed = true;
        printf("LED OFF\n");
        usleep(OFF_TIME);
    }

    return true;
    #else
    PrintStatus();
    #endif
}

//******************************.PrintStatus.***********************************
// Purpose : To print status of led ON or OFF.
// Inputs  : None
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool PrintStatus(void)
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
//******************************************************************************
// EOF