#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *insertAtBeginning(Node *head)
{
}

Node *insertAtMiddle(Node *head)
{
}

Node *insertAfterValue(Node *head)
{
}

Node *insertAtEnd(Node *head)
{
}

Node *deleteFromBeginning(Node *head)
{
}

Node *deleteFromMiddle(Node *head)
{
}

Node *deleteFromEnd(Node *head)
{
}

void Traversal(Node *head)
{
}

int main()
{
    Node *head = NULL;
    while (1)
    {
        int c;
        printf(" 1. Insert at the beginning\n 2. Insert at the middle\n 3. Insert after a value\n 4. Insert at end\n 5. Delete from the beginning\n 6. Delete from the middle\n 7. Delete from the end\n 8. Traversal\n 9. Exit\n ");
        printf("Enter your Choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            head = insertAtBeginning(head);
            break;

        case 2:
            head = insertAtMiddle(head);
            break;

        case 3:
            head = insertAfterValue(head);
            break;

        case 4:
            head = insertAtEnd(head);
            break;

        case 5:
            head = deleteFromBeginning(head);
            break;

        case 6:
            head = deleteFromMiddle(head);
            break;

        case 7:
            head = deleteFromEnd(head);
            break;

        case 8:
            Traversal(head);
            break;

        case 9:
            freeList(head);
            exit(0);

        default:
            printf("Invalid choice...\n");
        }
    }
}