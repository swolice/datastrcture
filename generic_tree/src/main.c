/*
 * main.c
 *
 *  Created on: 2016年7月7日
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "generic_tree.h"

void printf_data(generic_data* data)
{
	printf("%c", (int)data);
}


int main(int argc, char* argv[])
{
	generic_tree* tree=generic_tree_create();
	int i=0;

	generic_tree_insert(tree, (generic_data*)'A', -1);
	generic_tree_insert(tree, (generic_data*)'B', 0);
	generic_tree_insert(tree, (generic_data*)'C', 0);
	generic_tree_insert(tree, (generic_data*)'D', 0);
	generic_tree_insert(tree, (generic_data*)'E', 1);
	generic_tree_insert(tree, (generic_data*)'F', 1);
	generic_tree_insert(tree, (generic_data*)'G', 3);
	generic_tree_insert(tree, (generic_data*)'H', 3);
	generic_tree_insert(tree, (generic_data*)'I', 3);
	generic_tree_insert(tree, (generic_data*)'J', 3);
	generic_tree_insert(tree, (generic_data*)'K', 3);

	printf("Tree height: %d\n", generic_tree_height(tree));
	printf("Tree Degree: %d\n", generic_tree_degree(tree));
	printf("Full Tree:\n");

	generic_tree_display(tree, printf_data, 2, ' ');

	printf("Get Tree Data: \n");

	for (i = 0; i < generic_tree_count(tree); ++i) {
		printf_data(generic_tree_get(tree, i));
		printf("\n");
	}

	printf("Get Root Data: \n");
	printf_data(generic_tree_root(tree));

	printf("\n");

	generic_tree_delete(tree, 3);
	printf("After deleting D:\n");

	generic_tree_display(tree, printf_data, 2, '-');

	generic_tree_clear(tree);

	printf("After Clearing Tree:\n");

	generic_tree_display(tree, printf_data, 2, '.');

	generic_tree_destory(tree);

	return EXIT_SUCCESS;

}
