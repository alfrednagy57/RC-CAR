/*
 ============================================================================
 Name        : motorDriver.c
 Module Name : MOTOR DRIVER
 Author      : Ahmed Ali
 Date        : 12 July 2024
 Description : Source file for the motor driver
 ============================================================================
 */

#include "motorDriver.h"
#include "../MOTOR/motor.h"
#include "../../MCAL/TIMER0/timer0.h"

/*
 * Description :
 * The Function responsible for moving the car forward.
 */
void Move_Backward()
{
	DcMotor1_Rotate(ANTI_CLOCK_WISE);
	DcMotor2_Rotate(ANTI_CLOCK_WISE);
}

/*
 * Description :
 * The Function responsible for moving the car backward.
 */
void Move_Forward()
{
	DcMotor1_Rotate(CLOCK_Wise);
	DcMotor2_Rotate(CLOCK_Wise);
}

/*
 * Description :
 * The Function responsible for moving the car right.
 */
void Move_Left()
{
	DcMotor1_Rotate(CLOCK_Wise);
	DcMotor2_Rotate(ANTI_CLOCK_WISE);
}

/*
 * Description :
 * The Function responsible for moving the car left.
 */
void Move_Right()
{
	DcMotor1_Rotate(ANTI_CLOCK_WISE);
	DcMotor2_Rotate(CLOCK_Wise);
}

/*
 * Description :
 * The Function responsible for stop the car.
 */
void stop()
{
	DcMotor1_Rotate(STOP);
	DcMotor2_Rotate(STOP);
}

/*
 * Description :
 * The Function responsible for setting the car speed.
 */
void Set_Speed(uint8 speed)
{
	Timer0_PWM_Start(speed);
}
