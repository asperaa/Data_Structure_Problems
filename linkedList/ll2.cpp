#include <bits/stdc++.h>

using namespace std;

struct node{

int data;
struct node* next;
};


void printNode(struct node* head)
{
	struct node* mover;
	mover=head;
	while(mover!=NULL)
	{
		cout<<mover->data<<endl;
		mover=mover->next;
	}
}

struct node* addData()
{
	int nodeData;
	cin>>nodeData;

	struct node* head;
	head=(struct node*)malloc(sizeof(struct node));

	head->data=nodeData;
	head->next=NULL;

	struct node* prevNode=head;

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

	return head;
}




int main()
{
	
	struct node* head=addData();
	
	printNode(head);

}