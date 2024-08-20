/*
 * ring_buffer.h
 *
 *  Created on: Aug 20, 2024
 *      Author: denys
 */

#ifndef INC_RING_BUFFER_H_
#define INC_RING_BUFFER_H_

#include "main.h"

#define RING_BUFFER_SIZE 16

#define ENDLINE '\n'

// Success status
typedef enum
{
  RB_OK       = 1,
  RB_ERROR    = 0
} RB_Status;

// RB object
typedef struct
{
	uint16_t Head;
	uint16_t Tail;
	uint8_t Buffer[RING_BUFFER_SIZE];
} RingBuffer_t;

// Functions

RB_Status RingBuffer_Write(RingBuffer_t *RingBuffer, uint8_t Value);

RB_Status RingBuffer_Read(RingBuffer_t *RingBuffer, uint8_t *Value);

void RingBuffer_Flush(RingBuffer_t *RingBuffer);

#endif /* INC_RING_BUFFER_H_ */
