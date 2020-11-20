// Day-1: Find largest number in an Array.
// Date: 02/11/2020

#include<stdio.h>

int main()
{   
    int n;
    int i;
    printf("Enter the Size of Array : ");
    scanf("%d", &n);

    int a[n];
    
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    for(i = 1; i < n; i++)
         if (a[i]>a[0])
            a[0] = a[i];
      

    printf("Largest Element is : %d", a[0]);
    
    return 0;
}

// Largest element by using function.
// Find max and min in the same.
// Largest element using pointer.