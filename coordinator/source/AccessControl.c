/*
 * AccessControl.c
 *
 *  Created on: Apr 16, 2020
 *      Author: armando
 */


#include "AccessControl.h"

node_t nodes[NUMBER_OF_NODES] = {0};

static uint8_t g_freeNodes = NUMBER_OF_NODES;

static bool_t AccessControl_IsThereSpace(void);

uint16_t AccessControl_CheckList(uint64_t Address)
{
	uint8_t nodeIndex = 0;
	for (nodeIndex = 0 ; nodeIndex < NUMBER_OF_NODES ; nodeIndex++)
	{
		if (nodes[nodeIndex].Device_Address == Address)
			return nodes[nodeIndex].Short_Address;
	}
	return ERROR;
}

void AccessControl_SetNewNode(uint64_t DeviceAddress, uint16_t shortAddress, uint8_t RxOnWhenIdel, uint8_t DeviceType )
{
	static uint8_t nextFreeNode = 0;
	if(AccessControl_IsThereSpace())
	{
		nodes[nextFreeNode].Device_Address = DeviceAddress;
		nodes[nextFreeNode].Short_Address = shortAddress;
		nodes[nextFreeNode].RxOnWhenIdel = RxOnWhenIdel;
		nodes[nextFreeNode].DeviceType = DeviceType;
		nextFreeNode++;
		g_freeNodes --;
	}

}

static bool_t AccessControl_IsThereSpace(void){
	if (ZERO == g_freeNodes)
	{
		return FALSE;
	}
	return TRUE;
}
