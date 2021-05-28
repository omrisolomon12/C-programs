#include<stdio.h>

int Find_GCD(int num1, int num2);

int main()
{
    int number1 = 0, number2 = 0;
    int GCD = 0;

    printf("Find the GCD of two numbers \n\n");

    printf("Enter first number :\n");
    scanf("%d",&number1);

    printf("\nEnter second number :\n");
    scanf("%d",&number2);

    GCD = Find_GCD(number1,number2);
    printf("\nTHe GCD of %d and %d is :%d",number1,number2,GCD);
}

int Find_GCD(int num1,int num2)
{

    while (num1 != num2)
    {
        if (num1 > num2)
        {
             return Find_GCD(num1-num2,num2);
        }
        else
        {
             return Find_GCD(num2-num1,num1);
        }
    }

    return num1;

}
