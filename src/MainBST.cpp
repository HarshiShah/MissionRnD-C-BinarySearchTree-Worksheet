/*
This Project will seem to be little tougher than before ones .But It can be done very easily
once you completed C-Recursion Project completely .

Note : You can use the functions specified as wrapper functions ,and write new functions 
which might take more parameters .

*/


#include <stdio.h>
#include <stdlib.h>
#include "FunctionHeadersBST.h"

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct node *newNode(int key)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


struct node* new_node_spec(int data){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node * add_node_spec(struct node *root, int data){
	if (root == NULL) return new_node_spec(data);

	if (data < root->data)
		root->left = add_node_spec(root->left, data);
	else if (data > root->data)
		root->right = add_node_spec(root->right, data);

	return root;
}


int main(){
	struct node *root = NULL;
	int nums[10] = { 30, 10, 60, 40, 70, 65, 80, 67, 90, 85 };
	int elements = 10;
	for (int i = 0; i < elements; i++){
		root = add_node_spec(root, nums[i]);
	}

	int ans[3][10] = {
		{ 10, 30, 40, 60, 65, 67, 70, 80, 85, 90 },
		{ 30, 10, 60, 40, 70, 65, 67, 80, 90, 85 },
		{ 10, 40, 67, 65, 85, 90, 80, 70, 60, 30 }
	};
	int results[3][10];
	inorder(root, results[0]);
	preorder(root, results[1]);
	postorder(root, results[2]);

	for (int i = 0; i < 1; i++){
		printf("\n");
		for (int j = 0; j < 4; j++){

			printf("\n%d -->  %d", ans[i][j], &results[i][j]);
		}
	}
	for (int i = 0; i < 3; i++){
		printf("\n");
		for (int j = 0; j < 10; j++)
			printf("%d ", results[i][j]);
	}
	return 0;
}
