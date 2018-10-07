/* Program to implement a queue using two stacks */
#include<stdio.h>
#include<stdlib.h>
 
/* structure of a stack node */
struct sNode
{
    int data;
    struct sNode *next;
};

struct queue
{
    struct sNode *stack1;
    struct sNode *stack2;
};
/* Function to push an item to stack*/
/* Function to push an item to stack*/
void push(struct sNode** top_ref, int new_data)
{
    /* allocate node */
    struct sNode* new_node =
        (struct sNode*) malloc(sizeof(struct sNode));
        
 
/* put in the data */
new_node->data = new_data;
 
/* link the old list off the new node */
new_node->next = (*top_ref);
 
/* move the head to point to the new node */
(*top_ref) = new_node;
}
 
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
    int res;
    struct sNode *top;
     
    /*If stack is empty then error */
    if(*top_ref == NULL)
    {
        printf("Stack underflow \n");
        getchar();
        exit(0);
         
    }
    else
    {
      
        res = top->data;
        *top_ref = top->next;
      
        return res;
         
    }
}
 
 
/* Function to enqueue an item to queue */
void enQueue(struct queue *q, int x)
{
    push(&q->stack1, x);
}
 
/* Function to dequeue an item from queue */
int deQueue(struct queue *q)
{
    int x;
    /* If both stacks are empty then error */
    if(q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Q is empty");
        
    }
 
/* Move elements from stack1 to stack 2 only if
stack2 is empty */
if(q->stack2 == NULL)
{
    while(q->stack1 != NULL)
    {
        x = pop(&q->stack1);
        push(&q->stack2, x);
         
    }
}
 
x = pop(&q->stack2);
return x;
}
 

/* Driver function to test anove functions */
int main()
{
    /* Create a queue with items 1 2 3*/
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
     
    /* Dequeue items */
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
 
}
