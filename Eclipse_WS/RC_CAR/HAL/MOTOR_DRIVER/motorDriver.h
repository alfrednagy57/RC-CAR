/*
 ============================================================================
 Name        : motorDriver.h
 Module Name : MOTOR DRIVER
 Author      : Ahmed Ali
 Date        : 12 July 2024
 Description : Header file for the motor driver
 ============================================================================
 */

#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_

#include "../../LIB/std_types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for moving the car forward.
 */
void Move_Forward();

/*
 * Description :
 * The Function responsible for moving the car backward.
 */
void Move_Backward();

/*
 * Description :
 * The Function responsible for moving the car right.
 */
void Move_Right();

/*
 * Description :
 * The Function responsible for moving the car left.
 */
void Move_Left();

/*
 * Description :
 * The Function responsible for stop the car.
 */
void stop();

/*
 * Description :
 * The Function responsible for setting the car speed.
 */
void Set_Speed(uint8 speed);

#endif /* MOTORDRIVER_H_ */
