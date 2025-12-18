#include <stdio.h>

void Display(const char *msg, int a[], int n)
{
    int i;
    printf("%s ", msg);
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void HashArray(int a[], int n)
{
    int i;
    int hash[n + 1];

    // Initialize the hash array with {0}
    for (i = 0; i <= n; i++)
    {
        hash[i] = 0;
    }

    // Count the frequency of each element
    for (i = 0; i < n; i++)
    {
        if (a[i] <= n && a[i] >= 0)
            hash[a[i]]++;
        else
            printf("%d is out of range\n", a[i]);
    }

    int k;
    printf("Search Occurrence: ");
    scanf("%d", &k);
    printf("%d occurs %d times\n", k, hash[k]);
}

int main()
{
    int n, i;
    printf("Enter the size of the Array: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter Elements: \n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf("%d", &a[i]);
    }

    Display("Array: ", a, n);

    HashArray(a, n);

    return 0;
}