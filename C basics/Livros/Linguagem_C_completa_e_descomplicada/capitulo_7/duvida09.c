#include <stdio.h>
#include <string.h>

int main ()
{
    char str[50];
    char stra[50];
    char b[2] = {'a','\0'};
    char c[2] = "b";
    printf("Digite 2 frases.\n");
    gets(str);
    gets(stra);
    char *a = str;
    int cont = 0;
    int ok = 1;
    //printf("%d,%d\n",strstr(str,stra),strstr(a,stra));
    do
    {
        a = strstr(a + strlen(stra),stra);
        if(a == 0)
            ok = 0;
        if(strstr(str,stra) != 0)
            cont++;
    } while(ok); 
    printf("%d aparicoes.",cont);
    return 0;
}