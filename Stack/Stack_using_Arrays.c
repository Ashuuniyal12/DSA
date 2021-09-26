#include<stdio.h>
#include <stdlib.h>
#define N 50

int stack[N];
int top =-1;

void push() //this function will add item in stack
{
    int x;
    printf("\nEnter the data");
    scanf("%d", &x);
    if(top ==N-1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top]=x;
    }

}

int pop() // this function will remove the top element.
{
    int x =-1;
    if(top == -1)
    {
        printf("Underflow");
    }
    else
    {
        x= stack[top];
        top--;
    }
    return x;
}

void peek() // this function will show the top element wwithout removing it.
{
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        printf("%d", stack[top]);
    }
}

void display()
{
    int i=top;
    while(i>= 0)
    {
        printf("%d ",stack[i]);
        i--;
    }
}

int main()
{
    int choice =1;
    do{
     printf("\nEnter the choice:\n ");
     printf("1-PUSH  2-POP  3-PEEK  4- DISPLAY 0-EXIT");
     scanf("%d", &choice);

    switch (choice)
    {
    case 1: push();
        break;
    case 2: pop();
        break;
    case 3: peek();
        break;
    case 4: display();
        break;
    default: choice=0;
        break;
    }
    }while(choice);
}