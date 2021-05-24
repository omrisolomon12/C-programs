#include <stdio.h>
#include <math.h>

int convert_bin_to_decimal(long long n);

int main(){

    long long n;
    printf("enter your binary number: ");
    scanf("%lld",&n);
    printf("%lld in binary = %d in decimal\n",n,convert_bin_to_decimal(n));
    return(0);
}

int convert_bin_to_decimal(long long n){


    int decimal_number =0, i =0, reminder;
    while (n!=0){

    reminder = n%10;
    n /= 10;
    decimal_number += reminder*pow(2,i);
    ++i;
}
    return decimal_number;

}



