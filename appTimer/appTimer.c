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
#include "../common.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.AppTimerDateTime.******************************
// Purpose : To print the values of date and time of corresponding timezones. 
// Inputs  : Pointer ulpEpochTime that points to value of epoch.
// Outputs : None
// Return  : True in case of success and False in case of failure. 
// Notes   : None
//******************************************************************************
bool AppTimerEpochToTime(uint32 *ulpEpochtime)
{
    if (*ulpEpochtime == NULL)
    {
        return false;
    }

    uint32 unYear = *ulpEpochtime / SECONDS_IN_YEAR;
    uint32 unActualYear = unYear + YEAR_STARTING;

    uint32 unMonthCorrection = unYear * MONTHS;
    uint32 unMonth = *ulpEpochtime / SECONDS_IN_MONTH;
    uint32 unMonth_minus_one = unMonth - unMonthCorrection;
    uint32 unActualMonth = unMonth_minus_one + INCREMENT; 

    uint32 unSecondsinDays = (SECONDS_IN_YEAR * unYear) + 
                             (SECONDS_IN_MONTH * unMonth_minus_one);
    uint32 unRemainingEpochDays = (*ulpEpochtime) - unSecondsinDays;
    uint32 unDay = unRemainingEpochDays / SECONDS_IN_DAY ;
    uint32 unActualDay = unDay + INCREMENT_TWO;

    uint32 unSeconds = (*ulpEpochtime) % SECONDS_MINUTES;
    *ulpEpochtime = *ulpEpochtime / SECONDS_MINUTES;

    uint32 unMinutes = (*ulpEpochtime) % SECONDS_MINUTES;
    *ulpEpochtime = *ulpEpochtime / SECONDS_MINUTES;

    uint32 unHours = (*ulpEpochtime) % HOURS;
    *ulpEpochtime = *ulpEpochtime / HOURS;

    uint8 ucAmOrPm[AM_PM_LIMIT];
    if (HOUR_LIMIT <= unHours)
    {
        ucAmOrPm[0] = 'P';
        ucAmOrPm[1] = 'M';
        unHours -= HOUR_LIMIT;
    }
    else
    {
        ucAmOrPm[0] = 'A';
        ucAmOrPm[1] = 'M';
    }

    printf("TIME : %02d:%02d:%02d %s \n", 
                   unHours, unMinutes, unSeconds, ucAmOrPm);
    printf("DATE : %02d/%02d/%02d \n", 
                   unActualDay, unActualMonth, unActualYear);
    
    return true;
}
//******************************.mainFunction.**********************************
//******************************************************************************
// EOF