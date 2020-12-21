// WAP to Search an Element in a Tree Non-Recursively.

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    long int data;
    struct node *left;
    struct node *right;
};

struct node *root;

void insert( long int data)
{
    struct node *current;
    struct node *parent;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(root == NULL)
    {
        root = newNode;

        printf("\n ------------------------------------------------------------");
        printf("\n|                       Element Inserted!                    |");
        printf("\n ------------------------------------------------------------\n\n");    
        
        return;
    }
    else{
        current = root;
        parent = NULL;
        while (1)
        {
            parent = current;
            if(data < current -> data)
            {
                current = current -> left;

                if(current == NULL)
                {
                    parent->left = newNode;
                    
                    printf("\n ------------------------------------------------------------");
                    printf("\n|                       Element Inserted!                    |");
                    printf("\n ------------------------------------------------------------\n\n");
                    
                    return;
                }
            }
            else 
            {
                current = current->right;
                if(current == NULL)
                {
                    parent->right = newNode;
                    
                    printf("\n ------------------------------------------------------------");
                    printf("\n|                       Element Inserted!                    |");
                    printf("\n ------------------------------------------------------------\n\n");    
                    
                    return;
                }
            }
        }
    }
}

void search( int key)
{
    struct node *current;
    
    if(root == NULL)
    {
        return;
    }
    else{
        current = root;

        while (1)
        {
            if(key == current -> data)
            {
                printf("\n ------------------------------------------------------------");
                printf("\n|                         Element Found!                     |");
                printf("\n ------------------------------------------------------------\n\n");
                return;
            }
            else if(key < current -> data)
            {
                current = current -> left;
            }
            else 
            {
                current = current->right;
            }
        }   
    }   
}

void inOrder(struct node *node)
{
    if(node == NULL)
        return;
    else
    {
        inOrder(node->left);
        printf("%d\t",node->data);
        inOrder(node->right);
    }
}

void preOrder(struct node *node)
{
    if(node == NULL)
        return;
    else
    {
        printf("%d\t",node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(struct node *node)
{
    if(node == NULL)
        return;
    else
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d\t",node->data);
    }
}

int main()
{
    char choice;
    int  data, key;
 
    while (1)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                     Binary Search Tree                     |");
        printf("\n ------------------------------------------------------------\n\n");
        
        printf(" Press any key to Continue... ");
        getch();

        printf("\n\n --X--X--X--X Operation on  Binary Search Tree X--X--X--X--");
        printf("\n|                                                            |");
        printf("\nX    1. Insert Data at the begining of the List              X");
        printf("\n|    2. Inorder Traversal                                    |");
        printf("\nX    3. Preorder traversal                                   X");
        printf("\n|    4. Postorder Traversal                                  |");
        printf("\nX    5. Search an Element                                    X");
        printf("\n|    6. Exit                                                 |");
        printf("\nX                                                            X");
        printf("\n --X--X--X--X--X--X--X--X--X---X--X--X--X--X--X--X--X--X--X--");

        printf("\n\n Enter Your Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1: 
                printf("\n ------------------------------------------------------------");
                printf("\n|                       Insertion of data                    |");
                printf("\n ------------------------------------------------------------\n\n");
                printf("\n Enter the Element: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("\n ------------------------------------------------------------");
                printf("\n|                      Inorder Traversal!                   |");
                printf("\n ------------------------------------------------------------\n\n");
                
                inOrder(root);
                break;
            case 3:
                printf("\n ------------------------------------------------------------");
                printf("\n|                      Preorder Traversal!                   |");
                printf("\n ------------------------------------------------------------\n\n");
                
                preOrder(root);
                break;
            case 4:
                printf("\n ------------------------------------------------------------");
                printf("\n|                     Postorder Traversal!                   |");
                printf("\n ------------------------------------------------------------\n\n");
            
                postOrder(root);
                break;
            case 5:
                printf("\n ------------------------------------------------------------");
                printf("\n|                       Searching Element!                   |");
                printf("\n ------------------------------------------------------------\n\n");
                printf(" Enter the Element to Search: ");
                scanf("%d", &key);
                search(key);
                break;
            case 6:
                printf("\n ------------------------------------------------------------");
                printf("\n|              Linked List Implementation Ended!             |");
                printf("\n ------------------------------------------------------------\n\n");
                exit(0);
                break;
            default:
                printf("\n ------------------------------------------------------------");
                printf("\n|                       Invalid Choice!                      |");
                printf("\n ------------------------------------------------------------\n\n");
        }
    }    
    return 0;
}