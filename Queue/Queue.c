#include<stdio.h>
#include<stdlib.h>
struct queue {
    int size;
    int front;
    int rear;
    int *Q;

};

void create(struct queue *q,int size)
{
    q->size= size;
    q->front = q->rear =-1;
    q->Q = (int *)malloc(sizeof(int)*q->size);
}

void enque(struct queue *q,int x)
{

    if(q->rear ==q->size-1){
        printf("Queue is Full");
        return;
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int deque(struct queue *q)
{
    int x=-1;
    if(q->rear==q->front){
        printf("Queue is Empty");
        return;
    }
    else
    {
        q->front++;
        x=q->Q[q->front];
        return x;
    }
}

void Display(struct queue *q)
{
    int x = q->rear;

    for(int i=0;i<x;i++)
    {
        printf("%d",q->Q[i]);
    }
    printf("\n");
}

int main()
{
    struct queue *Que;
    printf("Enter the size of queue");
    int n;
    scanf("%d",&n);
    create(Que,n);
    enque(Que,56);
    enque(Que,5);
    enque(Que,6);
    enque(Que,86);
    Display(Que);
    deque(Que);
    deque(Que);
    Display(Que);
}
