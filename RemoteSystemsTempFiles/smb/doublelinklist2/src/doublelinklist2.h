/*
 * doublelinklist2.h
 *
 *  Created on: 2016Äê6ÔÂ24ÈÕ
 *      Author: shuiting
 */

#ifndef DOUBLELINKLIST2_H_
#define DOUBLELINKLIST2_H_

typedef void dlinklist;
typedef struct _tag_dlinklistnode dlinklistnode;
struct _tag_dlinklistnode {
	dlinklistnode* next;
	dlinklistnode* pre;
};


dlinklist* dlinklist_Create();

void dlinklist_Destroy(dlinklist* list);

void dlinklist_Clear(dlinklist* list);

int dlinklist_Length(dlinklist* list);

int dlinklist_Insert(dlinklist* list, dlinklistnode* node, int pos);

dlinklistnode* dlinklist_Get(dlinklist* list, int pos);

dlinklistnode* dlinklist_Delete(dlinklist* list, int pos);

dlinklistnode* dlinklist_DeleteNode(dlinklist* list, dlinklistnode* node);

dlinklistnode* dlinklist_Reset(dlinklist* list);

dlinklistnode* dlinklist_Current(dlinklist* list);

dlinklistnode* dlinklist_Next(dlinklist* list);

dlinklistnode* dlinklist_Pre(dlinklist* list);

#endif /* DOUBLELINKLIST2_H_ */
