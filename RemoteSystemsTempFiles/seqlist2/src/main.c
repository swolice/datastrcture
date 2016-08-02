/*
 * main.c
 *
 *  Created on: 2016Äê6ÔÂ28ÈÕ
 *      Author: shuiting
 */




#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "seqlist2.h"

int main(int argc, char *argv[]) {

	seqlist* list=seqlist_Create(10);

	int i=0;
	int j=1;
	int k=2;
	int l=3;
	int m=4;
	int n=5;

	seqlist_Insert(list, &i, 0);
	seqlist_Insert(list, &j, 0);
	seqlist_Insert(list, &k, 0);
	seqlist_Insert(list, &l, 0);
	seqlist_Insert(list, &m, 7);
	seqlist_Insert(list, &n, 8);

	seqlist_Delete(list, 5);

	printf("%x\n", seqlist_Get(list, 5));

	seqlist_Destroy(list);


	return EXIT_SUCCESS;
}
