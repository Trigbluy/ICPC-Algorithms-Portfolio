#include <stdio.h>

int main ()
{
    int idade;
    printf("Qual a idade do nadador?\n");
    scanf("%d",&idade);
    if (idade > 17)
    {
        printf("Sua categoria eh Senior");
    }
    else if (idade >4 && idade <8)
    {
        printf("Sua categoria eh Infantil A");
    }
    else if (idade >7 && idade <11)
    {
        printf("Sua categoria eh Infantil B");
    }
    else if (idade >10 && idade <14)
    {
        printf("Sua categoria eh Juvenil A");
    }
    else if (idade >13 && idade <18)
    {
        printf("Sua categoria eh Juvenil B");
    }
    return 0;
}