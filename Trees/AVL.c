#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    int height;
    struct node *right;

} tree;

int NodeHeight(tree *root)
{
    int hl, hr;
    hl = root && root->left ? root->height : 0;
    hr = root && root->right ? root->height : 0;
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(tree *root)
{
    int hl, hr;
    hl = root && root->left ? root->height : 0;
    hr = root && root->right ? root->height : 0;
    return hl - hr;
}

void LLRotation(tree **root)
{
    tree *rootLeft = (*root)->left;
    tree *rootLeftRight = (*root)->left->right;

    rootLeft->right = *root;
    (*root)->left = rootLeftRight;

    (*root)->height = NodeHeight(*root);
    rootLeft->height = NodeHeight(rootLeft);
}

void LRRotation(tree **root)
{
    tree *rootLeft = (*root)->left;
    tree *rootLeftRight = (*root)->left->right;

    rootLeft->right = rootLeftRight->left;
    (*root)->left = rootLeftRight->right;
    rootLeftRight->left = rootLeft;
    rootLeftRight->right = *root;

    (*root)->height = NodeHeight(*root);
    rootLeftRight->height = NodeHeight(rootLeftRight);
    rootLeft->height = NodeHeight(rootLeft);
}

void RRRotation(tree **root)
{
    tree * rootRight = (*root)->right;
    tree * rootRightLeft = (*root)->right->left;

    (*root)->right = rootRight->left;
    rootRight->left = (*root);

    (*root)->height = NodeHeight(*root);
    rootRight->height = NodeHeight(rootRight);

}
void RLRotation(tree **root)
{
    tree *rootRight = (*root)->right;
    tree *rootRightLeft = (*root)->right->left;

    rootRight->left = rootRightLeft->right;
    (*root)->right = rootRightLeft->left;
    rootRightLeft->left = *root;
    rootRightLeft->right = rootRight;

    (*root)->height = NodeHeight(*root);
    rootRightLeft->height = NodeHeight(rootRightLeft);
    rootRight->height = NodeHeight(rootRight);

}

void insert(tree **root, int key)
{
    tree *newnode = NULL;
    
    if ((*root) == NULL)
    {
        newnode = (tree *)malloc(sizeof(tree));
        newnode->data = key;
        newnode->height = 1;
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

    (*root)->height = NodeHeight(*root);

    // perform rotation.
    if (BalanceFactor(*root) == 2 && BalanceFactor((*root)->left) == 1)
        LLRotation(root);
    else if (BalanceFactor(*root) == 2 && BalanceFactor((*root)->right) == -1)
        LRRotation(root);
    else if (BalanceFactor(*root) == -2 && BalanceFactor((*root)->right) == -1)
        RRRotation(root);
    else if (BalanceFactor(*root) == -2 && BalanceFactor((*root)->right) == 1)
        RLRotation(root);
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

    insert(&root, 20);
    insert(&root, 35);
    insert(&root, 30);
    insert(&root, 5);
    insert(&root, 10);
    insert(&root, 40);
    insert(&root, 25);
    insert(&root, 27);
    insert(&root, 50);
    insert(&root, 60);
    Inorder(root);

}