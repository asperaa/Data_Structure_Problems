#include <bits/stdc++.h>

using namespace std;

#define MAX 100
class Stack
{
	int top;

public:
	int a[MAX];

	Stack()
	{
		top=-1;
	}

	bool push(int data);
	bool isEmpty();
	int pop();
	int peek();

};

bool Stack::push(int data)
{
	if(top>=MAX-1)
	{
		cout<<"Stack overflow\n";
		return false;
	}

	else
	{
		a[++top]=data;
		return true;
	}
}


int Stack::pop()
{
	if(top<-1)
	{
		cout<<"Stack underflow\n";
		return 0;
	}

	else
	{
		int x=a[top--];
		return x;

	}
}

bool Stack::isEmpty()
{
	return (top<0);
}

int Stack::peek()
{
	if(top>=MAX-1)
	{
		cout<<"Stack overflow\n";
		return 0;

	}

	else if(top<-1)
	{
		cout<<"Stack underflow";
		return -1;
	}

	else
	{
		int x=a[top];
		return x;
	}
}


class SpecialStack:public Stack
{
    
    Stack min;

public:
	bool push(int data);
	int pop();
	int getMin();





};

bool SpecialStack::push(int data)
{
	if(isEmpty())
	{
		Stack::push(data);
		min.push(data);
	}

	else
	{
		Stack::push(data);
		if(data<=min.peek())
		{
			min.push(data);

		}

		else
		{
			min.push(min.peek());
		}

	}

	return true;
}

int SpecialStack::pop()
{
	int x=Stack::pop();
	min.pop();

	return x;
}

int SpecialStack::getMin()
{
	int x=min.pop();
	min.push(x);
	
	return x;

}





int main()
{
	SpecialStack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

   cout<<s.getMin()<<endl;

    return 0;
}