#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *FRONT = NULL;
struct Node *REAR = NULL;

void Enqueue()
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) // If memory not available
    {
        printf("Queue Overflow (Memory not available)\n");
    }
    else
    {
        int a; 
        printf("Enter an element to insert: ");
        scanf("%d", &a);

        ptr->data = a;    // Store data in new node
        ptr->next = NULL; // New node will be the last node

        // If queue is empty (first node)
        if (FRONT == NULL)
        {
            FRONT = REAR = ptr; // Both FRONT and REAR point to new node
        }
        else
        {
            REAR->next = ptr; // Link old REAR to new node
            REAR = ptr;       // Move REAR to new node
        }
        printf("%d inserted into the Queue\n", a);
    }
}

void Dequeue()
{
    if (FRONT == NULL) // Queue empty
    {
        printf("Queue Underflow (No element to delete)\n");
    }
    else
    {
        struct Node *ptr = FRONT; // Temp pointer to FRONT
        printf("%d is Deleted from the Queue\n", FRONT->data);

        FRONT = FRONT->next; // Move FRONT to next node
        free(ptr);           // Free memory of deleted node

        // If queue becomes empty after deletion
        if (FRONT == NULL)
        {
            REAR = NULL; // Reset REAR also
        }
    }
}

void Peek()
{
    if (FRONT == NULL) // Queue empty
    {
        printf("Queue Underflow (No elements)\n");
        return;
    }
    printf("The First Inserted Element = %d\n", FRONT->data);
    printf("The Last Inserted Element = %d\n", REAR->data);
}

void Traversal()
{
    if (FRONT == NULL) // Queue empty
    {
        printf("Queue Underflow (No elements)\n");
        return;
    }
    struct Node *ptr = FRONT;
    printf("Queue Elements: ");
    while (ptr != NULL) // Traverse until last node
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        int c;
        printf("\nMenu: \n");
        printf(" 1. Enqueue (Insert)\n 2. Dequeue (Delete)\n 3. Peek (Front & Rear)\n 4. Traversal (Display)\n 5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Traversal();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice...\n");
        }
    }
    return 0;
}