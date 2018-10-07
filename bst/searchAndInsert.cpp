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


struct node* search(struct node* root,int key)
{
	if(root==NULL || root->data==key)
		return root;

	if(key<root->data)
		return search(root->left,key);

	if(key>root->data)
		return search(root->right,key);
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

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
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
  
    inorder(root);
  
    return 0;
}