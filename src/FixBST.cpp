/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void swap_nodes(struct node *a, struct node*b);
void inorder_check(struct node* root, struct node** swaplist,int* index);
void inorder_check(struct node* root, struct node** swaplist,int* index){
	if (*index == 2 || root == NULL)
		return;
	if (root->left != NULL && root->data < root->left->data)
		swaplist[(*index)++] = root->left;
	if (root->right != NULL && root->data > root->right->data && *index != 2)
		swaplist[(*index)++] = root->right;
	inorder_check(root->left, swaplist, index);
	inorder_check(root->right, swaplist, index);
	return;
}

void swap_nodes(struct node *a, struct node*b){
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}


void fix_bst(struct node* root){
	if (root != NULL){
		struct node** swaplist = (struct node**)malloc(sizeof(struct node*) * 2);
		swaplist[0] = NULL;
		swaplist[1] = NULL;
		int index = 0;
		inorder_check(root, swaplist,&index);
		if (swaplist[1] == NULL){
			if (swaplist[0]->left != NULL && swaplist[0]->data < swaplist[0]->left->data)
				swaplist[1] = swaplist[0]->left;
			else if (swaplist[0]->right != NULL && swaplist[0]->data > swaplist[0]->right->data)
				swaplist[1] = swaplist[0]->right;
			else
				swaplist[1] = root;
		}
		swap_nodes(swaplist[0], swaplist[1]);
	}
	return;
}