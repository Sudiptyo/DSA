#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the linked list
struct Node
{
    int data;              // Data part of the node
    struct Node * next;    // Pointer to the next node
};

// Function to traverse the linked list and print elements
void LinkedListTraversal(struct Node * ptr)
{
    while(ptr != NULL) // Loop until the end of the list
    {
        printf("Element: %d\n", ptr->data); // Print the current node's data
        ptr = ptr->next; // Move to the next node
    }
    
}

struct Node * InsertatFirst(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    if (ptr == NULL) 
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

struct Node * InsertatIndex(struct Node * head, int data, int index)
{
    
}

struct Node * InsertatEnd(struct Node * head, int data)
{
    
}

struct Node * InsertAfterNode(struct Node * head, int data, int index)
{
    
}

void FreeList(struct Node * head)
{
    // Free all nodes to avoid memory leaks
    struct Node *temp;
    while (head != NULL) 
    {
        temp = head;       // store current head
        head = head -> next; // move to the next node
        free(temp);        // free the old head
    }
}

int main()
{
    // Declare pointers for the nodes
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // Allocate memory for each node
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // Check if allocation failed for any node
    if (head == NULL || second == NULL || third == NULL || fourth == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1; // Exit the program with an error code
    }

    // Link first node to second node
    head->data = 1;      // Assign data to head node
    head->next = second; // Point head to second node

    // Link second node to third node
    second->data = 2;       // Assign data to second node
    second->next = third;   // Point second node to third node

    // Link third node to fourth node
    third->data = 3;        // Assign data to third node
    third->next = fourth;   // Point third node to fourth node

    // Link fourth node to NULL (end of the list)
    fourth->data = 4;       // Assign data to fourth node
    fourth->next = NULL;    // Marks the end of the linked list

    // Call traversal function to display the linked list
    // LinkedListTraversal(head);

    head = InsertatFirst(head, 5); // Insert 5 at the beginning of the linked list
    LinkedListTraversal(head);

    FreeList(head);

    return 0;
}