#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < b; i++)
#define f first
#define s second
#define endl '\n'
const int NMAX = 3*10e5+1;
typedef vector<int> vi;
typedef pair<int,int> ii;

void solve(){
    int n;
    cin >> n;
    char a;
    int n0l = 0, n0r = 0, mx_dist = 0, dist = -n;
    bool has1 = false;
    while(n--){
        cin >> a;
        if(a == '1') {
            mx_dist = max(mx_dist, dist);
            dist = 0;
            n0r = 0;
            has1 = true;
        } else {
            if (has1) {
                dist++;
                n0r++;
            }
            else
                n0l++;
        }
    }

    cout << max(n0l + n0r, mx_dist) << endl;
}
signed main (){
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}