#include <bits/stdc++.h>

using namespace std;

struct node{

	int data;
	struct node* next;
};

int main()
{
	struct node* head=(struct node*)malloc(sizeof(struct node));

	head->data=1;
	head->next=NULL;

	struct node* node2 = (struct node*)malloc(sizeof(struct node));
    head->next=node2;
    node2->data=2;

    struct node* node3 = (struct node*)malloc(sizeof(struct node));
    node2->next = node3;
    node3->data = 3;

    node3->next=NULL;

    struct node* mover;
    mover=head;

    while(mover!=NULL)
    {
    	cout<<mover->data<<endl;
    	mover=mover->next;
    }

    return 0;

}