// Lab-32:  WAP To Find the Smallest and Largest Elements in the Binary Search Tree.
// Developed by: Ghanshyam Prajapati
// Date: 22/12/2020

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node* Insert(  struct node *current, long int data);
void InsertRoot(struct node* current, int data);
void inOrder(struct node *node);
void preOrder(struct node *node);
void postOrder(struct node *node);
void search( struct node *current, int key); 
void maxElement(struct node *current);
void minElement(struct node *current);

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root;

struct node* Insert( struct node *current, long int data)
{    
    if(current == NULL)
    {
        struct node *newNode = (struct node*)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        
        return newNode;
    }
    if(data < current->data) // 2 < 15 / 2 < 3
    {
        current->left = Insert(current->left, data); // 3, 2 // NULL, 2
    }
    else if(data > current->data)
    {
        current->right = Insert(current->right, data);
    }
    return current;
}

void InsertRoot(struct node *current, int data) 
{
    if(root == NULL)
    {
        root = Insert(current,data);
    }
    else
        Insert(current,data);
}

void search( struct node* current, int key) 
{
    if(current == NULL)
    {
        return;
    }
    else
    {
        if(current->data == key)
        {
            printf("\n Element Found!\n");
            return;
        }
        else if(key < current -> data)
        {
            search(current -> left, key);
        }
        else 
        {
            search(current -> right, key);
        }
    }
}

void minElement(struct node *current)
{
    if(root == NULL)
        return;
    else
    {
        if(current->left ==  NULL)
        {
            printf("\n %d\n", current->data);
            return;
        }
        else
        {
            minElement(current->left);
        }   
    }
}

void maxElement(struct node *current)
{
    if(root == NULL)
        return;
    else
    {
        if(current->right ==  NULL)
        {
            printf("\n %d\n", current->data);
            return;
        }
        else
        {
            maxElement(current->right);
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
        printf("\nX    1. Insert Data                                          X");
        printf("\n|    2. Inorder Traversal                                    |");
        printf("\nX    3. Preorder traversal                                   X");
        printf("\n|    4. Postorder Traversal                                  |");
        printf("\nX    5. Search an Element                                    X");
        printf("\n|    6. Smallest Element                                     |");
        printf("\nX    7. Largest Element                                      X");
        printf("\n|    8. Exit                                                 |");
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
                InsertRoot( root, data);
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
                search(root, key);
                break;
            case 6:
                printf("\n ------------------------------------------------------------");
                printf("\n|                     Smallest Element                       |");
                printf("\n ------------------------------------------------------------\n\n");
                minElement(root);
                break;
            case 7:
                printf("\n ------------------------------------------------------------");
                printf("\n|                      Largest Element                       |");
                printf("\n ------------------------------------------------------------\n\n");
                maxElement(root);
                break;
            case 8:
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
