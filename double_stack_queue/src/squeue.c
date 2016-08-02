/*
 * squeue.c
 *
 *  Created on: 2016Äê7ÔÂ4ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkList.h"
#include "LinkStack.h"
#include "squeue.h"

typedef struct _tag_squeue {
	LinkStack* instack;
	LinkStack* outstack;
} tsqueue;

SQueue* SQueue_Create(){
	tsqueue* ret=(tsqueue*)malloc(sizeof(tsqueue));

	if (ret!=NULL) {
		ret->instack=LinkStack_Create();
		ret->outstack=LinkStack_Create();

		if((ret->instack==NULL)||(ret->outstack==NULL))
		{
			LinkStack_Destroy(ret->instack);
			LinkStack_Destroy(ret->outstack);

			free(ret);
			ret=NULL;
		}
	}

	return ret;
}

void SQueue_Destroy(SQueue* queue) {
	SQueue_Clear(queue);
	free(queue);
}

void SQueue_Clear(SQueue* queue){
	tsqueue* squeue=(tsqueue*)queue;
	if (squeue!=NULL) {
		LinkStack_Clear(squeue->instack);
		LinkStack_Clear(squeue->outstack);
	}
}

int SQueue_Append(SQueue* queue, void* item){
	tsqueue* squeue=(tsqueue*)queue;
	if (squeue!=NULL) {
		LinkStack_Push(squeue->instack, item);
	}
}

void* SQueue_Retrieve(SQueue* queue) {
	tsqueue* squeue=(tsqueue*)queue;
	void* ret=NULL;
	if (squeue!=NULL) {
		if (LinkStack_Size(squeue->outstack)>0) {
			while(LinkStack_Size(squeue->instack)>0)
			{
				LinkStack_Push(squeue->outstack, LinkStack_Pop(squeue->instack));
			}
		}

		ret=LinkStack_Pop(squeue->outstack);
	}
	return ret;
}

void* SQueue_Header(SQueue* queue){
	tsqueue* squeue=(tsqueue*)queue;
	void* ret=NULL;
	if (squeue!=NULL) {
		if (LinkStack_Size(squeue->outstack)==0) {
			while(LinkStack_Size(squeue->instack)>0)
			{
				LinkStack_Push(squeue->outstack, LinkStack_Pop(squeue->instack));
			}
		}
		ret=LinkStack_Top(squeue->outstack);
	}

	return ret;
}

int SQueue_Length(SQueue* queue){
	tsqueue* squeue=(tsqueue*)queue;
	int ret=-1;
	if (squeue!=NULL) {
		ret=LinkStack_Size(squeue->instack)+LinkStack_Size(squeue->outstack);
	}

	return ret;
}

