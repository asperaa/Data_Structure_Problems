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


struct node* addDataBegin(struct node** refHead,int nodeData)
{
	

	
    struct node* curNode=*refHead;
    
    struct node* nextNode=(struct node*)malloc(sizeof(struct node));

	nextNode->data=nodeData;

	nextNode->next=curNode;
    curNode=nextNode;

	

	*refHead=curNode;

	return *refHead;

	


}

struct node* sumDigit(struct node** a,struct node** b)
{
	struct node* tempA=*a;
	struct node* tempB=*b;

	int carry=0;
    
    struct node* ansLL=NULL;

	while(tempA!=NULL && tempB!=NULL)
	{
		int add=tempA->data+tempB->data +carry;

		int ans=add%10;

		carry=add/10;
        //cout<<ans<<endl;
        ansLL=addDataBegin(&ansLL,ans);

        tempA=tempA->next;
        tempB=tempB->next;


	}

	return ansLL;

}






int main()
{
	struct node* l1=NULL;
	struct node* l2=NULL;

	l1=addDataEnd(&l1);
	l2=addDataEnd(&l2);
     
    struct node* ans=sumDigit(&l1,&l2);
     
    // if(ans==NULL)
     //	cout<<"YES";

    printList(&ans);
    
    

	return 0;
}









