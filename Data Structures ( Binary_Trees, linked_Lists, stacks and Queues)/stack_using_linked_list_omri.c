#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// Stack - first in last out;

struct node
{
    int data;
    struct node *link;
};

struct node *top, *temp;

void push(int data)
{
    temp =(struct node *)malloc(sizeof(struct node));
    if (temp != NULL)
    {
    temp->data = data;
    temp->link = top;
    top = temp;
    }
}

int IsEmpty ()
{
    return top ==NULL;
}


void pop() // delete the first element
{

    struct node *temp;
    if(top != NULL)
    {
        temp = top;
        top = top->link;
        temp ->link = NULL;
        free(temp);
    }
}


void display()
{
    struct node *temp;
    temp = top;
    if (top != NULL)
    {
        temp = top;

        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }

    }
}


int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    display();

    pop();
    pop();

    display();

    return 0;




}
