#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *InsertAtBeginning(Node *head)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (!ptr)
    {
        printf("Memory Allocation Failed !\n");
        return head;
    }
    int e;
    printf("Enter an element to Insert: ");
    scanf("%d", &e);
    ptr->data = e;
    ptr->next = head;
    head = ptr;

    printf("%d is Inserted at the Beginning\n", e);

    return head;
}
Node *InsertAtIndex(Node *head)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (!ptr)
    {
        printf("Memory Allocation Failed !\n");
        return head;
    }
    int k;
    printf("Enter an Index: ");
    scanf("%d", &k);
    if (k == 0)
    {
        return head = InsertAtBeginning(head);
    }

    if (head == NULL)
    {
        return head = InsertAtBeginning(head);
    }

    int e;
    printf("Enter an element to Insert: ");
    scanf("%d", &e);
    ptr->data = e;

    Node *p = head;
    for (int i = 0; i < k - 1 && p != NULL; i++)
        p = p->next;
    ptr->next = p->next;
    p->next = ptr;

    printf("%d is Inserted at the Index %d\n", e, k);

    return head;
}
Node *InsertAtEnd(Node *head)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    if (!ptr)
    {
        printf("Memory Allocation Failed !\n");
        return head;
    }

    if (head == NULL)
    {
        return head = InsertAtBeginning(head);
    }

    int e;
    printf("Enter an element to Insert: ");
    scanf("%d", &e);
    ptr->data = e;
    ptr->next = NULL;

    Node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = ptr;

    return head;
}
Node *DeleteFromBeginning(Node *head)
{
    return head;
}
Node *DeleteFromIndex(Node *head)
{
    return head;
}
Node *DeleteFromEnd(Node *head)
{
    return head;
}

void Display(Node *head)
{
    if (head == NULL)
    {
        printf("List is already Empty !\n");
        return;
    }
    Node *p = head;
    printf("Linked List: ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void freeNode(Node *head)
{
    Node *t = head;
    while (head != NULL)
    {
        t = head;
        head = head->next;
        free(t);
    }
}

int main()
{
    Node *head = NULL;
    while (1)
    {
        int c;
        printf("\nMenu: \n");
        printf(" 1.Insert at Beginning\n 2.Insert at Index\n 3.Insert at End\n 4.Delete from Beginning\n 5.Delete from Index\n 6.Delete from End\n 7.Display\n 8.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            head = InsertAtBeginning(head);
            break;
        case 2:
            head = InsertAtIndex(head);
            break;
        case 3:
            head = InsertAtEnd(head);
            break;
        case 4:
            head = DeleteFromBeginning(head);
            break;
        case 5:
            head = DeleteFromIndex(head);
            break;
        case 6:
            head = DeleteFromEnd(head);
            break;
        case 7:
            Display(head);
            break;
        case 8:
            freeNode(head);
            printf("Exiting...");
            exit(0);
        }
    }
    return 0;
}