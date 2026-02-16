#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < b; i++)
#define f first
#define s second
#define endl '\n'
#define int ll
const signed NMAX = 3*10e5+1;
const signed M = 998244353;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<int,int> mp;

vi graph[NMAX];
int val[NMAX];
mp seqs[NMAX];

bool ord (int a, int b){
    return val[a] > val[b];
}

void solve(){
    int n, m;
    cin >> n >> m;
    int a, b;
    fin(i,0,n){
        seqs[i+1].clear();
        graph[i+1].clear();
        cin >> val[i+1];
    }
    fin(i,0,m){
        cin >> a >> b;
        graph[a].pb(b);
        seqs[b][a] = 1;
    }

    vi ordem,marc(n+1,0);
    fin(i,1,n+1)
        ordem.pb(i);
    sort(ordem.rbegin(),ordem.rend(),ord);
    int ans = m;
    for (int v : ordem) {
        // cout << "ordem: " << v << endl;
        marc[v] = 1;
        fin(i,0,graph[v].size()){
            int viz = graph[v][i];
            for (ii p : seqs[v]){
                // cout << "analasing: " << p.f << ", " << p.s << " -> " << v << " -> " << viz << endl;

                if (val[v] + val[p.f] == val[viz] && !marc[viz]) {
                        ans = (ans + p.s)%M;
                        seqs[viz][v] = p.s + 1;
                }
            }
        }
    }
    
    cout << ans << endl;
}


signed main (){
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

/*
4
4 4
3 4 3 6
1 2
1 3
2 4
3 4
4 6
1 1 1 2
1 2
2 3
3 1
1 4
2 4
3 4
8 11
2 4 2 6 8 10 18 26
1 2
2 3
3 1
4 3
2 4
3 5
5 6
4 6
6 7
7 5
5 8
2 2
10 10
1 2
2 1



1
4 4
3 4 3 6
1 2
1 3
2 4
3 4


1
8 11
2 4 2 6 8 10 18 26
1 2
2 3
3 1
4 3
2 4
3 5
5 6
4 6
6 7
7 5
5 8

*/