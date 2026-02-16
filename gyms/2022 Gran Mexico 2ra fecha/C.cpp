#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long double ld;
#define ii pair<int,int>
#define f first
#define s second
#define pb push_back
#define LSOne(S) ((S)&-(S))
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
using namespace std;

class FenwickTree {
public:
    vll ft;
    FenwickTree(int m) {ft.assign(m+1,0);}

    ll rsq (int j) {
        ll sum = 0;
        for(;j;j-=LSOne(j))
            sum += ft[j];
        return sum;
    }
    ll rsq (int i, int j) {return rsq(j) - rsq(i-1);}

    void update (int i, ll v) { //ll
        for(;i < (int) ft.size(); i += LSOne(i))
            ft[i] += v;
    }

};

class RUPQ {
    private:
        FenwickTree ft;
    public:
        RUPQ(int m) : ft(FenwickTree(m)) {}
        void range_update(int ui, int uj, ll v) { //ll
            ft.update(ui, v);
            ft.update(uj+1, -v);
        }
        ll point_query(int i) {return ft.rsq(i);}
};

class RURQ {
    private:
        RUPQ rupq;
        FenwickTree purq;
    public:
        RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)){}
        void range_update (int ui, int uj, ll v) { //ll
            rupq.range_update(ui,uj,v);
            purq.update(ui,v*(ui-1));
            purq.update(uj+1,-v*uj);
        }

        ll rsq(int j){
            return rupq.point_query(j)*j - purq.rsq(j);
        }
        ll rsq(int i, int j) {return rsq(j) - rsq(i-1);}

        int select (ll k) {
            int lo = 1, hi = purq.ft.size()-1;
            for(int i = 0; i < 30; i++){
                int mid = (lo+hi)/2;
                (rsq(1,mid) < k) ? lo = mid : hi = mid;
            }
            return hi;
        }
};

void solve () {
    int n, q;
    cin >> n >> q;
    vll arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    RURQ fw(n);
    while (q--) {
        vector <pair<ii, int>> upts;
        int k;
        cin >> k;
        int l, r, x;
        while(k--) {
            cin >> l >> r >> x;
            upts.pb({{l,r},x});
            fw.range_update(l,r,x);
        }
        // cout << "Saiu do While" << endl;
        int sz = fw.rsq(1,n);
        // cout << "Fez o rsq" << sz << endl;
        if (sz%2) {
            int j = fw.select(sz/2 + 1) - 1;
            cout << arr[j] << endl;
        }
        else {
            int j1 = fw.select(sz/2) - 1;
            int j2 = fw.select(sz/2 + 1) - 1;

            ld aux = arr[j1] + arr[j2]  ;
            cout << aux/2 << endl;
        }
        for (auto p : upts) {
            l = p.f.f;
            r = p.f.s;
            x = p.s;
            fw.range_update(l,r,-x);
        }
        upts.clear();
    }
}
int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}