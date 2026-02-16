#include <bits/stdc++.h>

#define vi vector <int>
#define pb push_back
#define ff first
#define ss second
#define ll long long
#define int ll
#define endl '\n'

using namespace std;

vi primes;
void pre_calc_primes () {
    primes.pb(2);
    primes.pb(3);
    primes.pb(5);
    for (int i = 7; i <= 2e5+1; i+=2) {
        bool ehp = true;
        for (int j = 0; primes[j]*primes[j] <= i; j ++)
            if (i % primes[j] == 0)
                ehp = false;
        if (ehp)
            primes.pb(i);
    }
}

void solve () {
    pre_calc_primes();
    int n;
    cin >> n;
    map <int, int> freq;
    int aux;
    for (int i = 0 ; i < n; i++) {
        cin >> aux;
        for (int j = 0; primes[j]*primes[j] <= aux + 1; j++) {
            int p = primes[j];
            int sqr = p*p;
            if (aux % (sqr) == 0) {
                aux /= sqr;
                j--;
            }
        }
        freq[aux]++;
    }

    int ans = 0;
    ans += freq[0]*(n-freq[0]);

    for (auto v : freq) {
        ans += (v.ss * (v.ss - 1)) / 2;
    }

    cout << ans << endl;
}
signed main () {
    int nt = 1;
    // cin >> nt;
    while(nt--)
        solve ();
    return 0;
}