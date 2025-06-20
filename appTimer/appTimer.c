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

//***************************** Include Files **********************************
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "appTimer.h"
#include "../common.h"

//***************************** Local Types ************************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************
static bool AppTimerCheckLeapYear(uint32 ulYearToCheck);

//***************************.AppTimerEpochToTime.******************************
// Purpose : To print the values of date and time of corresponding timezones. 
// Inputs  : Pointer ulpEpochTime that points to value of epoch.
// Outputs : None
// Return  : True in case of success and False in case of failure. 
// Notes   : None
//******************************************************************************
bool AppTimerEpochToTime(uint32 *ulpEpochtime)
{
    uint32 ulpEpochSeconds = *ulpEpochtime;

    if (ulpEpochtime == NULL)
    {
        return false;
    }
    uint32 ulSeconds = (*ulpEpochtime) % SECONDS_MINUTES;
    *ulpEpochtime = *ulpEpochtime / SECONDS_MINUTES;

    uint32 ulMinutes = (*ulpEpochtime) % SECONDS_MINUTES;
    *ulpEpochtime = *ulpEpochtime / SECONDS_MINUTES;

    uint32 ulHours = (*ulpEpochtime) % HOURS;
    *ulpEpochtime = *ulpEpochtime / HOURS;

    uint32 ulYear = YEAR_STARTING;
    ulpEpochSeconds /= SECONDS_IN_DAY;

    while (INCREMENT)
    {
        uint32 ulDayInYear = ZERO;

        if (AppTimerCheckLeapYear(ulYear))
        {
            ulDayInYear = LEAP_YEAR;
        }
        else
        {
            ulDayInYear = NORMAL_YEAR;
        }

        if (ulpEpochSeconds >= ulDayInYear)
        {
            ulpEpochSeconds -= ulDayInYear;
        }
        else
        {
            break;
        }
        ulYear ++;
    }

    uint32 ulMonth = ZERO;
    uint32 ulDaysInMonth[] = {EXTRA, FEBRUARY, EXTRA, NORMAL, EXTRA,
                              NORMAL, EXTRA, EXTRA, NORMAL, EXTRA,
                              NORMAL, EXTRA};

    if (ONE == AppTimerCheckLeapYear(ulYear))
    {
        ulDaysInMonth[INCREMENT] = LEAP;
    }
    
    while (ulpEpochSeconds >= ulDaysInMonth[ulMonth])
    {
        ulpEpochSeconds -= ulDaysInMonth[ulMonth];
        ulMonth ++;
    }
    uint32 ulDay = ulpEpochSeconds + INCREMENT;
    uint8 ucAmOrPm[AM_PM_LIMIT];

    if (HOUR_LIMIT <= ulHours)
    {
        ucAmOrPm[ZERO] = 'P';
        ucAmOrPm[ONE] = 'M';
        ulHours -= HOUR_LIMIT;
    }
    else
    {
        ucAmOrPm[ZERO] = 'A';
        ucAmOrPm[ONE] = 'M';
    }

    printf("TIME : %02ld:%02ld:%02ld %s\n", 
                   ulHours, ulMinutes, ulSeconds, ucAmOrPm);
    printf("DATE : %02ld/%02ld/%02ld \n", 
                   ulDay, ulMonth + INCREMENT, ulYear);
    
    return true;
}
//**************************.AppTimerCheckLeapYear.*****************************
// Purpose : To check if the given year is a leap year. 
// Inputs  : A value corresponding to an year.
// Outputs : None
// Return  : True if leap year and False if not. 
// Notes   : None
//******************************************************************************
static bool AppTimerCheckLeapYear(uint32 ulYearToCheck)
{
    bool blResult = false;

    if (ulYearToCheck % LEAP_YEAR_MULTIPLE == ZERO && 
        (ulYearToCheck % HUNDRED != ZERO || 
         ulYearToCheck % FOUR_HUNDRED == ZERO))
        {
            blResult = true;
        }

    return blResult;
}

//******************************.mainFunction.**********************************
//******************************************************************************
// EOF