/*
 * main.c
 *
 *  Created on: 2016Äê6ÔÂ24ÈÕ
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "doublelinklist2.h"

struct value {
	dlinklistnode header;
	int v;
};

int main(int argc, char *argv[]) {

	dlinklist* list = dlinklist_Create();

	struct value v1;
	struct value v2;
	struct value v3;
	struct value v4;
	struct value v5;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;

	dlinklist_Insert(list, (dlinklistnode*) &v1, 0);
	dlinklist_Insert(list, (dlinklistnode*) &v2, 0);
	dlinklist_Insert(list, (dlinklistnode*) &v3, 0);
	dlinklist_Insert(list, (dlinklistnode*) &v4, 0);
	dlinklist_Insert(list, (dlinklistnode*) &v5, 0);

	dlinklist_Reset(list);

	printf("%x\n", dlinklist_Current(list));

	dlinklist_Destroy(list);

	return EXIT_SUCCESS;
}
