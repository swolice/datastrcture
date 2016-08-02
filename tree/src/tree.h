/*
 * tree.h
 *
 *  Created on: 2016年7月7日
 *      Author: shuiting
 */

#ifndef TREE_H_
#define TREE_H_

typedef void tree;
typedef void tree_node;

tree* tree_create();
void tree_destroy(tree* tree);
void tree_clear(tree* tree);
int tree_insert(tree* tree, tree_node* node, int pos);
tree_node* tree_delete(tree* tree, int pos);
tree_node* tree_get(tree* tree, int pos);
tree_node* tree_root(tree* tree);
int tree_height(tree* tree);
int tree_count(tree* tree);
int tree_degree(tree* tree);




#endif /* TREE_H_ */
