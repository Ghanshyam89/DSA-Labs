// Day-1: Find largest number in an Array using Pinter.
// Date: 02/11/2020

#include<stdio.h>
#include<stdlib.h>

int get_array();
int largest(int * arr);

int size;

int get_array()
{
    int i;
    printf("\nEnter the Size of Array : ");
    scanf("%d", &size);

    int a[size];

    for(i = 0; i < size; i++)
    {
        printf("Enter element[%d]: ",i+1);
        scanf("%d",&a[i]);
    }

    return largest(a);
}

int largest(int * arr) 
{
    int i;
    
    for(i = 1; i < size; i++)
    {
        if (arr[i]>arr[0])
        {
            arr[0] = arr[i];
        }
    }
    return arr[0];
}

int main()
{   
    printf("\n----- Largest Number Finder using Pointer -----\n");

    int largestNumber = get_array();
    printf("\n-----------------------------------------------\n");
    printf("\nLargest Element in the Array is : %d \n\n", largestNumber);
    
    return 0;
}

// Largest element by using function.
// Find max and min in the same.
// Largest element using pointer.