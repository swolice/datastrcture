/*
 * seqlist2.c
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "seqlist2.h"

typedef unsigned int tseqlistnode;
typedef struct _tag_seqlist {
	int capacity;
	int length;
	tseqlistnode* node;
} tseqlist;



seqlist* seqlist_Create(int capacity) {
	tseqlist* ret=NULL;
	if (capacity>=0) {
		ret=(tseqlist*)malloc(sizeof(tseqlist)+sizeof(tseqlistnode)*capacity);
	}

	if (ret!=NULL) {
		ret->capacity=capacity;
		ret->length=0;
		ret->node=(tseqlistnode*)(ret+1);
	}

	return ret;
}

void seqlist_Destroy(seqlist* list) {
	free(list);
}

void seqlist_Clear(seqlist* list) {
	tseqlist* slist=(tseqlist*)list;
	if (slist!=NULL) {
		slist->length=0;
	}
}

int seqlist_Length(seqlist* list) {
	tseqlist* slist=(tseqlist*)list;
	int ret=-1;

	if (slist!=NULL) {
		ret=slist->length;
	}

	return ret;
}

int seqlist_Capacity(seqlist* list) {
	tseqlist* slist=(tseqlist*)list;
	int ret=-1;
	if (slist!=NULL) {
		ret=slist->capacity;
	}
	return ret;
}

int seqlist_Insert(seqlist* list, seqlistNode* node, int pos) {
	tseqlist* slist=(tseqlist*)list;
	int ret=(slist!=NULL);
	int i=0;

	if(ret)
	{
		if(pos>=slist->length)
		{
			pos=slist->length;
		}
		for (i = slist->length; i >pos; i--) {
			slist->node[i]=slist->node[i-1];
		}
		slist->node[i]=(tseqlistnode)node;
		slist->length++;
	}

	return ret;
}

seqlistNode* seqlist_Get(seqlist* list, int pos) {
	tseqlist* slist=(tseqlist*)list;
	seqlistNode* ret=NULL;

	if ((slist!=NULL)&&(0<=pos)&&(pos<slist->length)) {
		ret=(seqlistNode*)(slist->node[pos]);
	}

	return ret;
}

seqlistNode* seqlist_Delete(seqlist* list, int pos) {
	tseqlist* slist=(tseqlist*)list;
	seqlistNode* ret=seqlist_Get(list, pos);
	int i=0;
	if (ret!=NULL) {
		for(i=pos+1; i<slist->length;i++)
		{
			slist->node[i-1]=slist->node[i];
		}
		slist->length--;
	}

	return ret;
}
