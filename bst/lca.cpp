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

struct node* lcaR(struct node* root,int n1,int n2)
{
	if(root==NULL)
		return NULL;

	if(root->data>n1 && root->data>n2)
		return lcaR(root->left,n1,n2);

	if(root->data<n1 && root->data<n2)
       return lcaR(root->right,n1,n2);

    return root;
 }



 struct node* lcaI(struct node* root,int n1,int n2)
 {
 	while(root!=NULL)
 	{


 		if(root->data > n1 && root->data >n2 )
 			root=root->left;

 		else if(root->data < n1 && root->data < n2)
 			root=root->right;
        
        else
        	break;

 	}

 	return root;
 }


 int main()
{
    // Let us construct the BST shown in the above figure
    struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
 
    int n1 = 10, n2 = 14;
    struct node *t = lcaR(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lcaR(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lcaR(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    return 0;
}