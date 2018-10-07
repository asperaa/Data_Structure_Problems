#include <bits/stdc++.h>

using namespace std;

struct node{

int data;
struct node* next;
};


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

struct node* addDataBegin(struct node** refHead)
{
	
	int nodeData;
	
	while(1)
	{
		cin>>nodeData;
		
		if(nodeData==-100)
			break;

		struct node* newNode=(struct node*)malloc(sizeof(struct node));

		newNode->data=nodeData;
		newNode->next=*refHead;
		*refHead=newNode;
		
	}

	return *refHead;

}


struct node* addDataAfter(struct node* prevNode,struct node** refHead)
{
	int nodeData;

	if(prevNode==NULL)
	{
		cout<<"Previous can't be null\n";
		return *refHead;
	}


	while(1)
	{
		cin>>nodeData;

		if(nodeData==-100)
			break;

		struct node* newNode=(struct node*)malloc(sizeof(struct node));

		newNode->data=nodeData;
		newNode->next=prevNode->next;
		prevNode->next=newNode;
	}

	return *refHead;

}


struct node* deleteKey(struct node** refHead)
{
	int key;								//Taking the input
	cin>>key;

	struct node* head=*refHead;				//initialise the finder/iterater from the reference of head

	struct node* finder=*refHead;
	struct node* prevfinder=*refHead;;


	

	if(head->data==key) 					//Case of head node having the key value
	{
		head=prevfinder->next;

		*refHead=head;

		return head;
	}




	while(finder->next!=NULL && finder->data!=key)     //Case of any of the middle node having a key value
	{
		
		prevfinder=finder;
		finder=finder->next;
	}

	if(finder->next==NULL && finder->data!=key)			//Case of not finding the key value
		return head;

	
	prevfinder->next=finder->next;						//Updating the pointer to skip the deleted node
	
		

	delete finder;                                     //deleting the (free memory) of the node                                                          
	return head;


}




int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);

	//head=deleteKey(&head);
	//head=addDataBegin(&head);

	head=addDataAfter(head->next->next,&head);
	

	
	printList(head);

}