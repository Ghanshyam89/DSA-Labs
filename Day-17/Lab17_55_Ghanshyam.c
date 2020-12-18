// Lab-17: WAP to implement a Linked List
// Developed by: Ghanshyam Prajapati.
// Date: 01/12/2020.

#include<stdio.h>
#include<stdlib.h>

void Insertatlast(int);
void Insertatbegin(int);
void Deletefrombegin();
void Deletefromlast();
void Display();

struct node
{
    int data;
    struct node *next;
};

struct node *Head, *currptr;

int main()
{
    char choice;
    int data;
    while(1)
    {
        printf("\n --X--X--X--X--X-- Operation on Linked List --X--X--X--X--X--");
        printf("\n|                                                            |");
        printf("\nX    1. Insert Data at the begining of the List              X");
        printf("\n|    2. Insert Data at the End of the List                   |");
        printf("\nX    3. Delete Data from the begining of the List            X");
        printf("\n|    4. Delete Data from the end of the List                 |");
        printf("\nX    5. Display                                              X");
        printf("\n|    6. Exit                                                 |");
        printf("\nX                                                            X");
        printf("\n --X--X--X--X--X--X--X--X--X---X--X--X--X--X--X--X--X--X--X--");

        printf("\n\n Enter Your Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1: 
            printf("\n Enter the Element: ");
            scanf("%d", &data);
            Insertatbegin(data);
            break;
        case 2:
            printf("\n Enter the Element: ");
            scanf("%d", &data);
            Insertatlast(data);
            break;
        case 3:
            Deletefrombegin();
            break;
        case 4:
            Deletefromlast();
            break;
        case 5:
            Display();
            break;
        case 6:
            printf("\n --X--X--X--X--X--X--X--X-- Bye! --X--X--X--X--X--X--X--X--X--");
            exit(0);
            break;
        default:
            printf("\nInvalid Choice");
        }
    }
    return 0;
}

void Insertatbegin(int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    
    if(Head == NULL)
    {
        newNode -> next = NULL;
        Head = newNode;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {
        newNode -> next = Head;
        Head = newNode;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
}

void Insertatlast(int data)       //Inserting the Node at the last of the List
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    if(Head == NULL)
    {
        Head = newNode;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {   
        currptr = Head;
        
        while(currptr -> next != NULL)
        {
            currptr = currptr -> next;
        }
        currptr -> next = newNode;
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Inserted!               |");
        printf("\n ------------------------------------------------------------\n");
    }
}

void Display()
{
    
    if(Head == NULL)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                       List is Empty!                       |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {
        currptr = Head;
        printf("\n ");
        while(currptr -> next != NULL)
        {
            printf("%d  ", currptr -> data);
            currptr = currptr -> next;
        }
        printf("%d\n", currptr -> data);
    }
}

void Deletefromlast()           //Deleting the node from the last 
{
    struct node * backptr;
    currptr = Head;
    backptr = Head;
    if(currptr == NULL)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                   List is Already Empty!                   |");
        printf("\n ------------------------------------------------------------\n");  
    }
    else{
        currptr = currptr -> next;
        while(currptr -> next != NULL)
        {
            currptr = currptr -> next;
            backptr = backptr -> next;
        }
        backptr -> next = NULL;
        free(currptr);
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Deleted!                |");
        printf("\n ------------------------------------------------------------\n");
    }
}

void Deletefrombegin()
{
    currptr = Head;
    if(currptr == NULL)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                   List is Already Empty!                   |");
        printf("\n ------------------------------------------------------------\n");  
    }
    else
    {
        Head = Head -> next;
        free(currptr);
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Deleted!                |");
        printf("\n ------------------------------------------------------------\n");
    }
}
