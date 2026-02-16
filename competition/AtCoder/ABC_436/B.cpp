#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < b; i++)
#define f first
#define s second
#define endl '\n'
#define int ll
const signed NMAX = 3*10e2;
const signed M = 998244353;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<int,int> mp;

int grid[NMAX][NMAX];
void solve(){
    int n;
    cin >> n;
    int r, c, k;
    r = 0, c = (n-1)/2, k = 1;
    fin(i,0,n*n){
        grid[r][c] = k;
        k++;
        if (!grid[(r-1+n)%n][(c+1+n)%n]){
            r = (r-1+n)%n;
            c = (c+1)%n;
        }
        else {
            r = (r+1)%n;
        }
    }

    fin(i,0,n){
        cout << grid[i][0];
        fin(j,1,n)
            cout << ' ' << grid[i][j];
        cout << endl;
    }
}

signed main (){
    fastio;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}