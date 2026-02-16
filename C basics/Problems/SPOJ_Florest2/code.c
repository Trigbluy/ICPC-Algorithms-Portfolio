#include <stdio.h>
#include <math.h>
int main ()
{
    short int t;
    scanf("%d",&t);
    for(short int k = 0; k < t ; k++)
    {
        long int m,n;
        scanf("%d %d",m,n);
        for(long int p = (n%2 == 1)?n:n-1; p <= m;p = p + 2)
        {
            long int d = 3; 
            for(d <=sqrt(p);d++;)
                if(p%d == 0)
                    break;
            if(d>sqrt(p))
                printf("%ld\n",p);
        }
        printf("\n");
    }
    return 0;
}