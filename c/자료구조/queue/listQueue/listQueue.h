#ifndef _LISTQUEUE_H_
#define _LISTQUEUE_H_

#include <stdio.h>
#define MAX_INDEX 10000

typedef int element;
typedef struct
{
    int front, roar;
    element data[MAX_INDEX];
} listQueue;

void init(listQueue* q);

int empty(const listQueue* q);
int full(const listQueue* q);
int size(const listQueue* q);

void push(listQueue* q, element item);
element pop(listQueue* q);
element front(const listQueue* q);
element back(const listQueue* q);
#endif