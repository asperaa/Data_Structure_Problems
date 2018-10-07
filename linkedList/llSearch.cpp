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


bool iterSearch(struct node* head)
{
	int searchKey;

	struct node* temp=head;

	cin>>searchKey;

	while(temp!=NULL)
	{
		if(temp->data==searchKey)
			return true;
		temp=temp->next;

	}

	return false;
	
}

bool recurSearch(struct node* head,int searchKey)
{
	

	struct node* temp=head;
	if(temp==NULL)
		return false;

	if(temp->data==searchKey)
		return true;
	else
		return recurSearch(temp->next,searchKey);
}

int main()
{
	struct node* head=NULL;
	head=addDataEnd(&head);

	if(iterSearch(head))
		cout<<"Yes"<<endl; 
	else
		cout<<"No"<<endl;


	int searchKey;
	cin>>searchKey;
	
	if(recurSearch(head,searchKey))
		cout<<"Yes"<<endl; 
	else
		cout<<"No"<<endl;


	
}