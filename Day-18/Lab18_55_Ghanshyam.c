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
void Reverse();

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
        printf("\nX       1. Insert Data at the begining of the List           X");
        printf("\n|       2. Insert Data at the End of the List                |");
        printf("\nX       3. Delete Data from the begining of the List         X");
        printf("\n|       4. Delete Data from the end of the List              |");
        printf("\nX       5. Reverse the List                                  X");
        printf("\n|       6. Display the List                                  |");
        printf("\nX       7. Exit                                              X");
        printf("\n|                                                            |");
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
            Reverse();
            break;
        case 6:
            Display();
            break;
        case 7:
            printf("\n --X--X--X--X--X--X--X--X-- Bye! --X--X--X--X--X--X--X--X--X--");
            exit(0);
            break;
        default:
            printf("\nInvalid Choice");
        }
    }
    return 0;
}

void Reverse()
{
    struct node * prevptr = NULL, *currptr = Head, *nextptr = NULL;
    if(Head == NULL)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                       List is Empty!                       |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {
        while(currptr != NULL)
        {
            nextptr = currptr -> next;
            currptr -> next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
        }
        Head = prevptr;
        printf("\n ------------------------------------------------------------");
        printf("\n|                  List has been Reversed!                   |");
        printf("\n ------------------------------------------------------------\n");
    }
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
        printf("\nX------------------ Elements in the List --------------------X\n\n ");
        
        while(currptr -> next != NULL)
        {
            printf("%d  ", currptr -> data);
            currptr = currptr -> next;
        }
        printf("%d\n", currptr -> data);
        printf("\nX------------------------------------------------------------X\n");
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
    else if(currptr -> next == NULL)
    {
        Head = NULL;
        free(currptr);
        printf("\n ------------------------------------------------------------");
        printf("\n|               Element Successfully Deleted!                |");
        printf("\n ------------------------------------------------------------\n");
    }
    else
    {
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
