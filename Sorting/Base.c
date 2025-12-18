#include <stdio.h>

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

void Sort(int a[], int n)
{
    int i;
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

    Sort(a, n);

    Display("Sorted Array:", a, n);

    return 0;
}