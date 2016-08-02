/*
 * squeue.h
 *
 *  Created on: 2016Äê7ÔÂ4ÈÕ
 *      Author: shuiting
 */

#ifndef SQUEUE_H_
#define SQUEUE_H_

typedef void SQueue;

SQueue* SQueue_Create();

void SQueue_Destroy(SQueue* queue);

void SQueue_Clear(SQueue* queue);

int SQueue_Append(SQueue* queue, void* item);

void* SQueue_Retrieve(SQueue* queue);

void* SQueue_Header(SQueue* queue);

int SQueue_Length(SQueue* queue);


#endif /* SQUEUE_H_ */
