// Lab 14: a) WAP to sort N numbers in Acsending order using Selection sort. Corman
// Developed by: Ghanshyam Prajpati
// Date: 09/12/2020.

#include<stdio.h>

void Selection(int array[], int n)
{
    int i, j, k, min, temp;

    for ( i = 0; i < n; i++)
    {
        min = i;
        for ( j = i + 1; j < n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }        
        }
        if (min != i)
        {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;        
        }
        printf("\nPass %d ==> ", i + 1);
        for(k = 0; k < n; k++)
        {
            printf("\t%d",array[k]);
        }
        printf("\n");
    }
}

int main()
{
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

    Selection(array, n);
    
    printf("\nNumbers in Acsending Order: \n\n==>\t");
    for(i = 0; i < n; i++)
    {
        printf("\t%d",array[i]);
    }
    printf("\n\n");

    return 0;
}