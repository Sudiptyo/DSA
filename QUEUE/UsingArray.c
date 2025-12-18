#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Maximum size of the Queue // (n)

int Queue[MAX], FRONT = -1, REAR = -1; // Queue array with FRONT and REAR pointers

void Enqueue()
{
    if (REAR == MAX - 1) // Check if Queue is full
    {
        printf("Queue Overflow !\n");
    }
    else
    {
        if (FRONT == -1)
            FRONT = 0; // If inserting the first element, set FRONT = 0
        int a;
        printf("Enter an Element to insert: ");
        scanf("%d", &a);

        Queue[++REAR] = a; // Increment REAR and insert element
        printf("%d is Inserted into the Queue\n", a);
    }
}

void Dequeue()
{
    if (FRONT == -1 || FRONT > REAR) // Check if Queue is empty
    {
        printf("Queue Underflow !\n");
    }
    else
    {
        printf("%d is Deleted from the Queue\n", Queue[FRONT++]); // Remove element at FRONT

        if (FRONT > REAR) // If Queue becomes empty after deletion, reset FRONT and REAR
        {
            FRONT = REAR = -1;
        }
    }
}

void Peek()
{
    if (FRONT == -1 || FRONT > REAR) // Check if Queue is empty
    {
        printf("Queue Underflow !\n");
        return;
    }

    printf("The Last Inserted Element = %d\n", Queue[FRONT]); // Element at FRONT
    printf("The First Inserted Element = %d\n", Queue[REAR]);   // Element at REAR
}

void Traversal()
{
    if (FRONT == -1 || FRONT > REAR) // Check if Queue is empty
    {
        printf("Queue is Empty, Nothing to Display !\n");
        return;
    }

    int i;
    printf("Queue Elements (Front -> Rear): ");
    for (i = FRONT; i <= REAR; i++) // Print from FRONT to REAR
    {
        printf("%d ", Queue[i]);
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        int c;
        printf("\nMenu: \n");
        printf(" 1. Enqueue (Insert)\n 2. Dequeue (Delete)\n 3. Peek (Front & Rear)\n 4. Traversal (Front -> Rear)\n 5. Exit\n");
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