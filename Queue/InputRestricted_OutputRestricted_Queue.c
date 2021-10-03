#include<stdio.h>
#define N 50

int Queue[N];
int front=-1 ,rear=-1;

void enquefront()
{
    if(front == 0)
        printf("Queue is Full");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("Enter the data ");
        scanf("%d", &Queue[front]);
    }
    else
    {
        front--;
        printf("Enter the data ");
        scanf("%d", &Queue[front]);
    }

}
void dequefront()
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

void enquerear()
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

void dequerear()
{   
    if (front == -1 && rear == -1)
        printf("UNDRFLOW");
    else if (front == rear)
        front = rear = -1;
    else
    {
        rear--;
    }
}

void peekfront()
{
    if (front == -1 && rear == -1)
        printf("Queue is empty");
    else
    {
        printf("%d", Queue[front]);
    }
}
void peekrear()
{
    if (front == -1 && rear == -1)
        printf("Queue is empty");
    else
    {
        printf("%d", Queue[rear]);
    }
}

void display()
{
    if (front == -1 && rear == -1)
        printf("UNDRFLOW");
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", Queue[i]);
        }
    }
}

int main()
{
    printf("\nName- Ashutosh Uniyal, Section C, Student id 20011073\n\n");
    
    int choose =0;
    printf("To use Input Restricted Queue Press 1\n");
    printf("To use Output Restricted Queue Press 2\n");
    printf("Enter the choice: ");
    scanf("%d" ,&choose);

    if (choose ==1)
    {
        printf("1-Enque from Rear \n2-Deque from Front\n3-Deque from Rear \n4-PEEK from Front \n5-PEEK from Rear \n6-DISPLAY \n0-EXIT\n");
        int choice = 1;
        do
        {
            printf("\nEnter the choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                enquerear();
                break;
            case 2:
                dequefront();
                break;
            case 3:
                dequerear();
                break;
            case 4:
                peekfront();
                break;
            case 5:
                peekrear();
                break;
            case 6:
                display();
                break;
            default:
                choice = 0;
                break;
            }
        } while (choice);
    }
    else if (choose==2)
    {
        printf("1-Enque from Front \n2-Deque from Front \n3-Enque from Rear \n4-PEEK from Front \n5-PEEK from Rear \n6-DISPLAY \n0-EXIT\n");
        int choice = 1;
        do
        {
            printf("\nEnter the choice: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                enquefront();
                break;
            case 2:
                dequefront();
                break;
            case 3:
                enquerear();
                break;
            case 4:
                peekfront();
                break;
            case 5:
                peekrear();
                break;
            case 6:
                display();
                break;
             default:
                choice = 0;
                break;
            }
        } while (choice);
    }
}