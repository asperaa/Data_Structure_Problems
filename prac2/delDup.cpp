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










struct node* delDup(struct node** refHead)
{

	struct node* curNode=*refHead;
	struct node* nextNode=(*refHead)->next;

	while(nextNode!=NULL)
	{
		if(curNode->data==nextNode->data)
		{

			curNode->next=curNode->next->next;
			delete nextNode;
			nextNode=curNode->next;
        }
        
        else
        {
         	curNode=nextNode;
         	nextNode=nextNode->next;
         }


	}

    return *refHead;
}

struct node* delDupUnsorted(struct node** refHead)
{

   struct node* curNode=*refHead;
   struct node* prevNode=*refHead;

   set<int>s;

   while(curNode!=NULL)
   {

   	if(s.find(curNode->data)!=s.end())
   	{

   		prevNode->next=prevNode->next->next;
   		delete curNode;
   		curNode=prevNode->next;
   	}

   	else
   	{
   		s.insert(curNode->data);
   		prevNode=curNode;
        curNode=curNode->next;
   	}
    
    

   }


   return *refHead;
}


int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);
   // printList(&head);
    
    //head=delDup(&head);
    head=delDupUnsorted(&head);
    printList(&head);


	return 0;
}
