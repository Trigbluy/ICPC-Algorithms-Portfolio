#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define fin(i,a,b) for (int i = a; i < (int) b; i++)
#define pb push_back
#define f first
#define s second
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int NMAX = 1e5 + 100;
vi graph[NMAX], arestas[NMAX];
int marc[NMAX];
void solve () {
    int n, m;
    cin>> n>> m;
    int a,b,c;
    fin(i,0,m){
        cin >> a >> b >>c;
        graph[a].pb(b);
        graph[b].pb(a);
        arestas[a].pb(c);
        arestas[b].pb(c);
    }
    vi added;
    map<ll,ll> mp;
    ll ans = 0, d = 1;
    added.pb(1);n--; marc[1] = 1;
    while(n){
        for (int v : added)
            fin(i,0,graph[v].size()){
                int viz = graph[v][i];
                int arestSz = arestas[v][i];
                if (!marc[viz]){
                    if (mp.find(viz) == mp.end())
                        mp[viz] = arestSz;
                    else
                        mp[viz] = min(mp[viz],arestSz);
                }
            }
        added.clear();
        for (ii p : mp){
            added.pb(p.f);
            ans += d*p.s;
            marc[p.f] = 1;
            n--;
        }
        mp.clear();
        d++;
    }
    cout << ans << endl;
}
int32_t main () {
    // fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}