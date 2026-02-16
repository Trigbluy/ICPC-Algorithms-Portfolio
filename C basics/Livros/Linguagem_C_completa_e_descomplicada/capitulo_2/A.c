#include <stdio.h>
int main ()
{
    char x;
    int y;
    float z;
    scanf("%c%d%f",&x,&y,&z);
    printf("%c  %d  %f\n%d %f %c\n%f  %c  %d",x,y,z,y,z,x,z,x,y);
    return 0;
}