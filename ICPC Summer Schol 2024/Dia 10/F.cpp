#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int NMAX = 1e5+10;
ll prefix[NMAX];
set<ll>pref;

int n, nt, total;

ll pf (int v)
{
    return prefix[v % n];
}
int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie(0);

    while (cin >> n)
    {
        memset (prefix, 0, (n+2)*sizeof(prefix)/NMAX);
        pref.clear();
        nt = 0;
        ll a;
        for (int i = 1; i <= n; i++)
        {
            pref.insert(prefix[i-1]);
            cin >> a;
            prefix[i] = prefix[i-1] + a;
        }
        total = prefix[n];
        ll arc = total/3;
        if (3*arc != total)
        {
            cout << 0 << endl;
            return 0;
        }
        for (auto p : pref)
        {
            if (pref.find((p + arc) % total) != pref.end())
                if (pref.find((p + 2*arc) % total) != pref.end())
                    nt++;
        }
        cout << nt/3 << endl;
    }
    return 0;
}