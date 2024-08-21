/*
 * utils.c
 *
 *  Created on: Aug 21, 2024
 *      Author: denys
 */

#include "utils.h"
#include "usart.h"
#include "string.h"

// Functions
// UART Interrupt Logs 115200 8n1
void UartLogIT(char* Message)
{
	HAL_UART_Transmit_IT(&hlpuart1, (uint8_t*)Message, strlen(Message));
}
