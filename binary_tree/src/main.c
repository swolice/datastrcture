/*
 * main.c
 *
 *  Created on: 2016年7月8日
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

struct node {
	btreenode* header;
	char v;
};

void printf_data(btreenode* node) {
	if (node != NULL) {
		printf("%c", ((struct node*) node)->v);
	}
}

int main(int argc, char* argv[]) {
	btree* tree = btree_create();
	struct node n1 = { { NULL, NULL }, 'A' };
	struct node n2 = { { NULL, NULL }, 'B' };
	struct node n3 = { { NULL, NULL }, 'C' };
	struct node n4 = { { NULL, NULL }, 'D' };
	struct node n5 = { { NULL, NULL }, 'E' };
	struct node n6 = { { NULL, NULL }, 'F' };

	btree_insert(tree, (btreenode*) &n1, 0, 0, 0);
	btree_insert(tree, (btreenode*) &n2, 0x00, 1, 0);
	btree_insert(tree, (btreenode*) &n3, 0x01, 1, 0);
	btree_insert(tree, (btreenode*) &n4, 0x00, 2, 0);
	btree_insert(tree, (btreenode*) &n5, 0x02, 2, 0);
	btree_insert(tree, (btreenode*) &n6, 0x02, 3, 0);

	printf("Height: %d\n", btree_height(tree));
	printf("Degree: %d\n", btree_degree(tree));
	printf("Count: %d\n", btree_count(tree));

	printf("position At (0x02, 2): %c\n",
			((struct node*) btree_get(tree, 0x02, 2))->v);
	printf("Full Tree: \n");

	btree_display(tree, printf_data, 4, '-');

	btree_delete(tree, 0x00, 1);

	printf("After delete B: \n");
	printf("Height: %d\n", btree_height(tree));
	printf("Degree: %d\n", btree_degree(tree));
	printf("Count: %d\n", btree_count(tree));

	printf("Full Tree: \n");

	btree_display(tree, printf_data, 4, '-');

	btree_clear(tree);

	printf("After clear: \n");
	printf("Height: %d\n", btree_height(tree));
	printf("Degree: %d\n", btree_degree(tree));
	printf("Count: %d\n", btree_count(tree));\

	btree_display(tree, printf_data, 4, '-');
	btree_destroy(tree);


	return EXIT_SUCCESS;
}
