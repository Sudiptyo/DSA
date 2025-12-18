#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

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

struct Node *InsertatFirst(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    int data1;

    printf("\nEnter a Data to insert: ");
    scanf("%d", &data1);

    if (ptr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return head;
    }

    ptr->data = data1;
    ptr->next = head;

    printf("\n");

    return ptr;
}

struct Node *InsertatIndex(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    struct Node *p = head;

    int data2, index;

    printf("\nEnter a Data to insert: ");
    scanf("%d", &data2);

    printf("\nEnter an index to Insert: ");
    scanf("%d", &index);

    if (ptr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return head;
    }

    ptr->data = data2;

    if (index == 0)
    {
        ptr->next = head;

        return ptr;
    }

    int i = 0;

    while (p != NULL && i < index - 1)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        printf("Index out of Bound !!\n");

        free(ptr);

        return head;
    }

    ptr->next = p->next;
    p->next = ptr;

    printf("\n");

    return head;
}

struct Node *InsertatEnd(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return head;
    }

    int data3;
    printf("\nEnter a Data to insert: ");
    scanf("%d", &data3);
    ptr->data = data3;
    ptr->next = NULL;

    if (head == NULL)
        return ptr; // new node becomes head

    struct Node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = ptr;
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
        printf(" 1. Insert at First\n 2. Insert at an Index\n 3. Insert at End\n 4. Traversal\n 5. Exit\n");

        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = InsertatFirst(head);
            break;

        case 2:
            head = InsertatIndex(head);
            break;

        case 3:
            head = InsertatEnd(head);
            break;

        case 4:
            Traversal(head);
            break;

        case 5:
            FreeList(head);
            exit(0);
            break;

        default:
            printf("Invalid Choice...");
        }
    }

    return 0;
}