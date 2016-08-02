/*
 * linkqueue2.c
 *
 *  Created on: 2016Äê7ÔÂ4ÈÕ
 *      Author: shuiting
 */

#include <stdlib.h>
#include <stdio.h>
#include "linkqueue2.h"
#include <malloc.h>
typedef struct _tag_linkqueuenode TLinkqueuenode;

struct _tag_linkqueuenode{
	TLinkqueuenode* next;
	void* item;
};

typedef struct _tag_linkqueue {
	TLinkqueuenode* front;
	TLinkqueuenode* rear;
	int length;
} tlinkqueue;


LinkQueue* LinkQueue_Create()
{
	tlinkqueue* ret=(tlinkqueue*)malloc(sizeof(tlinkqueue));
	if (ret!=NULL) {
		ret->front=NULL;
		ret->rear=NULL;
		ret->length=0;
	}
	return ret;

}

void LinkQueue_Destroy(LinkQueue* queue){

	LinkQueue_Clear(queue);
	free(queue);
}

void LinkQueue_Clear(LinkQueue* queue){
	while(LinkQueue_Length(queue)>0)
	{
		LinkQueue_Retrieve(queue);
	}
}

int LinkQueue_Append(LinkQueue* queue, void* item){
	tlinkqueue* squeue=(tlinkqueue*)queue;
	TLinkqueuenode* node=(TLinkqueuenode*)malloc(sizeof(TLinkqueuenode));

	int ret=(squeue !=NULL)&&(item!=NULL)&&(node!=NULL);

	if (ret) {
		node->item=item;
		if (squeue->length>0) {
			squeue->rear->next=node;
			squeue->rear=node;
			node->next=NULL;
		}else {
			squeue->front=node;
			squeue->rear=node;
			node->next=NULL;
		}
		squeue->length++;
	}
	if (!ret) {
		free(node);
	}

	return ret;
}

void* LinkQueue_Retrieve(LinkQueue* queue){
	tlinkqueue* squeue=(tlinkqueue*)queue;
	TLinkqueuenode* node=NULL;
	void* ret=NULL;
	if ((squeue!=NULL)&&(squeue->length>0)) {
		node=squeue->front;
		squeue->front=node->next;
		ret=node->item;
		free(node);
		squeue->length--;
		if (squeue->length==0) {
			squeue->front=NULL;
			squeue->rear=NULL;
		}
	}
	return ret;
}


void* LinkQueue_Header(LinkQueue* queue){
	tlinkqueue* squeue=(tlinkqueue*)queue;
	void* ret=NULL;

	if ((squeue!=NULL)&&(squeue->length>0)) {
		ret=squeue->front->item;
	}
	return ret;
}

int LinkQueue_Length(LinkQueue* queue){
	tlinkqueue* squeue=(tlinkqueue*)queue;
	int ret=-1;
	if (squeue!=NULL) {
		ret=squeue->length;

	}
	return ret;
}
