/*
 * linkqueue2.h
 *
 *  Created on: 2016Äê7ÔÂ4ÈÕ
 *      Author: shuiting
 */

#ifndef LINKQUEUE2_H_
#define LINKQUEUE2_H_

typedef void LinkQueue;


LinkQueue* LinkQueue_Create();

void LinkQueue_Destroy(LinkQueue* queue);

void LinkQueue_Clear(LinkQueue* queue);

int LinkQueue_Append(LinkQueue* queue, void* item);

void* LinkQueue_Retrieve(LinkQueue* queue);

void* LinkQueue_Header(LinkQueue* queue);

int LinkQueue_Length(LinkQueue* queue);

#endif /* LINKQUEUE2_H_ */
