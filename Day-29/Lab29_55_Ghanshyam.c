// WAP to perform inorder, preorder, postorder traversal.

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
                    printf(" Inserted at Left\n");
                    return;
                }
            }
            else 
            {
                current = current->right;
                if(current == NULL)
                {
                    parent->right = newNode;
                    printf(" Inserted at Right\n");
                    return;
                }
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
    long int  data;
    // struct node *root;
    while (1)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                     Binary Search Tree                     |");
        printf("\n ------------------------------------------------------------\n\n");
        
        printf(" Press any key to Continue... ");
        getch();

        printf("\n\n --X--X--X--X--X-- Operation on Linked List --X--X--X--X--X--");
        printf("\n|                                                            |");
        printf("\nX    1. Insert Data at the begining of the List              X");
        printf("\n|    2. Inorder Traversal                                    |");
        printf("\nX    3. Preorder traversal                                   X");
        printf("\n|    4. Postorder Traversal                                  |");
        printf("\nX    5. Exit                                                 X");
        printf("\n|                                                            |");
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