/*
 * main.c
 *
 *  Created on: 2016Äê6ÔÂ23ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "circlelist.h"

struct value {
	CircleListNode header;
	int v;
};


int main(int argc, char *argv[])
{
	int i=0;
	CircleList* list=CircleList_Create();

	struct value v1;
	struct value v2;
	struct value v3;
	struct value v4;
	struct value v5;
	struct value v6;
	struct value v7;
	struct value v8;

	v1.v=1;
	v2.v=2;
	v3.v=3;
	v4.v=4;
	v5.v=5;
	v6.v=6;
	v7.v=7;
	v8.v=8;

	CircleList_Insert(list,(CircleListNode*)&v1, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v2, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v3, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v4, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v5, CircleList_Length(list));

	CircleList_Insert(list, (CircleListNode*)&v5,5);
	CircleList_Delete(list, 0);

	for(i=0;i<2*CircleList_Length(list);i++)
	{
		struct value* pv=(struct value*)CircleList_Get(list, i);

		printf("%d\n", pv->v);

	}

	printf("\n");

	while(CircleList_Length(list)>0)
	{
		struct value* pv=(struct value*) CircleList_Delete(list, 0);

		printf("%d\n", pv->v);
	}

	printf("\n");

	CircleList_Insert(list,(CircleListNode*)&v1, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v2, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v3, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v4, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v5, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v6, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v7, CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v8, CircleList_Length(list));

	for(i=0;i<CircleList_Length(list);i++)
	{
		struct value* pv=(struct value*)CircleList_Next(list);
		printf("%d\n", pv->v);
	}

	printf("\n");

	CircleList_Reset(list);

	while(CircleList_Length(list)>0)
	{
		struct value* pv=NULL;
		for(i=1;i<3;i++)
		{
			CircleList_Next(list);
		}
		pv=(struct value*)CircleList_Current(list);

		printf("%d\n", pv->v);

		CircleList_DeleteNode(list, (CircleListNode*)pv);
	}

	CircleList_Destroy(list);

	return EXIT_SUCCESS;
}
