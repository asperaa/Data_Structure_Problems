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



struct node* insert(struct node* root,int key)
{

	if(root==NULL) return newNode(key);


	if(key<root->data)
        root->left = insert(root->left,key);

    if(key>root->data)
    	root->right = insert(root->right,key);
    
    return root;
}


bool isBST(struct node* root,struct node* l=NULL,struct node* r=NULL)
{

	if(root==NULL)
    	return true;

	if(l!=NULL && l->data > root->data)
		return false;

	if(r!=NULL && r->data < root->data)
		return false;


    

	return (isBST(root->left,l,root) && isBST(root->right,root,r));


}



int main()
{
    
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
  
    cout<<isBST(root);
  
    return 0;
}