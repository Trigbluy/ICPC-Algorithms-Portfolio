#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
unordered_map <int,int> diag[2];

int n;

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n)
    {
        diag[0].clear();
        diag[1].clear();

        ll tot = n*n;
        ll qr = 0;
        ll sz;

        ll a,b, np, ns;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            np = diag[0][a + b]++;
            ns = diag[1][a - b]++;

            // qr += 2*np + 2*ns;
        }



        for (int i = 0; i < 2; i++)
            for (auto a : diag[i])
            {
                sz = a.second;
                qr += sz * (sz - 1);
                // cout << "Looking to " << a.first << " with " << a.second << " in " << i << " and ";
                // cout << "adding " << sz << " " << qr << endl;
            }

        // cout << qr << " " << tot << endl;
        long double resp = qr;
        resp /= (long double) tot;

        cout << fixed <<  setprecision(7)  << resp << endl;
    }

   return 0;
}