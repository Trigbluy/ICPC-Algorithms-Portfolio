#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fin(a,b,c) for(int a = b, a < c; a++)
#define pb push_back
#define f first
#define s second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve () {
    int n, ans = 1;
    char att, ant, frst;
    bool can_grow = false;
    cin >> n;
    cin >> frst;
    ant = att = frst;
    while (--n){
        cin >> att;
        if (att != ant){
            ans++;
            ant = att;
        }
        else
            can_grow = true;
    }
    if (frst != att && can_grow)
        ans++;
    cout << ans << endl;
}

int main () {
    fastio;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}