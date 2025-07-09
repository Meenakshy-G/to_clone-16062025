//**************************** TimerApp ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved
//******************************************************************************
// File    : main.c
// Summary : Display systems current time in real time and 
//           display status of LED and blink LED.
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
#include <gpiod.h>
#include "appTimer.h"
#include "ledStatus.h"
#include "gpioFunctions.h"
#include "common.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.mainFunction.**********************************
// Purpose : Display time, shows LED status or blinks LED and refresh the time.
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
    uint16 unCheckReturn    = 0; 

    #ifdef RUN_ON_PI
    struct gpiod_line *pstLine = NULL;
    struct gpiod_chip *pstChip = NULL;

    GpioFunctionsInitialisation(&pstChip, &pstLine);
    GpioFunctionsRequestOutput(&pstLine);
    #endif

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
        #ifdef RUN_ON_PI
        LedStatusDisplay(&pstLine);
        #else
        LedStatusPrint();
        #endif
        unCheckReturn = system("clear");
        (void)unCheckReturn;
    }

    #ifdef RUN_ON_PI
    GpioFunctionsRelease(&pstChip, &pstLine);
    #endif

    return 0;
}
// EOF