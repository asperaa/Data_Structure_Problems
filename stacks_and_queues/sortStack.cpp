#include <bits/stdc++.h>

using namespace std;

stack<int> sortStack(stack<int> &input)
{
	stack<int>tmpStack;

	while(!input.empty())
	{
		int tmp=input.top();
		input.pop();

		while(!tmpStack.empty() && tmpStack.top()>tmp)
		{
			int x=tmpStack.top();
			tmpStack.pop();
			input.push(x);

		}

		tmpStack.push(tmp);
	}

	return tmpStack;
}

int main()
{
	stack<int>s;
	s.push(90);
	s.push(-100);
	s.push(34);
    

	s=sortStack(s);
    
    while(!s.empty())
    {
    	cout<<s.top()<<endl;
    	s.pop();
    }
	
}