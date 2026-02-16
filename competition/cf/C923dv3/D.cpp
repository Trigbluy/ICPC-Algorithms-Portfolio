#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define endl '\n'
using namespace std;

vector <int> arr;
vector <pair<int,int>> resp;
vector<pair<pair<int,int>, int>> qrs;
vector<pair<int,pair<int,int>>> last_;
map <int, int> last;
multiset <pair<int,pair<int,int>>> seg;
int n,q;

void solve () {

    cin >> n;

    int aux;
    arr.clear();
    last.clear();
    last_.clear();
    arr.pb(-1);
    last_.pb({-1,{-1,-1}});

    for (int i = 1; i <= n; i++) {
        cin >> aux;
        arr.pb(aux);

        if (last[arr[i]] == 0)
            last_.pb({-1,{-1,-1}});
        else 
            last_.pb({ last[arr[i]] , {last[arr[i]], i} });

        last[arr[i]] = i;
    }

    cin >> q;
    int l, r;

    qrs.clear();
    resp.clear();

    for (int i = 0 ; i < q; i++) {
        cin >> l >> r;
        qrs.pb({{l,r},i});
        resp.pb({-1,-1});
    }

    sort(qrs.begin(), qrs.end());
    
    l = 0, r = 0;

    seg.clear();

    for (auto cs : qrs) {
        int la  = cs.first.first;
        int ra  = cs.first.second;
        int ind = cs.second;
        if (r < ra)
            while (r < ra) {
                seg.insert(last_[r+1]);
                r++;
            }
        else
            while (r > ra) {
                seg.erase(last_[r]);
                r--;
            }

        while (l < la) {
            seg.erase(last_[l]);
            l++;
        }

        auto mx = *seg.rbegin();
        if (mx.first >= l) {
            resp[ind] = mx.second;
        }
    }

    for (auto ans : resp)
        cout << ans.first << ' ' << ans.second << endl;
}

int main () {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}