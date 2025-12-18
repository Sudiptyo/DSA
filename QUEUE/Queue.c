#include<stdio.h>
#include<stdlib.h>
#define MAX 4
int Q[MAX], F = -1, R = -1;

void Insert()
{
    int x;
    if(R == MAX - 1)
    printf("Queue is Full");
    else
    {
        printf("Enter a value: ");
        scanf("%d",&x);
        if(R == -1)
        {
            F = 0;
            R = 0;
            Q[R] = x;
        }
        else
        {
            R = (R + 1) % MAX;
            Q[R] = x;
        }
        printf("Elements Inserted %d",x);
    }
}
void Delete()
{
    int x;
    if(F == -1)
    printf("Queue is Empty");
    else
    {
        x = Q[F];
        if(F == R)
        {
            F = -1;
            R = -1;
        }
        else
        {
            F = (F + 1) % MAX;
        }
        printf("Element Deleted %d",x);
    }
}
void Traverse()
{
    int k;
    if(F == -1)
    {
        printf("Queue is Empty");
    }
    else
    {
        printf("Queue Elements are: ");
        if(F <= R)
        {
            for(k = F;k <= R;k++)
            printf("%d ",Q[k]);
        }
        else
        {
            for(k = F;k <= (MAX + R);k++)
            printf("%d",Q[k%MAX]);        }
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n 1.Insert\n 2.Delete\n 3.Traverse\n 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: Insert();
            break;
            
            case 2: Delete();
            break;
            
            case 3: Traverse();
            break;
            
            case 4: exit(0);
            
            default: printf("\nWrong Choice.");
        }
    }
    return 0;
}