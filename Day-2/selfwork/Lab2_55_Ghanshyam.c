// Lab-02: WAP to find the second largest element in a single traversal
// Date: 03/11/2020

#include<stdio.h>

int main()
{   
    int n;
    int i, max2;
    printf("Enter the Size of Array : ");
    scanf("%d", &n);

    int a[n];
    max2 = a[0];
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i = 1; i < n; i++)
    {
        if (max2 < a[i])
        {
            max2 = a[i];
            
            if(a[0] > max2)
            {
                a[0] = max2;
            }
        }
    }

    printf("Largest Element is : %d", a[0]);
    printf("Scond Largest Element is : %d", max2);
    
    return 0;
}