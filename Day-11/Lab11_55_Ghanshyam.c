// Lab-11: WAP to evaluate postfix expression (using Stack).
// Date: 18/11/2020.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

void push(char);
char pop();
int peek();
int isEmpty();
int isDigit(char);
int isAlphabet(char);
int is_operator(char);
int precedence(char);
int evaluate(char, char, char);
int EvalutePostfix(char*);
char *to_Postfix(char*);

int Stack[max], top = -1;

int main()
{
    int i = 0, value = 0;
    char A = 0, B = 0;
    char item;
    char infix[max];
    char *postfix;

    printf("Infix Expression\n");
    gets(infix);

    postfix = to_Postfix(infix);

    value = EvalutePostfix(postfix);
    printf("Evaluated value of the Postfix Expression is %d\n",value);
    return 0;
}

char *to_Postfix(char *infix)                // This Function Converts Infix Expresion into Postfix Expresion 
{                                            //and returns the pointer to Prefix.
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

int EvalutePostfix(char postfix[])                     //Evaluates the Popstfix Expression.
{
    int i = 0, value = 0;
    char A = 0, B = 0;
    char item;
    
    int n = strlen(postfix);

    postfix[n] = ')';
    n++;

    while (postfix[i] != ')')
    {   
        item = postfix[i];

        if( isDigit(item))
		{
			push(item - '0');                           //Operand is pushed to Stack.
		}
        else if (is_operator(item) == 1)
        {
            A = pop(); 
            B = pop(); 
            value = evaluate(item, A, B);               //Operation is Evaluated.
            push(value);
        }
        else
        {
            printf("Invalid Postfix Expression\n");
            exit(0);
        }

        value = peek();

        i++;
    }

    return value;
}

int evaluate(char item, char A, char B)                 //Returns the Operated value.
{   
    if(item == '+')
    {
        return B + A;
    }else if (item == '-')
    {
        return (B - A);
    }else if (item == '*')
    {
        return (B * A);
    }else if (item == '/')
    {
        return (B / A);
    }else
    {
        printf("Invalid Operator\n");
        return 0;
    }
}

int is_operator(char item)               //Check whether the item is Operator or not.
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
void push(char item)                    //Inserting value into Stack.
{
    top++;
    Stack[top] = item;
}

char pop()                              //Delete and Returns the deleted top value from Stack.
{
    if(isEmpty())
    {
        printf("Stack Underflow!");
    }
    else
    {
        char temp = Stack[top];
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

int isDigit(char item)                  //Checks Whether the item is Digit or not.
{
    if(item >= '0')
        return 1;
    else
        return 0;
}
int isAlphabet(char item)               //Checks whether the item is Alphabet or not.
{
    if((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z'))
        return 1;
    else
        return 0;
}