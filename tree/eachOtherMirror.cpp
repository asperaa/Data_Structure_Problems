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

bool isMirror(struct node* a,struct node* b)
{
	if(a==NULL && b==NULL)
		return true;

	if(a==NULL || b==NULL)
		return false;

	bool res=(a->data==b->data && isMirror(a->left,b->right) && isMirror(a->right,b->left) ); 
}



int main()
{
	struct node* a=newNode(1);

	a->left=newNode(2);
	a->right=newNode(3);

	a->left->left=newNode(4);
	a->left->right=newNode(5);

	a->right->left=newNode(6);
	a->right->right=newNode(7);

	struct node* b=newNode(1);

	b->left=newNode(3);
	b->right=newNode(2);

	b->left->left=newNode(7);
	b->left->right=newNode(6);

	b->right->left=newNode(5);
	b->right->right=newNode(4);

	cout<<isMirror(a,b)<<endl;

	return 0;
}