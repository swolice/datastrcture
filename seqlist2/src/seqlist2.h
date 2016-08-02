/*
 * seqlist2.h
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: shuiting
 */

#ifndef seqlist2_H_
#define seqlist2_H_

typedef void seqlist;
typedef void seqlistNode;

seqlist* seqlist_Create(int capacity);

void seqlist_Destroy(seqlist* list);

void seqlist_Clear(seqlist* list);

int seqlist_Length(seqlist* list);

int seqlist_Capacity(seqlist* list);

int seqlist_Insert(seqlist* list, seqlistNode* node, int pos);

seqlistNode* seqlist_Get(seqlist* list, int pos);

seqlistNode* seqlist_Delete(seqlist* list, int pos);


#endif /* seqlist2_H_ */
