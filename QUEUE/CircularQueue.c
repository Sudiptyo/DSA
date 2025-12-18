#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 // Maximum size of the Queue

int CQueue[SIZE], FRONT = -1, REAR = -1; // Queue array with FRONT and REAR pointers

// Insert element in circular queue
void Enqueue()
{
    if ((REAR + 1) % SIZE == FRONT) // Check if Queue is full
    {
        printf("Queue Overflow !\n");
    }
    else
    {
        if (FRONT == -1) // First insertion
            FRONT = 0;

        int a;
        printf("Enter an Element to insert: ");
        scanf("%d", &a);

        REAR = (REAR + 1) % SIZE; // Move REAR circularly
        CQueue[REAR] = a;
        printf("%d is Inserted into the Queue\n", a);
    }
}

// Delete element from circular queue
void Dequeue()
{
    if (FRONT == -1) // Queue empty
    {
        printf("Queue Underflow !\n");
    }
    else
    {
        printf("%d is Deleted from the Queue\n", CQueue[FRONT]); // Print current FRONT

        if (FRONT == REAR) // Only one element left
        {
            FRONT = REAR = -1;
        }
        else
        {
            FRONT = (FRONT + 1) % SIZE; // Move FRONT circularly
        }
    }
}

// Show front and rear elements
void Peek()
{
    if (FRONT == -1) // Queue empty
    {
        printf("Queue Underflow !\n");
        return;
    }

    printf("The First Inserted Element = %d\n", CQueue[FRONT]); // FRONT element
    printf("The Last Inserted Element = %d\n", CQueue[REAR]);   // REAR element
}

// Display all elements
void Traversal()
{
    if (FRONT == -1) // Queue empty
    {
        printf("Queue is Empty, Nothing to Display !\n");
        return;
    }

    printf("Queue Elements : ");
    int i = FRONT;
    while (1)
    {
        printf("%d ", CQueue[i]);
        if (i == REAR)
            break;          // Stop at REAR
        i = (i + 1) % SIZE; // Move circularly
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
            exit(0); // Exit program
        default:
            printf("Invalid Choice...\n");
        }
    }
    return 0;
}