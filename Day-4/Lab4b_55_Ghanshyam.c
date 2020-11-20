// Date: 05/11/2020
// Lab-04: b) WAP to print all locations at which required element is found 
//            and also the number of times it occurs in the list.

#include<stdio.h>

int main()
{
    int i = 0, n = 0, key = 0, flag = 1, count = 0;

    printf("Enter the Size of the Array: ");
    scanf("%d",&n);

    int arr[n], location[n];

    for( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the Number to find: ");
    scanf("%d",&key);

    //Searching is the Number present in the given Array or not!

    for( i = 0; i < n; i++)
    {
        if(key == arr[i]){
            flag = 0;                   //setting flag to 0 indicating that number has been found.
            location[count] = i+1;      //putting location of all the found position in an array Location[].
            count++;                    //Counting how many times the Number found in the list.
        }
    }

    if(flag == 0)
    {
        for ( i = 0; i < count; i++)
        {
            printf("%d found at \"%d\" location!\n", key, location[i]);
        }
        printf("The number occured %d times in the list!\n",count);
    }
    else
    {
        printf("%d not found!\n", key);
    }
    

    return 0;
}