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
#include "appTimer.h"

//******************************* Local Types **********************************

//***************************** Local Constants ********************************

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************

//******************************.mainFunction.**********************************
// Purpose : To print the menu and call functions to convert and print times
// Inputs  : None
// Outputs : None
// Return  : Zero
// Notes   : None
//******************************************************************************
int main()
{
    while (true)
    {
        time(&currentTime);
        printf("UTC (0:00)\n");
        printf("--------------------\n");
        currentTimeUtc = currentTime - UTC_TIME_DIFFERENCE;
        AppTimerPrintTime(&currentTimeUtc);
        printf("Epoch: %d\n",currentTime);
        printf("\n");

        printf("IST (+05:30)\n");
        printf("--------------------\n");
        AppTimerPrintTime(&currentTime);
        printf("\n");

        printf("PST (-07:00)\n");
        printf("--------------------\n");
        currentTimePst = currentTime - PST_TIME_DIFFERENCE;
        AppTimerPrintTime(&currentTimePst);
        printf("\n");

        sleep(1);
    }

    return 0;
}
// EOF