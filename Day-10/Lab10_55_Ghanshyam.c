// Lab-10: WAP to convert infix expression into postfix expression.
// Example. infix expression = a+b*c postfix expression = abc*+
// Date: 12/11/2020

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 50

void push(char);
char pop();
int isEmpty();
char *to_Postfix(char*);

char Stack[max];
int top = -1; 

void push(char item)
{
    top++;
    Stack[top] = item;
}

char pop()
{
    if(isEmpty())
        printf("Stack Underflow!");
    else
    {
        char temp = Stack[top];
        top--;
        return temp;   
    }
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int isDigit(char item)
{
    if(item >= '0' && item <= '9')
        return 1;
    else
        return 0;
}

int isAlphabet(char item)
{
    if((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z'))
        return 1;
    else
        return 0;
}

int is_operator(char item)
{
    if(item == '+' || item == '-' || item == '*' || item == '/')
        return 1;
    else
        return 0;
}

int precedence(char item)
{
    if(item == '+' || item == '-')
        return 1;
    else if (item == '*' || item == '/')
        return 2;
    else
        return 0;
}   

char *to_Postfix(char *infix)
{
    int i = 0, j = 0, p = 0, k = 0;
    char item, x;
    
    int n = strlen(infix);
    
    char postfix[max];
    char *PointertoPostfix;
    PointertoPostfix = malloc(max * sizeof(char));

    //Conversion of Infix to Postfix.

    push('(');
    infix[n] = ')';
    n++;

    for( i = 0; i < n; i++)
    {
        item = infix[i];
        
        if(item == '(')
		{
			push(item);
		}
        else if( isDigit(item) || isAlphabet(item))
		{
			postfix[j] = item;              /* add operand symbol to postfix expr */
			j++;
		}
        else if (is_operator(item) == 1)
        {
            x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix[j] = x;
                j++;
                x = pop();
            }

            push(x);

            push(item);
        }
        else if(item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix[j] = x;
				j++;
				x = pop();
            }
        }
        else
        {
            printf("\nInvalid infix Expression.\n");
			exit(0);
        }
    }
    
    if(top>0)
    {
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		exit(0);
	}
    if(top>0)
	{
    	printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		exit(0);
	}
	postfix[j] = '\0';
    
    strcpy(PointertoPostfix, postfix);

    return PointertoPostfix;
}

int main()
{
    int i = 0, j = 0, p = 0;
    char item, x;
    char infix[max];
    char *postfix;

    printf("Infix Expression\n");
    gets(infix);

    int n = strlen(infix);

    postfix = to_Postfix(infix);
    
    printf("\nPostfix Expression\n");
    
    printf("%s",postfix);

    free(postfix);
    return 0;
}