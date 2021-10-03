#include <Stdio.h>
#define N 50
int Queue[N];
int front = -1;
int rear = -1;

void enque()
{
    if ((rear+1)%N==front)
        printf("Queue is Full");

    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("Enter the data ");
        scanf("%d", &Queue[rear]);
    }
    else
    {
       rear =  (rear+1)%N;
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
        printf("Dequed value :%d",Queue[front]);
        front = (front+1)%N;
    }
}

void display()
{
    if (front == -1 && rear == -1)
        printf("UNDRFLOW");
    else
    {
        int i =front;
       do
        {
            printf("%d ", Queue[i]);
            i= (i+1)%N;
        } while(i!=rear);
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
    printf("Name-Ashutosh Uniyal, Section D, Student ID - 20011073");
    
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