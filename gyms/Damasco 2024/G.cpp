#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define f first
#define s second
#define pb push_back
#define MAXN 200010
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;

 
struct seg{
    int size;
    vector<vector<pair<int, ii>>> values;

    vector<pair<int, ii>> neutro(){
        vector<pair<int, ii>> a(26, {0, {1000001, 0}});
        return a; 
    }

    void init(int N){
        size = 3e6+5e5;
        values.assign(size, neutro());
    }

    vector<pair<int, ii>> single(int v, int pos){
        vector<pair<int, ii>> a(26, {0, {1000001, 0}});
        a[v].f = 1;
        a[v].s = {pos, pos};
        return a;
    }

    pair<int,vector<pair<int, ii>>> merge(vector<pair<int, ii>> a, vector<pair<int, ii>> b){
        pair<int,vector<pair<int, ii>>> c = {0, neutro()};
        rep(i,0,25){
            c.f += ((c.s[i].f = a[i].f + b[i].f) > 0);
            c.s[i].s.f = min(a[i].s.f, b[i].s.f);
            c.s[i].s.s = max(a[i].s.s, b[i].s.s);
        } 
        return c;
    }

    void build(string &t, int x, int lx, int rx){
        //cout << x << " " << lx << " " << rx << endl;
        if(rx - lx == 0){
            values[x] = single(t[lx] - 'a', lx);
            return;
        }
        int m = (lx + rx)/2;
        build(t, 2*x+1, lx, m);
        if(m+1 <= rx)
            build(t, 2*x+2, m+1, rx);
        auto aux = merge(values[2*x+1], values[2*x+2]);
        values[x] = aux.s;
        //cout << "return" << endl;       
    }

    vector<pair<int, ii>> query(int l, int r, int x, int lx, int rx){
        if(lx > r || rx < l) return neutro();
        if(lx >= l && rx <= r) return values[x];
        int m = (lx + rx)/2;
        vector<pair<int, ii>> s1 = query(l,r,2*x+1,lx,m);
        vector<pair<int, ii>> s2 = query(l,r,2*x+2,m+1,rx);
        return merge(s1, s2).s;
    }

    int freq(int l, int r){
        vector<pair<int, ii>> s = query(l,r,0,0,n-1);
        int ans = 0;
        for(int i = 0 ; i < 26; i++)
            ans += (s[i].f > 0);
        return ans;
    }

    int bb (int val, int lx, int rx) {
        int l = lx, r = rx, m;
        while(l<r){
            m = (l+r+1)/2;
            if(freq(lx,m) < val) l = m+1;
            else r = m - 1;
        }
        if(freq(lx,l) < val) l++;
        return l;
    }
    void print(int x, int lx, int rx){
        cout << x << " " << lx << " " << rx << endl;
        for(int i = 0; i < 3; i++){
            cout << values[x][i].f << " " << values[x][i].s.f << " " <<  values[x][i].s.s << " | ";
        }
        cout << endl;
        int m = (lx+rx)/2;
        if(lx == rx) return;
        if(lx <= m)
            print(2*x+1, lx, m);
        if(m+1 <= rx)
            print(2*x+2, m+1, rx);

    }
};
 
void solve() {
    string str, ans;
    cin >> str;
    ans = str;
    n = str.size();
    seg st;
    st.init(n);
    st.build(str, 0, 0, n-1);
    int j = 0;
    for (int i = 0; i < n; i++){
        int ff = st.freq(j,n-1);
        // cout << i << ' ' << ff << endl;
        if(ff == str[i]-'a'+1) continue;
        if(ff < str[i] -'a' + 1){
            j = i+1;
            continue;
        }
        int ind = st.bb(ff, i, n-1) + 1;
        // cout << ind << endl;
        while(ind < n && str[ind] <= ff + 'a' - 1) ind++;
        for (int z = j; z < ind; z++) ans[z] = ff + 'a' - 1;
        i = ind - 1;
        j = i+1;
    }
    cout << ans << endl;
}
 /*
 abababzciu
 */
 
int main() {
    _
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
}