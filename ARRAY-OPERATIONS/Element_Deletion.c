#include <stdio.h>

void Display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void Delete(int arr[], int size, int index)
{
    int i;
    for (i = index; i < size - 1; i++)  // Shift elements left
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int n, i, in;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter Array elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    Display(arr, n);

    printf("Enter the index position to delete: ");
    scanf("%d", &in);

    if (in < 0 || in >= n)
    {
        printf("Invalid index. Deletion failed.\n");
    }
    else
    {
        Delete(arr, n, in);
        n--;
        printf("Array after Deletion:\n");
        Display(arr, n);
    }

    return 0;
}
