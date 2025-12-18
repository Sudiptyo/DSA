#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 100  // Define capacity as a constant

void Display(int arr[], int size)
{
    int i;
    // TRAVERSAL
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int Insert(int arr[], int size, int element, int capacity, int index)
{
    int i;

    // INSERTION
    if (size >= capacity) // Check if array is full
    {
        printf("Array is full\n");
        return -1;
    }

    for (i = size - 1; i >= index; i--)  // Shift elements
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;  // Insert element at index
    return 1;
}

int main()
{
    int n, i, e, in, s;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[CAPACITY];

    printf("Enter Array elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    Display(arr, n);

    printf("Enter an element to insert: ");
    scanf("%d", &e);

    printf("Enter the index position to insert: ");
    scanf("%d", &in);

    s = n; // current size

    if (in < 0 || in > n)
    {
        printf("Invalid index. Insertion failed.\n");
    }
    else if (Insert(arr, s, e, CAPACITY, in) == true)
    {
        n++; // Increase size after successful insertion
        printf("Array after insertion:\n");
        Display(arr, n);
    }

    return 0;
}
