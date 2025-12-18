#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int n;

void DFS_Util(int node, int visited[])
{
    visited[node] = 1;   // Mark current node as visited
    printf("%d ", node); // Print node

    // Visit all adjacent unvisited nodes
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i] == 1 && visited[i] == 0)
        {
            DFS_Util(i, visited); // Recursive DFS call
        }
    }
}

void DFS()
{
    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Validate start vertex
    if (start < 0 || start >= n)
    {
        printf("Invalid Start Vertex!\n");
        return;
    }

    int visited[MAX] = {0}; // Array to track visited nodes

    printf("DFS Traversal: ");
    DFS_Util(start, visited); // Begin DFS
    printf("\n");
}

void CreateGraph()
{
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices!\n");
        return;
    }

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
        printf("\nMenu:\n");
        printf(" 1. Create Graph\n");
        printf(" 2. Display Graph\n");
        printf(" 3. DFS Traversal\n");
        printf(" 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            CreateGraph();
            break;
        case 2:
            DisplayGraph();
            break;
        case 3:
            DFS();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice...\n");
        }
    }

    return 0;
}
