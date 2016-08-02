/*
 * linklist_singlelist.c
 *
 *  Created on: 2016Äê6ÔÂ20ÈÕ
 *      Author: shuiting
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linklist_singlelist.h"

typedef struct _tag_linklist {
	LinkListNode header;
	int length;
} TLinkList;

LinkList* LinkList_Create() {
	TLinkList* ret = (TLinkList*) malloc(sizeof(TLinkList));

	if (ret != NULL) {
		ret->length = 0;
		ret->header.next = NULL;
	}

	return ret;
}

void LinkList_Destroy(LinkList* list) {
	free(list);
}

void LinkList_Clear(LinkList* list) {
	TLinkList* slist = (TLinkList*) list;

	if (slist != NULL) {
		slist->length = 0;
		slist->header.next = NULL;
	}
}

int LinkList_Length(LinkList* list) {
	TLinkList* slist = (TLinkList*) list;
	int ret = 1;

	if (slist != NULL) {
		ret = slist->length;
	}

	return ret;
}

int LinkList_Insert(LinkList* list, LinkListNode* node, int pos) {
	TLinkList* slist = (TLinkList*) list;
	int ret = (slist != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;
	if (ret) {
		LinkListNode* current = (LinkListNode*) slist;
		for (i = 0; (i < pos) && (current->next != NULL); i++) {
			current = current->next;
		}
		node->next = current->next;
		current->next = node;
		slist->length++;
	}
	return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos) {
	TLinkList* slist = (TLinkList*) list;
	LinkListNode* ret = NULL;
	int i = 0;
	if ((slist != NULL) && (0 <= pos) && (pos < slist->length)) {
		LinkListNode* current = (LinkListNode*) slist;
		for (i = 0; i < pos; i++) {
			current = current->next;
		}
		ret = current->next;
	}
	return ret;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos) {
	TLinkList* slist = (TLinkList*) list;
	LinkListNode* ret = NULL;
	int i = 0;
	if ((slist != NULL) && (0 <= pos) && (pos < slist->length)) {
		LinkListNode* current = (LinkListNode*) slist;
		for (i = 0; i < pos; i++) {
			current = current->next;
		}
		ret = current->next;
		current->next = ret->next;

		slist->length--;

	}
	return ret;
}

