/*
 * binary_tree.c
 *
 *  Created on: 2016年7月8日
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "binary_tree.h"

typedef struct _tag_btree tbtree;
struct _tag_btree {
	int count;
	btreenode* root;
};

static void recursive_display(btreenode* node, btree_printf* p_func, int format, int gap, char div)
{
	int i=0;
	if ((node!=NULL)&&(p_func!=NULL)) {
		for (i = 0; i < format; ++i) {
			printf("%c", div);
		}
		p_func(node);

		printf("\n");

		if ((node->left!=NULL)||(node->right!=NULL)) {
			recursive_display(node->left, p_func, format+gap, gap, div);
			recursive_display(node->right, p_func, format+gap, gap, div);
		}
	} else {
		for (i = 0; i < format; ++i) {
			printf("%c", div);
		}
		printf("\n");
	}
}

static int recursive_count(btreenode* root)
{
	int ret=0;
	if (root!=NULL) {
		ret=recursive_count(root->left)+1+recursive_count(root->right);
	}

	return ret;
}

static int recursive_height(btreenode* root)
{
	int ret=0;
	if (root!=NULL) {
		int lh=recursive_height(root->left);
		int rh=recursive_height(root->right);

		ret=((lh>rh)?lh:rh)+1;
	}
	return ret;
}

static int recursive_degree(btreenode* root)
{
	int ret=0;
	if (root!=NULL) {
		if (root->left!=NULL) {
			ret++;
		}
		if(root->right!=NULL)
		{
			ret++;
		}

		if(ret==1)
		{
			int ld=recursive_degree(root->left);
			int rd=recursive_degree(root->right);

			if (ret<ld) {
				ret=ld;
			}
			if(ret<rd)
			{
				ret=rd;
			}
		}
	}

	return ret;
}


btree* btree_create(){
	tbtree* ret=(tbtree*)malloc(sizeof(tbtree));

	if (ret!=NULL) {
		ret->count=0;
		ret->root=NULL;
	}

	return ret;
}

void btree_destroy(btree* tree){
	free(tree);
}

void btree_clear(btree* tree){
	tbtree* btree=(tbtree*)tree;

	if (btree!=NULL) {
		btree->count=0;
		btree->root=NULL;
	}
}

int btree_insert(btree* tree, btreenode* node, btpos pos, int count, int flag){
	tbtree* btree=(tbtree*)tree;
	int ret=(btree!=NULL)&&(node!=NULL)&&((flag==bt_left)||(flag==bt_right));
	int bit=0;

	if (ret) {
		btreenode* parent=NULL;
		btreenode* current=btree->root;

		node->left=NULL;
		node->right=NULL;

		while((count>0)&&(current!=NULL))
		{
			bit=pos&1;
			pos=pos>>1;
			parent=current;

			if (bit==bt_left) {
				current=current->left;
			}else if (bit==bt_right) {
				current=current->right;
			}

			count--;
		}

		if (flag==bt_left) {
			node->left=current;
		}else if (flag==bt_right) {
			node->right=current;
		}

		if (parent!=NULL) {
			if (bit==bt_left) {
				parent->left=node;
			} else if (bit==bt_right) {
				parent->right=node;
			}
		}else {
			btree->root=node;
		}

		btree->count++;
	}
	return ret;
}

btreenode* btree_delete(btree* tree, btpos pos, int count){
	tbtree* btree=(tbtree*)tree;
	btreenode* ret=NULL;
	int bit=0;
	if (btree!=NULL) {
		btreenode* parent=NULL;
		btreenode* current=btree->root;

		while((count>0)&&(current!=NULL))
		{
			bit=pos&1;
			pos=pos>>1;

			parent=current;

			if (bit==bt_left) {
				current=current->left;
			}else if (bit==bt_right) {
				current=current->right;
			}
			count--;
		}
		if (parent!=NULL) {
			if (bit==bt_left) {
				parent->left=NULL;
			} else if (bit==bt_right) {
				parent->right=NULL;
			}
		} else {
			btree->root=NULL;
		}

		ret=current;

		btree->count=btree->count-recursive_count(ret);
	}

	return ret;
}

btreenode* btree_get(btree* tree, btpos pos, int count){
	tbtree* btree=(tbtree*)tree;
	btreenode* ret=NULL;
	int bit=0;

	if (btree!=NULL) {
		btreenode* current=btree->root;

		while((count>0)&&(current!=NULL))
		{
			bit=pos&1;
			pos=pos>>1;
			if (bit==bt_left) {
				current=current->left;
			} else if(bit==bt_right){
				current=current->right;
			}
			count--;
		}
		ret=current;
	}
	return ret;
}

btreenode* btree_root(btree* tree){
	tbtree* btree=(tbtree*)tree;
	btreenode* ret=NULL;

	if (btree!=NULL) {
		ret=btree->root;
	}
	return ret;
}

int btree_height(btree* tree){
	tbtree* btree =(tbtree*)tree;
	int ret=0;
	if (btree!=NULL) {
		ret=recursive_height(btree->root);
	}

	return ret;
}

int btree_count(btree* tree){
	tbtree* btree=(tbtree*)tree;

	int ret=0;

	if(btree!=NULL)
	{
		ret=btree->count;
	}

	return ret;
}

int btree_degree(btree* tree){

	tbtree* btree=(tbtree*)tree;
	int ret=0;

	if (btree!=NULL) {
		ret=recursive_degree(btree->root);
	}

	return ret;
}

void btree_display(btree* tree, btree_printf* p_func, int gap, char div){
	tbtree* btree=(tbtree*)tree;

	if (btree!=NULL) {
		recursive_display(btree->root, p_func, 0, gap, div);
	}
}

