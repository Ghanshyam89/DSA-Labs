// Queue Operation.

#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int Queue[MAX], front = -1, rear = -1;
void enqueue();
int dequeue();

void enqueue()
{
    if(rear == MAX && front == -1)
    {
        printf("\nQueue Oveflow");
    }
    else
    {
        int item;
        if(front == -1)
        {
            front = 0;
        }
        printf("Enter the Element: ");;
        scanf("%d",&item);
        
        Queue[++rear] = item;
        
    }
}
int dequeue()
{
    if (front == -1)
    {
        printf("\nQueue Underflow!");
    }
    else
    {
        return Queue[front++];
    }
}
void display()
{   
    int i;
    printf("Queue: \n");
    for(i = front; i <= rear; i++)
    {
        printf("%d  ",Queue[i]);
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("\n--------Queue Operation--------");
        printf("\n| 1. Insertion                |");
        printf("\n| 2. Deletion                 |");
        printf("\n| 3. Display                  |");
        printf("\n| 4. Exit                     |");
        printf("\n-------------------------------");

        printf("\nEnter Your Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\n------------ Bye! -------------\n");
            exit(0);
            break;
        default:
            printf("\nInvalid Choice");
        }
    }
    
    return 0;
}