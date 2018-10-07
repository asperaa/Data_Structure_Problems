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

	return (treeNode);
}


int findMaxUtil(struct node* root,int &res)
{
	if(root==NULL)
		return 0;

	int ls=findMaxUtil(root->left,res);
	int rs=findMaxUtil(root->right,res);

	int max_single=max(max(ls,rs)+root->data,root->data);

	int max_top=max(max_single,ls+rs+root->data);

	res=max_top;

	return max_single;
}

int findMax(struct node* root)
{
	int res=INT_MIN;

	findMaxUtil(root,res);
	return res;
}

int main()
{
	struct node* root=newNode(3);

	root->left=newNode(2);
	root->right=newNode(1);

	root->left->left=newNode(4);
	root->left->right=newNode(5);

	root->right->left=newNode(6);
	//root->right->right=newNode(7);

	cout<<findMax(root);

	return 0;
}