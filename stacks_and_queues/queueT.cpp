#include <bits/stdc++.h>

using namespace std;


struct Qnode{
	int data;
	struct Qnode* next;
};

struct Queue{

struct Qnode* front;
struct Qnode* rear;

};


struct Qnode* createQnode(int data)
{
	struct Qnode* newNode=(struct Qnode*)malloc(sizeof(struct Qnode));
	newNode->data=data;
	newNode->next=NULL;
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
	struct Qnode* newNode=createQnode(data);

	if(q->rear==NULL)
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


struct Qnode* deQueue(struct Queue* q)
{
	if(q->front==NULL)
	{
		cout<<"empty queue\n";
		return NULL;
	}

    struct Qnode* temp=q->front;
	q->front=q->front->next;

	if(q->front==NULL)
		q->rear=NULL;

	return temp;


}


int main()
{
	struct Queue* q=createQueue();

	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);

	struct Qnode* qn=deQueue(q);

	cout<<qn->data<<endl;

}