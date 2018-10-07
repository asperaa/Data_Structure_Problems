#include <bits/stdc++.h>

using namespace std;


struct QNode
{
	int data;
	struct QNode* next ;
};

struct Queue
{
	struct QNode* front;
	struct QNode* rear;
};

struct QNode* createQNode(int data)
{
	struct QNode* temp=(struct QNode*)malloc(sizeof(struct QNode));
	temp->data=data;
	temp->next=NULL;

	return temp;

}

struct Queue* createQueue()
{
	struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=NULL;
	q->rear=NULL;

	return q;
}

void enQueue(struct Queue* q,int data)
{
	struct QNode* newNode=createQNode(data);

	if(q->front==NULL && q->rear==NULL)
	{
		q->front=newNode;
		q->rear=newNode;
	}

	else
	{
		q->rear->next=newNode;
		q->rear=newNode;

	}
}

struct QNode* deQueue(struct Queue* q)
{
	if(q->rear==NULL && q->front==NULL)
	{
        cout<<"Empty Queue\n";
		return NULL;
	}
	
	
	struct QNode* ans=q->front;
	q->front=q->front->next;

    if(q->front==NULL)
    	q->rear=NULL;

	return ans;

	
}

int main()
{
	struct Queue* q=createQueue();

	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);

	struct QNode* qn=deQueue(q);

	cout<<qn->data<<endl;

}