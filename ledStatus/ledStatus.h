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

//******************************* Global Types *********************************

//***************************** Global Constants *******************************
#define GPIO_CHIP_NAME "gpiochip0"
#define LED_PIN (23)
#define ON_TIME (840000)
#define OFF_TIME (532000)
//***************************** Global Variables *******************************

//**************************** Forward Declarations ****************************
bool LedStatusDisplay(void);

//*********************** Inline Method Implementations ************************
//******************************************************************************

#endif // _LED_STATUS_H
// EOF 