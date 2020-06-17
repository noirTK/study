#ifndef _LISTSTACK_H_
#define _LISTSTACK_H_
#include <stdio.h>

// list stack elements
#define MAX_INDEX 10000
typedef int element;
// list stack elements

typedef struct
{
    element data[MAX_INDEX];
    int size;
}stack;

void init(stack* s);

int empty(stack* s);
int full(stack* s);

int size(stack* s);

void push(stack* s, element item);
element top(stack* s);
element pop(stack* s);

#endif
