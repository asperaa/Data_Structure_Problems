#include <bits/stdc++.h>
//Handles all cases.

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


void swapNodes(struct node** refHead,int x,int y)
{

	if(x==y)
		return;

	struct node* prevX=NULL;
	struct node* currX=*refHead;
	struct node* prevY=NULL;
	struct node* currY=*refHead;

	while(currX && currX->data!=x)
	{
		prevX=currX;
		currX=currX->next;
	}


	while(currY && currY->data!=y)
	{
		prevY=currY;
		currY=currY->next;
	}


	if(currX==NULL || currY==NULL)
		return;

	if(prevX!=NULL)
		prevX->next=currY;
	else
		*refHead=currY;


	if(prevY!=NULL)
		prevY->next=currX;
	else
		*refHead=currX;


	struct node* temp=currX->next;

	currX->next=currY->next;

	currY->next=temp;



}

int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);

	int firstData,secondData;
	cin>>firstData>>secondData;

	swapNodes(&head,firstData,secondData);

	printList(head);
}