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
	struct node* treeNode=(struct node*)malloc(sizeof(struct node));

	treeNode->data=data;

	treeNode->left=NULL;
	treeNode->right=NULL;

	return treeNode;
}

int height(struct node* root)
{
	if(root==NULL)
		return 0;

	return ( 1 + max(height(root->left),height(root->right)));
}

int dia(struct node* root)
{
	if(root==NULL)
		return 0;

	int lh=height(root->left);
	int rh=height(root->right);

	int ld=dia(root->left);
	int rd=dia(root->right);

	return max(lh+rh+1,max(ld,rd));

	
}


int main()
{
	struct node* root=newNode(3);

	root->left=newNode(2);
	root->right=newNode(1);

	root->left->left=newNode(4);
	root->left->right=newNode(5);

	root->right->left=newNode(6);

	cout<<dia(root);

	return 0;
}


