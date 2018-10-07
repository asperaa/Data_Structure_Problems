#include <bits/stdc++.h>

using namespace std;

struct node {

int data;
struct node* next;

};

int main()
{
	struct node* head;

	head=(struct node*)malloc(sizeof(struct node));

	head->data=22;
    head->next=NULL;
    
   
	cout<<head->data<<endl;


	return 0;

}