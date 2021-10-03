#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node *link;
};

void enque(struct node **front , struct node **rear)
{
    struct node *nextnode;

    nextnode = (struct node *)malloc(sizeof(struct node ));
    if(  nextnode !=0 )
    {
        printf("Enter the data: ");
        scanf("%d",&nextnode->data);
        nextnode->link=0;

        if((*front)==0 && (*rear)== 0)
        {
           (*front) = (*rear) = nextnode;
        }
         else
        {
            (*rear)->link= nextnode;
            (*rear)=nextnode;
        }
    }
    else
    {
       printf("Queue is full\n");  
    }
}

void deque(struct node **front,struct node **rear)
{
    struct node * temp;
    temp = *front;
    if(temp == (*rear)->link)
    {
        printf("Queue is empty");
    }
    else
    {
        *front=(*front)->link;
        free(temp);
    }
} 

void peek(struct node *front,struct node *rear)
{
    if(front==0 && rear == 0)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("%d", front->data);
    }
}

void display(struct node *front,struct node *rear)
{
    if(front==0 && rear == 0)
    {
        printf("Queue is Empty");
    }
    else
    {
        struct node *temp;
        temp = front;
        while(temp)
        {
            printf("%d ",temp->data);
            temp= temp->link;
        }
    }
}

 int main()
 {
     struct node *front= 0;
     struct node *rear = 0;

    printf("1-ENQUE \n2-DEQUE \n3-PEEK  \n4-DISPLAY \n0-EXIT\n");


    int choice = 1;
    do
    {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enque(&front,&rear);
            break;
        case 2:
            deque(&front,&rear);
            break;
        case 3:
            peek(front ,rear);
            break;
        case 4:
            display(front ,rear);
            break;
        default:
            choice = 0;
            break;
        }
    } while (choice);

 }