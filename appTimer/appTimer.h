//**************************** TimerApp ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
// Summary : Contains all type defenitions and declarations. 
// Note    : None
//****************************************************************************** 
#ifndef _APPTIMER_H
#define _APPTIMER_H

//******************************* Include Files ******************************** 
#include <time.h>

//******************************* Global Types *********************************
typedef unsigned char uint8;
typedef unsigned long uint32;

//***************************** Global Constants ******************************* 
#define PST_TIME_DIFFERENCE (45000)
#define UTC_TIME_DIFFERENCE (19800)
#define MAX_LIMIT (80)

//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool AppTimerDateTime(uint32 *pulEpochTime);

//*********************** Inline Method Implementations ************************ 
//******************************************************************************

#endif // _APPTIMER_H 
// EOF 