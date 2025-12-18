#include <stdio.h>

void Display(int a[], int n);
void Linear(int a[], int n, int e);

int main()
{
    int n, e;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &a[i]); 
    }

    Display(a, n);

    printf("Enter the element you want to find: ");
    scanf("%d", &e);

    Linear(a, n, e);

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

void Linear(int a[], int n, int e)
{
    int i, found = 0;

    for (i = 0; i < n; i++)
    {
        if (e == a[i])
        {
            printf("Element found at index: %d\n", i);
            found = 1;
        }
    }
    if (!found)
        printf("Element not found in the array.\n");
}
