#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{                                      // decleartion of tree node 
    int data;
    struct treeNode *left;
    struct treeNode *right;
} tree;

typedef struct node            //Node can be used for both Queue and Stack
{
    struct treeNode* data;
    struct node *link;
} Queue,Stack;

/*-----------------Queue-----------------------------------*/
void enque(tree* value,Queue **front,Queue **rear) // funtion to enque address in queue
{
    Queue *nextnode;

    nextnode = (Queue *)malloc(sizeof(Queue));
    if( nextnode !=0 )
    {
        nextnode->data = value;
        nextnode->link=0;

        if((*front)==0)
           (*front) = (*rear) = nextnode;

         else
        {
            (*rear)->link= nextnode;
            (*rear)=nextnode;
        }
    }
    else
       printf("Queue is full\n");  
}

tree* deque(Queue **front,Queue **rear) // funtion to deque address in queue
{
    Queue * temp;
    temp = (*front);
    *front=(*front)->link;
    return temp->data;
}

int isEmpty(Queue *front,Queue *rear)
{
 return front == NULL;
}
/*----------------------STACK--------------------*/

void push(Stack **top , tree * val)
{
    Stack *newnode;
    newnode = (Stack *)malloc (sizeof(Stack));
    newnode->data = val;
    newnode->link= (*top);
    (*top) = newnode;
}

tree * pop(Stack **top)
{
    Stack * temp;
   temp = (*top);
   (*top) =(*top)->link;
   return temp->data;
}

int isEmptystack(Stack *top)
{
    if(top != NULL) return 1;
    else return 0;
}

/*-----------------------TREE-----------------------------------*/
void create( tree **root ,Queue**front,Queue **rear)    // funtion to create a tree 
{
    tree *temp , *p;
    int x;

    *root = (tree *) malloc (sizeof(tree));
    
    printf("Eneter root value ");
    scanf("%d",&(*root)->data);
    (*root)->left =NULL;
    (*root)->right = NULL;

    enque(*root,front , rear);

    while(! isEmpty(*front, *rear))
    {
        p = deque(front ,rear);
        printf("eneter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            temp=(tree *)malloc(sizeof(tree));
            temp->data=x;
            temp->left =NULL;
            temp->right=NULL;
            p->left=temp;
            enque(temp, front , rear);
        }

        printf("eneter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            temp=(tree *)malloc(sizeof(tree));
            temp->data=x;
            temp->left =NULL;
            temp->right=NULL;
            p->right=temp;
            enque(temp, front , rear);
        }
    }
}

void Preorder(tree *p)
{
    Stack *top;
    tree *temp = p;
    while(temp != NULL || isEmptystack(top))
    {
        if(temp!= NULL)
        {
            printf("%d ", temp->data);
            push(&top,temp);
            temp = temp->left;
        }
        else
        {
            temp = pop(&top);
            temp = temp->right;
        }
    }
}

void Inorder(tree *p)
{
    Stack *top;
    tree *temp = p;
    while(temp != NULL || isEmptystack(top))
    {
        if(temp!= NULL)
        {
            push(&top,temp);
            temp = temp->left;
        }
        else
        {
            temp = pop(&top);
            printf("%d ", temp->data);
            temp = temp->right;
        }
    }
}

void Postorder(tree *p)
{
    Stack *top1, *top2;
    top1->data = p;
    tree *curr = NULL;

    while(!isEmptystack(top1))
    {
        curr = top1->data;
        pop(&top1);
        push(&top2 ,curr);
        if(curr->left != NULL)
            push(&top1, curr->left);
        if(curr->right != NULL)
            push(&top1, curr->right);
    }
    while(!isEmptystack(top2))
    {
        curr = top2->data;
        printf("%d ",curr->data);
        pop(&top2);
    }
}

void Levelordere(tree *p)
{
    Queue *f,*r;
    printf("%d ",p->data);
    enque(p,&f,&r);
    while (!isEmpty(f,r))
    {
        p = deque(&f,&r);
        if(p->left)
        {
            printf("%d ",p->left->data);
            enque((p->left),&f,&r);
        }
        if(p->right)
        {
            printf("%d ",p->right->data);
            enque((p->right),&f,&r);
        }
    }
}

int  count (tree *p)
{
    int x, y=0;
    if(p!=NULL){
    x=count(p->left);
    y = count(p->right);
    return x+y+1;
    }
    return 0;
}

int main()
{
    Queue *front= 0;
    Queue *rear = 0;
    tree *root = 0; // root node of a tree;
    create( &root ,&front , &rear); // calling  the create tree funtion

    printf("No of nodes in given tree is:%d \n",count(root));
    
    printf("\nPreorder Traversal is : ");
    Preorder(root);
    printf("\nInorder Traversal is : ");
    Inorder(root);
    printf("\nPostorder Traversal is : ");
    Postorder(root);
    printf("\nLevelorder Traversal is : ");
    Levelordere(root);
    printf("No of nodes in given tree is:",count(root));

    return 0;
}