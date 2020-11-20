#include<stdio.h>

int main()
{
    int i = 0, j = 0, n;
    

    printf("Size of Array: ");
    scanf("%d",&n);
    
    int a[n];
    
    printf("Enter the Elements\n");
    
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-1; j++)
        {
            if(a[i] != 0 && a[i] == a[i+1])
            {
                a[i] *= 2;
                a[i+1] = 0;
            }
        }
    }

    printf("Before Modification Elements in the Array are: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }

    for ( i = 0; i < n; i++)
    {
        if(a[i] == 0) {
            for( j = i + 1; j < n; j++)
            {
                if(a[j] != 0)
                {
                    a[i] = a[j];
                    a[j] = 0;
                    break;
                }
            }
        }
    }
    
    printf("\nAfter Modification Elements in the Array are: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}