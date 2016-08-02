/*
 * main.c
 *
 *  Created on: 2016Äê7ÔÂ4ÈÕ
 *      Author: shuiting
 */




#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkList.h"
#include "LinkStack.h"
#include "squeue.h"

int main(int argc, char *argv[]) {

	SQueue* queue=SQueue_Create();
	int a[10]={0};
	int i=0;
	for (i = 0; i < 10; ++i) {
		a[i]=i+1;

		SQueue_Append(queue, a+i);
	}

	printf("Header: %d\n", *(int*)SQueue_Header(queue));
	printf("Length: %d\n", SQueue_Length(queue));

	for (i = 0; i < 5; ++i) {
		printf("Retrieve: %d\n", *(int*)SQueue_Retrieve(queue));
	}

	printf("Header: %d\n", *(int*)SQueue_Header(queue));
	printf("Length: %d\n", SQueue_Length(queue));

	for (i = 0; i < 10; ++i) {
		a[i]=i+1;
		SQueue_Append(queue, a+i);
	}
	while(SQueue_Length(queue)>0)
	{
		printf("Retrieve: %d\n", *(int*)SQueue_Retrieve(queue));
	}

	SQueue_Destroy(queue);



	return EXIT_SUCCESS;
}
