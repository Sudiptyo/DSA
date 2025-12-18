    // // Index:            0 1 2 3 4
    // // Initial array:    5 3 8 4 2
    
    // // Step 1: Split array into halves
    // Left:  [5 3 8] (index 0-2)
    // Right: [4 2]   (index 3-4)

    // // Step 2: Split left half [5 3 8]
    // Left:  [5 3]  (index 0-1)
    // Right: [8]    (index 2)

    // // Step 3: Split [5 3]
    // Left:  [5]  (index 0)
    // Right: [3]  (index 1)

    // // Step 4: Merge [5] and [3]
    // Compare 5 and 3 → 3 goes first, then 5
    // // → Merged array: [3 5] (index 0-1)

    // // Step 5: Merge [3 5] and [8]
    // Compare 3 and 8 → 3 first
    // Compare 5 and 8 → 5 next
    // 8 goes last
    // // → Merged array: [3 5 8] (index 0-2)

    // // Step 6: Split right half [4 2]
    // Left:  [4] (index 3)
    // Right: [2] (index 4)
    
    // // Step 7: Merge [4] and [2]
    // Compare 4 and 2 → 2 first, then 4
    // // → Merged array: [2 4] (index 3-4)

    // // Step 8: Merge left [3 5 8] and right [2 4]
    // Compare 3 and 2 → 2 first
    // Compare 3 and 4 → 3 next
    // Compare 5 and 4 → 4 next
    // Remaining 5, 8 → placed in order

    // // Final sorted array: [2 3 4 5 8]


#include <stdio.h>

void UnsortedDisplay(int a[], int n);
void SortedDisplay(int a[], int n);
void Merge(int a[], int low, int mid, int high);
void MergeSort(int a[], int low, int high);

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

void Merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int b[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];

    // Copy back to original array
    for (i = low, j = 0; i <= high; i++, j++)
        a[i] = b[j];
}

void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
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

    UnsortedDisplay(a, n);

    MergeSort(a, 0, n - 1);

    SortedDisplay(a, n);

    return 0;
}
