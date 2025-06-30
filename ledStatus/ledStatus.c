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

//***************************** Local Functions ********************************

//******************************************************************************
//******************************.LedStatusDisplay.******************************
// Purpose : To print the status of LED.
// Inputs  : A pointer flag blpLedStatus to check current led status.
// Outputs : None
// Return  : True for successfull completion, else false. 
// Notes   : None
//******************************************************************************
bool LedStatusDisplay(bool *blpLedStatus)
{
    bool blResult = true;

    if (NULL == blpLedStatus)
    {
        printf("NULL POINTER");
        blResult = false;
    }
    else if (*blpLedStatus)
    {
        printf("LED ON\n");
        *blpLedStatus = false;
    }
    else
    {
        printf("LED OFF\n");
        *blpLedStatus = true;
    }

    return blResult;
}

//******************************************************************************
// EOF