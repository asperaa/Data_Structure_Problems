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

int IterLength(struct node** refHead)
{
	struct node* cnt=*refHead;
	int count=0;
	while(cnt!=NULL)
	{

		cnt=cnt->next;
		count++;
	}

	return count;
}

int RecurLength(struct node* Head)
{
	struct node* cnt=Head;

	if(cnt==NULL)	
		return 0;
	return 1+RecurLength(cnt->next);
}

int iterSearch(int key,struct node** refHead)
{
	struct node* curPtr=*refHead;

	while(curPtr->data!=key && curPtr!=NULL)
	{
		curPtr=curPtr->next;
	}

	if(curPtr!=NULL)
		return curPtr->data;
	else
		return 0;


   
}


int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);

	cout<<"Length(Iterative):"<<IterLength(&head)<<endl;

	cout<<"Length(Recursive):"<<RecurLength(head)<<endl;

}