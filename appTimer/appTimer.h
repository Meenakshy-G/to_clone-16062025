//**************************** TimerApp ****************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//****************************************************************************** 
// Summary : Contains all forward declarations and macros.
// Note    : None
//****************************************************************************** 
#ifndef _APPTIMER_H
#define _APPTIMER_H

//******************************* Include Files ******************************** 
#include <time.h>
#include "../common.h"

//******************************* Global Types *********************************

//***************************** Global Constants ******************************* 
#define PST_TIME_DIFFERENCE (25200)
#define IST_TIME_DIFFERENCE (19800)
#define SECONDS_IN_DAY      (86400)
#define YEAR_STARTING       (1970)
#define SECONDS_MINUTES     (60)
#define HOURS               (24)
#define AM_PM_LIMIT         (2)
#define SLEEP_TIME          (1)
#define HOUR_LIMIT          (12)
#define MONTHS              (12)
#define INCREMENT           (1)
#define HUNDRED             (100)
#define FOUR_HUNDRED        (400)
#define LEAP_YEAR_MULTIPLE  (4)
#define NORMAL_YEAR         (365)
#define LEAP_YEAR           (366)
#define NORMAL              (30)
#define EXTRA               (31)
#define FEBRUARY            (28)
#define LEAP                (29)
#define ZERO                (0)
#define ONE                 (1)
//***************************** Global Variables ******************************* 

//**************************** Forward Declarations **************************** 
bool AppTimerEpochToTime(uint32 *ulpEpochtime);

//*********************** Inline Method Implementations ************************ 
//******************************************************************************

#endif // _APPTIMER_H 
// EOF 