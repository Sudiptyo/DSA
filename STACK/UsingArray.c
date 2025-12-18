#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Maximum size of the stack // (n)

int Stack[MAX], Top = -1; // Stack array and Top pointer

void Push()
{
    if (Top == MAX - 1) // Check if stack is full
    {
        printf("Stack Overflow !\n");
    }
    else
    {
        int x;
        printf("Enter a number to Push: ");
        scanf("%d", &x);

        Stack[++Top] = x; // First Increment Top and then insert element
        printf("%d is Pushed into the Stack\n", x);
    }
}

void Pop()
{
    if (Top == -1) // Check if stack is empty
    {
        printf("Stack Underflow !\n");
    }
    else
    {
        printf("%d is Popped from the Stack\n", Stack[Top--]); // Remove top
    }
}

void Peek()
{
    if (Top == -1) // Check if stack is empty
    {
        printf("Stack is Empty, Nothing to Peek !\n");
        return;
    }

    printf("Top Element: %d\n", Stack[Top]);
}

void Traversal()
{
    if (Top == -1) // Check if stack is empty
    {
        printf("Stack is Empty, Nothing to Display !\n");
        return;
    }

    printf("Stack Elements (Top -> Bottom): ");
    for (int i = Top; i >= 0; i--) // Print from top to bottom
    {
        printf("%d ", Stack[i]);
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        int c;
        printf("\nMenu: \n");
        printf(" 1. Push (Insert)\n 2. Pop (Delete)\n 3. Peek (Top)\n 4. Traversal (Top -> Bottom)\n 5. Exit\n");
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