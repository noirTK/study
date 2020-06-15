#ifndef _LINKEDSTACK_H_
#define _LINKEDSTACK_H_
#include <stdio.h>

// linked stack elements
typedef int element;
typedef struct
{
    element data;
    struct Node* link;
} Node;
// linked stack elements

typedef struct
{
    Node* top;
    int size;
} stack;

void init(stack* s);
int empty(stack *s);
int size(stack* s);

void push(stack *s, element item);
element pop(stack *s);
element top(stack *s);

#endif