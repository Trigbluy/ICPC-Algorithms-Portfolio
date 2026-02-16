#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define int ll
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector <int>
#define pb push_back
#define ff first
#define ss second
#define endl '\n'

using namespace std;
struct train {
    int l, d, k, c, b;
};
const ull INF =  numeric_limits<ull> :: max();
const int NMAX = 2e5 + 10;
int marc[NMAX];
vi arestas[NMAX];
vector <train> info;
priority_queue<pair<ull,int>> process;
void solve () {
    int n, m;
    cin >> n >> m;
    int l, d, k, c, a, b;
    for (int i = 0; i < m; i++) {
        cin >> l >> d >> k >> c >> a >> b;
        arestas[b].pb(i);
        info.pb({l, d, k, c, a});
    }
    vector<ull> resp (n + 1, INF);
    process.push({INF, n});
    while (!process.empty()) {
        auto v = process.top(); process.pop();
        int t = -v.ff;
        int node = v.ss;
        if (marc[node] == 1) continue;
        marc[node] = 1;
        resp[node] = t;

        for (int id : arestas[node]) {
            auto base = info[id];
            l = base.l, d = base.d, k = base.k, c = base.c, b = base.b;

            if (t - c < l)
                continue;
            
            if (t - c >= l + (k-1)*d) {
                process.push({-(l+(k-1)*d), b});
            }
            else {
                int ki = (t - c - l)/d;
                process.push({-(l+ki*d), b});
            }
        }
    }

    for (int i = 1; i < n; i++) {
        if (resp[i] == INF)
            cout << "Unreachable" << endl;
        else
            cout << resp[i] << endl;
    }
}
signed main () {
    fastio;
    int nt = 1;
    // cin >> nt;
    while(nt--)
        solve ();
    return 0;
}