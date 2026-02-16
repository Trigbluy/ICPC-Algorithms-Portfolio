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
ll pal (ll a, ll la, ll na, ll base_a) {
    ll ans = 0;
    ans += ((na + (1LL << base_a)) << (la-base_a-1));
    ans++;
    if (la%2) base_a >>= 1;
    fin(i,0,base_a)
        if((1LL << i)&na)
            ans += (1LL << (base_a-i));
    return ans;
}
void solve () {
    int q;
    cin >> q;
    while (q--){
        ll a, b, ans = 0;
        cin >> a >> b;
        ll la = 0, lb = 0;
        while ((1LL << la) <= a) la++;
        while ((1LL << lb) <= b) lb++;
        cout << la<< ' ' << lb << endl;
        fin(i,la+1,lb) ans += (1LL << (i-1)/2);

        ll base_a = (la-1)/2;
        ll base_b = (lb-1)/2;
        ll na = (a >> (la-base_a-1)) % (1LL << base_a);
        ll nb = (b >> (lb-base_b-1)) % (1LL << base_b);
        cout << base_a << ". " << na <<endl;
        cout << base_b << ". " << nb <<endl;
        ans += (1LL << base_a) - na;
        ans += nb;
        if (a==b){
            cout << (int) (pal(a,la,na,base_a) == a) << endl;
            continue;
        }
        
        if (la == lb) ans -= (1LL << (la-1)/2);
        ans += pal(a,la,na,base_a) >= a;
        ans += pal(b,lb,nb,base_b) <= b;
        cout << ans << endl;
    }
}
int32_t main () {
    // fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}