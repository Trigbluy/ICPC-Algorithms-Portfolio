#include <stdio.h>

int main ()
{
    char x[100];
    printf("4");
    scanf("0.%[0-9]...\n",x);
    printf("%s\n",x);
    return 0;
}