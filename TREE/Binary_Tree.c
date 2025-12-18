#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *Create_Node(const char *msg)
{
    Node *ptr = malloc(sizeof(Node));
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    int e;
    printf("%s", msg);
    scanf("%d", &e);
    ptr->data = e;
    ptr->left = NULL;
    ptr->right = NULL;

    return ptr;
}

void PreOrder(Node *ROOT)
{
    if (ROOT != NULL)
    {
        printf("%d ", ROOT->data);
        PreOrder(ROOT->left);
        PreOrder(ROOT->right);
    }
}

void InOrder(Node *ROOT)
{
    if (ROOT != NULL)
    {
        InOrder(ROOT->left);
        printf("%d ", ROOT->data);
        InOrder(ROOT->right);
    }
}

void PostOrder(Node *ROOT)
{
    if (ROOT != NULL)
    {
        PostOrder(ROOT->left);
        PostOrder(ROOT->right);
        printf(" %d", ROOT->data);
    }
}

void free_node(Node *ROOT)
{
    if (ROOT == NULL)
        return;
    free_node(ROOT->left);
    free_node(ROOT->right);
    free(ROOT);
}

int main()
{
    // Root Node
    Node *ROOT = Create_Node("Enter the root node data: ");
    // Left Node
    Node *LEFT = Create_Node("Enter the left node data: ");
    // Right Node
    Node *RIGHT = Create_Node("Enter the right node data: ");
    ROOT->left = LEFT;
    ROOT->right = RIGHT;

    // Left -> Left Node
    Node *LEFT_LEFT = Create_Node("Enter the left -> left node data: ");
    // Left -> Right Node
    Node *LEFT_RIGHT = Create_Node("Enter the left -> right node data: ");
    LEFT->left = LEFT_LEFT;
    LEFT->right = LEFT_RIGHT;

    printf("PreOrder: ");
    PreOrder(ROOT);
    printf("\n");

    printf("InOrder: ");
    InOrder(ROOT);
    printf("\n");

    printf("PostOrder: ");
    PostOrder(ROOT);
    printf("\n");

    free_node(ROOT);
    return 0;
}