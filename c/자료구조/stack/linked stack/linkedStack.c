#include "linkedStack.h"

void init(stack* s)
{
    s->top = NULL;
};

int empty(stack *s)
{
    return s->top == NULL; 
};

int size(stack* s)
{
    Node* point = s->top;
    int size = 0;
    while(point != NULL)
    {
        ++size;
        point = point->link;
    }
    return size;
}


void push(stack *s, element item)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL)
    {
        fprintf(stderr,"memory assignment error\n");
        exit(1);
    }
    temp->data = item;
    temp->link = s->top;
    s->top = temp;
};

element pop(stack *s)
{
    if(s->top == NULL)
    {
        fprintf(stderr, "The linked stack is empty\n");
        exit(1);   
    }
    Node* temp = s->top;
    s->top = s->top->link;
    element data = temp->data;
    free(temp);
    return data;
};

element top(stack *s)
{
    if(s->top == NULL)
    {
        fprintf(stderr, "The linked stack is empty\n");
        exit(1);   
    }
    return s->top->data;
};