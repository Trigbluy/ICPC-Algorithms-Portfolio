#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int count[] = {0,0,0,0};
    char a;
    
    while (cin >> a)
        if (a == '_')
            count [0]++;
        else if ( 'a' <= a && a <= 'z')
            count [1]++;
        else if ( 'A' <= a && a <= 'Z')
            count [2]++;
        else
            count [3]++;
    
    for (int i = 0; i < 4; i++)
        printf("%.12lf\n", ((double) count[i])/( count [0] + count [1] + count [2] + count [3] ));

    return 0;
}