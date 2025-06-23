//**************************** TimerApp ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Display systems current time in real time 
//           in GMT, IST, PST, timezones.
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
// Purpose : Display menu and refresh time
// Inputs  : None
// Outputs : None
// Return  : Zero
// Notes   : None
//******************************************************************************
int main()
{
    while (true)
    {
        time_t ulcurrentTime = 0;
        uint32 ulcurrentTimeUtc = 0;
        uint32 ulCurrentTimeIst = 0;
        uint32 ulCurrentTimePst = 0;
        uint32 ulEpochUtc = 0;

        ulcurrentTime = time(NULL);
        ulEpochUtc = ulcurrentTime;
        printf("UTC (0:00)\n");
        printf("--------------------\n");
        ulcurrentTimeUtc = ulcurrentTime;
        AppTimerEpochToTime(ulcurrentTimeUtc);
        printf("Epoch: %lu\n", ulEpochUtc);
        printf("\n");
        printf("IST (+05:30)\n");
        printf("--------------------\n");
        ulCurrentTimeIst = ulcurrentTime + IST_TIME_DIFFERENCE;
        AppTimerEpochToTime(ulCurrentTimeIst);
        printf("\n");
        printf("PST (-07:00)\n");
        printf("--------------------\n");
        ulCurrentTimePst = ulcurrentTime - PST_TIME_DIFFERENCE;
        AppTimerEpochToTime(ulCurrentTimePst);
        printf("\n");

        sleep(SLEEP_TIME);
        system("cls");
    }

    return 0;
}
// EOF