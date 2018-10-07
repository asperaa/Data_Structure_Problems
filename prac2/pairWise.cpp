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


struct node* pairWiseSwap(struct node** refHead)
{
	struct node* curNode=*refHead;
	while(curNode->next!=NULL)
	{
		swap(curNode->data,curNode->next->data);
		curNode=curNode->next->next;

		if(curNode==NULL)
			break;
	}

	return *refHead;

}

void pairWiseSwapRecur(struct node* head)
{
   struct node* temp=head;

   if(temp==NULL)
   	return;

   if(temp->next==NULL)
   return;

   pairWiseSwapRecur(temp->next->next);

   swap(temp->data,temp->next->data);

   return;	 
}


int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);
   
   // printList(&head);
	//head=pairWiseSwap(&head);
	pairWiseSwapRecur(head)
	printList(&head);


	return 0;
}