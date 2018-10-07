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

void printLevelOrder(struct node* root)
{

  if(root==NULL)
  	return;

  queue <node*>q;
  
  q.push(root);
  
  while(!q.empty())
  {
      struct node* temp=q.front();

      cout<<temp->data<<endl;

      q.pop();

      if(temp->left!=NULL) 	
         q.push(temp->left);
     
      if(temp->right!=NULL)
         q.push(temp->right);
     
  }

  

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