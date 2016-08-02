/*
 * circlelist2.h
 *
 *  Created on: 2016Äê6ÔÂ24ÈÕ
 *      Author: shuiting
 */

#ifndef CIRCLELIST2_H_
#define CIRCLELIST2_H_

typedef void circle_list;
typedef struct _tag_circle_listnode circle_listnode;
struct _tag_circle_listnode {
	circle_listnode* next;
};


circle_list* circle_list_Create();

void circle_list_Destroy(circle_list* list);

void circle_list_Clear(circle_list* list);

int circle_list_Length(circle_list* list);

int circle_list_Insert(circle_list* list, circle_listnode* node, int pos);

circle_listnode* circle_list_Get(circle_list* list, int pos);

circle_listnode* circle_list_Delete(circle_list* list, int pos);

circle_listnode* circle_list_DeleteNode(circle_list* list, circle_listnode* node);

circle_listnode* circle_list_Reset(circle_list* list);

circle_listnode* circle_list_Current(circle_list* list);

circle_listnode* circle_list_Next(circle_list* list);



#endif /* CIRCLELIST2_H_ */
