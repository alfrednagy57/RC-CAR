/*
 ============================================================================
 Name        : motor.c
 Module Name : MOTOR
 Author      : Ahmed Ali
 Date        : 10 Oct 2023
 Description : Source file for the DC motor driver
 ============================================================================
 */

#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/TIMER0/timer0.h"
#include "motor.h"
#include "../../LIB/common_macros.h"

/*
 * Description :
 * 1. The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * 2. Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	/* Make The Configuration Of Timer0 To Be in FAST PWM Mode */
	TIMER0_ConfigType TIMER0_CONFIG =
	{ 0, 0, FAST_PWM_MODE, PRESCALER_64, CTC_CLEAR__PWM_NON_INVERTING };

	/* Init Timer0 in FAST PWM Mode */
	Timer0_init(&TIMER0_CONFIG);

	/* Set OC0 pin direction as output */
	GPIO_setupPinDirection(OC0_PORTID, OC0_PINID, PIN_OUTPUT);

	/* Set IN1 and IN2 motor 1 pins direction as output */
	GPIO_setupPinDirection(MOTOR1_PORTID, MOTOR1_IN1_PINID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR1_PORTID, MOTOR1_IN2_PINID, PIN_OUTPUT);

	/* Set IN1 and IN2 motor 2 pins direction as output */
	GPIO_setupPinDirection(MOTOR2_PORTID, MOTOR2_IN1_PINID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR2_PORTID, MOTOR2_IN2_PINID, PIN_OUTPUT);

	/* Stop motor 1 as initial state */
	GPIO_writePin(MOTOR1_PORTID, MOTOR1_IN1_PINID, LOGIC_LOW);
	GPIO_writePin(MOTOR1_PORTID, MOTOR1_IN2_PINID, LOGIC_LOW);

	/* Stop motor 2 as initial state */
	GPIO_writePin(MOTOR2_PORTID, MOTOR2_IN1_PINID, LOGIC_LOW);
	GPIO_writePin(MOTOR2_PORTID, MOTOR2_IN2_PINID, LOGIC_LOW);

	/* Inital the two motors works at full speed */
	Timer0_PWM_Start(100);
}

/*
 * Description :
 * 1. The function responsible for rotate the DC Motor 1 CW/
 *    or A-CW or stop the motor based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor1_Rotate(DcMotor_State a_state)
{
	switch (a_state)
	{
	case CLOCK_Wise:
		/* Clock wise mode => (IN1 = 1 and INT2 = 0) */
		GPIO_writePin(MOTOR1_PORTID, MOTOR1_IN1_PINID, LOGIC_HIGH);
		GPIO_writePin(MOTOR1_PORTID, MOTOR1_IN2_PINID, LOGIC_LOW);
		break;
	case ANTI_CLOCK_WISE:
		/* Anti clock wise mode => (IN1 = 0 and INT2 = 1) */
		GPIO_writePin(MOTOR1_PORTID, MOTOR1_IN1_PINID, LOGIC_LOW);
		GPIO_writePin(MOTOR1_PORTID, MOTOR1_IN2_PINID, LOGIC_HIGH);
		break;
	default:
		/* Any case else, the motor be in stop mode */
		GPIO_writePin(MOTOR1_PORTID, MOTOR1_IN1_PINID, LOGIC_LOW);
		GPIO_writePin(MOTOR1_PORTID, MOTOR1_IN2_PINID, LOGIC_LOW);
	}
}

/*
 * Description :
 * 1. The function responsible for rotate the DC Motor 2 CW/
 *    or A-CW or stop the motor based on the state input state value.
 * 2. Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor2_Rotate(DcMotor_State a_state)
{
	switch (a_state)
	{
	case CLOCK_Wise:
		/* Clock wise mode => (IN1 = 1 and INT2 = 0) */
		GPIO_writePin(MOTOR2_PORTID, MOTOR2_IN1_PINID, LOGIC_HIGH);
		GPIO_writePin(MOTOR2_PORTID, MOTOR2_IN2_PINID, LOGIC_LOW);
		break;
	case ANTI_CLOCK_WISE:
		/* Anti clock wise mode => (IN1 = 0 and INT2 = 1) */
		GPIO_writePin(MOTOR2_PORTID, MOTOR2_IN1_PINID, LOGIC_LOW);
		GPIO_writePin(MOTOR2_PORTID, MOTOR2_IN2_PINID, LOGIC_HIGH);
		break;
	default:
		/* Any case else, the motor be in stop mode */
		GPIO_writePin(MOTOR2_PORTID, MOTOR2_IN1_PINID, LOGIC_LOW);
		GPIO_writePin(MOTOR2_PORTID, MOTOR2_IN2_PINID, LOGIC_LOW);
	}
}
