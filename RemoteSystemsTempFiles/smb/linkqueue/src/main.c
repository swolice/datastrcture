/*
 * main.c
 *
 *  Created on: 2016Äê7ÔÂ4ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkqueue.h"
#include "LinkList.h"

int main(int argc, char *argv[]) {

	LinkQueue* queue=LinkQueue_Create();
	int a[10]={0};
	int i=0;

	for (i = 0; i < 10; ++i) {
		a[i]=i+1;
		LinkQueue_Append(queue, a+i);
	}

	printf("header: %d\n", *(int*)LinkQueue_Header(queue));
	printf("length: %d\n", LinkQueue_Length(queue));

	while(LinkQueue_Length(queue)>0)
	{
		printf("Retrieve: %d\n", *(int*)LinkQueue_Retrieve(queue));
	}

	LinkQueue_Destroy(queue);




	return EXIT_SUCCESS;
}
