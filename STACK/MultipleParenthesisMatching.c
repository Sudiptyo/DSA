#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100   

char Stack[MAX]; 
int Top = -1;

void Push(char x)
{
    if (Top == MAX - 1)  
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        Stack[++Top] = x;
    }
}

char Pop()
{
    if (Top == -1)  
    {
        return '\0';  // Return null character to indicate no element
    }
    else
    {
        return Stack[Top--];  
    }
}

// Function to check if two brackets form a valid pair
int MatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']');
}

// Function to check whether an expression has balanced brackets
int isBalanced(char exp[])
{
    for (int i = 0; exp[i] != '\0'; i++)  // Traverse the expression
    {
        char ch = exp[i];

        // If character is an opening bracket, push it
        if (ch == '(' || ch == '{' || ch == '[')
        {
            Push(ch);
        }
        // If character is a closing bracket, check with top of stack
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            char popped = Pop();  // Pop last opening bracket
            if (!MatchingPair(popped, ch))  // If not matching
            {
                return 0;  // Expression is not balanced
            }
        }
    }
    // Expression is balanced only if stack is empty in the end
    return (Top == -1);
}

int main()
{
    char expression[MAX];

    printf("Enter an Expression: ");
    fgets(expression, MAX, stdin);  

    // Remove newline character added by fgets
    expression[strcspn(expression, "\n")] = '\0';
    
    if (isBalanced(expression))
        printf("The expression is Balanced.\n");
    else
        printf("The expression is NOT Balanced.\n");
        
    return 0;
}
