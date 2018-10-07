#include <bits/stdc++.h>

using namespace std;

class Stack{

    queue<int>q1,q2;

public:
	bool Push(int data);
	int Pop();
};


bool Stack::Push(int data)
{
	q2.push(data);

	while(!q1.empty())
	{
		q2.push(q1.front());
		q1.pop();
		
	}

	queue<int>q=q1;
	q1=q2;
	q2=q;

	return true;
}

int Stack::Pop()
{
	if(q1.empty())
		return 0;
    
    int x=q1.front();
    
    q1.pop();
	
	return x;
}

int main()
{
	Stack s;

	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);

	cout<<s.Pop()<<endl;
	cout<<s.Pop()<<endl;
		cout<<s.Pop()<<endl;

    return 0;
}


