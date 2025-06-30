//**************************** TimerApp ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : ledStatus.c
// Summary : Function of TimerApp to print led status ON or OFF. 
// Note    : Header file included.
// Author  : Meenakshy G
// Date    : 27/JUNE/2025
//******************************************************************************

//***************************** Include Files **********************************
#include <stdio.h>
#include <stdbool.h>
#include "ledStatus.h"
#include "../common.h"

//***************************** Local Types ************************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************
static bool sblLedStatus = false;

//***************************** Local Functions ********************************

//******************************************************************************
//******************************.LedStatusDisplay.******************************
// Purpose : To print the status of LED.
// Inputs  : None
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool LedStatusDisplay(void)
{
    bool blResult = false;

    if (sblLedStatus)
    {
        printf("LED ON\n");
        sblLedStatus = false;
        blResult = true;
    }
    else
    {
        printf("LED OFF\n");
        sblLedStatus = true;
        blResult = true;
    }

    return blResult;
}

//******************************************************************************
// EOF