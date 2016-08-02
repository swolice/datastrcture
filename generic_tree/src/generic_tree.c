/*
 * generic_tree.c
 *
 *  Created on: 2016年7月7日
 *      Author: shuiting
 */

#include <stdio.h>
#include <stdlib.h>
#include "linklist_singlelist.h"
#include "generic_tree.h"

typedef struct _tag_generic_tree_node generic_tree_node;
struct _tag_generic_tree_node
{
	generic_data* data;
	generic_tree_node* parent;
	LinkList* child;
};

typedef struct _tag_tree_link_node tree_link_node;
struct _tag_tree_link_node {
	LinkListNode header;
	generic_tree_node* node;
};

static void recursive_display(generic_tree_node* node, generic_printf* p_func, int format, int gap, char div)
{
	int i=0;
	if ((node!=NULL)&&(p_func!=NULL)) {
		for (i = 0; i < format; ++i) {
			printf("%c", div);
		}
		p_func(node->data);
		printf("\n");

		for (i = 0; i < LinkList_Length(node->child); ++i) {
			tree_link_node* trnode=(tree_link_node*)LinkList_Get(node->child, i);
			recursive_display(trnode->node, p_func, format+gap, gap, div);
		}
	}
}

static void recursive_delete(LinkList* list, generic_tree_node* node)
{
	if ((list!=NULL)&&(node!=NULL)) {
		generic_tree_node* parent=node->parent;
		int index=-1;
		int i=0;

		for (i = 0; i < LinkList_Length(list); ++i) {
			tree_link_node* trnode=(tree_link_node*)LinkList_Get(list, i);
			if (trnode->node==node) {
				LinkList_Delete(list, i);
				free(trnode);
				index=i;
				break;
			}
		}

		if (index>=0) {
			if (parent!=NULL) {
				for (i = 0; i < LinkList_Length(parent->child); ++i) {
					tree_link_node* trnode=(tree_link_node*)LinkList_Get(parent->child,i);
					if (trnode->node==node) {
						LinkList_Delete(parent->child, i);
						free(trnode);
						break;
					}
				}
			}
			while(LinkList_Length(node->child)>0)
			{
				tree_link_node* trnode=(tree_link_node*)LinkList_Get(node->child, 0);
				recursive_delete(list, trnode->node);
			}

			LinkList_Destroy(node->child);
			free(node);
		}
	}
}

static int recursive_height(generic_tree_node* node) {
	int ret=0;
	if (node!=NULL) {
		int subheight=0;
		int i=0;
		for (i = 0; i < LinkList_Length(node->child); ++i) {
			tree_link_node* trnode=(tree_link_node*)LinkList_Get(node->child,i);

			subheight=recursive_height(trnode->node);
			if (ret<subheight) {
				ret=subheight;
			}
		}
		ret=ret+1;
	}
	return ret;
}

static int recursive_degree(generic_tree_node* node)
{
	int ret=-1;
	if (node!=NULL) {
		int subdegree=0;
		int i=0;
		ret=LinkList_Length(node->child);
		for (i = 0; i < LinkList_Length(node->child); ++i) {
			tree_link_node* trnode=(tree_link_node*)LinkList_Get(node->child,i);
			subdegree=recursive_degree(trnode->node);

			if (ret<subdegree) {
				ret=subdegree;
			}
		}
	}

	return ret;
}


generic_tree* generic_tree_create() {

	return LinkList_Create();

}
void generic_tree_destory(generic_tree* tree)
{
	generic_tree_clear(tree);
	LinkList_Destroy(tree);
}
void generic_tree_clear(generic_tree* tree){
	generic_tree_delete(tree, 0);
}
int generic_tree_insert(generic_tree* tree, generic_data* data, int npos){
	LinkList* list=(LinkList*)tree;
	int ret=(list=NULL)&&(data!=NULL)&&(npos<LinkList_Length(list));

	if (ret) {
		tree_link_node* trnode=(tree_link_node*)malloc(sizeof(tree_link_node));
		tree_link_node* cldnode=(tree_link_node*)malloc(sizeof(tree_link_node));
		tree_link_node* pnode=(tree_link_node*)LinkList_Get(list, npos);
		generic_tree_node* cnode=(generic_tree_node*)malloc(sizeof(generic_tree_node));

		ret=(trnode!=NULL)&&(cldnode!=NULL)&&(cnode!=NULL);

		if (ret) {
			cnode->data=data;
			cnode->parent=NULL;
			cnode->child=LinkList_Create();

			trnode->node=cnode;
			cldnode->node=cnode;

			LinkList_Insert(list, (LinkListNode*)trnode, LinkList_Length(list));

			if (pnode!=NULL) {
				cnode->parent=pnode->node;
				LinkList_Insert(pnode->node->child, (LinkListNode*)cldnode, LinkList_Length(pnode->node->child));
			}
		}else {
			free(trnode);
			free(cldnode);
			free(cnode);
		}
	}

	return ret;
}
generic_data* generic_tree_delete(generic_tree* tree, int pos) {
	tree_link_node* trnode=(tree_link_node*)LinkList_Get(tree, pos);
	generic_tree_node* ret=NULL;

	if (trnode!=NULL) {
		ret=trnode->node->data;

		recursive_delete(tree, trnode->node);
	}

	return ret;
}
generic_data* generic_tree_get(generic_tree* tree, int pos){
	tree_link_node* trnode=(tree_link_node*)LinkList_Get(tree, pos);
	generic_tree_node* ret=NULL;

	if (trnode!=NULL) {
		ret=trnode->node->data;
	}

	return ret;
}
generic_data* generic_tree_root(generic_tree* tree){
	return generic_tree_get(tree, 0);
}
int generic_tree_height(generic_tree* tree){
	tree_link_node* trnode=(tree_link_node*)LinkList_Get(tree, 0);
	int ret=0;
	if (trnode!=NULL) {
		ret=recursive_height(trnode->node);
	}
	return ret;
}


int generic_tree_count(generic_tree* tree){
	return LinkList_Length(tree);
}
int generic_tree_degree(generic_tree* tree){
	tree_link_node* trnode=(tree_link_node*)LinkList_Get(tree,0);
	int ret=-1;
	if (trnode!=NULL) {
		ret=recursive_degree(trnode->node);
	}

	return ret;
}
void generic_tree_display(generic_tree* tree, generic_printf* p_func, int gap, char div){
	tree_link_node* trnode=(tree_link_node*)LinkList_Get(tree, 0);

	if ((trnode!=NULL)&&(p_func!=NULL)) {
		recursive_display(trnode->node, p_func, 0, gap, div);

	}
}

