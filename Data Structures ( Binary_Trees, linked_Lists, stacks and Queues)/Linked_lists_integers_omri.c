#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int value;
    struct node *next;
};

struct node *createNode(int);
void InsertNodeAtTheBeginning();
void InsertNodeAtTheEnd();
void InsertNodeAtPosition();
void deletePosition();
void search();
void updateValue();
void display();

struct node *newnode, *ptr, *prev, *temp;
struct node *head = NULL, *tail = NULL;


int main()
{
    int ch='\0';

    while (true)
    {
        printf("\n---------------------------------\n");
        printf("\nOperations on a linked list\n");
        printf("\n---------------------------------\n");
        printf("\n1.Insert node at the beginning");
        printf("\n2.Insert node at the end");
        printf("\n3.Insert node at a specific position");
        printf("\n4.delete note from any position");
        printf("\n5.update node value");
        printf("\n6.Search elements in the linked list");
        printf("\n7.Display list");
        printf("\n8.Exit");
        printf("\n--------------------------------------\n");
        printf("enter your choice:");
        scanf("%d",&ch);


        switch(ch)
        {

        case 1:
            InsertNodeAtTheBeginning();
            break;
        case 2:
            InsertNodeAtTheEnd();
            break;
        case 3:
            InsertNodeAtPosition();
            break;
        case 4:
            deletePosition();
            break;
        case 5:
            updateValue();
            break;
        case 6:
            search();
            break;
        case 7:
            display();
            break;
        case 8:
            printf("\n...Exiting...");
            return 0;

        default:
            printf("\nInvalid Choice\n ");
        }

    }
return 0;
}


struct node *createNode(int val)// the value "val" is past in the created node
{
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
};

void InsertNodeAtTheBeginning()
{
    int val = 0;
    printf("\nInsert the value for the node:\n");
    scanf("%d",&val);
    createNode(val);
    newnode = createNode(val);

    if((head==tail)&&(head==NULL))// if the list is empty
    {
        head = tail = newnode;
        head->next = NULL;
        tail->next = NULL;
    }
    else// if the list is not empty
    {
        temp = head;
        head = newnode;
        head->next = temp;
    }
    printf("\n----INSERTED----");
}

void InsertNodeAtTheEnd()
{
    int val = 0;
    printf("\nInsert the value for the node:\n");
    scanf("%d",&val);
    createNode(val);
    newnode = createNode(val);

    if((head==tail)&&(head==NULL))// if the list is empty
    {
        head = tail = newnode;
        head->next = NULL;
        tail->next = NULL;
    }
    else// if the list is not empty ->insert newnode to tail and tail ->next to null
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = NULL;
    }
 printf("\n----INSERTED----");
}

void InsertNodeAtPosition()
{
    int val = 0, pos, count = 0,i;
    printf("\nInsert the value for the node: ");
    scanf("%d",&val);
    newnode = createNode(val);
    printf("\nInsert value for position");
    scanf("%d",&pos);

    ptr = head;

    while(ptr!=NULL)
    {
        ptr = ptr->next;
        count++;
    }

    if(pos==1)
    {

        if((head==tail)&&(head==NULL))// if the list is empty
            {
            head = tail = newnode;
            head->next = NULL;
            tail->next = NULL;
            }
        else// if the list is not empty
            {
            temp = head;
            head = newnode;
            head->next = temp;
            }
    printf("\n----INSERTED----");
    }

    else if(pos>1 && pos<=count)
    {
        ptr = head;
        for(i=1; i<pos; i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        prev->next =newnode;
        newnode->next = ptr;
        printf("\n----INSERTED----");
    }
     else
     {
         printf("\nPosition out of range");

     }
}

void deletePosition()
{
    int pos,i,count = 0;

   if(head==NULL)
   {
       printf("\nList is empty");
       printf("\nNo model to be deleted");
   }
   else
   {
    printf("\nInsert value for position to be deleted");
    scanf("%d",&pos);

    ptr = head;

    if(pos==1)
    {
        head = ptr->next;
        printf("\nElement Deleted");
    }

    else
    {
        while(ptr!=NULL)
            {
                ptr = ptr->next;
                count++;
            }

        ptr = head;
        if(pos>0 && pos <= count)
        {
            for(i=1; i<pos; i++)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = ptr->next;
            printf("\nElement deleted");
        }
        else
        {
         printf("\nPosition out of range");
        }
    free(ptr);
    }
   }
}

void updateValue()
{
    int oldval, newval, flag = 0;

    if (head == NULL)
    {
        printf("List is empty\n");
        printf(":No nodes in the list to update\n");
    }
    else
    {
        printf("\nEnter the value to be updated: ");
        scanf("%d", &oldval);
        printf("\nEnter the new value:");
        scanf("%d", &newval);
        for (ptr = head;ptr != NULL;ptr = ptr->next)
        {
            if (ptr->value == oldval)
            {
                ptr->value = newval;
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nUpdated Successfully");
        }
        else
        {
            printf("\nValue not found in List");
        }
    }
}


void search()
{
    int flag = 0, key, pos = 0;

    if (head == NULL)
    {
        printf("List is empty\n");
        printf(":No nodes in the list\n");
    }
    else
    {
        printf("\nEnter the value to search ");
        scanf("%d", &key);
        for (ptr = head;ptr != NULL;ptr = ptr->next)
        {
            pos = pos + 1;
            if (ptr->value == key)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nElement %d found at %d position\n", key, pos);
        }
        else
        {
            printf("\nElement %d not found in list\n", key);
        }
    }
}




void display()
{
    if (head == NULL)
    {
        printf("\nList is empty");
        printf("\nNo nodes in the list to display");
    }
    else
    {
        for (ptr = head;ptr != NULL;ptr = ptr->next)
        {
            printf("%d\t", ptr->value);
        }
    }
}


