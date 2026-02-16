#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define fin(i,a,b) for (int i = a; i < (int) b; i++)
#define int ll
#define pb push_back
#define f first
#define s second
// #define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
const ll INF = numeric_limits<ll> :: max();
const ll NINF = -(INF-1);
const int NMAX = 2e5+100;
void solve () {
    int n, m;
    cin >> n >> m;
    vector<pair<ii,ll>> edges;
    int a, b, c;
    fin(i,0,m){
        cin >> a >> b >> c;
        edges.pb({{a,b},c});
    }
    vi d(n+1,1), p(n+1,-1);
    d[1] = 0;
    int x;
    fin(i,0,n){
        x = -1;
        for(auto e : edges) {
            a = e.f.f, b = e.f.s, c = e.s;
            if (d[b] > d[a] + c){
                d[b] = d[a] + c;
                p[b] = a;
                x = a;
            }
        }
        if(x==-1){
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    fin(i,0,n) x = p[x];      // Tem que voltar n caras, se nao dah BO
    int cur = x;
    vi nodes; nodes.pb(x);
    while (cur != -1 && p[cur] != x){
        cur = p[cur];
        nodes.pb(cur);
    }
    reverse(nodes.begin(), nodes.end());
    cout << x;
    for(int i : nodes)
        cout << ' ' << i;
    cout << endl;
}
 
int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while(n_c--)
        solve();
 
    return 0;
}
/*


10 12
1 2 4
5 7 1
4 6 4
7 9 3
9 10 1
7 8 5
1 3 1
6 7 4
4 5 1
3 4 2
8 10 5
2 4 3

*/