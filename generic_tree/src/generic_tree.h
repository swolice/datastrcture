/*
 * generic_tree.h
 *
 *  Created on: 2016年7月7日
 *      Author: shuiting
 */

#ifndef GENERIC_TREE_H_
#define GENERIC_TREE_H_

typedef void generic_tree;
typedef void generic_data;
typedef void (generic_printf)(generic_data*);

generic_tree* generic_tree_create();
void generic_tree_destory(generic_tree* tree);
void generic_tree_clear(generic_tree* tree);
int generic_tree_insert(generic_tree* tree, generic_data* data, int npos);
generic_data* generic_tree_delete(generic_tree* tree, int pos);
generic_data* generic_tree_get(generic_tree* tree, int pos);
generic_data* generic_tree_root(generic_tree* tree);
int generic_tree_height(generic_tree* tree);
int generic_tree_count(generic_tree* tree);
int generic_tree_degree(generic_tree* tree);
void generic_tree_display(generic_tree* tree, generic_printf* p_func, int gap, char div);


#endif /* GENERIC_TREE_H_ */
