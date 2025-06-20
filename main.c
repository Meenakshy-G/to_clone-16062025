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
#include <string.h>
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
    time_t currentTime;
    uint32 ulCurrentTimeIst;
    uint32 ulCurrentTimePst;

    while (true)
    {
        time(&currentTime);
        uint32 ulEpochStorage = currentTime;
        uint32 ulEpochStorage2 = currentTime;
        uint32 ulEpochStorage3 = currentTime;
        printf("UTC (0:00)\n");
        printf("--------------------\n");

        AppTimerEpochToTime(&currentTime);
        printf("Epoch: %ld\n", ulEpochStorage);
        printf("\n");

        printf("IST (+05:30)\n");
        printf("--------------------\n");
        ulCurrentTimeIst = ulEpochStorage2 + IST_TIME_DIFFERENCE; 
        AppTimerEpochToTime(&ulCurrentTimeIst);
        printf("\n");

        printf("PST (-07:00)\n");
        printf("--------------------\n");
        ulCurrentTimePst = ulEpochStorage3 - PST_TIME_DIFFERENCE;
        AppTimerEpochToTime(&ulCurrentTimePst);
        printf("\n");

        sleep(SLEEP_TIME);
    }

    return 0;
}
// EOF