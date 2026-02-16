#include <stdio.h>

int main ()
{
    int a, *b, **c, ***d;
    b = &a;
    c = &b;
    d = &c;
    scanf("%d",&a);
    printf("%d, %d, %d, %d",a,2*(*b),3*(**c),4*(***d));
    return 0;

}