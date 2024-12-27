/*
 ============================================================================
 Name        : motor.h
 Module Name : MOTOR
 Author      : Ahmed Ali
 Date        : 10 Oct 2023
 Description : Header file for the DC motor driver
 ============================================================================
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../LIB/std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum
{
	STOP, ANTI_CLOCK_WISE, CLOCK_Wise
} DcMotor_State;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MOTOR1_PORTID				PORTA_ID
#define MOTOR1_IN1_PINID			PIN0_ID
#define MOTOR1_IN2_PINID			PIN1_ID

#define MOTOR2_PORTID				PORTA_ID
#define MOTOR2_IN1_PINID			PIN2_ID
#define MOTOR2_IN2_PINID			PIN3_ID

#define MOTOR_MAX_SPEED			100

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * 1. The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * 2. Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * 1. The function responsible for rotate the DC Motor 1 CW/
 *    or A-CW or stop the motor based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor1_Rotate(DcMotor_State a_state);

/*
 * Description :
 * 1. The function responsible for rotate the DC Motor 2 CW/
 *    or A-CW or stop the motor based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor2_Rotate(DcMotor_State a_state);

#endif /* MOTOR_H_ */
