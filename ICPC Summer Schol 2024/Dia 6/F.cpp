#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1e5+10;
typedef long long ll;
ll num[NMAX], numf[NMAX];

ll n, med;
ll val (ll m)
{
    return num[m] - med;
}
int main ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    ll a, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        num[i] = a;
        sum += a;
    }

    int med = sum/n;
    int mmed = sum - med*n;

    for (int i = 0; i < mmed; i ++)
        numf[i] = med + 1;
    for (int i = mmed; i < n; i++)
        numf[i] = med;

    sort(numf, numf + n);
    sort(num , num + n);

    ll t = 0;

    for (int i = 0; i < n; i++)
        t += abs(num[i] - numf[i]);

    cout << t/2 << endl;

    return 0;
}
