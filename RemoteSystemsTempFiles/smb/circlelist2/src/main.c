/*
 * main.c
 *
 *  Created on: 2016Äê6ÔÂ24ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include "circlelist2.h"

struct value {
	circle_listnode header;
	int v;
};

int main(int argc, char *argv[]) {

	circle_list* list=circle_list_Create();

	struct value v1;
	struct value v2;
	struct value v3;
	struct value v4;


	int i=0;

	v1.v=1;
	v2.v=2;
	v3.v=3;
	v4.v=4;


	circle_list_Insert(list, (circle_listnode*)&v1, 0);
	circle_list_Insert(list, (circle_listnode*)&v2, 0);
	circle_list_Insert(list, (circle_listnode*)&v3, 0);
	circle_list_Insert(list, (circle_listnode*)&v4, 0);

	for (i = 0; i < 2*circle_list_Length(list); ++i) {
		struct value* pv=(struct value*)circle_list_Get(list, i);

		printf("%d\n", pv->v);
	}

	while(circle_list_Length(list)>0)
	{
		circle_list_Delete(list,0);
	}

	printf("\n");

	circle_list_Destroy(list);

	return EXIT_SUCCESS;
}
