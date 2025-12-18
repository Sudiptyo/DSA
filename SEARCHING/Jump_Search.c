#include <stdio.h>
#include <math.h>

void Display(int a[], int n);
int Jump(int a[], int n, int e);

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

    printf("Array: ");
    Display(a, n);

    printf("Enter the element you want to find: ");
    scanf("%d", &e);

    int result = Jump(a, n, e);

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

int Jump(int a[], int n, int e)
{
    int step = (int)floor(sqrt(n));
    int prev = 0;

    // Finding the block where element may exist
    while (a[(step < n ? step : n) - 1] < e)
    {
        prev = step;
        step += (int)floor(sqrt(n)); // jump to next block

        if (prev >= n)
            return -1; // not found
    }

    // Linear search within the identified block
    int upper = (step < n) ? step : n;
    for (int i = prev; i < upper; i++)
    {
        if (a[i] == e)
            return i;
    }

    return -1;
}
