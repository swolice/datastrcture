/*
 * linkqueue.h
 *
 *  Created on: 2016��7��4��
 *      Author: shuiting
 */

#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

typedef void LinkQueue;

LinkQueue* LinkQueue_Create();

void LinkQueue_Destroy(LinkQueue* queue);

void LinkQueue_Clear(LinkQueue* queue);

int LinkQueue_Append(LinkQueue* queue, void* item);

void* LinkQueue_Retrieve(LinkQueue* queue);

void* LinkQueue_Header(LinkQueue* queue);

int LinkQueue_Length(LinkQueue* queue);


#endif /* LINKQUEUE_H_ */
