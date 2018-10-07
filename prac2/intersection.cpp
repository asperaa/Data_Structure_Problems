#include <bits/stdc++.h>

using namespace std;

struct node {

	int data;
	struct node* next;

};



struct node* addDataEnd(struct node** refHead)
{
	int nodeData;

	if(*refHead==NULL)
	{
		cin>>nodeData;
		struct node* nextNode=(struct node*)malloc(sizeof(struct node));
		nextNode->data=nodeData;
		nextNode->next=NULL;

		*refHead=nextNode;
	}

	struct node* prevNode;

	prevNode=*refHead;

	while(prevNode->next!=NULL)
		prevNode=prevNode->next;

  while(1)
  {

  	cin>>nodeData;
    if(nodeData==-100)
    	break;
    
	struct node* nextNode=(struct node*)malloc(sizeof(struct node));
	
	nextNode->data=nodeData;
	prevNode->next=nextNode;

	prevNode=nextNode;
   
   }

   prevNode->next=NULL;

	return *refHead;
}


void printList(struct node** refHead)
{
	struct node* mover=*refHead;

	while(mover!=NULL)
	{
		cout<<mover->data<<endl;
		mover=mover->next;
	}
}


struct node* inter(struct node* a,struct node* b)
{
	if(a==NULL || b==NULL)
		return NULL;

	if(a->data<b->data)
		return inter(a->next,b);

	if(a->data>b->data)
		return inter(a,b->next);

	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=a->data;

	temp->next=inter(a->next,b->next);

	return temp;
}

int main()
{
	struct node* l1=NULL;
	struct node* l2=NULL;

	l1=addDataEnd(&l1);
	l2=addDataEnd(&l2);
     
   struct node* head=inter(l1,l2);
	printList(&head);


	return 0;
}

