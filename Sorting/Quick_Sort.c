    // // Index:       0 1 2 3 4
    // Initial array:  5 3 8 4 2

    // // Pass 1 (low=0, high=4, pivot=5):
    // Compare 3 ≤ 5 → i moves right
    // Compare 8 > 5 → j moves left
    // Compare 2 ≤ 5 → i moves right
    // Swap elements at i=1 and j=4 → 5 2 8 4 3
    // Continue until i >= j
    // Place pivot 5 at correct position (swap with A[j])
    // // → 3 2 4 5 8

    // Left subarray to sort:  [3 2 4] (index 0–2)
    // Right subarray to sort: [8]     (index 4)

    // // Pass 2 (low=0, high=2, pivot=3):
    // Compare 2 ≤ 3 → i moves right
    // Compare 4 > 3 → j moves left
    // i >= j, stop
    // Place pivot 3 at correct position (swap with A[j])
    // // → 2 3 4 5 8

    // Left subarray to sort:  [2] (index 0–0)
    // Right subarray to sort: [4] (index 2–2)

    // // Pass 3 (low=0, high=0):
    // Single element → already sorted
    //
    // // Pass 4 (low=2, high=2):
    // Single element → already sorted    
    

    // // Final sorted array: 2 3 4 5 8


#include <stdio.h>

void Swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

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

int Partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int t;

    do
    {
        while (i <= high && A[i] <= pivot) // Increment i until an element greater than pivot is found
        {
            i++;
        }
        while (j >= low && A[j] > pivot) // Decrement j until an element less than or equal to pivot is found
        {
            j--;
        }
        if (i < j) // Swap elements at i and j if i is still less than j
        {
            Swap(&A[i], &A[j]);
        }
    } while (i < j); // Continue until i is no longer less than j

    // Place pivot at correct position
    // t = A[low];
    // A[low] = A[j];
    // A[j] = t;
    Swap(&A[low], &A[j]);

    return j;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = Partition(A, low, high); // Partitioning index everytime i becomes less than j
        QuickSort(A, low, partitionIndex - 1);  // Recursively sort left subarray
        QuickSort(A, partitionIndex + 1, high); // Recursively sort right subarray
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

    Display("Unsorted Array:", a, n);

    QuickSort(a, 0, n - 1);

    Display("Sorted Array:", a, n);

    return 0;
}
