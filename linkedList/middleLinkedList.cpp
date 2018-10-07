#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node* next;
};



struct node* addDataEnd(struct node** refHead)
{
	int nodeData;
	
	

	if(*refHead==NULL)								//Check if the you are starting the node from scratch
	{
		cin>>nodeData;
		

		struct node* nextNode=(struct node*)malloc(sizeof(struct node));
		nextNode->data=nodeData;
		nextNode->next=NULL;

		*refHead=nextNode;
	}

	struct node* prevNode=*refHead;				//prevNode is the iterator here

	while(prevNode->next!=NULL)				//Iterate to the end of linked list.
		prevNode=prevNode->next;

	while(1)
	{
		cin>>nodeData;
		

		if(nodeData==-100)
			break;

		struct node* nextNode=(struct node*)malloc(sizeof(struct node));

		prevNode->next=nextNode;
		nextNode->data=nodeData;
		prevNode=nextNode;


	}

	prevNode->next=NULL;

	return *refHead;						//return the address of the head.
}


void printList(struct node* head)
{
	struct node* mover;
	mover=head;
	while(mover!=NULL)
	{
		cout<<mover->data<<endl;
		mover=mover->next;
	}
}


int midLinkedList(struct node* head)
{
	struct node* slowptr=head;
	struct node* fastptr=head;

	while(fastptr->next!=NULL && fastptr->next->next!=NULL)
	{
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;
	}

	if(fastptr->next==NULL)
		return slowptr->data;
	else
		return slowptr->next->data;

}

int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);

	cout<<midLinkedList(head)<<endl;

	//printList(head);
}