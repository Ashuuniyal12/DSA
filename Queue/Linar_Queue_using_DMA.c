#include<stdio.h>
#include<stdlib.h>

int * enque(int *front, int *rear, int*Queue)
{
    int*ptr=NULL;
    if(Queue==NULL)
    {
        (*front)++;
        ptr= (int*)calloc(1,sizeof(int));
    }
    else
    {
        ptr = (int*)realloc(Queue,1*sizeof(int));
    }
    if(ptr!=NULL)
    {
        (*rear)++;
        Queue=ptr;
        printf("Enter the Data: " );
        scanf("%d", &Queue[(*rear)]);
    }
    else
    printf("\nno more memory is available currently.");
    return Queue;

}

void deque(int *front, int *rear ,int*Queue)
{
    if(Queue == NULL || (*front) ==(*rear))
        printf("Queue is Empty\n");
    else
    {
        (*front)++;
    }

}

void display(int front,int rear, int *Queue)
{
    if (front == -1 && rear == -1)
        printf("UNDRFLOW");
    else
    {
        for (int i = front; i <=rear; i++)
        {
            printf("%d ", Queue[i]);
        }
    }
}

void peek(int front, int rear,int* Queue)
{
    if (front == -1 && rear == -1)
        printf("Queue is empty");
    else
    {
        printf("%d", Queue[front]);
    }
}
int main()
{

    int *Queue=NULL;
    int choice = 1;
    int front=-1,rear=-1;
    do
    {
        printf("\nEnter the choice:\n ");
        printf("1-Enque  2-Deque  3-PEEK  4- DISPLAY 0-EXIT");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Queue = enque(&front, &rear, Queue);
            break;
        case 2:
            deque(&front, &rear ,Queue);
            break;
       case 3:
            peek(front, rear ,Queue);
            break;
        case 4:
            display(front, rear ,Queue);
            break;
        default:
            choice = 0;
            break;
        }
    } while (choice);
}