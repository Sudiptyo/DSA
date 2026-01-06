    // Index:            0 1 2 3 4
    // // Initial array: 5 3 8 4 2

    // // Pass 1: Insert element at index 1 (key = 3)
    // Compare 5 & 3 → shift 5 → 5 5 8 4 2
    // Place 3 at index 0 → 3 5 8 4 2

    // // Pass 2: Insert element at index 2 (key = 8)
    // Compare 5 & 8 → no shift
    // Key stays at index 2 → 3 5 8 4 2

    // // Pass 3: Insert element at index 3 (key = 4)
    // Compare 8 & 4 → shift 8 → 3 5 8 8 2
    // Compare 5 & 4 → shift 5 → 3 5 5 8 2
    // Compare 3 & 4 → stop
    // Place 4 at index 1 → 3 4 5 8 2

    // // Pass 4: Insert element at index 4 (key = 2)
    // Compare 8 & 2 → shift 8 → 3 4 5 8 8
    // Compare 5 & 2 → shift 5 → 3 4 5 5 8
    // Compare 4 & 2 → shift 4 → 3 4 4 5 8
    // Compare 3 & 2 → shift 3 → 3 3 4 5 8
    // Place 2 at index 0 → 2 3 4 5 8

    // // Array sorted

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

void InsertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i <= n - 1; i++) // PASSES
    {
        key = a[i]; // Element being inserted 
        j = i - 1;

        while(j >= 0 && a[j] > key) // COMPARES
        {
            a[j + 1] = a[j];
            j--;
        }
            a[j + 1] = key;
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

    InsertionSort(a, n);

    return 0;
}