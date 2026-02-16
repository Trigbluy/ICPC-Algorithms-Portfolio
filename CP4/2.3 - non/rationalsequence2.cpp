#include <bits/stdc++.h>

using namespace std;

long long source (long long p, long long q)
{
    if (p == q)
        return 1LL;
    
    if (p > q)
        return 2*source(p-q, q) + 1LL;
    
    return 2*source(p, q-p);
}

int main ()
{
    int n;

    cin >> n;
    
    while(n--)
    {
        long long k, p,q;
        cin >> k >> p;
        cin.ignore(1);
        cin >> q;

        cout << k << ' ' << source(p,q) << endl;
    }

    return 0;
}