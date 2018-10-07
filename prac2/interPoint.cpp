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

int interPointH(struct node** a,struct node** b)
{
	struct node* headA=*a;
	struct node* headB=*b;
   
    set<struct node*>s;

    while(headA!=NULL)
    {
    	s.insert(headA);
    	headA=headA->next;
    }

    while(headB!=NULL)
    {
    	if(s.find(headB)!=s.end())
    		return headB->data;

    	s.insert(headB);
    	headB=headB->next;
    }

    return 0;


}


int interPointE(struct node** a,struct node** b)
{
	struct node* headA=*a;
	struct node* headB=*b;

	struct node* tempA=headA;
    struct node* tempB=headB;


	int na=0;
	int nb=0;
	int d=0;

	while(headA!=NULL)
	{
		na++;
		headA=headA->next;
	}

	while(headB!=NULL)
	{
		nb++;
		headB=headB->next;
	}

	d=abs(na-nb);
    
	while(d--)
	{
		if(na>nb)
			tempA=tempA->next;
		else
			tempB=tempB->next;

	}


	while(tempB!=NULL && tempA!=NULL)
	{
		if(tempB==tempA)
		{
			return tempA->data;
		}

		tempA=tempA->next;
		tempB=tempB->next;
	}

	return 0;
}

int main()
{
	struct node* l1=NULL;
	struct node* l2=NULL;

	l1=addDataEnd(&l1);
	l2=addDataEnd(&l2);
     
 
    
    l2->next->next=l1->next->next->next;

    int num=interPointE(&l1,&l2);
    if(num!=0)
    	cout<<"YES "<<num;
    else
    	cout<<"NO";


	return 0;
}