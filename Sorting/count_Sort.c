    // // Index:         0 1 2 3 4
    // // Initial array: 4 2 3 2 5

    // Step 1: Find maximum element
    // max = 5

    // // Step 2: Initialize Count array (size = max + 1 = 6)
    // // Count: [0 0 0 0 0 0]

    // // Step 3: Count frequency of each element in the array
    // Array element 4 → Count[4] = 1 → Count: [0 0 0 0 1 0]
    // Array element 2 → Count[2] = 1 → Count: [0 0 1 0 1 0]
    // Array element 3 → Count[3] = 1 → Count: [0 0 1 1 1 0]
    // Array element 2 → Count[2] = 2 → Count: [0 0 2 1 1 0]
    // Array element 5 → Count[5] = 1 → Count: [0 0 2 1 1 1]

    // // Step 4: Reconstruct the sorted array using Count array
    // Start j = 0
    // i = 0 → Count[0] = 0 → skip
    // i = 1 → Count[1] = 0 → skip
    // i = 2 → Count[2] = 2 → place 2 twice → Array: [2 2 _ _ _], Count[2]=0
    // i = 3 → Count[3] = 1 → place 3 → Array: [2 2 3 _ _], Count[3]=0
    // i = 4 → Count[4] = 1 → place 4 → Array: [2 2 3 4 _], Count[4]=0
    // i = 5 → Count[5] = 1 → place 5 → Array: [2 2 3 4 5], Count[5]=0

    // // Final Sorted array: 2 2 3 4 5

#include <stdio.h>

void Display(const char *message, int a[], int n);
int Max(int a[], int n);
void CountSort(int a[], int n);

void Display(const char *message, int a[], int n)
{
    int i;
    printf("%s ", message);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int Max(int a[], int n)
{
    int i, max = a[0];
    for (i = 1; i < n; i++)
    {
        if (max < a[i]) // Compare current element with max
        {
            max = a[i]; // Update max if current element is greater
        }
    }
    return max;
}

void CountSort(int a[], int n)
{
    int max = Max(a, n);
    int Count[max + 1];
    int i, j = 0;

    // Initialize Count array to 0
    for (i = 0; i <= max; i++)
    {
        Count[i] = 0;
    }

    // Count frequency of each element in the array
    for (i = 0; i < n; i++)
    {
        Count[a[i]]++;
    }

    // Reconstruct the sorted array using Count array
    for (i = 0; i <= max; i++)
    {
        while (Count[i] > 0)
        {
            a[j++] = i;
            Count[i]--;
        }
    }
    Display("Sorted Array:", a, n);
}

int main()
{
    int n, i;

    printf("Enter the size of the Array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n");

    Display("Unsorted Array:", a, n);
    CountSort(a, n);

    return 0;
}
