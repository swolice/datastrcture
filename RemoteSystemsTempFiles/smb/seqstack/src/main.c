/*
 * main.c
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "seqlist.h"
#include "seqstack.h"

int main(int argc, char *argv[]) {

	seqstack* stack = seqstack_Create(20);

	int a[10] = { 0 };
	int i = 0;
	for (i = 0; i < 10; ++i) {
		a[i]=i;
		seqstack_Push(stack, a+i);
	}

	printf("Top: %d\n", *(int*)seqstack_Top(stack));
	printf("Capacity: %d\n", seqstack_Capacity(stack));
	printf("Length: %d\n", seqstack_Size(stack));

	return EXIT_SUCCESS;
}
