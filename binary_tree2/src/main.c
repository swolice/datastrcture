/*
 * main.c
 *
 *  Created on: 2016年7月8日
 *      Author: shuiting
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkqueue2.h"
#include "binary_tree2.h"

struct node {
	btreenode header;
	char v;
};

void printf_data(btreenode* node)
{
	if (node!=NULL) {
		printf("%c", ((struct node*)node)->v);
	}
}

void pre_order_traversal(btreenode* root)
{
	if (root!=NULL) {
		printf("%c", ((struct node*)root)->v);

		pre_order_traversal(root->left);
		pre_order_traversal(root->right);
	}
}

void middle_order_traversal(btreenode* root)
{
	if (root!=NULL) {
		middle_order_traversal(root->left);
		printf("%c", ((struct node*)root)->v);

		middle_order_traversal(root->right);
	}
}

void post_order_travelsal(btreenode* root)
{
	if (root!=NULL) {
		post_order_travelsal(root->left);
		post_order_travelsal(root->right);
		printf("%c", ((struct node*)root)->v);
	}
}

void level_order_traversal(btreenode* root)
{
	if (root!=NULL) {
		LinkQueue* queue=LinkQueue_Create();
		if (queue!=NULL) {
			LinkQueue_Append(queue, root);

			while(LinkQueue_Length(queue)>0)
			{
				struct node* node=(struct node*)LinkQueue_Retrieve(queue);

				printf("%c ", node->v);

				LinkQueue_Append(queue, node->header.left);
				LinkQueue_Append(queue, node->header.right);
			}
		}

		LinkQueue_Destroy(queue);
	}
}







int main(int argc, char* argv[])
{

	btree* tree = btree_create();

	struct node n1={{NULL, NULL}, 'A'};
	struct node n2={{NULL, NULL}, 'B'};
	struct node n3={{NULL, NULL}, 'C'};
	struct node n4={{NULL, NULL}, 'D'};
	struct node n5={{NULL, NULL}, 'E'};
	struct node n6={{NULL, NULL}, 'F'};

	btree_insert(tree, (btreenode*)&n1, 0, 0, 0);
	btree_insert(tree, (btreenode*)&n2, 0x00, 1, 0);
	btree_insert(tree, (btreenode*)&n3, 0x01, 1, 0);
	btree_insert(tree, (btreenode*)&n4, 0x00, 2, 0);
	btree_insert(tree, (btreenode*)&n5, 0x02, 2, 0);
	btree_insert(tree, (btreenode*)&n6, 0x02, 3, 0);

	printf("Full tree:\n");

	btree_display(tree, printf_data, 4, '-');

	printf("pre order traversal: \n");

	pre_order_traversal(btree_root(tree));

	printf("\n");

	printf("Middle order traversal: \n");

	middle_order_traversal(btree_root(tree));

	printf("\n");

	printf("post order traversal: \n");

	post_order_travelsal(btree_root(tree));
	printf("\n");
	printf("level order traversal: \n");

	level_order_traversal(btree_root(tree));
	printf("\n");

	btree_destroy(tree);



	return EXIT_SUCCESS;
}

