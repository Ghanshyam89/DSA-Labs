// WAP to Reverse a Queue.
// Date: 19/11/2020

#include<stdio.h>
#include<string.h>
#define MAX 50

void enqueue(int, int);
void reverse();
void display();

int Queue[MAX];
int front = -1, rear = -1;

void enqueue(int item, int n)
{
    if(rear == n - 1 && front == -1)
    {
        printf("\nQueue Oveflow");
    }
    else
    {        
        if(front == -1)
        {
            front = 0;
        }
        Queue[++rear] = item;        
    }
}
void reverse()
{
    int i, j;
    int temp;
    for (i = front, j = rear; i < j; i++, j--)
    {
        temp = Queue[i];
        Queue[i] = Queue[j];
        Queue[j] = temp;
    }
}
void display()
{   
    int i;
    for(i = front; i <= rear; i++)
    {
        printf("    %d  ",Queue[i]);
    }
}
int main()
{
    int i = 0, n, item;
    
    printf("\n<--------> Reverse Operation on Queue <-------->\n");
    printf("\n Enter the Number of Elements: ");
    scanf("%d", &n);
    printf(" Enter the Elements: \n");
    for(i = 0; i < n; i++)
    {
        printf("=>        ");
        scanf("%d",&item);
        enqueue(item, n);
    }

    printf("\n------------------------------------------\n|");
    printf("\n| Queue before Reversal\n|->");
    display();
    
    //Revese the Queue.
    reverse();
    //Display the Queue.
    printf("\n| Queue After Reversal\n|->");
    display();
    printf("\n|");
    printf("\n------------------------------------------\n");

    return 0;
}