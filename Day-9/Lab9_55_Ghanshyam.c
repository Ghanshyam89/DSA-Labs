// Lab-9: WAP to reverse given string by using Stack.
// Example: “GeeksQuiz” should be converted to “ziuQskeeG”.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(char);
char pop();

char Stack[50];
int top = -1;

void push(char data)
{
    top++;
    Stack[top] = data;
}
char pop()
{
    char data = Stack[top];
    top--;
    return data;
}

int main()
{
    int n, i;
    char str[50];

    printf("\nEnter the String: ");
    scanf("%s",str);

    n = strlen(str);

    for( i = 0; i < n; i++)
    {
        push(str[i]);
    }

    for( i = 0; i < n; i++)
    {
        str[i] = pop();
    }

    printf("Reversed String: %s\n\n", str);

    return 0;

}