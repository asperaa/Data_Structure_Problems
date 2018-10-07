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


void inOrder(struct node* root)
{
	if(root==NULL)
		return;

	inOrder(root->left);

	cout<<root->data<<"\n";

	inOrder(root->right);
}


void preOrder(struct node* root)
{
	if(root==NULL)
		return;
    
    cout<<root->data<<"\n";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct node* root)
{
	if(root==NULL)
		return;
    
    postOrder(root->left);
	postOrder(root->right);
    cout<<root->data<<"\n";
	
}







int main()
{
	struct node* root=newNode(1);

	root->left=newNode(2);
	root->right=newNode(3);

	root->left->left=newNode(4);
	root->left->right=newNode(5);

	root->right->left=newNode(6);

    cout<<"Inorder traversal\n";
	inOrder(root);

    cout<<"\npreOrder traversal\n";
    preOrder(root);

    cout<<"\npostOrder traversal\n";
    postOrder(root);

	return 0;
}