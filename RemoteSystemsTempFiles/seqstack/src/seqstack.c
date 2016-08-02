/*
 * seqstack.c
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: shuiting
 */
#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"
#include "seqstack.h"

seqstack* seqstack_Create(int capacity) {
	return SeqList_Create(capacity);
}

void seqstack_Destroy(seqstack* stack) {
	SeqList_Destroy(stack);
}

void seqstack_Clear(seqstack* stack) {
	SeqList_Clear(stack);
}

int seqstack_Push(seqstack* stack, void* item) {
	return SeqList_Insert(stack, item, SeqList_Length(stack));
}

void* seqstack_Pop(seqstack* stack) {
	return SeqList_Delete(stack, SeqList_Length(stack) - 1);
}

void* seqstack_Top(seqstack* stack) {
	return SeqList_Get(stack, SeqList_Length(stack)-1);
}

int seqstack_Size(seqstack* stack) {
	return SeqList_Length(stack);
}

int seqstack_Capacity(seqstack* stack) {
	return SeqList_Capacity(stack);
}

