#include <stdio.h>

long long convertDecimalToBinary(int n);

int main()
{
 int num1 = 0, num2 = 0;
 long long b_num1 = 0, b_num2 = 0;

 long long b_num1ComplementResult = 0;
 long long b_num2ComplementResult = 0;
 long long b_num1_AND_b_num2 = 0;
 long long b_num1_OR_b_num2 = 0;
 long long b_num1_XOR_b_num2 = 0;
 long long b_num1_LEFT_Shift = 0;

 printf("Enter an integer : \n");
 scanf("%d",&num1);
 printf("Enter another integer : \n");
 scanf("%d",&num2);

 b_num1 = convertDecimalToBinary(num1);
 b_num2 = convertDecimalToBinary(num2);


 b_num1ComplementResult = convertDecimalToBinary(~num1);
 b_num2ComplementResult = convertDecimalToBinary(~num2);


 b_num1_AND_b_num2 = convertDecimalToBinary(num1 & num2) ;
 b_num1_OR_b_num2 = convertDecimalToBinary(num1 | num2) ;
 b_num1_XOR_b_num2 = convertDecimalToBinary(num1 ^ num2) ;
 b_num1_LEFT_Shift = convertDecimalToBinary(num1<<2);

 printf("The result of applying operator ~ of number %d (%lld) is : %lld \n",num1,b_num1,b_num1ComplementResult);
 printf("The result of applying operator ~ of number %d (%lld) is : %lld \n",num2,b_num2, b_num2ComplementResult);
 printf("The result of applying operator & of number %lld and number %lld is : %lld \n",b_num1,b_num1,b_num1_AND_b_num2);
 printf("The result of applying operator | of number %lld and number %lld is : %lld \n",b_num1,b_num1,b_num1_OR_b_num2);
 printf("The result of applying operator ^ of number %lld and number %lld is : %lld \n",b_num1,b_num1,b_num1_XOR_b_num2);
 printf("The result of applying operator << of number %d by 2 places is number is : %lld \n",num1,b_num1_LEFT_Shift);
}

long long convertDecimalToBinary(int n)
{
    long long binaryNumber = 0;
    int reminder, i=1;
    while(n!=0)
    {
        reminder = n%2;
        n /= 2;
        binaryNumber += reminder*i;
        i *= 10;
    }
    return binaryNumber;
}
