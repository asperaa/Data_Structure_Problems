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



struct node* addDataBegin(struct node** refHead)
{
	int nodeData;

	
    struct node* curNode=*refHead;
    
    while(1)
    {
      cin>>nodeData;
      
      if(nodeData==-100)
      	break;
      struct node* nextNode=(struct node*)malloc(sizeof(struct node));

	  nextNode->data=nodeData;

	  nextNode->next=curNode;
      curNode=nextNode;

	}

	*refHead=curNode;

	return *refHead;

	


}

struct node* addDataAfter(struct node* prevNode,struct node** refHead)
{
	struct node* ptr;
    ptr=*refHead;

	while(ptr!=prevNode)
		ptr=ptr->next;

	struct node* temp=ptr->next;

	struct node* newNode=(struct node*)malloc(sizeof(struct node));

	int nodeData;
	cin>>nodeData;

	newNode->data=nodeData;

	ptr->next=newNode;
	newNode->next=temp;

	return *refHead;
}


struct node* deleteKey(int key,struct node** refHead)
{

	struct node* finder;
	struct node* prevFinder;
    
    finder=*refHead;
    prevFinder=finder;
    
   if(finder->data==key)
   {
   	finder=finder->next;
   }

   *refHead=finder;

   




	while(finder->data!=key)
	{
		
		prevFinder=finder;
		finder=finder->next;
        
        if(finder==NULL)
            break;		

	}

	
    if(finder!=NULL)
	   prevFinder->next=finder->next;
    

    delete finder;
	return *refHead;
	



}


struct node* deletePos(struct node** refHead)
{
	int nodePos;

	while(1)
	{


        cin>>nodePos;

        if(nodePos==-100)
        	break;

        int count=0;
        
        struct node* finder;
        struct node* prevFinder;
        struct node* head=*refHead;
        finder=*refHead;
        prevFinder=finder;
        

        if(nodePos==1)
        {
        	finder=finder->next;
        	*refHead=finder;
        	continue;
        }
        


        nodePos--;

        while(nodePos-- && finder!=NULL)
        {
        	
        	prevFinder=finder;
        	finder=finder->next;
        	

        }

        if(finder!=NULL)
           prevFinder->next=finder->next;

        if(finder==NULL)
        	cout<<"Out of bounds\n";

    }


    




    return *refHead;














	
}



struct node* delLinkedList(struct node** refHead)
{
	struct node* prevPtr;
	struct node* curPtr;

	curPtr=*refHead;
	prevPtr=curPtr;

	while(curPtr!=NULL)
	{
		prevPtr=curPtr;
		curPtr=curPtr->next;

		delete prevPtr;
	}

	*refHead=curPtr;

	return *refHead;
}


int iterLength(struct node** refHead)
{
	int cnt=0;

	struct node* curPtr=*refHead;

	while(curPtr!=NULL)
	{

		curPtr=curPtr->next;
		cnt++;
	}

	return cnt;
}

int recurLength(struct node* refHead)
{
	
    struct node* curPtr=refHead;

	if(curPtr==NULL)
		return 0;

	return recurLength(curPtr->next)+1;
}

int iterSearch(int key,struct node** refHead)
{
	struct node* curPtr=*refHead;

	while(curPtr->data!=key )
	{
		curPtr=curPtr->next;
		if(curPtr==NULL)
			break;
	}

	if(curPtr!=NULL)
		return curPtr->data;
	else
		return 0;


   
}

int recurSearch(int key,struct node* head)
{
	struct node* curPtr=head;

	if(curPtr==NULL)
		return 0;

	else if(curPtr->data==key)
		return 1;

	else
		return recurSearch(key,curPtr->next);
}



int nthNode(struct node** refHead,int index)
{
	struct node* curPtr=*refHead;
    
    index--;

	int cnt=0;

	while(cnt!=index)
	{
		curPtr=curPtr->next;
        cnt++;
	}

	return curPtr->data;

}



int midLinkedList(struct node** refHead)
{

   struct node* slowPtr=*refHead;
   struct node* fastPtr=*refHead;

   while(fastPtr->next!=NULL)
   {
   	slowPtr=slowPtr->next;
   	fastPtr=fastPtr->next->next;

   	if(fastPtr==NULL)
   		break;
   }

   return slowPtr->data;
}

