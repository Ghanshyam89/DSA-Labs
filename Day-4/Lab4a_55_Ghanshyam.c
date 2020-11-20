// Date: 05/11/2020
// Lab-04: a) WAP for Linear search to find whether a number is present in an array. 
//            If it is present, then at what location it appeared.

#include<stdio.h>

int main()
{
    int i, n, key, flag = 0, location;

    printf("Enter the Size of the Array: ");
    scanf("%d",&n);

    int arr[n];

    for( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the Number to find: ");
    scanf("%d",&key);

    //Search the Number int given Array

    for( i = 0; i < n; i++)
    {
        if(key == arr[i]){
            location = i+1;
            flag = 0;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    
    if(flag == 1)
    {
        printf("%d found at %d location!\n", key, location);
    }
    else
    {
        printf("%d not found!\n", key);
    }
    return 0;
}