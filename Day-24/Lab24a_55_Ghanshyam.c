// Lab 14: a) WAP to sort N numbers in Acsending order using Insertion sort.
// Developed by: Ghanshyam Prajpati
// Date: 09/12/2020.

#include<stdio.h>

void Insertion(int array[], int n)
{
    int i, j, temp, k;
    for(i = 0; i < n; i++)
    {
        temp = array[i];
        j = i;
        while (j > 0 && temp < array[j - 1])
        {
            array[j] = array[j - 1];
            j--;
        }
        
        array[j] = temp;
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

    Insertion(array, n);
    
    printf("\nNumbers in Acsending Order: \n\n==>\t");
    for(i = 0; i < n; i++)
    {
        printf("\t%d",array[i]);
    }
    printf("\n\n");

    return 0;
}