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

int main()
{
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;

    return 0;
}