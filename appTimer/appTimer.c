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
    if (ulpEpochtime == NULL)
    {
        return false;
    }

    uint32 ulYear = *ulpEpochtime / SECONDS_IN_YEAR;
    uint32 ulActualYear = ulYear + YEAR_STARTING;

    uint32 ulMonthCorrection = ulYear * MONTHS;
    uint32 ulMonth = *ulpEpochtime / SECONDS_IN_MONTH;
    uint32 ulMonth_minus_one = ulMonth - ulMonthCorrection;
    uint32 ulActualMonth = ulMonth_minus_one + INCREMENT; 

    uint32 ulSecondsinDays = (SECONDS_IN_YEAR * ulYear) + 
                             (SECONDS_IN_MONTH * ulMonth_minus_one);
    uint32 ulRemainingEpochDays = (*ulpEpochtime) - ulSecondsinDays;
    uint32 ulDay = ulRemainingEpochDays / SECONDS_IN_DAY ;
    uint32 ulActualDay = ulDay + INCREMENT_TWO;

    uint32 ulSeconds = (*ulpEpochtime) % SECONDS_MINUTES;
    *ulpEpochtime = *ulpEpochtime / SECONDS_MINUTES;

    uint32 ulMinutes = (*ulpEpochtime) % SECONDS_MINUTES;
    *ulpEpochtime = *ulpEpochtime / SECONDS_MINUTES;

    uint32 ulHours = (*ulpEpochtime) % HOURS;
    *ulpEpochtime = *ulpEpochtime / HOURS;

    uint8 ucAmOrPm[AM_PM_LIMIT];
    if (HOUR_LIMIT <= ulHours)
    {
        ucAmOrPm[0] = 'P';
        ucAmOrPm[1] = 'M';
        ulHours -= HOUR_LIMIT;
    }
    else
    {
        ucAmOrPm[0] = 'A';
        ucAmOrPm[1] = 'M';
    }

    printf("TIME : %02ld:%02ld:%02ld %s \n", 
                   ulHours, ulMinutes, ulSeconds, ucAmOrPm);
    printf("DATE : %02ld/%02ld/%02ld \n", 
                   ulActualDay, ulActualMonth, ulActualYear);
    
    return true;
}
//******************************.mainFunction.**********************************
//******************************************************************************
// EOF