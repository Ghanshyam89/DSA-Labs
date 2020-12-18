// Lab 15: WAP to implement circular Queue using Array.
// Date: 20/11/2020
// Developed by: Ghanshyam Prajapati.

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int Queue[MAX], front = -1, rear = -1;
void enqueue();
int dequeue();

void enqueue()
{
    if(front == (rear+1) % MAX)
    {
        printf("\nQueue is Full\n");
    }
    else
    {
        int item;
        if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear+1) % MAX;
        }
        printf("Enter the Element: ");;
        scanf("%d",&item);
        Queue[rear] = item;
        printf("\n%d Succesfully Inserted!\n", item);
        
    }
}
int dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty!.\n");
        return 0;
    }
    else
    {
        int item;
        item = Queue[front];
        if(front == rear)
        {
            rear = -1; 
            front = -1;
        }
        else
        {
            front = (front+1) % MAX;    
        }
        printf("\n%d Succesfully Deleted!\n", item);
        return item;
    }
}
void display()
{   
    int i;
    if(front == -1)
    {
        printf("\nQueue is Empty!\n");
        return;
    }
    else
    {           //front -- max-1
                //
        printf("Queue: \n");
        for(i = front; i != rear; i = (i+1)%MAX)
        {
            printf("%d  ",Queue[i]);
        }
        printf("%d",Queue[i]);
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
