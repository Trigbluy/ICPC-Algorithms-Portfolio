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

void solve(){
    int n;
    string s;
    cin >> n >> s;
    fin(i,0,n-s.size())
        cout << 'o';
    cout << s << endl;
}

signed main (){
    fastio;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}