#include <stdio.h>

int main ()
{
    int a,b; // Os numeros a serem comparados
    printf("Diga 2 numeros inteiros.\n");
    scanf("%d%d",&a,&b);
    printf(" -- Comparando os numeros bit a bit:\n\n * ou exclusivo: %d\n* ou bit a bit: %d\n*  e bit a bit: %d",a^b,a|b,a&b);
    return 0;
}