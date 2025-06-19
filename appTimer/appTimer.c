//**************************** TimerApp ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : appTimer.c
// Summary : Functions of TimerApp to print time. 
// Note    : Header file included.
// Author  : Meenakshy G
// Date    : 18/JUNE/2025
//******************************************************************************

//******************************* Include Files ********************************
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "appTimer.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.AppTimerPrintTime.*****************************
// Purpose : To print the values of date and time of corresponding timezones. 
// Inputs  : Pointer pulEpochTime that points to value of epoch.
// Outputs : Prints the values of date and time accordingly
// Return  : True in case of success and False in case of failure. 
// Notes   : None
//******************************************************************************
bool AppTimerDateTime(uint32 *pulEpochTime)
{
    pCurrentTime = localtime(pulEpochTime);
    strftime(ucTimeString, sizeof(ucTimeString), 
             "%I:%M:%S %p,%d/%m/%Y ", pCurrentTime);

    pucToken = strtok(ucTimeString, ",");
    printf("TIME : %s\n", pucToken);
    pucToken = strtok(NULL, "\0");
    printf("DATE : %s \n", pucToken);

    return true;

}
//******************************.mainFunction.**********************************
//******************************************************************************
// EOF