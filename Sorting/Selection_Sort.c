    // Index:            0 1 2 3 4
    // // Initial array: 5 3 8 4 2

    // // Pass 1: Find min from index 0 → 4
    // // Min at index 0: 5
    // Compare 5 & 3 → min = 3
    // Compare 3 & 8 → min = 3
    // Compare 3 & 4 → min = 3
    // Compare 3 & 2 → min = 2
    // Swap 5 & 2 → 2 3 8 4 5

    // // Pass 2: Find min from index 1 → 4
    // // Min at index 1: 3
    // Compare 3 & 8 → min = 3
    // Compare 3 & 4 → min = 3
    // Compare 3 & 5 → min = 3
    // No swap (already minimum at index 1) → 2 3 8 4 5

    // // Pass 3: Find min from index 2 → 4
    // // Min at index 2: 8
    // Compare 8 & 4 → min = 4
    // Compare 4 & 5 → min = 4
    // Swap 8 & 4 → 2 3 4 8 5

    // // Pass 4: Find min from index 3 → 4
    // // Min at index 3: 8
    // Compare 8 & 5 → min = 5
    // Swap 8 & 5 → 2 3 4 5 8

    // // Array sorted

    // // Final array: 2 3 4 5 8

#include <stdio.h>

void UnsortedDisplay(int a[], int n);
void SortedDisplay(int a[], int n);
void SelectionSort(int a[], int n);

void UnsortedDisplay(int a[], int n)
{
    int i;
    printf("Unsorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void SortedDisplay(int a[], int n)
{
    int i;
    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void SelectionSort(int a[], int n)
{
    int i, j, t, min_index;
    for (i = 0; i < n - 1; i++) // PASSES
    {
        min_index = i;

        // find the index of the minimum element
        for (j = i + 1; j < n; j++) // COMPARES
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }

        // swap only once per pass
        if (min_index != i)
        {
            t = a[i];
            a[i] = a[min_index];
            a[min_index] = t;
        }
    }
    SortedDisplay(a, n);
}

int main()
{
    int n, i;

    printf("Enter the size of the Array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:~\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n");

    UnsortedDisplay(a, n);
    SelectionSort(a, n);

    return 0;
}
