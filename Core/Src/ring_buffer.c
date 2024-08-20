/*
 * ring_buffer.c
 *
 *  Created on: Aug 20, 2024
 *      Author: denys
 */

#include "ring_buffer.h"




// Functions
// Write
RB_Status RingBuffer_Write(RingBuffer_t *RingBuffer, uint8_t *Value)
{
	// <- Check if RB has place to write ->
}


// Read
RB_Status RingBuffer_Read(RingBuffer_t *RingBuffer, uint8_t Value)
{
	// <- Check if RB isn't empty ->
}


// Flush
RB_Status RingBuffer_Flush(RingBuffer_t *RingBuffer)
{
	// <- just flush it ->
}
