// Lab-08 : WAP to find whether the given string is a palindrome or not using Stack if given a string str. 
// Examples: Input: str = “geeksforgeeks” 
//           Output: No 
//           Input: str = “madam” 
//           Output: Yes
// Date: 10/11/2020.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char pop();
void push(char item);
int isPalindrome(char str[], int length);

char Stack[50];
int top = -1;

void push(char item)
{
    top++;
    Stack[top] = item;
}

char pop()
{
    char temp = Stack[top];
    top--;
    return temp;
}

int isPalindrome(char str[], int length)
{
    int i, mid;

    mid = length/2;

    for (i = 0; i < mid; i++) { 
        push(str[i]); 
    }

    if (length % 2 != 0) { 
        i++; 
    }

    while (i < length) { 
        char ele = pop(); 

        if (ele != str[i]) 
            return 0;
        else
            i++; 
    } 

    return 1;
}

int main()
{
    char str[100];
    printf("Entee the String: ");
    scanf("%s",&str);

    int n = strlen(str);

    int bool = isPalindrome(str, n);

    if(bool)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}