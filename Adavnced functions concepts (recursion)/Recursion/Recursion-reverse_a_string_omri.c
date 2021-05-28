#include<stdio.h>

char *reverse(char *str);

int main()
{
    char string[100];
    char *rev = NULL;

    printf("Enter your string :\n");
    scanf("%s",string);

    printf("your string is : %s\n", string);

    rev = reverse(string);
    printf("The revers string is :%s\n",rev);

    return 0;
}

char *reverse(char *str)
{
    static int i = 0;
    static char rev[100];

    if(*str)
    {
        reverse(str +1);
        rev[i++] = *str;
    }
    return rev;
}
