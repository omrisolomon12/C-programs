#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// size must be specified initially

#define MAXSIZE 5

struct stack{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;

STACK s;

void push(void);
void pop (void);
void display(void);

void main()
{
    int choice;
    int option = 1;
    s.top = -1;

    while (option)
    {
        printf("----------------------------------\n");
        printf("           1 -> push \n");
        printf("           2 -> pop \n");
        printf("           3 -> display \n");
        printf("           4 -> exit \n");
        printf("----------------------------------\n");

        printf("Enter your choice");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1 :
                push();
                break;
            case 2 :
                pop();
                break;
            case 3 :
                display();
                break;
            case 4 :
                return;
        }

        printf("Do you want to continue ? (type 0 or 1)\n");
        scanf("%d",&option);
    }
}


void push()
{
    int num = 0;
    if(s.top == MAXSIZE -1)
    {
        printf("stack is full");
    }
    else{

        printf("Enter the element to be pushed\n");
        scanf("%d",&num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}

void pop ()
{
    int num;
    if (s.top == -1)
    {
        printf("The stack is empty");
        return (s.top);
    }
    else{
        num = s.stk[s.top];
        printf("popped element is %d\n",num);
        s.top = s.top -1 ;
    }
    return (num);
}

void display()
{
    int i = 0;
    if (s.top==-1)
    {
        printf("Stuck is empty\n");
        return;
    }
    else
    {
        printf("\n The status of the Stuck is : \n");
        for (i = s.top; i>=0; i--)
        {
            printf("%d\n",s.stk[i]);
        }
        printf("\n");
    }

}
