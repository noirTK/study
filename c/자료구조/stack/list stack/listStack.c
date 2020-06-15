#include "listStack.h"

void init(stack* s)
{
    s->size = 0;
};

int empty(stack* s)
{
    return s->size == 0;
};

int full(stack* s)
{
    return s->size == MAX_INDEX-1;
};

int size(stack* s)
{
    return s->size;
};

void push(stack* s, element item)
{
    if(full(s))
    {
        fprintf(stderr, "The stack object is full.\n");
        exit(1);
    }
    s->data[(s->size)++] = item;
};

element top(stack* s)
{
    if(empty(s))
    {
        fprintf(stderr, "The stack object is full.\n");
        exit(1);
    }
    return s->data[s->size-1];
};

element pop(stack* s)
{
    if(empty(s))
    {
        fprintf(stderr, "The stack object is full.\n");
        exit(1);
    }
    return s->data[--(s->size)];
};