/*
 * main.c
 *
 *  Created on: 2016年7月8日
 *      Author: shuiting
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "binary_tree3.h"
#include "seqlist2.h"

struct Node {
	BTreeNode header;
	char v;
};

void printf_data(BTreeNode* node) {
	if (node != NULL) {
		printf("%c", ((struct Node*) node)->v);
	}
}

void thread_via_left(BTreeNode* root, BTreeNode** pp) {
	if ((root != NULL) && (pp != NULL)) {
		if (*pp != NULL) {
			(*pp)->left = root;
			*pp = NULL;
		}

		if (root->left == NULL) {
			*pp = root;
		}

		thread_via_left(root->left, pp);
		thread_via_left(root->right, pp);
	}
}

void thread_via_list(BTreeNode* root, seqlist* list) {
	if ((root != NULL) && (list != NULL)) {
		seqlist_Insert(list, (seqlistNode*) root, seqlist_Length(list));

		thread_via_list(root->left, list);
		thread_via_list(root->right, list);
	}
}

int main(int argc, char* argv[]) {
	btree* tree = btree_create();
	BTreeNode* current = NULL;
	BTreeNode* p = NULL;
	seqlist* list = NULL;
	int i = 0;

	struct Node n1 = { { NULL, NULL }, 'A' };
	struct Node n2 = { { NULL, NULL }, 'B' };
	struct Node n3 = { { NULL, NULL }, 'C' };
	struct Node n4 = { { NULL, NULL }, 'D' };
	struct Node n5 = { { NULL, NULL }, 'E' };
	struct Node n6 = { { NULL, NULL }, 'F' };

	btree_insert(tree, (BTreeNode*) &n1, 0, 0, 0);
	btree_insert(tree, (BTreeNode*) &n2, 0x00, 1, 0);
	btree_insert(tree, (BTreeNode*) &n3, 0x01, 1, 0);
	btree_insert(tree, (BTreeNode*) &n4, 0x00, 2, 0);
	btree_insert(tree, (BTreeNode*) &n5, 0x02, 2, 0);
	btree_insert(tree, (BTreeNode*) &n6, 0x02, 3, 0);

	printf("Full Tree: \n");

	btree_display(tree, printf_data, 4, '-');

	printf("Thread via List:\n");

	list = seqlist_Create(btree_count(tree));

	thread_via_list(btree_root(tree), list);

	for (i = 0; i < seqlist_Length(list); i++) {
		printf("%c, ", ((struct Node*) seqlist_Get(list, i))->v);
	}

	printf("\n");

	printf("Thread via Left:\n");

	current = btree_root(tree);

	thread_via_left(current, &p);

	while (current != NULL) {
		printf("%c, ", ((struct Node*) current)->v);

		current = current->left;
	}

	printf("\n");

	btree_destroy(tree);

	return EXIT_SUCCESS;
}

