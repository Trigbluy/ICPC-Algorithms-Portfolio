#include <bits/stdc++.h>
#define maxn 1001
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define f first
#define s second

using namespace std;

typedef pair<int,int> ii;
typedef long long int ll;
stack <ii> s;
int tams[maxn][maxn];

int main(){
    fastio;
    int n, m, i, j;
    ll resp=0;
    char c, lc;
    ii nex;
    cin >> n >> m;
    for(i=0;i<n;i++){
        lc = 'A';
        for(j=0;j<m;j++){
            cin >> c;
            if(c==lc) tams[i][j] = tams[i][j-1]+1;
            else tams[i][j] = 1;
            lc = c;
        }
    }
    for(j=0;j<m;j++){
        for(i=0;i<n;i++){
            if(!s.empty()) nex = s.top();
            while(!s.empty() && nex.f>tams[i][j]){
                resp = max(resp, (ll)min(nex.f, i-nex.s));
                s.pop();
                if(!s.empty()) nex = s.top();   
            }
            if(s.empty() || nex.f<tams[i][j]) s.push({tams[i][j], i});
        }
        while(!s.empty()){
            nex = s.top();
            resp = max(resp, (ll)min(nex.f, n-nex.s));
            s.pop();
        }
    }
    resp = resp*resp;
    cout << resp << endl;
    return (0);
}