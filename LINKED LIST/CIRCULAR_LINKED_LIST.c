#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traverse and print the circular linked list
void Traversal(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n\n");
        return;
    }

    struct Node *ptr = head;
    printf("\nElements: ");
    do
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

// Free all nodes in circular linked list
void FreeList(struct Node *head)
{
    if (head == NULL)
        return;

    struct Node *ptr = head->next;
    struct Node *t;
    while (ptr != head)
    {
        t = ptr;
        ptr = ptr->next;
        free(t);
    }
    free(head);
}

// Insert at first
struct Node *InsertatFirst(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (!ptr)
    {
        printf("Memory Allocation Failed\n");
        return head;
    }

    int data;
    printf("\nEnter a Data to insert: ");
    scanf("%d", &data);
    ptr->data = data;

    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }

    struct Node *tail = head;
    while (tail->next != head)
        tail = tail->next;

    ptr->next = head;
    tail->next = ptr;

    return ptr; // new head
}

// Insert at end
struct Node *InsertatEnd(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (!ptr)
    {
        printf("Memory Allocation Failed\n");
        return head;
    }

    int data;
    printf("\nEnter a Data to insert: ");
    scanf("%d", &data);
    ptr->data = data;

    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }

    struct Node *tail = head;
    while (tail->next != head)
        tail = tail->next;

    tail->next = ptr;
    ptr->next = head;

    return head;
}

// Insert at index
struct Node *InsertatIndex(struct Node *head)
{
    int index;
    printf("\nEnter an index to Insert: ");
    scanf("%d", &index);

    if (index < 0)
    {
        printf("Invalid index!\n");
        return head;
    }

    if (index == 0)
        return InsertatFirst(head);

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (!ptr)
    {
        printf("Memory Allocation Failed\n");
        return head;
    }

    int data;
    printf("\nEnter a Data to insert: ");
    scanf("%d", &data);
    ptr->data = data;

    struct Node *p = head;
    int i;
    for (i = 0; i < index - 1; i++)
    {
        p = p->next;
        if (p == head)
        {
            printf("Index out of bounds!\n");
            free(ptr);
            return head;
        }
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Delete at first
struct Node *DeleteatFirst(struct Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *tail = head;
    while (tail->next != head)
        tail = tail->next;

    struct Node *ptr = head;
    head = head->next;
    tail->next = head;

    free(ptr);
    return head;
}

// Delete at end
struct Node *DeleteatEnd(struct Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = NULL;

    while (p->next != head)
    {
        q = p;
        p = p->next;
    }

    q->next = head;
    free(p);

    return head;
}

// Delete at index
struct Node *DeleteatIndex(struct Node *head)
{
    if (head == NULL)
        return NULL;

    int index;
    printf("\nEnter an index to Delete: ");
    scanf("%d", &index);

    if (index < 0)
    {
        printf("Invalid index!\n");
        return head;
    }

    if (index == 0)
        return DeleteatFirst(head);

    struct Node *p = head;
    struct Node *q = NULL;
    int i;
    for (i = 0; i < index; i++)
    {
        q = p;
        p = p->next;
        if (p == head)
        {
            printf("Index out of bounds!\n");
            return head;
        }
    }

    q->next = p->next;
    free(p);

    return head;
}

// Delete by Value
struct Node *DeletebyValue(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return NULL;
    }

    int value;
    printf("Enter a Value to Delete: ");
    scanf("%d", &value);

    struct Node *ptr = head;
    struct Node *prev = NULL;

    // Case 1: head itself holds the value
    if (head->data == value)
    {
        if (head->next == head) // only one node
        {
            free(head);
            return NULL;
        }

        struct Node *tail = head;
        while (tail->next != head)
            tail = tail->next;

        head = head->next;
        tail->next = head;
        free(ptr);

        return head;
    }

    // Case 2: search value in the list
    do
    {
        prev = ptr;
        ptr = ptr->next;

        if (ptr->data == value)
        {
            prev->next = ptr->next;
            free(ptr);
            return head;
        }
    } while (ptr != head);

    printf("Value %d not found in list.\n", value);
    return head;
}

// Search an Element
void Search(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    int element, index = 0;
    printf("Enter an element to search: ");
    scanf("%d", &element);

    struct Node *ptr = head;
    do
    {
        if (ptr->data == element)
        {
            printf("Element %d found at index: %d\n", element, index);
            return;
        }
        ptr = ptr->next;
        index++;
    } while (ptr != head);

    printf("Element %d not found in the list\n", element);
}

int main()
{
    struct Node *head = NULL;

    while (1)
    {
        int choice;
        printf("\nMenu:\n");
        printf(" 1. Insert at First\n 2. Insert at Index\n 3. Insert at End\n");
        printf(" 4. Delete at First\n 5. Delete at Index\n 6. Delete at End\n");
        printf(" 7. Delete by Value\n 8. Traversal\n 9. Search an Element\n");
        printf(" 10. Exit\n");

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
            head = DeleteatFirst(head);
            break;
        case 5:
            head = DeleteatIndex(head);
            break;
        case 6:
            head = DeleteatEnd(head);
            break;
        case 7:
            head = DeletebyValue(head);
            break;
        case 8:
            Traversal(head);
            break;
        case 9:
            Search(head);
            break;
        case 10:
            FreeList(head);
            exit(0);
        default:
            printf("Invalid Choice...\n");
        }
    }

    return 0;
}
