/*
 ============================================================================
 Name        : main.c
 Module Name : APP
 Author      : Ahmed Ali
 Date        : 12 July 2024
 Description : The main function of project
 ============================================================================
 */

#include "HAL/BLUETOOTH/bluetooth.h"
#include "HAL/MOTOR/motor.h"
#include "HAL/MOTOR_DRIVER/motorDriver.h"
#include "HAL/ULTRASONIC_SENSOR/ultrasonic_sensor.h"
#include "MCAL/GPIO/gpio_private.h"

#include <util/delay.h>

uint8 HC5_input = 0;
uint8 Ultra_Distance = 0;

void RC_Desicion();
void ULTRA_Desicion();
void Desicion_Direction();

int main()
{
	/* Configuration and initialization functions */
	DcMotor_Init();
	bluetooth_init();
	Ultrasonic_init();

	SREG_REG.Bits.I_Bit = 1;

	while (1)
	{
		HC5_input = bluetooth_recieveByte();
		while (HC5_input == 'W') //RC mode
		{
			HC5_input = bluetooth_recieveByte();

			RC_Desicion();

			HC5_input = 'W';
		}
		while (HC5_input == 'U') //ultrasonic mode
		{
			Set_Speed(40);
			Ultra_Distance = Ultrasonic_readDistance();

			Desicion_Direction();

			ULTRA_Desicion();

			HC5_input = 'U';
		}
	}
}

void RC_Desicion()
{
	switch (HC5_input)
	{
	case 'F':
		Move_Forward();
		break;
	case 'B':
		Move_Backward();
		break;
	case 'L':
		Move_Left();
		break;
	case 'R':
		Move_Right();
		break;
	case 'G':
		Move_Left();
		_delay_ms(50);
		Move_Forward();
		_delay_ms(50);
		break;
	case 'I':
		Move_Right();
		_delay_ms(50);
		Move_Forward();
		_delay_ms(50);
		break;
	case 'H':
		Move_Left();
		_delay_ms(50);
		Move_Backward();
		_delay_ms(50);
		break;
	case 'J':
		Move_Right();
		_delay_ms(50);
		Move_Backward();
		_delay_ms(50);
		break;
	case 'S':
		stop();
		break;
	case '1':
		Set_Speed(10);
		break;
	case '2':
		Set_Speed(20);
		break;
	case '3':
		Set_Speed(30);
		break;
	case '4':
		Set_Speed(40);
		break;
	case '5':
		Set_Speed(50);
		break;
	case '6':
		Set_Speed(60);
		break;
	case '7':
		Set_Speed(70);
		break;
	case '8':
		Set_Speed(80);
		break;
	case '9':
		Set_Speed(90);
		break;
	case 'q':
		Set_Speed(100);
		break;
	default:
		stop();
		break;
	}
}

void Desicion_Direction()
{
	if (Ultra_Distance > 10)
	{
		HC5_input = 'F';
	}
	else
	{
		uint8 Right_val = 0, Left_val = 0;

		HC5_input = 'R';
		ULTRA_Desicion();

		Right_val = Ultrasonic_readDistance();

		HC5_input = 'L';
		ULTRA_Desicion();
		ULTRA_Desicion();

		Left_val = Ultrasonic_readDistance();

		HC5_input = 'R';
		ULTRA_Desicion();

		if (Right_val >= Left_val && Right_val > 10)
		{
			HC5_input = 'R';
		}
		else if (Left_val >= Right_val && Left_val > 10)
		{
			HC5_input = 'L';
		}
		else
		{
			HC5_input = 'R';
			ULTRA_Desicion();
			ULTRA_Desicion();

			HC5_input = 'F';
		}

	}
}

void ULTRA_Desicion()
{

	switch (HC5_input)
	{
	case 'F':
		Move_Forward();
		break;
	case 'B':
		Move_Backward();
		break;
	case 'L':
		Move_Left();
		_delay_ms(500);
		break;
	case 'R':
		Move_Right();
		_delay_ms(500);
		break;
	default:
		stop();
		break;
	}

}
