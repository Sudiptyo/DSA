#include <stdio.h>

void Display(const char *message, int a[], int n)
{
    int i;
    printf("%s ", message);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* -------- STABLE PARTITION -------- */
int StablePartition(int a[], int low, int high)
{
    int pivot = a[low];
    int pivotIndex = low;
    int i, j;

    for (i = low + 1; i <= high; i++)
    {
        if (a[i] <= pivot)
        {
            int temp = a[i];

            // Shift elements right instead of swapping
            for (j = i; j > pivotIndex + 1; j--)
                a[j] = a[j - 1];

            a[pivotIndex + 1] = temp;
            pivotIndex++;
        }
    }

    // Place pivot at correct position
    int t = a[low];
    for (int i = low; i < pivotIndex; i++)
        a[i] = a[i + 1];
    a[pivotIndex] = t;

    return pivotIndex;
}

void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int partitionIndex = StablePartition(a, low, high);
        QuickSort(a, low, partitionIndex - 1);
        QuickSort(a, partitionIndex + 1, high);
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
