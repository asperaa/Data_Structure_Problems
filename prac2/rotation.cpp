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


struct node* rotate(struct node** refHead,int k)
{
	struct node* oldHead=*refHead;
	struct node* newHead=*refHead;
    struct node* prevHead=*refHead;
	while(k--)
	{   prevHead=newHead;
		newHead=newHead->next;
	}

	prevHead->next=NULL;

	struct node* temp=newHead;

	while(temp->next!=NULL)
		temp=temp->next;

   temp->next=oldHead;

   return newHead;
}


int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);
   // printList(&head);
    
    //head=delDup(&head);
    head=rotate(&head,4);
    printList(&head);


	return 0;
}