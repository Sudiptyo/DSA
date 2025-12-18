#include <stdio.h>
#include <stdlib.h>

// Node structure for stack elements
struct Node
{
    int data;          // Data part
    struct Node *next; // Pointer to next node
};

struct Node *Top = NULL; // Global pointer to top of stack

void Push()
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory
    int data;
    printf("Enter a Value to Push: ");
    scanf("%d", &data);

    NewNode->data = data; // Store value
    NewNode->next = Top;  // Link new node with current top
    Top = NewNode;        // Update Top

    printf("%d is Pushed into the Stack\n", data);
}

void Pop()
{
    if (Top == NULL) // Stack empty check
    {
        printf("Stack Underflow !\n");
    }
    else
    {
        struct Node *temp = Top; // Store current top
        printf("%d is Popped from the Stack\n", Top->data);
        Top = Top->next; // Move Top to next node
        free(temp);      // Free memory of popped node
    }
}

void Peek()
{
    if (Top == NULL)
    {
        printf("Stack is Empty, Nothing to Peek !\n");
        return;
    }

    printf("Top Element: %d\n", Top->data);
}

void Traversal()
{
    if (Top == NULL)
    {
        printf("Stack is Empty, Nothing to Display !\n");
        return;
    }

    struct Node *ptr = Top;
    printf("Stack Elements (Top -> Bottom): ");
    while (ptr != NULL) // Traverse till last node
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    free(ptr);
}

int main()
{
    while (1)
    {
        int c;
        printf("\nMenu:\n");
        printf(" 1. Push\n 2. Pop\n 3. Peek\n 4. Traversal\n 5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
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