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
const int NMAX = 1e6 + 100;
const ll M = 1e9+7;
map<int,int> graph[NMAX];
map<int,int> color;
int cnt;
void solve () {
    int n, m, q;
    cin >> n >> m >> q;
    int a;
    vi arr;
    fin(i,0,n){
        cin >> a;
        arr.pb(a);
        if (color.find(a) == color.end())
            color[a] = ++cnt;
    }
    fin(i,0,n-1){
        if (arr[i] != arr[i+1]){
            graph[color[arr[i]]][color[arr[i+1]]]++;
            graph[color[arr[i+1]]][color[arr[i]]]++;
        }
    }
    int inv = 0;
    fin (i,0,n-1)
        if(arr[i+1] < arr[i])
            inv++;
    while(q--){
        int i;
        cin >> i;
        if (color.find(i) != color.end()){
            cout << "---" << endl;
            inv += graph[color[i]][i+1];
            inv -= graph[color[i+1]][i];
            swap(color[i],color[i+1]);
        }
        cout << inv << endl;
    }
}
int32_t main () {
    // fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}