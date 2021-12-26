#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node
{
    int data;
    struct node *next;
};

void push (struct node ** top )
{
    int x; 
    struct node *t;
    t=(struct node *)malloc (sizeof(struct node));
    if(t==NULL)
    {
        printf("Stack is full");
    }
    else
    {
    printf("Enter the data");
    scanf("%d",&x);
    t->data = x;
    t->next = *top;
    *top = t;
    }
}

int pop(struct node ** top)
{
     struct node *p;
     int x=-1;

     if(top==NULL)
        {
            printf("Stack is empty");
        }
     else
        {
            p =(*top);
            (*top) = (*top)->next;
            x= p->data;
            free (p);
            return x;
        }
}

void Display(struct node * top)
{
    struct node *p;
    p =top;
    while(p)
    {
        printf("%d ",p->data );
        p=p->next;
    }
    printf("\n");
}

int minelement(struct node **top)
{
    if((*top)==NULL)
        return INT_MAX;
    
    int temp = pop(top);
    int x = minelement(top);
    if(temp<x)
        return temp;
    else
        return x;
}

int main()
{
    struct node*top = NULL;
    int choice;
   do{
    printf("\n1-PUSH  2-POP  3- DISPLAY 0-EXIT");
    printf("\nEnter the choice:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1: push(&top);
        break;
    case 2: pop(&top);
        break;
    case 3: Display(top);
        break;
    default: choice=0;
        break;
    }
    }while(choice);
    
    printf("The minimum elemnt is %d ",minelement(&top));
}
