#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_

#include <stdio.h>

typedef int element;

typedef struct Node
{
    element data;
    struct Node* leftlink;
    struct Node* rightlink;
}Node;

typedef struct deque
{
    Node* front;
    Node* rear;
}deque;

void init(deque* const dq);
int empty(const deque* const dq);
int size(const deque* const dq);

void push_front(deque* dq, const element item);
void push_back(deque* dq, const element item);

element pop_front(deque* dq);
element pop_back(deque* dq);

element front(const deque* const dq);
element back(const deque* const dq);

#endif