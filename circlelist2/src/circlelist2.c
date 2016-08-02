/*
 * circle_list2.c
 *
 *  Created on: 2016Äê6ÔÂ24ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include "circlelist2.h"

typedef struct _tag_circlelist {
	circle_listnode header;
	circle_listnode* slider;
	int length;
} tcirclelist;


circle_list* circle_list_Create() {

	tcirclelist* ret=(tcirclelist*)malloc(sizeof(tcirclelist));

	if (ret!=NULL) {
		ret->length=0;
		ret->header.next=NULL;
		ret->slider=NULL;
	}

	return ret;
}

void circle_list_Destroy(circle_list* list){
	free(list);

}

void circle_list_Clear(circle_list* list){
	tcirclelist* slist=(tcirclelist*)list;
	if (slist!=NULL) {
		slist->length=0;
		slist->header.next=NULL;
		slist->slider=NULL;
	}
}

int circle_list_Length(circle_list* list) {
	tcirclelist* slist=(tcirclelist*)list;
	int ret=-1;
	if (slist!=NULL) {
		ret=slist->length;
	}

	return ret;
}

int circle_list_Insert(circle_list* list, circle_listnode* node, int pos) {
	tcirclelist* slist=(tcirclelist*)list;
	int ret=(slist!=NULL)&&(pos>=0)&&(node!=NULL);
	int i=0;

	if (ret) {
		circle_listnode* current=(circle_listnode*)slist;
		for (i = 0; (i<pos)&&(current->next!=NULL); ++i) {
			current=current->next;
		}
		node->next=current->next;
		current->next=node;

		if (slist->length==0) {
			slist->slider=node;
		}

		slist->length++;

		if (current==(circle_listnode*)slist) {
			circle_listnode* last=circle_list_Get(slist, slist->length-1);
			last->next=current->next;
		}
	}

	return ret;
}

circle_listnode* circle_list_Get(circle_list* list, int pos) {
	tcirclelist* slist=(tcirclelist*)list;
	circle_listnode* ret=NULL;
	int i=0;

	if((slist!=NULL)&&(pos>=0)&&(slist->length>0))
	{
		circle_listnode* current=(circle_listnode*)slist;
		for(i=0;i<pos;i++)
		{
			current=current->next;
		}

		ret=current->next;
	}

	return ret;
}

circle_listnode* circle_list_Delete(circle_list* list, int pos) {
	tcirclelist* slist=(tcirclelist*)list;
	circle_listnode* ret=NULL;
	int i=0;

	if ((slist!=NULL)&&(pos>=0)&&(slist->length>0)) {
		circle_listnode* current=(circle_listnode*)slist;
		circle_listnode* last =NULL;

		for (i = 0; i < pos; ++i) {
			current=current->next;

		}
		if (current==(circle_listnode*)slist) {
			last=(circle_listnode*)circle_list_Get(slist, slist->length-1);


		}

		ret=current->next;
		current->next=ret->next;

		slist->length--;

		if (last!=NULL) {
			slist->header.next=ret->next;
			last->next=ret->next;

		}

		if (slist->slider==ret) {
			slist->slider=ret->next;

		}
		if (slist->length==0) {
			slist->header.next=NULL;
			slist->slider=NULL;

		}
	}

	return ret;
}

circle_listnode* circle_list_DeleteNode(circle_list* list, circle_listnode* node) {
	tcirclelist* slist=(tcirclelist*)list;
	circle_listnode* ret=NULL;
	int i=0;

	if(slist!=NULL)
	{
		circle_listnode* current=(circle_listnode*)slist;

		for (i = 0; i < slist->length; ++i) {
			if(current->next==node)
			{
				ret=current->next;
				break;
			}
			current=current->next;
		}
		if (ret!=NULL) {
			circle_list_Delete(slist,i);
		}
	}

	return ret;
}

circle_listnode* circle_list_Reset(circle_list* list) {
	tcirclelist* slist=(tcirclelist*)list;
	circle_listnode* ret=NULL;
	if (slist!=NULL) {
		slist->slider=slist->header.next;
		ret=slist->slider;
	}

	return ret;
}

circle_listnode* circle_list_Current(circle_list* list) {
	tcirclelist* slist =(tcirclelist*)list;
	circle_listnode* ret=NULL;

	if (slist!=NULL) {
		ret=slist->slider;
	}

	return ret;
}

circle_listnode* circle_list_Next(circle_list* list) {
	tcirclelist* slist=(tcirclelist*)list;
	circle_listnode* ret=NULL;

	if ((slist!=NULL)&&(slist->slider!=NULL)) {
		ret=slist->slider;
		slist->slider=ret->next;
	}

	return ret;
}

