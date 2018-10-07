#include <bits/stdc++.h>

using namespace std;

struct node{

int data;
struct node* next;
};

int main()
{
	struct node* head;

	head=(struct node*)malloc(sizeof(struct node));

	head->data=1;
	head->next=NULL;

	cout<<head->data<<endl;

	struct node* node2;

	node2=(struct node*)malloc(sizeof(struct node));

	head->next=node2;
	node2->data=3;

	//node2->next=NULL;

	cout<<node2->data<<endl;

	struct node* node3;

	node3=(struct node*)malloc(sizeof(struct node));

	node2->next=node3;
	node3->data=4;

	node3->next=NULL;

	struct node* mover;
	mover=head;
	while(mover!=NULL)
	{
		cout<<mover->data<<endl;
		mover=mover->next;
	}


	
}