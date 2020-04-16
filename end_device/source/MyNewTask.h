/*
 * MyNewTask.h
 *
 *  Created on: Apr 13, 2020
 *      Author: armando
 */

#ifndef MYNEWTASK_H_
#define MYNEWTASK_H_


/* Fwk */
#include "TimersManager.h"
#include "FunctionLib.h"
#include "LED.h"
/* KSDK */
#include "fsl_common.h"
#include "EmbeddedTypes.h"
#include "fsl_os_abstraction.h"

/* Define the available Task's Events */
#define gStart 		(1 << 0)
#define gTrigger 	(1 << 1)
#define gSW3Event 	(1 << 2)
#define gSW4Event	(1 << 3)

#define gMyTaskPriority_c 3
#define gMyTaskStackSize_c 400

#define RED 	LED2
#define BLUE	LED4
#define GREEN	LED3

void MyTaskTimer_Start(void);
void MyTaskTimer_SW3(void);
void MyTaskTimer_SW4(void);
void MyTask_Init(void);

#endif /* MYNEWTASK_H_ */
