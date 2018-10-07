#include <bits/stdc++.h>

using namespace std;

class Queue
{
	int front;
	int rear;
	int size;
	int capacity;
	int *array;

	public:
		
		Queue(int cap){
			
		    capacity=cap;
		
			array=(int*)malloc(capacity*sizeof(int));
			
		
			front=0;
			size=0;
			rear=capacity-1;
		
		}

		void Enqueue(int data);
		int Dequeue();
		bool isEmpty();
		bool isFull();
		int Front();
		int Rear();

};

bool Queue::isFull()
{
	//cout<<size<<endl;
	//cout<<capacity<<endl;
	if(size==capacity)
        return true;
    else
    	return false;
}



bool Queue::isEmpty()
{
    if(size==0)
    	return true;
    else
    	return false;
}




void Queue::Enqueue(int data)
{
    if(isFull())
    {
    	cout<<"Queue full\n";
    	return;
    }

    
    rear=(rear+1)%capacity;
    array[rear]=data;
	size=size+1;

	return;

}

int Queue::Dequeue()
{
	if(isEmpty())
	{
		cout<<"Empty queue\n";
		return INT_MIN;
	}

	else
	{
		int x=array[front];
		front=(front+1)%capacity;
		size--;
        
        return x;
	}
}

int Queue::Front()
{
	if(isEmpty())
		return INT_MIN;

	return array[front];
}

int Queue::Rear()
{
	if(isFull())
		return INT_MIN;

	return array[rear];
}


int main()
{
	Queue h(10);

	h.Enqueue(1);
	h.Enqueue(2);
	h.Enqueue(3);

	h.Enqueue(4);

	cout<<h.Front()<<endl;;
	cout<<h.Rear()<<endl;

	cout<<h.Dequeue()<<endl;
	cout<<h.Dequeue()<<endl;
	cout<<h.Dequeue()<<endl;
	cout<<h.Dequeue()<<endl;
	cout<<h.Dequeue()<<endl;

	return 0;



}