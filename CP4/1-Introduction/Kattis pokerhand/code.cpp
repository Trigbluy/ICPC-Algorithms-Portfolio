#include <bits/stdc++.h>

int main ()
{
    int n;
    int nsols = 0;

    scanf("%d",&n);

    // numero arvores= x*y + (x-1)*(y-1) = 2xy -x -y +1 -> nar = (2y-1)*x -y + 1
    // -> x =(nar +y - 1)/(2*y-1)

    // nar = 2x²-2x+1 -> 2x²-2x+1-nar=0

    // x = (2 +-(4 -4*2*(1-nar)))/4
    // x =  ( 1+{2*nar-1})/2

    //y =2 -> n= 3*x -1 -> x = (n+1)/3
    // x>=y

    int cnst = (1 + sqrt(2*n-1))/2 + 1;
    for (int i = 2; i <= cnst; i++)
    {
        int k = (n + i -1)/(2*i -1);
        if (n == i*k + (i-1)*(k-1))
            nsols++;
    }
    
    
    printf("%d\n",nsols);

    return 0;
}