#include <stdio.h>

void Display(const char *msg, char a[], int n)
{
    int i;
    printf("%s ", msg);
    for (i = 0; i < n; i++)
    {
        printf("%c ", a[i]);
    }
    printf("\n");
}

void HashStringArray(char a[], int n)
{
    int i;
    int hash[256] = {0}; // Initialize the hash array with {0}

    // Count the frequency of each element
    // for (i = 0; i < n; i++)
    // {
    //     if (a[i] >= 'a' && a[i] <= 'z')
    //         hash[a[i] - 'a']++; // mapping: a->0, b->1, c->2 ...
    //     else
    //         printf("%c is out of range\n", a[i]);
    // }

    for (i = 0; i < n; i++)
    {
        hash[(unsigned char)a[i]]++; // store in 0–255 index
    }

    char k;
    printf("Search Occurrence: ");
    scanf(" %c", &k);
    // if (k >= 'a' && k <= 'z')
    // {
    //     // printf("%c occurs %d times\n", k, hash[k - 'a']); // Finding the index
    //     printf("%c occurs %d times\n", k, hash[k]);
    // }
    // else
    // {
    //     printf("%c is out of range\n", k);
    // }

    printf("'%c' occurs %d times\n", k, hash[(unsigned char)k]);
}

int main()
{
    int n, i;
    printf("Enter the size of the Array: ");
    scanf("%d", &n);
    char a[n];

    printf("Enter Characters: \n");
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i);
        scanf(" %c", &a[i]);
    }

    Display("Array: ", a, n);

    HashStringArray(a, n);

    return 0;
}