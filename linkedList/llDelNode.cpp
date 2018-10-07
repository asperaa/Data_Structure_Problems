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



struct node* deletePosition(struct node** refHead)
{
	int nodePos;

	while(1)
	{
		cin>>nodePos;

		if(nodePos==-100)
			break;

		struct node* prevNode=(struct node*)malloc(sizeof(struct node));
		prevNode=*refHead;

		if(nodePos==0)
		{
			*refHead=prevNode->next;

			delete prevNode;

			continue;
		}



		for(int i=0;i<nodePos-1 && prevNode->next!=NULL;i++)
			prevNode=prevNode->next;

		if(prevNode->next==NULL)
		{
			cout<<"Out of bounds position"<<endl;
			continue;
		}


		struct node* savedNode=prevNode->next->next;

		delete prevNode->next;

		prevNode->next=savedNode;



	}

	return *refHead;

}


int main()
{
	struct node* head=NULL;
	
	addDataEnd(&head);

	deletePosition(&head);

	printList(head);

}