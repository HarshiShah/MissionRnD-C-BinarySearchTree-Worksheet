/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};


void inorder2(struct node *root, int *arr, int* index);
void preorder2(struct node *root, int *arr, int* index);
void postorder2(struct node *root, int *arr, int* index);


void inorder(struct node *root, int *arr){
	if (arr != NULL){
		int index = -1;
		inorder2(root, arr, &index);
	}
	return;
}

void preorder(struct node *root, int *arr){
	if (arr != NULL){
		int index = -1;
		preorder2(root, arr, &index);
	}
	return;
}

void postorder(struct node *root, int *arr){
	if (arr != NULL){
		int index = -1;
		postorder2(root, arr, &index);
	}
	return;
}

void inorder2(struct node *root, int *arr, int* index){
	if (root != NULL){
		inorder2(root->left, arr, index);
		*index = *index + 1;
		arr[*index] = root->data;
		inorder2(root->right, arr, index);
	}
	return;
}

void preorder2(struct node *root, int *arr, int* index){
	if (root != NULL){
		*index = *index + 1;
		arr[*index] = root->data;
		preorder2(root->left, arr, index);
		preorder2(root->right, arr, index);
	}
	return;
}

void postorder2(struct node *root, int *arr, int* index){
	if (root != NULL ){
		postorder2(root->left, arr, index);
		postorder2(root->right, arr, index);
		*index = *index + 1;
		arr[*index] = root->data;

	}
	return;
}
