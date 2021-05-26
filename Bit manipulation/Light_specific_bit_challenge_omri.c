#include <stdio.h>
int main()
{
    int num, position, NewNum, bitStatus;

    /* Input number from user */
    printf("Enter any number : ");
    scanf("%d",&num);

    /* Input bit position you want to set */
    printf("Enter nth bit to check and set (0-31): ");
    scanf("%d",&position);

    // check if the position bit in num is 1 or 0
    // shift num position times to the right it means that we the position bit is go to the 0 bit and we check it
    // num = 4 (100) , and position = 2 - > bitStatus = 001 & 1 = 1

    bitStatus = (num >> position)&1;
    printf("the %d bit is set to %d\n",position,bitStatus);

    // shift 1 position times to the left -> bit in position is turn on to 1
    /* Left shift 1, n times and perform bitwise OR with num */
    NewNum = (1 << position)| num;
    printf("\nBit set successfully.\n\n");

    printf("Number before setting %d bit is: %d (in decimal)\n",position,num);
    printf("Number after setting %d bit is: %d (in decimal)",position,NewNum);








}
