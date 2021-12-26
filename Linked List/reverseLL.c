#include<stdio.h>
#include<stdlib.h>
#include<limits.h> // hold the minimun value  INT MIN Macro;

struct Node
  {
    int data ;
    struct Node *next;

  }*head=NULL;

void Create(int n)
{
      struct Node *nextnode ,*temp;

      for (int i=0;i<n;i++)
      {
         nextnode = (struct Node*)malloc(sizeof(struct Node));
         printf("Enter the Data in %d node :\n",i+1);
         scanf("%d",&nextnode->data);
         nextnode->next=NULL;

         if (head== NULL)
         {
             head = temp = nextnode;
         }
         else
         {
             temp->next=nextnode;
             temp=nextnode;
         }
      }
}

void Display()
{
    struct Node *temp =head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int sum(struct Node *p)
{
    int s =0;
    while (p!=0){
        s+= p->data;
        p= p->next;
    }
    return s;

}
int max (struct Node *p)
{
    int m=INT_MIN;
     while (p->next)
     {

         if (m< p->data)
         {
             m = p->data;
         }
         p= p->data;
     }
     return m;
}
void reverse()
{
    struct Node  *currentnode, *prenode,*nextnode;
    currentnode = nextnode =head;
    prenode =NULL;

    while(nextnode)
    {
        nextnode =nextnode->next;
        currentnode->next = prenode;
        prenode =currentnode;
        currentnode =nextnode;
    }
    head =prenode;

}
int main()
{
    int n;
    printf("How many number you want to enter?");
    scanf("%d",&n);
    Create(n);
    reverse();
    printf("\nsum = %d\n",sum(head));
    printf(" Max element is %d \n" ,max(head));
    Display();
}
