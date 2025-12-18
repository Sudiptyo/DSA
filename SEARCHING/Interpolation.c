#include <stdio.h>

void Display(int a[], int n);
int Interpolation(int a[], int n, int e);

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

    int result = Interpolation(a, n, e);

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

int Interpolation(int a[], int n, int e)
{
    int low = 0, high = n - 1;

    while (low <= high && e >= a[low] && e <= a[high])
    {
        if (a[high] == a[low])
        { 
            if (a[low] == e)
                return low;
            else
                return -1;
        }

        int probe = low + (high - low) * (e - a[low]) / (a[high] - a[low]);

        printf("Probe: %d\n", probe);

        if (a[probe] == e)
            return probe;
        else if (a[probe] < e)
            low = probe + 1;
        else
            high = probe - 1;
    }

    return -1;
}
