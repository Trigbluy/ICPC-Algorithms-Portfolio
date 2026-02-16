#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fin(i,a,b) for(int i = a; i < (int)b; i++)
#define int ll
#define pb push_back
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
const int NMAX = 2e5+100;
ll dp[NMAX];
int grau[NMAX], p[NMAX], ans[NMAX], name[NMAX];
vi graph[NMAX];
set<ii> qrs[NMAX];
int n;
bool trde (int v, int oc, ll q = 0){
    if(name[v] < name[oc]) return dp[oc] > dp[v] + q;
    return dp[oc] >= dp[v] + q;
}
ll dfs (int v, int pai){
    int a = 0;
    fin(i,0,graph[v].size()){
        int viz = graph[v][i];
        // cout << viz << endl;
        if(viz!=pai){
            p[viz] = v;
            dp[v] += dfs(viz,v);
            if(!a || trde(a,viz))
                a = viz;
        }
        grau[v]++;
    }
    if(!a)
        a = v;
    name[v] = name[a];
    return dp[v];
}


void lumberjack () {
    queue<int> tp;
    fin(i,1,n+1)
        tp.push(i);
    while(!tp.empty()){
        int v = tp.front(); tp.pop();
        int pai = p[v], oc;
        fin(i,0,graph[pai][i])
            if(graph[pai][i] != v && graph[pai][i] != p[pai])
                oc = graph[pai][i];
        for(ii aux : qrs[v]){
            int q = aux.f, i = aux.s;
            if(trde(v,oc,q))
                ans[i] = name[oc];
            else
                break;
        }
        if (qrs[pai].size() < qrs[v].size())
            swap(qrs[pai],qrs[v]);

        for(ii q : qrs[v])
            qrs[pai].insert(q);
        grau[pai]--;
        if(grau[pai] == 1 && p[pai])
            tp.push(pai);
    }
}

void solve () {
    cin >> n;
    fin(i,1,n+1)
        cin >> dp[i];
    ll a,b;
    fin(i,1,n){
        cin >> a >> b;
        graph[a].pb(n+i);
        graph[b].pb(n+i);
        graph[n+i].pb(a);
        graph[n+i].pb(b);
    }
    fin(i,1,2*n)
        sort(graph[i].begin(), graph[i].end());
    // fin(i,1,2*n){
    //     cout << i << ":";
    //     fin(j,0,graph[i].size())
    //         cout << ' ' << graph[i][j];
    //     cout << endl;
    // }
    fin(i,1,n+1)
        name[i]=i;
    dfs(2*n-1, 0);
    // fin(i,1,2*n){
    //     cout << i << ' ' << name[i] << endl;
    // }
    int q;
    cin >> q;
    qrs[1].insert({0,0}); ans[0] = 1;
    fin(i,1,q+1){
        cin >> a >> b;
        qrs[a].insert({b,i});
        ans[i] = name[a];
    }
    lumberjack();
    fin(i,0,q+1)
        cout << ans[i] << endl;
}

int32_t main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}

/*
4
1 1 1 1
2 3
5 4
1 6
3
1 4
1 1
5 3

6
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
4 6
1 3
5 2
9 8
10 7
3
5 1000000000
2 1000000000
6 1000000000

*/