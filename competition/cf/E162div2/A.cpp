#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0),cout.tie(0)
#define ll long long
#define int ll
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector <ii>
#define ff first
#define ss second
#define endl '\n'
using namespace std;

void solve () {
    int n;
    cin >> n;
    vi chips;
    int aux, ant = 0;;
    for (int i = 1; i <= n; i++) {
        cin >> aux;
        if (aux && ant)
            continue;
        chips.pb(aux);
        ant = aux;
    }

    int p = 0, i = 0;
    int ans = 0;
    while (p < chips.size() && i < chips.size())
    {
        
        while (p < chips.size() && !chips[p]) p++;
        i = p+1;
        while (i < chips.size() && !chips[i]) i++;
        if (p < chips.size() && i < chips.size() && i != p)
            ans += i - p - 1;
        p++;
    }
    cout << ans << endl;
}

int32_t main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while (nt--)
        solve();
    return 0;
}