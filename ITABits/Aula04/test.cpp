#include <iostream>

using namespace std;

int n;
int s;
int vector [30];

int rec (int a, int b)
{
    if (b == 0)
        if(a == s)
            return 1;
        else
            return 0;
    
    return (rec(a + vector[b-1],b-1) + rec(a,b-1));
}

int main ()
{
    cin >> n >> s;
    for(int k = 0; k<n;k++)
        cin >> vector[k];
    cout << rec(0,n);
    return 0;
}
