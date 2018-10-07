#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	struct node *next;
};


struct Queue
{
    struct node *stack1;
    struct node *stack2;
};


void push(struct node** topRef,int data)
{
	struct node *newNode=(struct node*)malloc(sizeof(struct node));

	newNode->data=data;
	newNode->next=*topRef;

	(*topRef)=newNode;
}

int pop(struct node** topRef)
{
	int x;
	struct node* temp;
	
	if(*topRef==NULL)
	{
		cout<<"SU\n";
		return 0;
	}

	else
	{
    
     
      //temp=(*topRef);
      int x=(*topRef)->data;
      (*topRef)=(*topRef)->next;
      
      return x;
	
	}

}

void enQueue(struct Queue* q,int data)
{
	push(&q->stack1,data);
}

int deQueue(struct Queue* q)
{
	if(q->stack1==NULL && q->stack2==NULL)
	{	
		cout<<"SU\n";
		return 0;
	}

	
		if(q->stack2==NULL)
		{
			while(q->stack1!=NULL)
			{
				int x=pop(&q->stack1);
			    push(&q->stack2,x);
			}
		}
	

	int x=pop(&q->stack2);

	return x;
}


int main()
{
	

	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
      printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
 
   

    return 0;
}