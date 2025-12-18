#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum number of vertices allowed

int adj[MAX][MAX];   // Adjacency matrix to store graph
int n;               // Number of vertices in the graph

void BFS()
{
    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Check if start vertex is within valid range
    if (start < 0 || start >= n)
    {
        printf("Invalid Start Vertex!\n");
        return;
    }

    int visited[MAX] = {0}; // Tracks whether a vertex is visited or not
    int queue[MAX];         // Array used as queue for BFS
    int front = 0, rear = 0; // Queue front and rear pointers

    visited[start] = 1;      // Mark the starting vertex as visited
    queue[rear++] = start;   // Insert start vertex into queue

    printf("BFS Traversal: ");

    // Continue until queue becomes empty
    while (front < rear)
    {
        int node = queue[front++]; // Dequeue the first element

        printf("%d ", node);       // Print the visited node

        // Explore all adjacent vertices of 'node'
        for (int i = 0; i < n; i++)
        {
            // If an edge exists AND vertex is not visited
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;     // Mark as visited
                queue[rear++] = i;  // Enqueue the vertex
            }
        }
    }

    printf("\n");
}

void CreateGraph()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Check valid vertex count
    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices!\n");
        return;
    }

    // Input adjacency matrix
    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    printf("NOTE: Use 1 for edge, 0 for no edge.\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Graph Created Successfully!\n");
}

void DisplayGraph()
{
    // Check if graph exists
    if (n == 0)
    {
        printf("Graph Not Created Yet!\n");
        return;
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        int c;

        // Menu for user
        printf("\nMenu:\n");
        printf(" 1. Create Graph\n");
        printf(" 2. Display Graph\n");
        printf(" 3. BFS Traversal\n");
        printf(" 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        // Menu-driven operations
        switch (c)
        {
        case 1:
            CreateGraph();
            break;
        case 2:
            DisplayGraph();
            break;
        case 3:
            BFS();
            break;
        case 4:
            exit(0); // Exit program
        default:
            printf("Invalid Choice...\n");
        }
    }

    return 0;
}
