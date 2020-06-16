#include "listQueue.h"

void init(listQueue* q)
{
    q->front = q->roar = 0;
}

int empty(const listQueue* q)
{
    return q->front == q->roar;
}

int full(const listQueue* q)
{
    return q->front == (q->roar+1)%MAX_INDEX;
}

int size(const listQueue* q)
{
    int size = 0;
    int t = (q->front)%MAX_INDEX;
    while(t != q->roar)
    {
        ++size;
        t = (t+1) % MAX_INDEX;
    }
    return size;
}

void push(listQueue* q, element item)
{
    if(full(q))
    {
        fprintf(stderr, "큐가 포화상태입니다. \n");
        exit(1);
    }
    q->roar = (q->roar+1)%MAX_INDEX;
    q->data[q->roar] = item;
}

element pop(listQueue* q)
{
    if(empty(q))
    {
        fprintf(stderr, "큐가 비어있습니다. \n");
        exit(1);
    }
    q->front = (q->front+1)%MAX_INDEX;
    return q->data[q->front];
}

element front(const listQueue* q)
{
    if(empty(q))
    {
        fprintf(stderr, "큐가 비어있습니다. \n");
        exit(1);
    }
    return q->data[q->front+1];
}

element back(const listQueue* q)
{
    if(empty(q))
    {
        fprintf(stderr, "큐가 비어있습니다. \n");
        exit(1);
    }
    return q->data[q->roar];
}