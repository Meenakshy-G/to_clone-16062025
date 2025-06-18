//**************************** TimerApp *************************************
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
#include <time.h>
#include "appTimer.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.AppTimerPrintTime.*****************************
// Purpose : To print the values of date and time of corresponding timezones. 
// Inputs  : Pointer pEpochTime that points to value of epoch.
// Outputs : Prints the values of date and time accordingly
// Return  : True in case of success and False in case of failure. 
// Notes   : None
//******************************************************************************
bool AppTimerPrintTime(uint32 *pEpochTime)
{
    struct tm *pTimeParts;
    pTimeParts = localtime(pEpochTime);
    uint8 ucAmOrPm[MAX_LIMIT];

    if (HOUR_LIMIT <= pTimeParts->tm_hour)
    {
        ucAmOrPm[0] = 'P';
        ucAmOrPm[1] = 'M';
        pTimeParts->tm_hour -= HOUR_LIMIT;
    }
    else
    {
        ucAmOrPm[0] = 'A';
        ucAmOrPm[1] = 'M';
    }

    if (INDEX_LIMIT > pTimeParts->tm_hour)
    {
        printf("TIME : 0%d:%d:%d %s\n",
                pTimeParts->tm_hour, pTimeParts->tm_min, 
                pTimeParts->tm_sec, ucAmOrPm);
    }
    else
    {
        printf("TIME : %d:%d:%d %s\n",
                pTimeParts->tm_hour, pTimeParts->tm_min, 
                pTimeParts->tm_sec, ucAmOrPm);
    }
    printf("DATE : %d/%d/%d \n", pTimeParts->tm_mday, 
            pTimeParts->tm_mon+1, pTimeParts->tm_year+1900);

    return true;
}
//******************************.mainFunction.**********************************

// EOF