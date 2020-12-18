// WAP to Sort an array of numbers using Quick Sort.
// Developed By: Ghanshyam Prajapati
// Date: 13/12/2020

#include<stdio.h>

void quickSort( int array[], int left, int right)
{
    int i, j, pivot, temp;
    if( left < right)
    {
        pivot = left;
        i = left;
        j = right;

        while( i < j)
        {
            for( ; array[i] <= array[pivot] && i < right; i++);
            for( ; array[j] > array[pivot] ; j--);

            if( i < j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;

        quickSort(array, left, j - 1);
        quickSort(array, j + 1, right);
    }
}

int main() { 
    int n, i;
    
    printf("How many numbers you want to Sort: ");
    scanf("%d",&n);
    
    int array[n];

    printf("\nEnter %d Numbers\n",n);
    for ( i = 0; i < n; i++)
    {
        printf("\nNumber %d ==> ", i + 1);
        scanf("%d",&array[i]);
    }

    printf("\nNumbers Before Sorting: \n\n==>\t");
    for(i = 0; i < n; i++)
    {
        printf("\t%d",array[i]);
    }
    printf("\n");
    quickSort(array, 0, n - 1);
    
    printf("\nNumbers in Acsending Order: \n\n==>\t");
    for(i = 0; i < n; i++)
    {
        printf("\t%d",array[i]);
    }
    printf("\n\n");

    return 0;
}