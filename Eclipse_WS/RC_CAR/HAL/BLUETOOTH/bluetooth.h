/*
 ============================================================================
 Name        : bluetooth.h
 Module Name : BLUETOOTH
 Author      : Ahmed Ali
 Date        : 12 July 2024
 Description : Header file for the bluetooth driver
 ============================================================================
 */

#include "../../LIB/std_types.h"

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for setup the bluetooth module with suitable baud rate.
 */
void bluetooth_init();

/*
 * Description :
 * The Function responsible for receive data from bluetooth module.
 */
uint8 bluetooth_recieveByte();

/*
 * Description :
 * The Function responsible for send data through bluetooth module.
 */
void bluetooth_sendByte(uint8 data);

#endif /* BLUETOOTH_H_ */
