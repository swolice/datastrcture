/*
 * circlelist.c
 *
 *
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "circlelist.h"

typedef struct _tag_circlelist {
	CircleListNode header;
	CircleListNode* slider;
	int length;
} tcirclelist;

CircleList* CircleList_Create() {
	tcirclelist* ret = (tcirclelist*) malloc(sizeof(tcirclelist));
	if (ret != NULL) {
		ret->length = 0;
		ret->header.next = NULL;
		ret->slider = NULL;
	}

	return ret;
}

void CircleList_Destroy(CircleList* list) {
	free(list);
}

void CircleList_Clear(CircleList* list) {
	tcirclelist* slist = (tcirclelist*) list;

	if (slist != NULL) {
		slist->length = 0;
		slist->header.next = NULL;
		slist->slider = NULL;
	}
}

int CircleList_Length(CircleList* list) {
	tcirclelist* slist = (tcirclelist*) list;
	int ret = -1;
	if (slist != NULL) {
		ret = slist->length;
	}

	return ret;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos) {
	tcirclelist* slist = (tcirclelist*) list;

	int ret = (slist != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;
	if (ret) {
		CircleListNode* current = (CircleListNode*) slist;
		for (i = 0; (i < pos) && (current->next != NULL); ++i) {
			current = current->next;
		}
		node->next = current->next;
		current->next = node;

		if (slist->length == 0) {
			slist->slider = node;
			node->next = node;
		}

		slist->length++;
	}

	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos) {
	tcirclelist* slist = (tcirclelist*) list;
	CircleListNode* ret = NULL;
	int i = 0;
	if ((slist != NULL) && (pos >= 0)) {
		CircleListNode* current = (CircleListNode*) slist;

		for (i = 0; i < pos; i++) {
			current = current->next;
		}

		ret = current->next;
	}

	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos) {
	tcirclelist* slist = (tcirclelist*) list;
	CircleListNode* ret = NULL;
	int i = 0;

	if ((slist != NULL) && (pos >= 0)) {
		CircleListNode* current = (CircleListNode*) slist;
		CircleListNode* first = slist->header.next;
		CircleListNode* last = (CircleListNode*) CircleList_Get(slist,
				slist->length - 1);

		for (i = 0; i < pos; i++) {
			current = current->next;
		}

		ret = current->next;
		current->next = ret->next;

		slist->length--;

		if (first == ret) {
			slist->header.next = ret->next;
			last->next = ret->next;
		}

		if(slist->slider==ret)
		{
			slist->slider=ret->next;
		}

		if(slist->length==0)
		{
			slist->header.next=NULL;
			slist->slider=NULL;
		}
	}

	return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node) {
	tcirclelist* slist=(tcirclelist*)list;
	CircleListNode*	ret=NULL;
	int i=0;

	if(slist!=NULL){
		CircleListNode* current=(CircleListNode*)slist;

		for(i=0;i<slist->length;i++)
		{
			if(current->next==node)
			{
				ret=current->next;
				break;
			}
			current=current->next;
		}
		if(ret!=NULL)
		{
			CircleList_Delete(slist,i);
		}
	}

	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list) {
	tcirclelist* slist=(tcirclelist*)list;
	CircleListNode*	ret=NULL;
	if(slist!=NULL){
		slist->slider=slist->header.next;
		ret=slist->slider;
	}

	return ret;
}

CircleListNode* CircleList_Current(CircleList* list) {
	tcirclelist* slist=(tcirclelist*)list;
	CircleListNode* ret=NULL;

	if(slist !=NULL)
	{
		ret=slist->slider;
	}

	return ret;
}


CircleListNode* CircleList_Next(CircleList* list) {
	tcirclelist* slist=(tcirclelist*)list;
	CircleListNode*	ret=NULL;
	if((slist!=NULL)&&(slist->slider!=NULL))
	{
		ret=slist->slider;
		slist->slider=ret->next;
	}

	return ret;
}
