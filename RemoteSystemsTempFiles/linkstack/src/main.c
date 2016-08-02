/*
 * main.c
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: shuiting
 */




#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linklist.h"
#include "linkstack.h"

int main(int argc, char *argv[]) {

	linkstack*  stack=linkstack_Create();
	int a[10];
	int i=0;
	for (i = 0; i < 10; ++i) {
		a[i]=i;
		linkstack_Push(stack, a+i);
	}

	printf("Top: %d\n", *(int*)linkstack_Top(stack));
	printf("Length: %d\n", linkstack_Size(stack));

	while(linkstack_Size(stack)>0)
	{
		printf("Pop: %d\n", *(int*)linkstack_Pop(stack));
	}

	linkstack_Destroy(stack);


	return EXIT_SUCCESS;
}
