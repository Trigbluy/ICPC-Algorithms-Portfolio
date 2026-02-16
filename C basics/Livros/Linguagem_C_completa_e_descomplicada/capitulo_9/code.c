#include <stdio.h>
int bits(int n)
{
    
    if(n != 0 && n != 1)
        bits(n/2);
    printf("%d",n%2);
    return 0;
}
int main ()
{
    int n;
    scanf("%d",&n);
    bits(n);
    return 0;
}