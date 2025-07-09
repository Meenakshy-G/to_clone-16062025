//**************************** LedStatus ***************************************
// Copyright (c) 2025 Trenser Technology Solutions
// All Rights Reserved 
//******************************************************************************
// Summary : Contains all forward declarations.
// Note    : None
//******************************************************************************
#ifndef _LED_STATUS_H
#define _LED_STATUS_H

//******************************* Include Files ********************************
#include <gpiod.h>

//******************************* Global Types *********************************

//***************************** Global Constants *******************************

//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
#ifdef RUN_ON_PI
bool LedStatusDisplay(struct gpiod_line **pstLineValue);
#else
bool LedStatusPrint(void);
#endif

//*********************** Inline Method Implementations ************************
//******************************************************************************

#endif // _LED_STATUS_H
// EOF 