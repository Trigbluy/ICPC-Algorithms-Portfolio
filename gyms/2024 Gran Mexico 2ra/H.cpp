#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<int>
#define pb push_back
typedef long long ll;
using namespace std;
const int NMAX = 2e4;
int seg[4*NMAX];
int n;

int build (int l, int r, int v) {
    if (l == r)
        return seg[v] = 1;
    int m = (l + r)/2;
    return seg[v] = build(l,m, 2*v) + build (m+1,r,2*v+1);
}
void build () {
    build (1,n, 1);
}
void update (int l, int r, int node, int v, int x) {
    if (l == r){
        if(l == node)
            seg[v] += x;
        return;
    }

    int m = (l+r)/2;
    if (node <= m)
        update(l, m, node, 2*v, x);
    if (node > m)
        update (m+1, r, node, 2*v+1, x);
    seg[v] = seg[2*v] + seg[2*v+1];  
}
void rem (int node) {
    // cout << "Removing " << node << endl;
    update(1,n,node,1, -1);
}
int check (int l, int r, int l1, int r1, int v) {
    // cout << "Checking " << l1 << ' ' << r1 <<' ' << v <<endl;
    if (r < l1 || r1 < l)
        return 0;
    if (l1 <= l && r <= r1)
        return seg[v];
    int m = (l+r)/2;
    int ans = 0;
    ans += check(l, m, l1, r1, 2*v);
    ans += check(m+1,r,l1, r1, 2*v+1);
    return ans;
}
int val (int l, int r) {
    int ans;
    if (r <= n)
        ans = check(1, n, l, r, 1);
    else
        ans = check (1,n, l, n, 1) + check (1,n, 1, r - n, 1);
    // cout << l << " " << r << "->" << ans << endl;
    return ans;
}
int bb (int a, int att) {
    // cout << "bb " << a << ' ' << att << endl;
    int l = att + 1, r = att + n - 1, m;
    while (l < r) {
        m = (l + r)/2;
        // cout << l << " " << r << " -> " << m << endl;
        // cout << val (att + 1, m) << endl;
        if (val(att + 1, m) < a)
            l = m + 1;
        else
            r = m;
    }
    return l;
}
vi hireds;
void solve() {
    int r, c;
    cin >> n >> r >> c;
    build();

    int na = n, s1 = 1, s2 = n;
    r--, c--;
    while (na > 2) {
        
        // cout << "From "<< s1 << ' ' << s2 << endl;
        if (r%na)
            s1 = bb(r%na, s1);
        if ((na - c%na) % na)
            s2 = bb((na - c%na) % na, s2);
        if (s1 < 1) s1+=n;
        if (s2 < 1) s2+=n;
        if (s1 > n) s1-=n;
        if (s2 > n) s2-=n;
        // cout << "To " <<  s1 << ' ' << s2 << endl;
        if (s1 == s2) {
            hireds.pb(s1);
            rem(s1), na--;
        }
        else 
            rem(s1), rem(s2), na -= 2;
        s1 = bb(1, s1);
        s2 = bb(na, s2);
        if (s1 < 1) s1+=n;
        if (s2 < 1) s2+=n;
        if (s1 > n) s1-=n;
        if (s2 > n) s2-=n;
    }
    for (int i = 1; i <= n; i++)
        if (val(i,i))
            hireds.pb(i);
    sort(hireds.begin(), hireds.end());
    cout << hireds[0];
    for (int i = 1; i < hireds.size(); i++)
        cout << ' ' << hireds[i];
    cout << endl;
}
int main () {
    fastio;
    int nt = 1;
    // cin >> nt;
    while(nt--)
        solve();
    return 0;
}