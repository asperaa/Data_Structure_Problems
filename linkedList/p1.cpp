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
	head->next=NULL;

	cout<<head->data<<endl;
	
}