/*
 * linkstack.c
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkstack.h"
#include "linklist.h"

typedef struct _tag_linkstacknode {
	LinkListNode header;
	void* item;
} tlinkstacknode;


linkstack* linkstack_Create() {
	return LinkList_Create();
}

void linkstack_Destroy(linkstack* stack) {
	linkstack_Clear(stack);
	LinkList_Destroy(stack);
}

void linkstack_Clear(linkstack* stack) {
	while( linkstack_Size(stack)>0)
	{
		linkstack_Pop(stack);
	}
}

int linkstack_Push(linkstack* stack, void* item) {
	tlinkstacknode* node=(tlinkstacknode*)malloc(sizeof(tlinkstacknode));
	int ret=(node!=NULL)&&(item!=NULL);

	if (ret) {
		node->item=item;
		ret=LinkList_Insert(stack, (LinkListNode*)node, 0);
	}

	if (!ret) {
		free(node);
	}

	return ret;
}

void* linkstack_Pop(linkstack* stack) {
	tlinkstacknode* node =(tlinkstacknode*)LinkList_Delete(stack,0);
	void * ret=NULL;
	if (node!=NULL) {
		ret=node->item;

		free(node);
	}

	return ret;
}

void* linkstack_Top(linkstack* stack) {
	tlinkstacknode* node=(tlinkstacknode*)LinkList_Get(stack,0);
	void* ret=NULL;
	if (node!=NULL) {
		ret=node->item;
	}
	return ret;
}

int linkstack_Size(linkstack* stack) {
	return LinkList_Length(stack);
}
