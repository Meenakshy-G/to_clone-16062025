//**************************** TimerApp ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Display systems current time in real time 
//           in GMT, IST, PST, timezones and give status of LED
// Note    : Included header file from appTimer folder.
// Author  : Meenakshy G
// Date    : 18/JUNE/2025
//******************************************************************************
//******************************* Include Files ********************************
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "appTimer.h"
#include "common.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.mainFunction.**********************************
// Purpose : Display time and LED status and refresh the time.
// Inputs  : None
// Outputs : None
// Return  : Zero
// Notes   : None
//******************************************************************************
int main()
{
    time_t ulcurrentTime    = 0;
    uint32 ulcurrentTimeUtc = 0;
    uint32 ulCurrentTimeIst = 0;
    uint32 ulCurrentTimePst = 0;
    uint32 ulEpochUtc       = 0;
    bool blLedStatus = false;

    while (true)
    {
        ulcurrentTime = time(NULL);
        ulEpochUtc = ulcurrentTime;
        printf("UTC (0:00)\n");
        printf("--------------------\n");
        ulcurrentTimeUtc = ulcurrentTime;

        if (!AppTimerEpochToTime(ulcurrentTimeUtc))
        {
            printf("ERROR");
        }
        printf("Epoch: %lu\n", ulEpochUtc);
        printf("\n");
        printf("IST (+05:30)\n");
        printf("--------------------\n");
        ulCurrentTimeIst = ulcurrentTime + IST_TIME_DIFFERENCE;

        if (!AppTimerEpochToTime(ulCurrentTimeIst))
        {
            printf("ERROR");
        }
        printf("\n");
        printf("PST (-07:00)\n");
        printf("--------------------\n");
        ulCurrentTimePst = ulcurrentTime - PST_TIME_DIFFERENCE;

        if (!AppTimerEpochToTime(ulCurrentTimePst))
        {
            printf("ERROR");
        }
        printf("\n");

        if(!PrintLedStatus(&blLedStatus))
        {
            printf("ERROR");
        }

        sleep(SLEEP_TIME);
        system("clear");
    }

    return 0;
}
// EOF