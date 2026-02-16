#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int NMAX = 300010;

ll bolas[NMAX], base[NMAX];

int t, n, k;

bool eh_pos (int sz)
{
    if (n < sz * k )
        return false;
    if (k == 1 || sz == 0)
        return true;
    
    for (int i = 0; i < sz; i++)
        base [i] = bolas[i];

    int count = sz;
    
    for (int i = sz; i < n; i++)
        if (base [count % sz] >=  bolas [i] * 2)
        {
            base [count % sz] = bolas [i];
            count++;
            if (count >= sz*k)
                return true;
        }
        
    return false;
}


int main ()
{
    cin >> t;
    for (int n_c = 1; n_c <= t; n_c++)
    {
        cin >> n >> k;
        ll a;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            bolas[i] = a;
        }

        sort(bolas, bolas + n);
        reverse(bolas, bolas + n);

        // Busca Binaria na resposta

        int l, r, m;
        l = 0;  r = n;

        while (l < r)
        {
            m = (l + r)/2;
            if (eh_pos(m) == true)
                l = m + 1;
            else
                r = m - 1;
        }

        cout << "Case #" << n_c << ": ";
        if (eh_pos(l) == true || l == 0)
            cout << l << endl;  
        else
            cout << l-1 << endl;
    }
    return 0;
}