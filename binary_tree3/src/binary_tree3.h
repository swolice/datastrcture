/*
 * binary_tree3.h
 *
 *  Created on: 2016年7月8日
 *      Author: shuiting
 */

#ifndef BINARY_TREE3_H_
#define BINARY_TREE3_H_

#define BT_LEFT 0
#define BT_RIGHT 1

typedef void btree;
typedef unsigned long long btpos;

typedef struct _tag_btreenode BTreeNode;
struct _tag_btreenode
{
	BTreeNode* left;
	BTreeNode* right;
};

typedef void (BTree_Printf)(BTreeNode*);

btree* btree_create();

void btree_destroy(btree* tree);

void btree_clear(btree* tree);

int btree_insert(btree* tree, BTreeNode* node, btpos pos, int count, int flag);

BTreeNode* btree_delete(btree* tree, btpos pos, int count);

BTreeNode* btree_get(btree* tree, btpos pos, int count);

BTreeNode* btree_root(btree* tree);

int btree_height(btree* tree);

int btree_count(btree* tree);

int btree_degree(btree* tree);

void btree_display(btree* tree, BTree_Printf* pFunc, int gap, char div);





#endif /* BINARY_TREE3_H_ */
