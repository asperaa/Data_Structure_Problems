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

bool sameTree(struct node* root1,struct node* root2)
{
	if(root1==NULL && root2==NULL)
		return true;

	else if(root1!=NULL && root2!=NULL)
	{
		bool sameData=(root1->data == root2->data);

		bool ls=sameTree(root1->left,root2->left);

		bool rs=sameTree(root1->right,root2->right);

		return (sameTree && ls && rs);
	}

	else
		return false;
}



int main()
{
	struct node* root1=newNode(3);

	root1->left=newNode(2);
	root1->right=newNode(1);

	root1->left->left=newNode(4);
	root1->left->right=newNode(5);

	root1->right->left=newNode(6);
	//root1->right->right=newNode(7);

	struct node* root2=newNode(3);

	root2->left=newNode(2);
	root2->right=newNode(1);

	root2->left->left=newNode(4);
	root2->left->right=newNode(5);

	root2->right->left=newNode(6);
	//root->right->right=newNode(7);

	cout<<sameTree(root1,root2);

	return 0;
}




