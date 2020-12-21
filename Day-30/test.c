// WAP to Search an Element in a Tree Recursively.

#include<stdio.h>
#include<stdlib.h>
// #include<conio.h>

// void insert( long int data);
// void inOrder(struct node *node);
// void preOrder(struct node *node);
// void postOrder(struct node *node);
// void search( struct node* current, int key); 

struct node
{
    long int data;
    struct node *left;
    struct node *right;
};

struct node *root;

struct node* Insert( struct node* current, int data)
{    
    if(current == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        
        return newNode;
    }
    if(data < current->data)
    {
        current->left = Insert(current->left, data);
        
        printf("\nElement Inserted!\n");
    }
    else if(data >= current->data)
    {
        current->right = Insert(current->right, data);

        printf("\nElement Inserted!\n");
    }
    else
    {
        printf("\nInvalid!\n");
    }

    return current;
}

void InsertRoot(struct node* current, int data)
{
    if(root == NULL)
    {
        root = Insert(current,data);
    }
    else
        Insert(current,data);
}

void search( struct node* parent, int key) 
{
    struct node* current = parent;

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

void inOrder(struct node *node)
{
    if(node != NULL)
    {
        inOrder(node->left);
        printf("%ld\t",node->data);
        inOrder(node->right);
    }
}

void preOrder(struct node *node)
{
    if(node != NULL)
    {
        printf("%ld\t",node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(struct node *node)
{
    if(node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%ld\t",node->data);
    }
}

int main()
{
    int choice;
    long int  data, key;
    // struct node *node;
    while (1)
    {
        printf("\n ------------------------------------------------------------");
        printf("\n|                     Binary Search Tree                     |");
        printf("\n ------------------------------------------------------------\n\n");
        
        printf(" Press any key to Continue... ");
        getchar();

        printf("\n\n --X--X--X--X--X-- Operation on Linked List --X--X--X--X--X--");
        printf("\n|                                                            |");
        printf("\nX    1. Insert Data                                          X");
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
                scanf("%ld", &data);
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
                printf("Enter the Element to Search: ");
                scanf("%ld", &key);
                search(root, key);
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