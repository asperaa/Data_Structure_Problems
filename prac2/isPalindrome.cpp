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




bool isPalindromeUtil(struct node** left,struct node* right)
{
    if(right==NULL)
    	return true;

    bool isp;

    isp=isPalindromeUtil(left,right->next);

    if(isp==false)
    	return false;

    if((*left)->data==right->data)
    	isp=true;

    *left=(*left)->next;

    return isp;
}

bool isPalindrome(struct node* head)
{
	return isPalindromeUtil(&head,head);
}




int main()
{
	struct node* head=NULL;

	head=addDataEnd(&head);
	printList(&head);

	if(isPalindrome(head))
		cout<<"1";
	else
		cout<<"0";
}