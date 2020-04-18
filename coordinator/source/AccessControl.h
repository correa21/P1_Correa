/*
 * AccessControl.h
 *
 *  Created on: Apr 16, 2020
 *      Author: armando
 */

#ifndef ACCESSCONTROL_H_
#define ACCESSCONTROL_H_

#include "stdint.h"
#include "EmbeddedTypes.h"

#define NUMBER_OF_NODES		5U
#define ERROR				255U
#define ZERO				0U

typedef	struct
{
	uint64_t Device_Address;
	uint16_t Short_Address;
	uint8_t	RxOnWhenIdel 	: 1; //just one bit because we are saving a flag
	uint8_t DeviceType		: 1; //just one bit because we are saving a flag

}node_t;


uint16_t AccessControl_CheckList(uint64_t Address);

void AccessControl_SetNewNode(uint64_t DeviceAddress, uint16_t shortAddress, uint8_t RxOnWhenIdel, uint8_t DeviceType );

uint8_t returnShortAdress(uint8_t node);
#endif /* ACCESSCONTROL_H_ */
