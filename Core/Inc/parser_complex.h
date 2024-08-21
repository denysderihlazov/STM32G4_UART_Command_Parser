/*
 * parser_complex.h
 *
 *  Created on: Aug 21, 2024
 *      Author: denys
 */

#ifndef INC_PARSER_COMPLEX_H_
#define INC_PARSER_COMPLEX_H_

#include "main.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "usart.h"

#include "ring_buffer.h"
#include "utils.h"


char Message[32];
uint8_t Length;

// Functions
// Take each line and put to ReceivedData buffer
void Parser_handleLine(RingBuffer_t *RingBuffer, uint8_t *DataToParse);
// Main parse function
void Parser_Parse(uint8_t *ReceivedData);


#endif /* INC_PARSER_COMPLEX_H_ */
