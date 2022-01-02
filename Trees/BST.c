#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} tree;

void insert(tree **root, int key)
{
    tree *newnode = NULL;
    if ((*root) == NULL)
    {
        newnode = (tree *)malloc(sizeof(tree));
        newnode->data = key;
        newnode->left = newnode->right = NULL;
        (*root) = newnode;
        return;
    }
    if ((*root)->data == key)
        return;
    else if (key < (*root)->data)
        insert(&(*root)->left, key);
    else
        insert(&(*root)->right, key);
}

// height of tree
int height(tree *root)
{
    int x, y;
    tree *temp = root;
    if (temp == NULL)
        return 0;
    x = height(temp->left);
    y = height(temp->right);
    return x > y ? x + 1 : y + 1;
}

// inorder predessor
tree *InPredressor(tree *root)
{

    while (root && root->right)
        root = root->right;

    return root;
}

// inorder successor
tree *InSuccessor(tree *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

void delete (tree **mainroot, int key)
{
    tree *root = *mainroot;
    if (root->left == NULL && (root->right == NULL))
    {
        if(root->data == key)
        {
            free(root);
            return;
        }
        else
        {
            printf("Key not found");
            return;
        }
    }
    
    // search for the element to be deleted
    if (key < root->data)
    {
        delete (&root->left, key);
    }
    else if (key > root->data)
    {
       delete (&root->right, key);
    }
        
    else
    {
        /*  once the element is found then decide wether successor or predessor
            which side element need to be replaced with the node to be reomved d
            on the basis of the height of both the trees.   */

        if ((height(root->left)) > (height(root->right)))
        {
            tree *q = InPredressor(root->left);
            root->data = q->data;
            delete (&root->left, q->data);
        }
        else
        {
            tree *q = InSuccessor(root->right);
            root->data = q->data;              
            delete (&root->right, q->data);     
        }
    }
}

void Inorder(tree *p)
{
    if (p)
    {
        Inorder(p->left);
        printf("%d ", p->data);
        Inorder(p->right);
    }
}

int main()
{
    tree *root = NULL;
    insert(&root, 50);
    insert(&root, 49);
    insert(&root, 70);
    insert(&root, 75);
    insert(&root, 90);
    insert(&root, 95);
    printf("Inorder treversal of tree is : \n");
    Inorder(root);
    delete (&root,75);
    printf("\nInorder treversal of tree is : \n");
    Inorder(root);
    delete (&root,49);
    printf("\nInorder treversal of tree is : \n");
    Inorder(root);
}