    // Index:            0 1 2 3 4
    // // Initial array: 5 3 8 4 2

    // // Pass 1:
    // Compare 5 & 3 → swap → 3 5 8 4 2
    // Compare 5 & 8 → no swap → 3 5 8 4 2
    // Compare 8 & 4 → swap → 3 5 4 8 2
    // Compare 8 & 2 → swap → 3 5 4 2 8
    // // Largest element (8) moved to last

    // // Pass 2:
    // Compare 3 & 5 → no swap → 3 5 4 2 8
    // Compare 5 & 4 → swap → 3 4 5 2 8
    // Compare 5 & 2 → swap → 3 4  2 5 8
    // // Second largest (5) in place

    // // Pass 3:
    // Compare 3 & 4 → no swap → 3 4 2 5 8
    // Compare 4 & 2 → swap → 3 2 4 5 8
    // // Third largest (4) in place

    // // Pass 4:
    // Compare 3 & 2 → swap → 2 3 4 5 8
    
    // // Array fully sorted

    // // Final array: 2 3 4 5 8

#include <stdio.h>

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

void BubbleSort(int a[], int n)
{
    int i, j, t, swapped;
    for (i = 0; i < n - 1; i++) // PASSES
    {
        swapped = 0; // OPTIMIZATION

        for (j = 0; j < n - 1 - i; j++) // COMPARES
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                swapped = 1;
            }
        }
        if (!swapped)
            break; // If no SWAPS, already SORTED
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

    BubbleSort(a, n);

    return 0;
}
