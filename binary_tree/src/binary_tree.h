/*
 * binary_tree.h
 *
 *  Created on: 2016年7月8日
 *      Author: shuiting
 */

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#define bt_left 0
#define bt_right 1

typedef void btree;
typedef unsigned long long btpos;

typedef struct _tag_btreenode btreenode;
struct _tag_btreenode {
	btreenode* left;
	btreenode* right;
};

typedef void (btree_printf)(btreenode*);

btree* btree_create();

void btree_destroy(btree* tree);

void btree_clear(btree* tree);

int btree_insert(btree* tree, btreenode* node, btpos pos, int count, int flag);

btreenode* btree_delete(btree* tree, btpos pos, int count);

btreenode* btree_get(btree* tree, btpos pos, int count);

btreenode* btree_root(btree* tree);

int btree_height(btree* tree);

int btree_count(btree* tree);

int btree_degree(btree* tree);

void btree_display(btree* tree, btree_printf* p_func, int gap, char div);





#endif /* BINARY_TREE_H_ */
