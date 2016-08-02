/*
 * seqstack.h
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: shuiting
 */

#ifndef seqstack_H_
#define seqstack_H_

typedef void seqstack;


seqstack* seqstack_Create(int capacity);

void seqstack_Destroy(seqstack* stack);

void seqstack_Clear(seqstack* stack);

int seqstack_Push(seqstack* stack, void* item);

void* seqstack_Pop(seqstack* stack);

void* seqstack_Top(seqstack* stack);

int seqstack_Size(seqstack* stack);

int seqstack_Capacity(seqstack* stack);

#endif /* seqstack_H_ */
