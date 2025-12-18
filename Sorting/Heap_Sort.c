#include <stdio.h>

void Display(const char *message, int a[], int n);
void Heapify(int a[], int n, int i);
void HeapSort(int a[], int n);

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
void Heapify(int a[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left
    int r = 2 * i + 2; // right
    if (l < n && a[l] > a[largest])
        largest = l; // If left child is larger than root
    if (r < n && a[r] > a[largest])
        largest = r;  // If right child is larger than largest so far
    if (largest != i) // If largest is not root
    {
        int t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        Heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) // Build heap
    {
        Heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--) // One by one extract an element from heap
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        Heapify(a, i, 0);
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

    HeapSort(a, n);

    Display("Sorted Array:", a, n);

    return 0;
}