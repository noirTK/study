#include "deque.h"

void init(deque* const dq)
{
    dq->front = dq->rear = NULL;
}

int empty(const deque* const dq)
{
    return dq->front == NULL;  
}

int size(const deque* const dq)
{
    int size = 0;
    Node* pointer = dq->front;
    while(pointer != NULL)
    {
        ++size;
        pointer = pointer->rightlink;
    }
    return size;
}

void push_front(deque* dq, const element item)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL)
    {
        fprintf(stderr, "메모리 할당 오류.\n");
        exit(0);
    }
    temp->data = item;
    temp->leftlink = NULL;

    if(empty(dq))
    {
        temp->rightlink = NULL;
        dq->front = dq->rear = temp;
    }
    else
    {
        temp->rightlink = dq->front;
        dq->front->leftlink = temp;
        dq->front = temp;
    }
}

void push_back(deque* dq, const element item)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp == NULL)
    {
        fprintf(stderr, "메모리 할당 오류.\n");
        exit(0);
    }
    temp->data = item;
    temp->rightlink = NULL;

    if(empty(dq))
    {
        temp->leftlink = NULL;
        dq->front = dq->rear = temp;
    }
    else
    {
        temp->leftlink = dq->rear;
        dq->rear->rightlink = temp;
        dq->rear = temp;
    }
}

element pop_front(deque* dq)
{
    if(empty(dq))
    {
        fprintf(stderr, "덱이 비었습니다. \n");
        exit(1);
    }
    Node* temp = dq->front;
    element item = temp->data;

    if(dq->front->rightlink == NULL) // 노드가 1개 밖에 없으면
    {
        dq->front = dq->rear = NULL;
    }
    else
    {
        dq->front->rightlink->leftlink = NULL;
        dq->front = dq->front->rightlink;
    }
    free(temp);

    return item;
}

element pop_back(deque* dq)
{
    if(empty(dq))
    {
        fprintf(stderr, "덱이 비었습니다. \n");
        exit(1);
    }
    Node* temp = dq->rear;
    element item = temp->data;

    if(dq->front->rightlink == NULL) // 노드가 1개 밖에 없으면
    {
        dq->front = dq->rear = NULL;
    }
    else
    {
        dq->rear->leftlink->rightlink = NULL;
        dq->rear = dq->rear->leftlink;
    }

    return item;
}

element front(const deque* const dq)
{
    return dq->front->data;
}

element back(const deque* const dq)
{
    return dq->rear->data;
}