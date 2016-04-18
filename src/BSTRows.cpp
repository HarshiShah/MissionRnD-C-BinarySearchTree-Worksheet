/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void Rows_BST(int* arr, int arr_index, struct node** buffer, int buff_index);


int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;
	int* arr = (int*)malloc(sizeof(int)* 10);
	struct node** buffer = (struct node**)malloc(sizeof(struct node*) * 10);
	buffer[0] = root;
	Rows_BST(arr, 0, buffer, 1);
	return arr;
}



void Rows_BST(int* arr, int arr_index, struct node** buffer, int buff_index){
	struct node* root = buffer[arr_index];
	arr[arr_index++] = root->data;
	if (root->right != NULL){
		buffer[buff_index++] = root->right;
	}
	if (root->left != NULL){
		buffer[buff_index++] = root->left;
	}
	if (root->right == NULL &&root->left == NULL && arr_index == buff_index)
		return;
	Rows_BST(arr, arr_index, buffer, buff_index);
	return;
}
