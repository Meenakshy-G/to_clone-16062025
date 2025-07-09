//**************************** AppTimer ****************************************
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

//***************************** Local Types ************************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//***************************** Local Functions ********************************
static bool AppTimerCheckLeapYear(uint32 ulYearToCheck);

//***************************.AppTimerEpochToTime.******************************
// Purpose : To print the values of date and time of corresponding timezones. 
// Inputs  : Variable ulEpochTime that gives epoch value.
// Outputs : None
// Return  : True in case of success and False in case of failure. 
// Notes   : None
//******************************************************************************
bool AppTimerEpochToTime(uint32 ulEpochtime)
{
    uint32 ulEpochSeconds = 0;
    uint32 ulSeconds = 0;
    uint32 ulMinutes = 0;
    uint32 ulHours = 0;
    uint32 ulYear = 0;
    uint32 ulMonth = 0;
    uint32 ulDaysInMonth[] = {EXTRA, FEBRUARY, EXTRA, NORMAL, EXTRA,
                              NORMAL, EXTRA, EXTRA, NORMAL, EXTRA,
                              NORMAL, EXTRA};
    uint32 ulDay = 0;
    uint8 ucAmOrPm[AM_PM_LIMIT];

    ulEpochSeconds = ulEpochtime;
    // Find seconds.
    ulSeconds = (ulEpochtime) % SECONDS_MINUTES; 
    ulEpochtime = ulEpochtime / SECONDS_MINUTES;
    // Find minutes.
    ulMinutes = (ulEpochtime) % SECONDS_MINUTES; 
    ulEpochtime = ulEpochtime / SECONDS_MINUTES;
    // Find hours.
    ulHours = (ulEpochtime) % HOURS; 
    ulYear = YEAR_STARTING;
    // Remaining days in epoch.
    ulEpochSeconds /= SECONDS_IN_DAY; 

    // To find year.
    while (INCREMENT)  
    {
        uint32 ulDayInYear = 0;

        // Include case of leap year.
        if (AppTimerCheckLeapYear(ulYear))  
        {
            ulDayInYear = LEAP_YEAR;
        }
        else
        {
            ulDayInYear = NORMAL_YEAR;
        }

        if (ulEpochSeconds >= ulDayInYear)
        {
            ulEpochSeconds -= ulDayInYear;
        }
        else
        {
            break;
        }
        ulYear ++;
    }

    if (ONE == AppTimerCheckLeapYear(ulYear))
    {
        ulDaysInMonth[INDEX_ONE] = LEAP_DAYS;
    }

    while (ulEpochSeconds >= ulDaysInMonth[ulMonth])
    {
        ulEpochSeconds -= ulDaysInMonth[ulMonth];
        // Month count.
        ulMonth ++; 
    }
    // Find day.
    ulDay = ulEpochSeconds + INCREMENT; 

    if (HOUR_LIMIT <= ulHours)
    {
        ucAmOrPm[INDEX_ZERO] = 'P';
        ucAmOrPm[INDEX_ONE] = 'M';
        ucAmOrPm[INDEX_TWO] = '\0';

        ulHours -= HOUR_LIMIT;
    }
    else
    {
        ucAmOrPm[INDEX_ZERO] = 'A';
        ucAmOrPm[INDEX_ONE] = 'M';
        ucAmOrPm[INDEX_TWO] = '\0';
    }
    printf("TIME : %02lu:%02lu:%02lu %s\n", 
                   ulHours, ulMinutes, ulSeconds, ucAmOrPm);
    printf("DATE : %02lu/%02lu/%02lu \n", 
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

//******************************************************************************
// EOF