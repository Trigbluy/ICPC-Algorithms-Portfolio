#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(), cout.tie()
#define frm(i,a,b) for (int i = a; i < b; i++)
#define frl(i,a,b) for (int i = a; i > b; i--)
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define f first
#define s second
using namespace std;
const int NMAX = 1e6+10;
const int T = 100;
int n, q, l, r;
vi arr;
map<int, int> freq;
multiset<int> st;

bool comp (pair<int,ii> a, pair<int,ii> b) {
    if (a.s.f/T != b.s.f/T) return a.s.f/T < b.s.f/T;
    if (a.s.s != b.s.s) return a.s.s < b.s.s;
    if (a.s.f != b.s.f) return a.s.f < b.s.f;
    return a.f < b.f;
}

bool gr (int a, int b) {
    return a > b;
}

void add (int a) {
    a = arr[a];
    // cout << "Add " << a << endl;
    auto lw = lower_bound(st.rbegin(), st.rend(), a, gr);
    auto up = upper_bound(st.begin(), st.end(), a);

    if (lw != st.rend()) {
        freq[a - *lw]++;
        // cout << "Lower: "<< *lw << endl;
    }
    if (up != st.end()) {
        freq[*up - a]++;
        // cout << "Upper: " << *up << endl;
    }
    if ((lw != st.rend()) && (up != st.end())) {
        if (freq[*up - *lw]-- == 1) {
            freq.erase(*up - *lw);
        }
    }

    st.insert(a);
}

void rem (int a) {
    a = arr[a];
    // cout << "Remove " << a << endl;
    st.erase(lower_bound(st.begin(), st.end(), a));

    auto lw = lower_bound(st.rbegin(), st.rend(), a, gr);
    auto up = upper_bound(st.begin(), st.end(), a);

    if (lw != st.rend()){
        // cout << "Lower: " << *lw << endl;
        if (freq[a - *lw]-- == 1 )
            freq.erase(a - *lw);
    }
    if (up != st.end()) {
        if (freq[*up - a]-- == 1)
            freq.erase(*up - a);
        // cout << "Upper: " << *up << endl;
    }
    if ((lw != st.rend()) && (up != st.end())) {
        freq[*up - *lw]++;
    }
}

void solve () {
    cin >> n;
    arr.pb(0);
    frm(i,0,n) {
        cin >> l;
        arr.pb(l);
    }
    cin >> q;
    vector<pair<int,ii>> queries;
    vi ans(q);
    frm(i,0,q){
        cin >> l >> r;
        queries.pb({i,{l,r}});
    }
    sort(queries.begin(), queries.end(), comp);
    l = 0, r = 0;
    frm(i,0,q) {
        int qr = queries[i].f;
        int lq = queries[i].s.f - 1;
        int rq = queries[i].s.s;

        while(r < rq)
            add(++r);
        while(r > rq)
            rem(r--);

        while(l > lq)
            add(l--);
        while(l < lq)
            rem(++l);
        
        ans[qr] = freq.begin()->f;
    }

    frm(i,0,q)
        cout << ans[i] << endl;
}
int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}