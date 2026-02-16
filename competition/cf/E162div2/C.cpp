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
const int NMAX = 3e5 + 10;
int pre[NMAX], qnt[NMAX];
void solve () {
    int n, q;
    cin >> n >> q;
    int aux;
    pre[0] = 0, qnt[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> aux;
        pre[i] = pre[i-1] + aux - 1;
        qnt[i] = qnt[i-1] + (aux == 1);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int sumlr = pre[r] - pre[l-1];
        int qnt1  = qnt[r] - qnt[l-1];
        int m     = r - l + 1;
        if (sumlr >= qnt1  && m > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int32_t main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while (nt--)
        solve();
    return 0;
}