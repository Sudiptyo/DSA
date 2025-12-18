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

    printf("\nElements: ");
    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
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

// Insert at first
struct Node *InsertatFirst(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return head;
    }

    int data;
    printf("\nEnter a Data to insert: ");
    scanf("%d", &data);

    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Insert at a specific index
struct Node *InsertatIndex(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return head;
    }

    int data, index;
    printf("\nEnter a Data to insert: ");
    scanf("%d", &data);

    printf("Enter an index to Insert: ");
    scanf("%d", &index);

    ptr->data = data;

    if (index == 0)
    {
        ptr->next = head;
        return ptr;
    }

    struct Node *p = head;
    for (int i = 0; i < index - 1 && p != NULL; i++)
        p = p->next;

    if (p == NULL)
    {
        printf("Index out of bounds!\n");
        free(ptr);
        return head;
    }

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Insert at end
struct Node *InsertatEnd(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return head;
    }

    int data;
    printf("\nEnter a Data to insert: ");
    scanf("%d", &data);

    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
        return ptr;

    struct Node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = ptr;
    return head;
}

// Delete at first
struct Node *DeleteatFirst(struct Node *head)
{
    if (head == NULL)
        return NULL;

    struct Node *ptr = head;
    head = head->next;
    free(ptr);
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

// Delete by Value
struct Node *DeletebyValue(struct Node *head)
{
    int value;
    printf("Enter a Value to Delete: ");
    scanf("%d",&value);
    
    struct Node *ptr = head;
    struct Node *prev = NULL;
    
    if(ptr == NULL)
    {
        printf("List is Empty\n");
        return head;
    }
    
    // Case 1: Head node itself holds the value
    if(ptr != NULL && ptr -> data == value)
    {
        head = ptr -> next;
        free(ptr);
        return head;
    }
    
    // Case 2: Search for the value
        while(ptr != NULL && ptr -> data != value)
    {
        prev = ptr;
        ptr = ptr -> next;
    }
    
    // If value not found
    if(ptr == NULL)
    {
        printf("Value %d not found in list.\n", value);
        return head;
    }
    
    // Case 3: Value found -> unlink node
    prev->next = ptr->next;
    free(ptr);
    
    return head;
}

// Delete at end
struct Node *DeleteatEnd(struct Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
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

// Search an Element
void Search(struct Node *head)
{
    int element, index = 0;
    printf("Enter an element to search: ");
    scanf("%d", &element);

    struct Node *ptr = head;

    while (ptr != NULL)
    {
        if (ptr->data == element)
        {
            printf("Element %d is Found at index: %d", element, index);
            return;
        }
        ptr = ptr->next;
        index++;
    }
    printf("Element not Found in the List");
}

int main()
{
    struct Node *head = NULL;

    while (1)
    {
        int choice;
        printf("\nMenu:\n");
        printf(" 1. Insert at First\n 2. Insert at Index\n 3. Insert at End\n");
        printf(" 4. Delete at First\n 5. Delete at Index\n 6. Delete by Value\n");
        printf(" 7. Delete at End\n 8. Traversal\n 9. Search an element\n");
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
            head = DeletebyValue(head);
            break;
        case 7:
            head = DeleteatEnd(head);
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
            break;
        default:
            printf("Invalid Choice...\n");
        }
    }

    return 0;
}
