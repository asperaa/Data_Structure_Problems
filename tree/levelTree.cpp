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

int height(struct node* root)
{
	if(root==NULL)
	{
		return 0;
	}

	else
	{
		int lh=height(root->left);
		int rh=height(root->right);


		if(lh>rh)
			return (lh+1);
		return(rh+1);
	}
}


void printGivenLevel(struct node* root,int level)
{

  if(root==NULL)
  	return;

  else if(level==1)
  	cout<<root->data<<endl;

  else
  {
  	printGivenLevel(root->left,level-1);
  	printGivenLevel(root->right,level-1);
  }

}

void printLevelOrder(struct node* root)
{
	int h=height(root);

	for(int i=1;i<=h;i++)
		printGivenLevel(root,i);
}


int main()
{
	struct node* root=newNode(3);

	root->left=newNode(2);
	root->right=newNode(1);

	root->left->left=newNode(4);
	root->left->right=newNode(5);

	root->right->left=newNode(6);

	printLevelOrder(root);

	return 0;
}