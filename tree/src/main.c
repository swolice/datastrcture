/*
 * main.c
 *
 *  Created on: 2016年7月7日
 *      Author: shuiting
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "tree.h"

int main(int argc, char* argv[])
{

	tree* tree=tree_create();

	tree_destroy(tree);


	return EXIT_SUCCESS;
}



