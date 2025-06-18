//**************************** TimerApp ************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
//
// Summary : Contains all type defenitions and declarations. 
// Note    : None
// 
//****************************************************************************** 
#ifndef _APPTIMER_H
#define _APPTIMER_H

//******************************* Include Files ******************************** 
#include <time.h>

//******************************* Global Types *********************************
time_t currentTime;
time_t currentTimeUtc;
time_t currentTimePst;
typedef unsigned char uint8;
typedef unsigned long uint32;

//***************************** Global Constants ******************************* 
#define PST_TIME_DIFFERENCE  (45000)
#define UTC_TIME_DIFFERENCE  (19800)
#define HOUR_LIMIT           (12)
#define INDEX_LIMIT          (10)
#define MAX_LIMIT            (3)

//***************************** Global Variables ******************************* 
struct tm *pCurrentTime;
uint8 ucTimeString[MAX_LIMIT];
uint8 *pToken;

//**************************** Forward Declarations **************************** 
bool AppTimerPrintTime(uint32 *epochTime);

//*********************** Inline Method Implementations ************************ 

#endif // _APPTIMER_H 
// EOF 