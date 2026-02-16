#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    long long amount = 0;

    cin >> n;
    char in;

    while (cin >> in)
    {
        
        if (in == 'R')
            amount = 2*amount + 2LL;
        else if (in == 'L')
            amount = 2*amount + 1LL;
    }

    long long opos = 1LL << (n + 1);

    cout << opos - amount - 1LL << endl;

    return 0;
}