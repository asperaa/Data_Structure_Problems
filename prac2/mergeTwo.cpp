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



struct node* merge(struct node** a,struct node** b)
{
	struct node* tempA=*a;
	struct node* tempB=*b;
    struct node* newS=NULL;
    struct node* newE=NULL;
    struct node* prevA=NULL;
    struct node* prevB=NULL;

	while(tempA!=NULL && tempB!=NULL)
	{
		if(tempA->data <= tempB->data)
		{
			if(newS==NULL)
			{
				newS=tempA;
				newE=tempA;
			}
            
            else
            {
            	newE=tempA;
            	newE=newE->next;
            }

            prevA=tempA;
			tempA=tempA->next;

		}


		else
		{

			if(newS==NULL)
			{
				newS=tempB;
				newE=tempB;
			}

			else
			{
				newE=tempB;
				newE=newE->next;

			}

            prevB=tempB;
			tempB=tempB->next;

		}
       

       
	}


	if(tempA==NULL)
	   prevA->next=tempB;
	

	if(tempB==NULL)
		prevB->next=tempA;


	return newS;



}




int main()
{
	struct node* l1=NULL;
	struct node* l2=NULL;

	l1=addDataEnd(&l1);
	l2=addDataEnd(&l2);
     
    struct node* ans=merge(&l1,&l2);
     
    // if(ans==NULL)
     //	cout<<"YES";

    printList(&ans);
    
    

	return 0;
}


