/*
 * parser_complex.c
 *
 *  Created on: Aug 21, 2024
 *      Author: denys
 */


#include "parser_complex.h"


// Functions
// Take each line and put to ReceivedData buffer
void Parser_handleLine(RingBuffer_t *RingBuffer, uint8_t *DataToParse)
{
	uint8_t TmpRead; // Buffer to read 1 byte from RingBuffer
	uint8_t i = 0; // Reset counter for next UART RX

	do
	{
		// Read 1 byte from Ring Buffer
		RingBuffer_Read(RingBuffer, &TmpRead);

		// Write to parse buffer
		if(TmpRead == ENDLINE)
		{
		  // Swap '\n' with 0
			DataToParse[i] = 0;
		}
		else
		{
		  // Put value read from RingBuffer to parse buffer
			DataToParse[i] = TmpRead;
		}
		i++;
	} while(TmpRead != ENDLINE); // Read from RingBuffer until '\n' sign
}


// LED LD2 control
// 	   1
//     0
static void Parser_ParseOnBoardLED()
{
	char *ParsePointer = strtok(NULL, ",");

	// Check if substring exist
	if(strlen(ParsePointer) > 0)
	{
		// Check if substring is 0 or 1
		if(ParsePointer[0] < '0' || ParsePointer[0] > '1')
		{
			UartLogIT("Wrong value for LD2. Please type 0 or 1!\r\n");
			return;
		}

		if(ParsePointer[0] == '1')
		{
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
			UartLogIT("LD2 On\r\n");
		}
		else if(ParsePointer[0] == '0')
		{
			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
			UartLogIT("LD2 Off\r\n");
		}
	}
}

// LED SMD5050
//
//
//static void Parser_SMD5050LED()
//{
//	char *ParsePointer = strtok(NULL, ",");
//
//	// Check if substring exist
//	if(strlen(ParsePointer) > 0)
//	{
//		// Check if substring is 0 or 1
//		if(ParsePointer[0] < '0' || ParsePointer[0] > '1')
//		{
//			UartLogIT("Wrong value for LD2. Please type 0 or 1!\r\n");
//			return;
//		}
//
//		if(ParsePointer[0] == '1')
//		{
//			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
//			UartLogIT("LD2 On\r\n");
//		}
//		else if(ParsePointer[0] == '0')
//		{
//			HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
//			UartLogIT("LD2 Off\r\n");
//		}
//	}
//}


// Main parse function
void Parser_Parse(uint8_t *DataToParse)
{
	// Pointer to sub-string
	char *ParsePointer = strtok((char*)DataToParse, "=");

	// LED control
	if(strcmp("LD2", ParsePointer) == 0)
	{
		Parser_ParseOnBoardLED();
	}

}
