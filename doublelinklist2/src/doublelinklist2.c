/*
 * doublelinklist2.c
 *
 *  Created on: 2016Äê6ÔÂ24ÈÕ
 *      Author: shuiting
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "doublelinklist2.h"

typedef struct _tag_dlinklist {
	dlinklistnode header;
	dlinklistnode* slider;
	int length;
} tdlinklist;

dlinklist* dlinklist_Create() {
	tdlinklist* ret = (tdlinklist*) malloc(sizeof(tdlinklist));
	if (ret != NULL) {
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}
	return ret;
}

void dlinklist_Destroy(dlinklist* list) {
	free(list);
}

void dlinklist_Clear(dlinklist* list) {
	tdlinklist* slist = (tdlinklist*) list;
	if (slist != NULL) {
		slist->length = 0;
		slist->header.next = NULL;
		slist->header.pre = NULL;
		slist->slider = NULL;
	}
}

int dlinklist_Length(dlinklist* list) {
	tdlinklist* slist = (tdlinklist*) list;
	int ret = -1;
	if (slist != NULL) {
		ret = slist->length;
	}
	return ret;
}

int dlinklist_Insert(dlinklist* list, dlinklistnode* node, int pos) {
	tdlinklist* slist = (tdlinklist*) list;
	int ret = (slist != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;

	if (ret) {
		dlinklistnode* current = (dlinklistnode*) slist;
		dlinklistnode* next = NULL;
		for (i = 0; (i < pos) && (current->next != NULL); ++i) {
			current = current->next;

		}

		next = current->next;
		current->next = node;
		node->next = next;

		if (next != NULL) {
			next->pre = node;
		}
		node->pre = current;

		if (slist->length == 0) {
			slist->slider = node;
		}
		if (current == (dlinklistnode*) slist) {
			node->pre = NULL;
		}
		slist->length++;
	}

	return ret;
}

dlinklistnode* dlinklist_Get(dlinklist* list, int pos) {
	tdlinklist* slist = (tdlinklist*) list;
	dlinklistnode* ret = NULL;
	int i = 0;
	if ((slist != NULL) && (0 <= pos) && (pos < slist->length)) {
		dlinklistnode* current = (dlinklistnode*) slist;
		for (i = 0; i < pos; ++i) {
			current = current->next;
		}

		ret = current->next;
	}
	return ret;

}

dlinklistnode* dlinklist_Delete(dlinklist* list, int pos) {
	tdlinklist* slist = (tdlinklist*) list;
	dlinklistnode* ret = NULL;
	int i = 0;

	if ((slist != NULL) && (0 <= pos) && (pos < slist->length)) {
		dlinklistnode* current = (dlinklistnode*) slist;
		dlinklistnode* next = NULL;

		for (i = 0; i < pos; ++i) {
			current = current->next;
		}

		ret = current->next;
		next = ret->next;

		current->next = next;

		if (next != NULL) {
			next->pre = current;

			if (current == (dlinklistnode*) slist) {
				next->pre = NULL;
			}

		}

		if (slist->slider == ret) {
			slist->slider = next;
		}

		slist->length--;
	}

	return ret;
}

dlinklistnode* dlinklist_DeleteNode(dlinklist* list, dlinklistnode* node) {
	tdlinklist* slist = (tdlinklist*) list;
	dlinklistnode* ret = NULL;
	int i = 0;

	if (slist != NULL) {
		dlinklistnode* current = (dlinklistnode*) slist;
		for (i = 0; i < slist->length; ++i) {
			if (current->next == node) {
				ret = current->next;
				break;
			}
			current = current->next;
		}
		if (ret != NULL) {
			dlinklist_Delete(slist, i);
		}
	}

	return ret;
}

dlinklistnode* dlinklist_Reset(dlinklist* list) {
	tdlinklist* slist = (tdlinklist*) list;
	dlinklistnode* ret = NULL;

	if (slist != NULL) {
		slist->slider = slist->header.next;
		ret = slist->slider;
	}

	return ret;
}

dlinklistnode* dlinklist_Current(dlinklist* list) {
	tdlinklist* slist = (tdlinklist*) list;
	dlinklistnode* ret = NULL;
	if (slist != NULL) {
		ret = slist->slider;
	}

	return ret;
}

dlinklistnode* dlinklist_Next(dlinklist* list) {
	tdlinklist* slist = (tdlinklist*) list;
	dlinklistnode* ret = NULL;
	if ((slist != NULL) && (slist->slider != NULL)) {
		ret = slist->slider;
		slist->slider = ret->next;
	}
	return ret;
}

dlinklistnode* dlinklist_Pre(dlinklist* list) {
	tdlinklist* slist = (tdlinklist*) list;
	dlinklistnode* ret = NULL;

	if ((slist != NULL) && (slist->slider != NULL)) {
		ret = slist->slider;
		slist->slider = ret->pre;
	}

	return ret;
}

