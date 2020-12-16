// WAP to sort the array in an ascending order using Heap sort.
// Developed by: Ghanshyam Prajapati
// Date: 13/12/2020

#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
  
void minheapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      minheapify(arr, n, largest);
    }
}  

void maxheapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] < arr[largest])
      largest = left;
  
    if (right < n && arr[right] < arr[largest])
      largest = right;
  
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      maxheapify(arr, n, largest);
    }
}  

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minheapify(arr, n, i);          // Ascending order
        // maxheapify(arr, n, i);       // Descending Order
  
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        minheapify(arr, i, 0);          // Ascending order
        // maxheapify(arr, i, 0);       // Descending Order
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
    
    heapSort(array, n);
    
    printf("\nNumbers in Acsending Order: \n\n==>\t");
    for(i = 0; i < n; i++)
    {
        printf("\t%d",array[i]);
    }
    printf("\n\n");

    return 0;
}
