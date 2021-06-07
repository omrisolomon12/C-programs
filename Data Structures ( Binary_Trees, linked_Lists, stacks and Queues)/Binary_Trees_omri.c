#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct treeNode
{
    int data; // node value
    struct treeNode *leftptr; // pointer to the left subtree
    struct treeNode *rightptr; // pointer to the right subtree
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;


void InsertNode(TreeNodePtr *treeptr, int value);
void inOrder(TreeNodePtr  treeptr);
void preOrder(TreeNodePtr  treeptr);
void postOrder(TreeNodePtr  treeptr);


int main()
{
    int i = 0;
    int item = 0;

    TreeNodePtr rootptr = NULL;

    srand(time(NULL));
    printf("The numbers being placed in the tree are:\n");

    //insert random values between 0 to 14 in the tree
    for (i=1; i<=10; i++)
    {
        item = rand() % 15;
        printf("%3d",item);
        InsertNode(&rootptr,item);
    }

    printf("\nThe preOrder traversal is:\n");//(root,left,right)
    preOrder(rootptr);
    printf("\nThe inOrder traversal is:\n"); // (left,root,right)
    inOrder(rootptr);
    printf("\nThe postOrder traversal is:\n");// (left,right,root)
    postOrder(rootptr);
    return 0;
}

void InsertNode(TreeNodePtr *treeptr, int value)
{
    if (*treeptr == NULL)
    {

        *treeptr = malloc(sizeof (TreeNode));

        // if memory was allocated then assign data
        if (*treeptr != NULL)
        {

            ( *treeptr )->data = value;
            ( *treeptr )->leftptr = NULL;
            ( *treeptr )->rightptr = NULL;
        }
        else {
            printf("%d no inserted. No memory available \n", value);
        }
    }
    else
    {
        if((( *treeptr ) ->data) < value )
        {
            InsertNode(&(( *treeptr )->rightptr),value);
        }

        else if ((( *treeptr )->data) > value)
        {
            InsertNode(&(( *treeptr )->leftptr),value);
        }
        else {
            printf("dup");
        }
    }
}

void inOrder(TreeNodePtr  treeptr)
{
    if (treeptr != NULL)
    {
        inOrder(treeptr->leftptr);
        printf("%3d",treeptr->data);
        inOrder(treeptr->rightptr);
    }
}


void preOrder(TreeNodePtr treeptr)
{
    if(treeptr != NULL)
    {
        printf("%3d", treeptr->data);
        preOrder(treeptr->leftptr);
        preOrder(treeptr->rightptr);
    }
}


void postOrder(TreeNodePtr treeptr)
{
    if(treeptr != NULL)
    {
        postOrder(treeptr->leftptr);
        postOrder(treeptr->rightptr);
        printf("%3d", treeptr->data);
    }
}
