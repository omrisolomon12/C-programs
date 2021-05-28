#include<stdio.h>

int Calculate_Sum(int num);

int main()
{
    int number;
    int sum;

    printf("\n\n Recursion : calculate the sum of numbers from 1 to n :\n\n");
    printf("-----------------------------------------------------------\n");

    printf(" Input n, the last number of the range starting from 1 : ");
    scanf("%d",&number);

    sum = Calculate_Sum(number);

    printf("\n The sum of numbers from 1 to %d is : %d\n\n",number,sum);
    return 0;
}

int Calculate_Sum(int num)
{
    int count;
    int res = 0;

    if (num == 1){
        return 1;
    }
    else
        res += num + Calculate_Sum(num-1);

    return res;





}
