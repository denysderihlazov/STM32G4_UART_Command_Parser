/*
 * ring_buffer.h
 *
 *  Created on: Aug 20, 2024
 *      Author: denys
 */

#ifndef INC_RING_BUFFER_H_
#define INC_RING_BUFFER_H_

#define BUFFER_SIZE 32

// Success status
typedef enum
{
  RB_OK       = 1,
  RB_ERROR    = 0
} RB_Status;

// RB object
typedef struct{
	uint8_t *Head;
	uint8_t *Tail;
	// uint8_t *RB[BUFFER_SIZE];
} RingBuffer_t;

// Functions

RB_Status RingBuffer_Write(RingBuffer_t *RingBuffer, uint8_t *Value);

RB_Status RingBuffer_Read(RingBuffer_t *RingBuffer, uint8_t Value);

RB_Status RingBuffer_Flush(RingBuffer_t *RingBuffer);

#endif /* INC_RING_BUFFER_H_ */
