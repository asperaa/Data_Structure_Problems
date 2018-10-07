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

int count(struct node* root)
{

	if(root==NULL)
		return 0;
	
	if(root->left==NULL && root->right==NULL)
	{
        return 1;
	}
    
    // if(root->left==NULL && root->right!=NULL)
    // 	return count(root->right);
    
    // if(root->left!=NULL && root->right==NULL)
    // 	return count(root->left);

	return count(root->left)+count(root->right);

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

	cout<<count(root);

	return 0;
}