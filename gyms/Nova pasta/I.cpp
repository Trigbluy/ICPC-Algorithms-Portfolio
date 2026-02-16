#include <bits/stdc++.h>
#define maxn 2003
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define f first
#define s second
#define mod 1000000007

using namespace std;

typedef vector <int> vi;
vi g[maxn];
int dp[maxn], vis[maxn], l, qnt=0;

void dfs(int u){
    vis[u] = 1;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]<l){
            if(!vis[g[u][i]]) dfs(g[u][i]);
            dp[u] = (dp[u]+dp[g[u][i]])%mod;
        }
        else{
            if(!vis[g[u][i]]){
                vis[g[u][i]] = 1;
                qnt++;
            }
            dp[u] = (dp[u]+1)%mod;
        }
    }
}

int main(){
    fastio;
    int n, i, j, k, a;
    cin >> n >> l;
    for(i=0;i<l;i++){
        cin >> k;
        for(j=0;j<k;j++){
            cin >> a;a--;
            g[i].push_back(a);
        }
    }
    dfs(0);
    cout << dp[0] << " " << qnt << endl;
    return (0);
}