#include <bits/stdc++.h>

using namespace std;

struct node{

	int data;
	struct node* next;
};


// void appendToTail(int data,struct node* head)
// {
//     struct node* newNode=(struct node*)malloc(sizeof(struct node));
//     newNode->data=data;

//     struct node* temp;

//     while(temp->next!=NULL)
//     {
//         temp=temp->next;
//     }

//     temp->next=newNode


// }

int main()
{
	struct node* head=(struct node*)malloc(sizeof(struct node));

	head->data=1;
	head->next=NULL;

	

   
    int n;
    cin>>n;
    
    struct node* prevNode=head;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data;

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        prevNode->next=newNode;
        newNode->data=data;
        newNode->next=NULL;
        prevNode=newNode;


    }


    struct node* mover;
    mover=head;
    
    while(mover!=NULL)
    {
    	cout<<mover->data<<endl;
    	mover=mover->next;
    }

    return 0;

}