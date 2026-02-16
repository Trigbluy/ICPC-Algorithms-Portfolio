#include <Stdio.h>

int main()
{
    int matriz[5][5];
    printf("Digite 25 numeros.\n");
    for (int i = 0; i < 5; i++)
    {
        for(int k = 0; k < 5 ;k++)
            scanf("%d",&matriz[i][k]);
    }
    int resp[5][5] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(int i = 0;i<5;i++)
        for(int k = 0;k<5;k++)
            for(int o = 0;o<5;o++)
                resp[i][k] += matriz[i][o]*matriz[o][k];
    for (int i = 0; i < 5; i++)
    {
        for(int k = 0; k < 5 ;k++)
            printf(" %d ",matriz[i][k]);
        printf("\n");
    }
    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        for(int k = 0; k < 5 ;k++)
            printf(" %d ",resp[i][k]);
        printf("\n");
    }
    return 0;

}