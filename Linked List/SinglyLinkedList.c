#include<stdio.h>
#include<stdlib.h>

struct Node     //Structre for a node in linked list .
{
    int data;   // to hold the data value.
    struct Node * next;   // this node pointer contains the address of nex node.

};

void Display(struct Node *head)   //this functioin is used to display the linked list
{
    struct Node *temp;
    temp =head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp= temp->next;
    }
}

struct Node* insertFirst(struct Node *head,int x) // function to insert a node at the begning of linked list.                                              
{                                                // return type is pointer because the orginal head is being 
    struct Node *newNode,*temp;                 //  passed by value and it canat be changed in the function

    newNode = (struct Node* ) malloc (sizeof(struct Node ));

    newNode->data = x;
    temp =head;
    newNode->next = temp;
    head = newNode;

    return head;
}

void insertPos(struct Node **head, int Pos ,int x) // function to insert an element after a given position.
{
    struct Node *newNode,*temp;
    temp = *head; 
    newNode = (struct Node* ) malloc (sizeof(struct Node ));

    newNode->data = x;
    newNode->next= NULL;

    int i=1;
    while(i<Pos)
    {
        temp= temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next= newNode;
}

void insertLast(struct Node **head , int x) // this function will store element at the last.
{
    struct Node *newNode,*temp;                 

    newNode = (struct Node* ) malloc (sizeof(struct Node));

    newNode->data = x;
    newNode->next= NULL;

    temp =*head;
    while(temp->next)
        temp=temp->next;

    temp->next = newNode;

}

void DeleteFirst(struct Node **head) //function to delete the first node.
{
  struct Node *temp =*head ;
  *head  = temp->next;   
  free(temp);             
}

void DeleteLast(struct Node **head) //function to delete the last node.
{
  struct Node *temp, *prevNode ;
  temp =prevNode =*head;
  while(temp->next)
  {
    prevNode =temp;
    temp = temp->next;
  } 
  prevNode->next = NULL;
  free(temp);             
}

void DeletePos(struct Node **head, int Pos)// function to delete node from a specific position in linked list.
{
    struct Node *temp = *head, *nextNode ;
    int i=0;
    while(i<Pos-1)
    {
        temp= temp->next;
        i++;
    }
    nextNode= temp->next;
    temp->next = nextNode->next;
    free(nextNode);
}


// --------------MAIN PROGRAM BEGINS FROM HERE------------------------ 
int main()
{
    struct Node *newNode,*temp,*head=NULL;

    int choice =1;
    while(choice)
    {
        newNode = (struct Node*)malloc (sizeof( struct Node)); //it will create a memory block of 
                                                              //struct node size for every new node.

        printf("\nEnter the data");
        scanf("%d",&newNode->data);
        newNode->next=0;

        if(head ==NULL)
        {
            head =temp = newNode;   //if head will be empty then it means
                                    // the list is empty so first node address will be the head addres.
        }
        else 
        {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do want to insert more(0/1)\n");
        scanf("%d",&choice);
    }

    Display(head);
    printf("\n");

    head = insertFirst(head,2);    //here the address is not passed so we need to update the head at return time . 

    insertPos(&head, 2 ,96);

    insertLast(&head,2020);

    DeleteFirst(&head);

    DeleteLast(&head);

    DeletePos(&head,3);

    Display(head);

    return 0;
}