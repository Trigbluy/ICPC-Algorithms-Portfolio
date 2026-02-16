#include <stdio.h>

int main()
{
    char str[50];
    printf("Digite uma frase.\n");
    gets(str);
    for(int i = 0;i<50;i++)
    {
        if(str[i]>=97-32 && str[i]<= 122-32)
            str[i]+=32;
    }
    printf("%s",str);
}