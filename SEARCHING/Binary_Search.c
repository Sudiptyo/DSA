#include <stdio.h>

void Display(int a[], int n);
int Binary(int a[], int n, int e);

int main()
{
    int n, e;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements (sorted):\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    Display(a, n);

    printf("Enter the element you want to find: ");
    scanf("%d", &e);

    int result = Binary(a, n, e);

    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}

void Display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int Binary(int a[], int n, int e)
{
    int low = 0, high = n - 1;

    while (low <= high) // Keep Searching until low & high converges or low <= high
    {
        int mid = (low + (high - low) / 2);

        if (a[mid] == e)
            return mid;
        else if (a[mid] < e)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Element not found
}
