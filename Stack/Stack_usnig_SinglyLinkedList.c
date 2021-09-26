#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void push(int x, struct Node **top)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;

    newNode->link = *top;
    *top = newNode;
}

void Display(struct Node *top)
{
    struct Node *temp = top;
    if (temp == NULL)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void pop(struct Node **top)
{
    struct Node *temp;
    temp = *top;
    if (temp == 0)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("%d", temp->data);
        *top = (*top)->link;
        free(temp);
    }
}

void peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack EMPTY\n");
    }
    else
    {
        printf("%d ", top->data);
    }
}

int main()
{
    struct Node *top = 0;
    push(56, &top);
    push(89, &top);
    push(5, &top);
    push(9, &top);

    Display(top);

    pop(&top);
    pop(&top);

    Display(top);
    peek(top);

}
