// Developed by: Ghanshyam Prajapati.
// Lab-12: You are given a stack of N integers. In one operation,
// you can either pop an element from the stack or push any popped
// element into the stack. You need to maximize the top element of
// the stack after performing exactly K operations. If the stack
// becomes empty after performing K operations and there is no
// other way for the stack to be non-empty, print -1.
// Input format:
// The first line of input consists of two space-separated integers N
// and K.
// The second line of input consists N space-separated integers
// denoting the elements of the stack. The first element represents
// the top of the stack and the last element represents the bottom of
// the stack.
// Output format:
// Print the maximum possible top element of the stack after
// performing exactly K operations.
// Sample Input
// 6 4
// 1 2 4 3 3 5
// Sample Output
// 4

#include<stdio.h>
#include<stdlib.h>
#define max 50

int Stack[max];
int top = -1;

int pop();
void push(int);
int isEmpty();
int peek();

int main()
{
    int i = 0, K, N;
    printf("Enter N & K\n");
    scanf("%d %d", &N, &K);

    int num_arr[N];

    printf("Enter the Elements in the Array\n");
    for(i = 0; i < N; i++)
    {
        scanf("%d", &num_arr[i]);
    }

    for(i = N-1; i >= 0; i--)
    {
        push(num_arr[i]);
    }

    int maximum = 0, item;
    for(i = 0; i < K; i++)
    {
        item = pop();
        if(maximum < item){
            maximum = item;
        }
    }
    if(K>N)
        printf("-1");
    else
        printf("%d", maximum);
    return 0;
}
void push(int item)                    //Inserting value into Stack.
{
    top++;
    Stack[top] = item;
}

int pop()                             //Delete and Returns the deleted top value from Stack.
{
    if(isEmpty())
    {
        printf("Stack Underflow!");
    }
    else
    {
        int temp = Stack[top];
        top--;
        return temp;   
    }
}

int isEmpty()                           //Checks whether the Stack is Empty or not.
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int peek()                              //Returns the value at the Top in the Stack. 
{   if(isEmpty())
        return 0;
    else
        return Stack[top];
}
