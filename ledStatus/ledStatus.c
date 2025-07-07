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
#include <unistd.h>
#include <gpiod.h>

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
    struct gpiod_chip *pstChip = NULL;
    struct gpiod_line *pstLine = NULL;
    static bool sblLed = false;

    pstChip = gpiod_chip_open_by_name(GPIO_CHIP_NAME);

    if (!pstChip) 
    {
        perror("Error in opening the chip");
    }
    pstLine = gpiod_chip_get_line(pstChip, LED_PIN);

    if (!pstLine) 
    {
        perror("Error in accessing the line");
        gpiod_chip_close(pstChip);
    }
    gpiod_line_request_output(pstLine, "blink-led", 0);

    if (sblLed)
    {
        gpiod_line_set_value(pstLine, 1);
        sblLed = false;
        printf("LED ON\n");
        usleep(ON_TIME);
    }
    else
    {
        gpiod_line_set_value(pstLine, 0);
        sblLed = true;
        printf("LED OFF\n");
        usleep(OFF_TIME);
    }
    gpiod_line_release(pstLine);
    gpiod_chip_close(pstChip);

    return true;
    #endif
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