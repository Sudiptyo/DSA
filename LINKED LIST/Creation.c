#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;          // Data part of the node
    struct Node *next; // Pointer to the next node
};

// Function to traverse the linked list and print elements
void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL) // Loop until the end of the list
    {
        printf("Element: %d\n", ptr->data); // Print the current node's data
        ptr = ptr->next;                    // Move to the next node
    }
}

int main()
{
    // Declare pointers for the nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for each node
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first node to second node
    head->data = 1;      // Assign data to head node
    head->next = second; // Point head to second node

    // Link second node to third node
    second->data = 2;     // Assign data to second node
    second->next = third; // Point second node to third node

    // Link third node to fourth node
    third->data = 3;      // Assign data to third node
    third->next = fourth; // Point third node to fourth node

    // Link fourth node to NULL (end of the list)
    fourth->data = 4;    // Assign data to fourth node
    fourth->next = NULL; // Marks the end of the linked list

    // Call traversal function to display the linked list
    LinkedListTraversal(head);

    return 0;
}
