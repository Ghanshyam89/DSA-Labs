// Write a program to find LCM and HCF of two numbers.

#include<stdio.h>

int hcf(int, int);
int lcm(int, int);
int hcf2(int, int);

int lcm(int a, int b)
{
    return (a*b)/hcf( a, b);
}

int hcf2(int a, int b) 
{
    int num, den, rem;
    int lcm, hcf;
    
    if(a > b)
    {
        num = a;
        den = b;
    }
    else if(b > a)
    {
        num = b;
        den = a;
    }
    else
    {
        return a;   
    }

    rem = num%den;

    while(rem != 0)
    {
        num = den;
        den = rem;
        rem = num%den;
    }

    hcf = den;
    lcm = a*b/hcf;
}

int hcf(int a, int b)
{
    if(a == 0)
        return b;

    if(b == 0)
        return a;
    
    if(a == b)
        return a;

    if(a > b)
        return hcf( a-b, b);
    else
        return hcf( a, b-a);
}

int main()
{
    int num1, num2;

    printf("\n-------LCM and HCF Finder-------\n\n");

    printf("Enter the first Number: ");
    scanf("%d",&num1);

    printf("Enter the Second Number: ");
    scanf("%d",&num2);

    printf("\n LCM of %d and %d is %d\n", num1, num2, lcm( num1, num2));
    printf(" HCF of %d and %d is %d\n", num1, num2, hcf( num1, num2));
}