/*
 * ring_buffer.c
 *
 *  Created on: Aug 20, 2024
 *      Author: denys
 */

#include "ring_buffer.h"


// Functions
// Write
RB_Status RingBuffer_Write(RingBuffer_t *RingBuffer, uint8_t Value)
{

	// Check if RB has place to write
	if((RingBuffer->Head + 1) % RING_BUFFER_SIZE == RingBuffer->Tail)
	{
		return RB_ERROR; // The buffer has no space to write
	}

	// Write value to ring buffer
	RingBuffer->Buffer[RingBuffer->Head] = Value;

	// Shift RB head pointer
	RingBuffer->Head = (RingBuffer->Head + 1) % RING_BUFFER_SIZE;

	return RB_OK;
}


// Read
RB_Status RingBuffer_Read(RingBuffer_t *RingBuffer, uint8_t *Value)
{
	// Check if RB isn't empty
	if(RingBuffer->Tail == RingBuffer->Head)
	{
		return RB_ERROR; // The buffer is empty
	}

	// <- Read from buffer ->
	*Value = RingBuffer->Buffer[RingBuffer->Tail];

	RingBuffer->Tail = (RingBuffer->Tail + 1) % RING_BUFFER_SIZE;

	return RB_OK;
}


// Flush (Clean RingBuffer)
void RingBuffer_Flush(RingBuffer_t *RingBuffer)
{
	// Reset Write\Read pointers
	RingBuffer->Head = 0;
	RingBuffer->Tail = 0;
}
