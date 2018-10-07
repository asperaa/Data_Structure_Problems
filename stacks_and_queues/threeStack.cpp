#include <bits/stdc++.h>

using namespace std;

#define MAX 100
class twoStack
{
	int top1;
	int top2;
	int top3;
	int size;
	int head3;
	int *a;

public:
	

	twoStack(int n)
	{   
		size=n;

		a=new int[n];
		top1= -1;
		top2= size;
		top3=size/2;
		head=size/2;
	}

	bool push1(int data);
	bool push2(int data);
	bool push3(int data);
	int pop1();
	int pop2();
	int pop3();


};

bool twoStack::push1(int data)
{
	if(top1==head3)
	{
		cout<<"Stack overflow\n";
		return false;
	}

	else
	{
		a[++top1]=data;
		return true;
	}
}

bool twoStack::push2(int data)
{
	if(top2==top3)
	{
		cout<<"Stack overflow\n";
		return false;
	}
	else
	{
		a[--top2]=data;
		return true;
	}
}


bool twoStack::push3(int data)
{
	if(top2==top3)
	{
		cout<<"Stack overflow\n";
		return false;
	}
	else
	{
		a[--top2]=data;
		return true;
	}
}


int twoStack::pop1()
{
	if(top1<-1)
	{
		cout<<"Stack underflow\n";
		return 0;
	}

	else
	{
		int x=a[top1--];
		return x;

	}
}

int twoStack::pop2()
{
	if(top2>=size)
	{
		cout<<"Stack underflow\n";
		return 0;
	}

	else
	{
		int x=a[top2++];
		return x;

	}
}





int main()
{
	twoStack s(100);

	s.push1(2);
	s.push1(23);
	s.push2(34);
	s.push2(46);

    cout<<s.pop1()<<endl;
    cout<<s.pop2()<<endl;
    cout<<s.pop1()<<endl;
    cout<<s.pop2()<<endl;
       

    return 0;
}