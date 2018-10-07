#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void printList(Node* head)
{
	Node* mover=head;

	while(mover!=NULL)
	{
		cout<<mover->data<<" ";
		mover=mover->next;

	}
}

Node* addEnd(Node** refHead,int data)
{
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;

	if(*refHead==NULL)
	{
		*refHead=newNode;

		return *refHead;
	}
    
    Node* mover=*refHead;

    while(mover->next!=NULL)
    {
    	mover=mover->next;
    }

    mover->next=newNode;

    return *refHead;



}

Node* addBegin(Node** refHead,int data)
{
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;

	if(*refHead==NULL)
	{
		*refHead=newNode;
		newNode->next=NULL;
		return *refHead;
	}

    newNode->next=*refHead;
    *refHead=newNode;

    return *refHead;

}

Node* addNodeAfter(Node* previous,Node** refHead,int data)
{

	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;

	Node* mover=*refHead;

	while(mover!=previous)
	{
		mover=mover->next;
	}

	newNode->next=previous->next;
	previous->next=newNode;

	return *refHead;

}


int main()
{

	Node* head=NULL;

	head=addEnd(&head,1);
    head=addEnd(&head,2);
    head=addEnd(&head,3);

    head=addBegin(&head,4);
    head=addBegin(&head,5);


    head=addNodeAfter(head->next->next,&head,6);
	printList(head);
}