#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traverse and print the list
void Traversal(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("List is Empty\n\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
}

// Free all nodes
void FreeList(struct Node *head)
{
    struct Node *t;

    while (head != NULL)
    {
        t = head;
        head = head->next;
        free(t);
    }
}

// Delete the first node
struct Node *DeleteatFirst(struct Node *head)
{
    if (head == NULL)
        return NULL;

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Delete node at a specific index
struct Node *DeleteatIndex(struct Node *head)
{
    if (head == NULL)
        return NULL;

    int index;
    printf("\nEnter an index to Delete: ");
    scanf("%d", &index);

    if (index == 0)
        return DeleteatFirst(head);

    struct Node *p = head;
    for (int i = 0; i < index - 1 && p->next != NULL; i++)
        p = p->next;

    if (p->next == NULL)
    {
        printf("Index out of bounds!\n");
        return head;
    }

    struct Node *q = p->next;
    p->next = q->next;
    free(q);

    return head;
}

// Delete the last node
struct Node *DeleteatEnd(struct Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL) // Only one node
    {
        free(head);
        return NULL;
    }

    struct Node *p = head;
    while (p->next->next != NULL)
        p = p->next;

    free(p->next);
    p->next = NULL;

    return head;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 5;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 7;
    second->next = third;

    third->data = 6;
    third->next = NULL;

    while (1)
    {
        int choice;

        printf("Menu: \n");
        printf(" 1. Delete at First\n 2. Delete at an Index\n 3. Delete at End\n 4. Traversal\n 5. Exit\n");

        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = DeleteatFirst(head);
            break;

        case 2:
            head = DeleteatIndex(head);
            break;

        case 3:
            head = DeleteatEnd(head);
            break;

        case 4:
            Traversal(head);
            break;

        case 5:
            FreeList(head);
            exit(0);
            break;

        default:
            printf("Invalid Choice...\n");
        }
    }

    return 0;
}
