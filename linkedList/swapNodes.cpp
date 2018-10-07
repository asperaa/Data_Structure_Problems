#include <bits/stdc++.h>
//Doesn't handle the case when head is one of the key  value
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

struct node* swapNodes(struct node** refHead,int fNode,int sNode)
{
	struct node* prevfNode;
	struct node* prevsNode;
	struct node* nextfNode;
	struct node* nextsNode;
	struct node* curfNode=NULL;
	struct node* cursNode=NULL;

	int flagF=0,flagS=0;

	struct node* temp=*refHead;



	while(temp->next!=NULL)
	{
		prevfNode=temp;
		//temp=temp->next;
		

		if(temp->data==fNode)
		{
			flagF=1;
			curfNode=temp;
			nextfNode=temp->next;
			
			break;
		}
	
		

	}


	

	temp=*refHead;



	while(temp->next!=NULL)
	{
		prevsNode=temp;
		temp=temp->next;
		if(temp->data==sNode)
		{	
			flagS=1;
			cursNode=temp;
			nextsNode=temp->next;
			
			break;
		}
		
	}


	if(curfNode==prevsNode && flagS==1 && flagS==1)
	{
		prevfNode->next=cursNode;
		cursNode->next=curfNode;

		curfNode->next=nextsNode;

	}

	else if(flagF==1 && flagS==1)
	{
		prevfNode->next=cursNode;
		cursNode->next=nextfNode;

		prevsNode->next=curfNode;
		curfNode->next=nextsNode;
	}

	else
		cout<<"One of the given values are not present"<<endl;


	return *refHead;

}

int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);

	int firstData,secondData;
	cin>>firstData>>secondData;

	head=swapNodes(&head,firstData,secondData);

	printList(head);
}