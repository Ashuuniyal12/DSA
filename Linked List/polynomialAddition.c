#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int power;
    int coff ;
    struct Node * next;   
};

void Display(struct Node *head) 
{
    struct Node *temp;
    temp =head;
    printf("polynomial ==> "); 
    while(temp)
    {
        printf("%dx^%d",temp->coff,temp->power);
        
        if(temp->coff >=0 && temp->next != NULL)
            printf(" + ");
            temp= temp->next;
    }
    printf("\n");
}

void create (struct Node **head){
    struct Node *newNode,*temp;

    int choice =1;
    while(choice)
    {
        newNode = (struct Node*)malloc (sizeof( struct Node)); 

        printf("\nEnter the coff : ");
        scanf("%d",&newNode->coff);
        printf("\nEenter the power of coff : ");
        scanf("%d", &newNode->power);
        newNode->next=0;

        if(*head ==NULL)
        {
           *head = newNode;  
           temp = newNode;
        }
        else 
        {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do want to insert more(0/1) : ");
        scanf("%d",&choice);
    }
}


void add (struct Node **head  , int cof , int pow){
    struct Node *newNode,*temp= *head;

    
        newNode = (struct Node*)malloc (sizeof( struct Node)); 
        newNode->coff=cof;
        newNode->power=pow;
        newNode->next=NULL;

        if(*head ==NULL)
        {
           *head = newNode;  
        }
        else 
        {   temp = *head;
            while(temp->next != NULL)
              temp = temp->next;
              
            temp->next = newNode;
        }

    
}

void solve(struct Node *p1,struct Node *p2,struct Node **p){
    struct Node *temp = *p;
    while(p1 != NULL &&p2 != NULL)
    {
        
        if(p1->power > p2->power )
        {
            add(p, p1->coff , p1->power);
             p1 = p1->next;
        }
        else if(p1->power < p2->power )
        {
          add(p, p2->coff , p2->power);
           p2 = p2->next;
        }
        else {
            add(p, (p1->coff+p2->coff) , p1->power);
               p1 = p1->next;
            p2= p2->next;
        }
       
    }
    
    if(p1 == NULL)
    {
        while(p2 != NULL)
        {
              add(p, p2->coff , p2->power);
           p2 = p2->next;
            
        }
    }
    if(p2 == NULL)
    {
      while(p1 != NULL)
        {
              add(p, p1->coff , p1->power);
           p1 = p1->next;
            
        }
    }
    
}

// --------------MAIN PROGRAM BEGINS FROM HERE------------------------ 
int main()
{
    struct Node *p1= NULL ,*p2 = NULL, *p =NULL;
    create(&p1);
     Display(p1);
    
    create(&p2);
     Display(p1);
     Display(p2);
    solve(p1,p2,&p);
    Display(p);

    return 0;
}