#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_

#include <stdio.h>

typedef int element;

typedef struct
{
    element data;
    struct node* link;
}node;

typedef struct
{
    node* front;
    node* rear; 
}linkedQueue;

void init(linkedQueue* const q);
int empty(const linkedQueue* const q);
int size(const linkedQueue* const q);

void push(linkedQueue* q, element item);
element pop(linkedQueue* q);
element front(linkedQueue* q);
element back(linkedQueue* q);
#endif