#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
typedef long long ll;
#define maxn 10006
#define primo 10037
#define f first
#define s second
using namespace std;

typedef pair<int,int> ii;
typedef pair<ll,pair<ll,ll>> lliii;
typedef vector<lliii> vii;
ll p[maxn][3], mod[3], has[maxn][3];
int grau[maxn];
ii edge[maxn];
vii v[2];

int main () {
    fastio;
    int n, i, a, b, j, flag;
    p[0][0] = p[0][1] = p[0][2] = 1;
    mod[0] = 1e9+7;
    mod[1] = 1e9+9;
    mod[2] = 37;
    for(i=1;i<maxn;i++){
        for(j=0;j<3;j++){
            p[i][j] = (p[i-1][j]*primo)%mod[j];
        }
    }
    while (cin >> n) {
        for(i=0;i<n-1;i++){
            cin >> a >> b;
            grau[a]++;
            grau[b]++;
            edge[i] = {a, b};
        }
        for(i=0;i<n-1;i++){
            for(j=0;j<3;j++){
                has[edge[i].f][j] += p[grau[edge[i].s]][j];
                has[edge[i].f][j] %= mod[j];
                has[edge[i].s][j] += p[grau[edge[i].f]][j];
                has[edge[i].s][j] %= mod[j];
            }
        }
        for(i=1;i<=n;i++){
            v[0].pb({has[i][0], {has[i][1], has[i][2]}});
        }
        sort(v[0].begin(), v[0].end());
        for(i=1;i<=n;i++){
            for(j=0;j<3;j++){
                has[i][j] = 0;
                grau[i]=0;
            }
        }
        for(i=0;i<n-1;i++){
            cin >> a >> b;
            grau[a]++;
            grau[b]++;
            edge[i] = {a, b};
        }
        for(i=0;i<n-1;i++){
            for(j=0;j<3;j++){
                has[edge[i].f][j] += p[grau[edge[i].s]][j];
                has[edge[i].f][j] %= mod[j];
                has[edge[i].s][j] += p[grau[edge[i].f]][j];
                has[edge[i].s][j] %= mod[j];
            }
        }
        for(i=1;i<=n;i++){
            v[1].pb({has[i][0], {has[i][1], has[i][2]}});
        }
        sort(v[1].begin(), v[1].end());
        flag=0;
        for(i=0;i<n;i++){
            if(v[0][i]!=v[1][i]){
                flag=1;
                break;
            }
        }
        if(flag) cout << "N" << endl;
        else cout << "S" << endl;
        for(i=1;i<=n;i++){
            for(j=0;j<3;j++){
                has[i][j] = 0;
                grau[i]=0;
            }
        }
        v[0].clear();
        v[1].clear();
    }
    return 0;
}