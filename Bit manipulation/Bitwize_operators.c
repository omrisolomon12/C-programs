#include <stdio.h>

int main(){

signed int w1 =3;
signed int w2 =2;

// להחליף את 2 המספרים בלי להגדיר משתנה temp (עם xor)

w1 ^= w2;
w2 ^= w1;
w1 ^= w2;
printf("w1 is: %d\nw2 is: %d\n", w1,w2);

w1 = 2;
//מספרים שליליים
signed int result=0;

result = ~(w1); //twos compliment אז מינוס 3 מייצג את פלוס 2 , ניקח את 3 נהפוך לו את כל הביטים ונוסיף אחד -> נקבל כמו שניקח את 2 ונהפוך לו את כל הביטים

printf("\n%d",result);


// shifting

int w3 =3; // 0000 0000 0000 0000 0000 0000 0000 0011 in 32 bits
int res = 0;
res = w3 << 1; // 0000 0000 0000 0000 0000 0000 0000 0110
printf("\n 3 after 1 shift to the left is: %d\n",res);
res = res << 2;
printf("\n 6 after 2 shifting to the left is: %d\n",res);// 0000 0000 0000 0000 0000 0000 0001 1000 is 24


}
