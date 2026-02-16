#include <bits/stdc++.h>
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

int32_t main () {
    int n, x;
    cin >> n >> x;
    int a;
    set<int> vals;
    fin(i,0,n) {
        cin >> a;
        vals.insert(a);
    }
    vii comb[20];
    int ans = 0, ind = 0, g;
    for (int a : vals) {
        if (ind){
            g = __gcd(comb[ind-1][0].s, a);
            comb[ind].pb({-((comb[ind-1][0].f)*g)/a, g}), ans += -(comb[ind-1][0].f*g)/a;
        }
        for (int i = ind - 1; i > 0; i--){
            for(ii b : comb[i-1]){
                g = __gcd(b.s,a);
                comb[i].pb({-b.f/a, g}), ans += -(b.f*g)/a;
            }
        }
        comb[0].pb({x/a,a}), ans += x/a;
        ind++;
    }
    cout << ans << endl;
    return 0;
}