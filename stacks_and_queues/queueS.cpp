#include <bits/stdc++.h>

using namespace std;

#define MAX 100
class Queue
{
	int top1;
	int top2;

public:
	int a[MAX];
	int b[MAX];

	Queue()
	{
		top1=-1;
		top2=-1;
	}


	bool push1(int data);
    bool push2(int data);
	bool isEmpty1();
    bool isEmpty2();
	int pop1();
	int pop2();
	bool enQueue(int data);
	int deQueue();

};

bool Queue::push1(int data)
{
	if(top1>=MAX-1)
	{
		cout<<"Queue overflow\n";
		return false;
	}

	else
	{
		a[++top1]=data;
		return true;
	}
}

bool Queue::push2(int data)
{
	if(top2>=MAX-1)
	{
		cout<<"Queue overflow\n";
		return false;
	}

	else
	{
		b[++top2]=data;
		return true;
	}
}


int Queue::pop1()
{
	if(top1<-1)
	{
		cout<<"Queue underflow\n";
		return 0;
	}

	else
	{
		int x=a[top1--];
		return x;

	}
}

int Queue::pop2()
{
	if(top2<-1)
	{
		cout<<"Queue underflow\n";
		return 0;
	}

	else
	{
		int x=b[top2--];
		return x;

	}
}

bool Queue::isEmpty1()
{
	return (top1<0);
}

bool Queue::isEmpty2()
{
	return (top2<0);
}


bool Queue::enQueue(int data)
{
	push1(data);
} 

int Queue::deQueue()
{

	if(isEmpty1() && isEmpty2())
	{
		cout<<"Error\n";
		return 0;
	}

	int temp;
    while(!isEmpty1() && isEmpty2())
    {
    	temp=pop1();
    	push2(temp);
    }
    
    temp=pop2();

    return temp;
}



int main()
{
	Queue s;

	s.enQueue(1);
	s.enQueue(2);
	s.enQueue(3);
	s.enQueue(4);

	cout<<s.deQueue()<<endl;
    cout<<s.deQueue()<<endl;



    return 0;
}