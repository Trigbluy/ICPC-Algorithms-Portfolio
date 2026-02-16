#include <stdio.h>

typedef struct {
    int x ;
    float y;
    char t[50];
} lol;
int main ()
{
    lol a = {1,2.1,"Paizin"};
    lol b;
    
    b = a;
    printf("%d%f%s",b.x,b.y,b.t);
    return 0;
}