// Lab-05: WAP to find whether a number is present in mid position of an array. 
// If it is present, then at what location it appeared.
// Date: 06?11/2020.
#include<stdio.h>
#include<stdlib.h>

int binarySearchIterative(int a[], int low, int high, int key)
{
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
}

int binarySearchRecursive(int a[], int low, int high, int key)
{
    if(key < a[0])
    {
        return -1;
    }
    
    if(key > a[high])
    {
        return -1;
    }

    if(low > high)
    {
        return -1;
    }

    int mid = (low + high)/2;

    if(key == a[mid])
    {
        return mid;
    }
    else if (key < a[mid])
    {
        return binarySearchRecursive(a, low, mid - 1, key);
    }
    else
    {
        return binarySearchRecursive(a, mid + 1, high, key);
    }
}

int main()
{
    int i = 0, n, key = 0, mid;

    printf("Enter the Size of the Array: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the Elements in the array\n(Please Enter the elements in Sorted order)\n");
    for( i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the Number to find: ");
    scanf("%d",&key);

    //Searching is the Number present in the given Array or not!

    mid = binarySearchIterative(arr, 0, n-1, key);
    mid = binarySearchRecursive(arr, 0, n-1, key);
    if (mid == -1)
    {
        printf("%d not found in the Array\n", key);
    }
    else
    {
        printf("%d found at %d Position\n", key, mid + 1);
    }

    return 0;

}