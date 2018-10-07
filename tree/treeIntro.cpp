#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;

	node->right=NULL;
	node->left=NULL;

	return (node);
}


int main()
{
	struct node* root;
	root=newNode(1);

	root->left=newNode(2);
	root->right=newNode(3);

	root->
}