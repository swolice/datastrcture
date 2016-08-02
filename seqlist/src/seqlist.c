/*
 * seqlist.c
 *
 *  Created on: 2016Äê6ÔÂ20ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "seqlist.h"

typedef unsigned int TSeqListNode;
typedef struct _tag_SeqList {

	int capacity;
	int length;
	TSeqListNode* node;
} TSeqList;

SeqList* SeqList_Create(int capacity) {

	TSeqList* ret = NULL;
	if (capacity >= 0)

	{
		ret = (TSeqList*) malloc(
				sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
	}
	if (ret != NULL) {
		ret->capacity = capacity;
		ret->length = 0;
		ret->node = (TSeqListNode*) (ret + 1);
	}

	return ret;
}

void SeqList_Destroy(SeqList* list) {
	free(list);
}

void SeqList_Clear(SeqList* list) {
	TSeqList* slist = (TSeqList*) list;

	if (slist != NULL) {
		slist->length = 0;
	}
}

int SeqList_Length(SeqList* list) {
	TSeqList* slist = (TSeqList*) list;
	int ret = -1;
	if (slist != NULL) {
		ret = slist->length;
	}

	return ret;
}

int SeqList_Capacity(SeqList* list) {
	TSeqList* slist = (TSeqList*) list;
	int ret = -1;

	if (slist != NULL) {
		ret = slist->capacity;
	}

	return ret;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos) {
	TSeqList* slist = (TSeqList*) list;
	int ret = (slist != NULL);
	int i = 0;

	ret = ret && (slist->length + 1 <= slist->capacity);
	ret = ret && (0 <= pos);

	if (ret) {
		if (pos >= slist->length) {
			pos = slist->length;
		}
		for (i = slist->length; i > pos; i--) {
			slist->node[i] = slist->node[i - 1];
		}
		slist->node[i] = (TSeqListNode) node;
		slist->length++;
	}

	return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos) {
	TSeqList* slist = (TSeqList*) list;
	SeqListNode* ret = NULL;

	if ((slist != NULL) && (0 <= pos) && (pos < slist->length)) {
		ret = (SeqListNode*) (slist->node[pos]);
	}

	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list, int pos) {
	TSeqList* slist = (TSeqList*) list;
	SeqListNode* ret = SeqList_Get(list, pos);
	int i = 0;

	if (ret != NULL) {
		for (i = pos + 1; i < slist->length; i++) {
			slist->node[i - 1] = slist->node[i];
		}
		slist->length++;
	}

	return ret;
}

