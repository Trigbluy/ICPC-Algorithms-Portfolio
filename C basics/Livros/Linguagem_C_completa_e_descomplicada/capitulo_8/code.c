#include <stdio.h>
enum teles {da,de,di,doh,du} ;
int main ()
{
    enum teles tel= di;
    printf("%d",tel);
    return 0;
}