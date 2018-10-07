#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
	struct node* nextRight;
};

struct node* newNode(int data)
{
	struct node* treeNode=(struct node*)malloc(sizeof(struct node));

	treeNode->data=data;
	treeNode->left=NULL;
	treeNode->right=NULL;
	treeNode->nextRight=NULL;

	return treeNode;
}


void connectRecur(struct node* root)
{
	if(!root)
		return;

	if(root->left)
		root->left->nextRight=root->right;

	if(root->right)
		root->right->nextRight=(root->nextRight)?root->nextRight->left:NULL;


	connectRecur(root->left);
	connectRecur(root->right);




}



void connect(struct node* root)
{
	root->nextRight=NULL;

	connectRecur(root);
}

int main()
{
 
  /* Constructed binary tree is
            10
          /   \
        8      2
      /
    3
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
 
  // Populates nextRight pointer in all nodes
  connect(root);
 
  // Let us check the values of nextRight pointers
  printf("Following are populated nextRight pointers in the tree "
    "(-1 is printed if there is no nextRight) \n");
  printf("nextRight of %d is %d \n", root->data,
   root->nextRight? root->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->data,
   root->left->nextRight? root->left->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->right->data,
   root->right->nextRight? root->right->nextRight->data: -1);
  printf("nextRight of %d is %d \n", root->left->left->data,
   root->left->left->nextRight? root->left->left->nextRight->data: -1);
  return 0;
}