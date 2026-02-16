#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll

template <ll p, ll m>  struct hashing_string
{
    int n;
    vector <ull> has, pows;
    hashing_string (string str) : n(str.size()), has(n+1), pows(n + 1) {
        pows [0] = 1;
        has  [0] = str[0];
        for (int i = 1; i < str.size(); i ++)
        {
            pows[i]  = (pows[i - 1]*p) % m;
            has [i]  = (has[i - 1]*p + str[i]) % m;
        }
    };
    ll operator () (int l, int r){
        return get_hash(l, r);
    }
    bool comp_int (int l1, int r1, int l2, int r2){
        return get_hash(l1,r1) == get_hash(l2,r2);
    }
    private:
        ll get_hash (int l, int r){
            ll hash_lr = has[r] - (l != 0 ? (has[l-1]*pows[r-(l-1)]) % m : 0);
            if (hash_lr < 0) hash_lr += m;
            return hash_lr;
        }
};

int main ()
{
    string in;
    cin >> in;

    hashing_string<31, (int) 1e9+9> hash_ (in);
    reverse(in.begin(), in.end());

    for (int i = 0; i < 15; i++)
    {
        int l,r;
        cin >> l >>  r;
        cout << hash_(l,r) << endl;
    }
    return 0;
}
