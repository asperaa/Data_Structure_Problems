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


struct node* oddEven(struct node** refHead)
{
	struct node* oddStart=NULL;
	struct node* oddEnd=NULL;
	struct node* evenStart=NULL;
	struct node* evenEnd=NULL;

	struct node* curPtr=*refHead;

	while(curPtr!=NULL)
	{
		if((curPtr->data)%2==1)
		{
			if(oddStart==NULL)
			{
				oddStart=curPtr;
				oddEnd=curPtr;

			}

			else
			{
				oddEnd->next=curPtr;
				oddEnd=curPtr;
			}
		}

		else
		{
			if(evenStart==NULL)
			{
				evenStart=curPtr;
				evenEnd=curPtr;
			}

			else
			{
				evenEnd->next=curPtr;
				evenEnd=curPtr;

			}
		}


		curPtr=curPtr->next;
	}

	evenEnd->next=oddStart;
	oddEnd->next=NULL;


	return evenStart;
}


int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);
   // printList(&head);
    
    //head=delDup(&head);
    head=oddEven(&head);
    printList(&head);


	return 0;
}