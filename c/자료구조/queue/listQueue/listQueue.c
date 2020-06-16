#include <stdio.h>

#define MAX_INDEX 5
typedef int element;

typedef struct
{
    int front, roar;
    element data[MAX_INDEX];
}listQueue;

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


int main()
{
    listQueue* q = (listQueue*)malloc(sizeof(listQueue));
    init(q);
    printf("큐는 비어있는가? [비어있음 : %d], [포화상태 : %d] 사이즈 : %d.\n", empty(q), full(q), size(q));
    push(q,1);
    printf("큐 값 : %d\n", front(q));
    push(q,2);
    printf("큐 맨 끝 값 : %d\n", back(q));
    push(q,3);
    printf("큐 맨 끝 값 : %d\n", back(q));
    push(q,4);
    printf("큐 맨 끝 값 : %d\n", back(q));
    printf("큐는 비어있는가? [비어있음 : %d], [포화상태 : %d] 사이즈 : %d.\n", empty(q), full(q), size(q));
    printf("%d, %d, %d, %d\n", pop(q), pop(q), pop(q), pop(q));
    printf("큐는 비어있는가? [비어있음 : %d], [포화상태 : %d] 사이즈 : %d.\n", empty(q), full(q), size(q));
    printf("end\n");
}