#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define int ll
#define ld long double
const int NMAX = 1e5 + 10;
int val [NMAX];
deque<int> ordem;
int n;
ld area, sen;

int32_t main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n ; i ++)
        cin >> val[i];
    
    sort(val, val + n);

    ordem.push_front(val[n-1]);
    ll fr, bk;
    for (int i = n-2; i >= 0; i--)
    {
        fr = ordem.front();
        bk = ordem.back();
        if (fr > bk)
            ordem.push_front(val[i]);
        else
            ordem.push_back(val[i]);
    }

    sen = sinl(2*M_PI/n);

    ll ft = ordem.front(); ordem.pop_front();
    ll ant = ft, at;

    while(!ordem.empty())
    {
        at = ordem.front();   ordem.pop_front();
        area += at*ant;
        ant = at;
    }
    area += ft*ant;

    area = (area*sen)/((ld)2);

    cout << fixed << setprecision(3) << area << endl;
    return 0;
}   