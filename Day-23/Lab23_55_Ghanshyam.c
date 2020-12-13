#include<stdio.h>
#define max 50;

int main()
{
    int i, j, k, n, swap;
    int a[10];
    
    printf("Enter the size of Array: ");
    scanf("%d", &n);

    printf("Enter the Elements in Array: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n - 1; i++)
    {
        for( j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                swap = a[j];
                a[j] = a[j + 1];
                a[j + 1] = swap;
            }
            
        }
        printf("Pass %d --> ", i + 1);
        for(k = 0; k < n; k++)
        {
            printf("\t%d", a[k]);
        }
        printf("\n");
    }

    printf("\nAfter Sorting Elements in Array: \n\n");
    for(i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n\n");
    return 0;
}