int countKeyLL(int key,struct node** refHead)
{
	struct node* cntPtr=*refHead;
	int cnt=0;

	while(cntPtr!=NULL)
	{
		if(cntPtr->data==key)
			cnt++;
		cntPtr=cntPtr->next;
		
		
	}

	return cnt;
}


struct node* reverseLL(struct node** refHead)
{
	struct node* prevNode=*refHead;
	struct node* curNode=*refHead;

	struct node* nextNode=curNode->next;
    struct node* head=*refHead;

	while(nextNode!=NULL)
	{
		curNode=nextNode;
		nextNode=curNode->next;
		curNode->next=prevNode;
		if(prevNode==head)
			prevNode->next=NULL;
		prevNode=curNode;
	}

	*refHead=curNode;

	return *refHead;
}

struct node* swapNodes(struct node** refHead,int fNode,int sNode)
{


   struct node* curX=*refHead;
   struct node* prevX=NULL;
   struct node* curY=*refHead;
   struct node* prevY=NULL;

   while(curX->data!=fNode)
   {
   	   prevX=curX;
   	   curX=curX->next;
   	   if(curX==NULL)
   	   	break;

   }

   while(curY->data!=sNode)
   {
	   	prevY=curY;
	   	curY=curY->next;
	   	if(curY==NULL)
	   		break;
   }


   if(curY==NULL || curX==NULL)
   {
   	 cout<<"Not found\n";

   	 return *refHead;
   }
   
   if(prevY!=NULL)
    prevY->next=curX;
   else
   	*refHead=curX;
  
   if(prevX!=NULL)
    prevX->next=curY;
   else
   	*refHead=curY;

	 
	struct node* temp;

    temp=curX->next;
	curX->next=curY->next;
	curY->next=temp;
	
   


   	
   
   return *refHead;



}

int loopDetectHash(struct node** refHead)
{
	struct node* mover=*refHead;

    set<struct node*> s;

	while(mover!=NULL)
	{
        if(s.find(mover)!=s.end())
        	return 1;
		

		s.insert(mover);

		mover=mover->next;


	}

	return 0;

   
}


struct node* loopDetectAndRemoveHash(struct node** refHead)
{
	struct node* mover=*refHead;
    struct node* prevNode=NULL;
    set<struct node*> s;
   
	while(mover!=NULL)
	{
        if(s.find(mover)!=s.end())
        {
          prevNode->next=NULL;
          return *refHead;
        }

		

		s.insert(mover);
        prevNode=mover;
		mover=mover->next;
		


	}

	return *refHead;

	

   
}


int loopDetectionFloyd(struct node** refHead)
{
	struct node* slowPtr=*refHead;
	struct node* fastPtr=slowPtr->next;

	while(slowPtr!=NULL)
	{
		if(slowPtr==fastPtr)
			return 1;

		slowPtr=slowPtr->next;
        
        if(fastPtr==NULL)
        	break;
		if(fastPtr->next==NULL)
			break;
		fastPtr=fastPtr->next->next;

		
	}

   return 0;
}



int main()
{
	struct node* head=NULL;

	//head=addDataEnd(&head);
    head=addDataBegin(&head);
	printList(&head);
    
    //head=addDataAfter(head->next->next,&head);

    //head=deleteKey(5,&head);
   // head=deletePos(&head);
   // head=delLinkedList(&head);
   // cout<<iterLength(&head);
    //printList(&head);
	//cout<<recurLength(head);
	//cout<<recurSearch(2,head);
	//cout<<nthNode(&head,3);
	
    //cout<<midLinkedList(&head);
     //cout<<countKeyLL(2,&head);

	//head=reverseLL(&head);
//	head=swapNodes(&head,3,5);
    

    //head->next->next->next->next->next = head->next->next;
	//printList(&head);

	//cout<<loopDetectHash(&head);
    //cout<<loopDetectionFloyd(&head);
  // head=loopDetectAndRemoveHash(&head);
   //printList(&head);
	return 0;
}

