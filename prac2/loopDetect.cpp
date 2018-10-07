#include <bits/stdc++.h>

using namespace std;

struct node {

	int data;
	struct node* next;
	bool marked;

};



struct node* addDataEnd(struct node** refHead)
{
	int nodeData;

	if(*refHead==NULL)
	{
		cin>>nodeData;
		struct node* nextNode=(struct node*)malloc(sizeof(struct node));
		nextNode->data=nodeData;
		nextNode->marked=false;
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
	nextNode->marked=false;
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

int loopDetect(struct node** refHead)
{
	struct node* mover=*refHead;

	while(mover!=NULL)
	{
		if(mover->marked==true)
			return 1;
        
        mover->marked=true;
		mover=mover->next;
	}

	return 0;
}


int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);
    
   // head->next->next->next=head;
	//printList(&head);
    cout<<loopDetect(&head);

	return 0;
}