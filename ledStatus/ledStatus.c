//**************************** LedStatus ***************************************
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

//***************************** Local Types ************************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

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
    static bool sblLedStatus = false;

    if (sblLedStatus)
    {
        printf("LED ON\n");
        sblLedStatus = false;
    }
    else
    {
        printf("LED OFF\n");
        sblLedStatus = true;
    }

    return true;
}

//******************************************************************************
// EOF