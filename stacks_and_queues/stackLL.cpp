#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
    struct node* next;
};


class Stack
{
	struct node* top;

public:

	Stack()
	{
		//struct node* head=(struct node*)malloc(sizeof(struct node));
		top=NULL;
	}
	bool push(int data);
	int pop();
	bool isEmpty();
	int peek();

};

bool Stack::push(int data)
{
	struct node* newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	
	if(top==NULL)
	{
		top=newNode;
		newNode->next=NULL;
	}

	else
	{
		newNode->next=top;
		top=newNode;
	}

	return true;

}


int Stack::pop()
{
	if(top==NULL)
	{
		cout<<"Stack underflow\n";
		return 0;
	}

	else
	{
		int x=top->data;
		top=top->next;

		return x;
	}

}


int Stack::peek()
{
	if(top==NULL)
	{
		cout<<"Stack empty\n";
		return 0;
	}

	else
	{
		int x=top->data;
		return x;
	}
}

bool Stack::isEmpty()
{
   if(top==NULL)
   	return true;
   else
   	return false;
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
	cout<<s.pop()<<endl;

	s.push(400);

	cout<<s.peek()<<endl;


	return 0;
}