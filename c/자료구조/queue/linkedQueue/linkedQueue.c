#include "linkedQueue.h"

void init(linkedQueue* const q)
{
    q->front = q->rear = NULL;
}

int empty(const linkedQueue* const q)
{
    return q->front == NULL;
}

int size(const linkedQueue* const q)
{
    node* pointer = q->front;
    int size = 0;
    while(pointer != NULL)
    {
        ++size;
        pointer = pointer->link;
    }
    return size;
}

void push(linkedQueue* q, element item)
{
    node* temp = (node*)malloc(sizeof(node));
    if(temp == NULL)
    {
        fprintf(stderr, "메모리 할당 오류\n");
        exit(1);
    }
    temp -> data = item;
    temp -> link = NULL;

    if(empty(q))
    {
        q->front = q->rear = temp;
    }
    else
    {
        q->rear->link = temp;
        q->rear = temp;
    }
}

element pop(linkedQueue* q)
{
    if(empty(q))
    {
        fprintf(stderr, "큐가 비었습니다.\n");
        exit(1);
    }
    node* temp = q->front;
    q->front = q->front->link;
    if(q->front == NULL) //링크드 리스트가 하나 밖에 없을 때
    {
        q->rear = NULL; 
    }
    element value = temp ->data;
    free(temp);
    return value;
}

element front(linkedQueue* q)
{
    if(empty(q))
    {
        fprintf(stderr, "큐가 비었습니다.\n");
        exit(1);
    }
    return q->front->data;
}

element back(linkedQueue* q)
{
    if(empty(q))
    {
        fprintf(stderr, "큐가 비었습니다.\n");
        exit(1);
    }
    return q->rear->data;
}