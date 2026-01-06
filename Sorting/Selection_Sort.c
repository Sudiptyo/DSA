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
    int i, j, min_index, key;
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

        // Store the minimum element found in the unsorted part of the array.
        // This value is saved because it will be overwritten during shifting.
        key = a[min_index]; // store minimum element
        // Instead of swapping the minimum element directly with a[i],
        // we shift all elements between index i and min_index − 1
        // one position to the right.
        // This prevents changing the relative order of equal elements,
        // which is why the algorithm becomes STABLE.
        while(min_index > i) // SHIFT elements to right
        {
            // Move the element just before min_index
            // one position to the right.
            // This creates an empty position at index i step by step.
            a[min_index] = a[min_index - 1]; // shift element to right by 1 position using min_index

            // Decrease min_index so that shifting continues
            // until we reach the correct insertion position i.
            min_index--; // move index left
        }

        // After all elements have been shifted,
        // place the stored minimum element into index i.
        // Now the smallest element is correctly placed,
        // and the order of equal elements is preserved.
        a[i] = key; // place minimum element at its correct position
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
