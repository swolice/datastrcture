/*
 * linkstack.h
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: shuiting
 */

#ifndef linkstack_H_
#define linkstack_H_

typedef void linkstack;

linkstack* linkstack_Create();

void linkstack_Destroy(linkstack* stack);

void linkstack_Clear(linkstack* stack);

int linkstack_Push(linkstack* stack, void* item);

void* linkstack_Pop(linkstack* stack);

void* linkstack_Top(linkstack* stack);

int linkstack_Size(linkstack* stack);


#endif /* linkstack_H_ */
