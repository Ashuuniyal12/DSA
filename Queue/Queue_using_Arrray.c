#include <Stdio.h>
#define N 50

int Queue[N];
int front = -1;
int rear = -1;

void enque()
{
    if (rear == N - 1)
        printf("Queue is Full");

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("Enter the data ");
        scanf("%d", &Queue[rear]);
    }
    else
    {
        rear++;
        printf("Enter the data ");
        scanf("%d", &Queue[rear]);
    }
}

void deque()
{
    if (front == -1 && rear == -1)
        printf("UNDRFLOW");
    else if (front == rear)
        front = rear = -1;
    else
    {
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
        printf("UNDRFLOW");
    else
    {
        for (int i = front; i < rear; i++)
        {
            printf("%d ", Queue[i]);
        }
    }
}

void peek()
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

    int choice = 1;
    do
    {
        printf("\nEnter the choice:\n ");
        printf("1-Enque  2-Deque  3-PEEK  4- DISPLAY 0-EXIT");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            choice = 0;
            break;
        }
    } while (choice);
}