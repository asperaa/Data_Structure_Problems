#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

int main()
{
	Node* head=(Node*)malloc(sizeof(Node));
	head->data=1;

	Node* node2=(Node*)malloc(sizeof(Node));
	node2->data=2;

	head->next=node2;

	Node* node3=(Node*)malloc(sizeof(Node));
	node3->data=3;

	node2->next=node3;

	Node* mover=head;

	while(mover!=NULL)
	{
		cout<<mover->data<<" ";
		mover=mover->next;
	}
}