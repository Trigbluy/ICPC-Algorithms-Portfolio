#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <ll P, ll M>
struct str_hash{
    int n;
    bool reversed;
    vector <ll> h,p;
    str_hash (string s) : n(s.size()), h(n+1), p(n+1), reversed (false) {
        h[0] = s[0]  ,  p[0] = 1;
        for (int i = 1; i < s.size(); i++)
            p[i] = p[i-1]*P % M,   h[i] = (h[i-1]*P % M + s[i]) % M;
    }
    str_hash (string :: reverse_iterator begin, string :: reverse_iterator end) : n(end-begin), h(n+1), p (n+1), reversed(true){
        h[0] = *begin, p[0] = 1;
        for (int i = 1; ++begin != end; i++)
            p[i] = p[i - 1]*P % M,  h[i] = (h[i-1]*P % M + *begin) % M;
    }
    ll operator () (int l, int r) {
        if (reversed) swap(l,r), l = n - 1 - l, r = n - 1 - r;  // guatemala (7,9) <-> alametaug (0,2)
        ll ha = h[r] - (l? (h[l-1]*p[r - (l-1)])%M : 0);
        return (ha + M) % M;
    }
};



int ini[int(1e6) + 2];
string in;

bool exist_pal (int sz, int n, str_hash <31, int(1e9+7)>& norm, str_hash <31, int(1e9+7)>& revr)
{
    if (sz <= 0) return true;
    for (int i = 0; i <= n - sz; i++)
    {
        int j = i + sz - 1;
        if (norm(i,j) == revr(i,j))
        {
            ini[sz] = i;
            return true;
        }
    }
    return false;
}

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie();

    cin >> in;
    str_hash <31, int(1e9+7)> norm(in), revr(in.rbegin(), in.rend());
    
    int maxpal = 0;
    for (int par = 0; par <= 1; par++)
    {
        int l = 0, r = (in.size())/2, m  = 0;
        while (l < r)
        {
            m = (l + r)/2;
            if (exist_pal(2*m + par, in.size(), norm, revr) == true)
                l = m + 1;
            else
                r = m - 1;
        }
        
        if (exist_pal(2*l + 2 + par, in.size(), norm, revr))
            maxpal = max(2*l+2+par, maxpal);
        else if (exist_pal(2*l + par, in.size(), norm, revr))
            maxpal = max(2*l + par, maxpal);
        else
            maxpal = max(2*((l - 1 > 0) ? (l-1) : 0) + par, maxpal);
    }

    for (int i = ini[maxpal]; i < ini[maxpal] + maxpal; i++)
        cout << in[i];
    cout << endl;

    return 0;
}