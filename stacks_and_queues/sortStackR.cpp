#include <bits/stdc++.h>

using namespace std;

struct stackN
{
    int data;
    struct stackN* next;

};

void initStack(struct stackN** s)
{
    *s=NULL;
}

bool isEmpty(struct stackN* s)
{
    if(s==NULL)
        return true;
    else
        return false;
}

void push(struct stackN** s,int data)
{
    struct stackN* newS=(struct stackN*)malloc(sizeof(struct stackN));

    newS->data=data;
    newS->next=*s;
    *s=newS;

}


int pop(struct stackN** s)
{
    if(*s==NULL)
    {
        cout<<"Empty\n";
        return 0;
    }

    
        struct stackN* tmp=*s;
        int x=tmp->data;
        (*s)=(*s)->next;
        delete tmp;

        return x;
    
}


int top(struct stackN* s)
{
    return s->data;
}

void SortedInsert(struct stackN** s,int data)
{
    if(isEmpty(*s) || top(*s)<data)
    {
        push(s,data);
        return;
    }

    int temp=pop(s);
    SortedInsert(s,data);

    push(s,data);
}


void sortStack(struct stackN** s)
{
    if(!isEmpty(*s))
    {
        int x=pop(s);

        sortStack(s);

        SortedInsert(s,x);
    }
}

int main()
{
    struct stackN* s;
    
    initStack(&s);

    push(&s,5);
    push(&s,9);
    push(&s,7);
    push(&s,11);
    push(&s,90);
   
    sortStack(&s);
    
    while(s)
    {
        printf("%d ", s->data);
        s = s->next;
    }
}