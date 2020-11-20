// Lab-07: 1. WAP to perform Push, Pop and display operations on a Stack.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 50

char pop();
void push(char item);
void display();

int Stack[n];
int top = -1;

void push(char item)
{
    if(top == n - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        Stack[top] = item;   
    }
}

char pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
        return Stack[top--];
}

void display()
{
    int i = 0;
    if(top == -1)
        printf("Stack is Empty\n");
    else
    {
        for(i = top; i >= 0; i--)
        {
            printf("%d ",Stack[i]);
        }
        printf("\n");   
    }
}

int main()
{
    int c, item;

    while(1)
    {
        printf("\n ---------Stack Operation---------\n");
        printf(" 1> Insert a Number in Stack.\n");
        printf(" 2> Delete a Number from Stack.\n");
        printf(" 3> Display the Numbers in Stack.\n");
        printf(" 4> Exit.");
        
        printf(" Enter your Option: ");
        scanf("%d", &c);

        switch(c) 
        {
            case 1: 
                printf("Enter the Number: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2: 
                printf("\nNumber Deleted from Stack is %d\n", pop());
                break;
            case 3:
                printf("\nNumbers in the Stack are \n");
                display();
                break;
            case 4:
                exit(0);
                break;
            default: 
                printf("Invalid Choice Please Try Again.\n");
        }
    }

    return 0;
}