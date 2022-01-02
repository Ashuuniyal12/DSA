#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{                                      // decleartion of tree node 
    int data;
    struct treeNode *left;
    struct treeNode *right;
} tree;BinaryTreeUsingRecursion
/*------------------Recursive functions --------------*/
tree * create()
{
  int x; 
  tree *newnode;
  newnode = (tree *) malloc (sizeof(tree));

  printf("\nEnter the data (-1 for no node)");
  scanf("%d",&x);
  if(x==-1) 
  {
      return 0;
  }
  newnode->data = x;
  printf("\nEnter the left child of %d ",x);
  newnode->left = create();
  printf("\nEnter the right child of %d",x);
  newnode->right = create();

  return newnode;
}

void Preorder(tree *p)
{
 if(p)
 {
    printf("Preorder treversal of tree is : \n")
    printf("%d ",p->data);
    Preorder(p->left);
    Preorder(p->right);
 }
}

void Inorder(tree *p)
{
 if(p)
 {
    printf("Inorder treversal of tree is : \n")
    Inorder(p->left);
    printf("%d ",p->data);
    Inorder(p->right);
 }
}void Postorder(tree *p)
{
 if(p)
 {
    printf("Postorder treversal of tree is : \n")
    Postorder(p->left);
    Postorder(p->right);
    printf("%d ",p->data);
 }
}

 int main()
 {
     tree * root ; 
     root = create();
     Preorder(root);
 }
