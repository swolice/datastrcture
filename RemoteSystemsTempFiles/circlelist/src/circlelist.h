/*
 * circlelist.h
 *
 *  Created on: 2016Äê6ÔÂ23ÈÕ
 *      Author: shuiting
 */

#ifndef CIRCLELIST_H_
#define CIRCLELIST_H_

typedef void CircleList;
typedef struct _tag_circlelistnode CircleListNode;
struct _tag_circlelistnode {
	CircleListNode* next;
};

CircleList* CircleList_Create();

void CircleList_Destroy(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);

CircleListNode* CircleList_Reset(CircleList* list);

CircleListNode* CircleList_Current(CircleList* list);

CircleListNode* CircleList_Next(CircleList* list);

#endif /* CIRCLELIST_H_ */
