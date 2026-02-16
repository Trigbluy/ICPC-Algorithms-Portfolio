#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define pb push_back
#define vi vector <int>
#define ii pair <int, int>
#define vii vector<ii>
#define ff first
#define ss second
using namespace std;
const int NMAX = 400;
map<string, int> cd;
map<int,string> encd;
ii better[NMAX];
string resp [NMAX];
vii opt [NMAX];
void solve () {
    int n, r, m, w;
    string aux;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> aux;
        cd[aux] = i;
        encd[i] = aux;

        better[i] = {0,0};
    }
    cin >> r;
    while (r--){
        cin >> m >> w;
        while(m--){
            cin >> aux;
            int el = cd[aux];
            if (better[el].ss < w) {
                better[el] = {1,w};
            } else if (better[el].ss == w) {
                better[el].ff++;
            }
        }
    }

    for (int i = 1; i <= n ; i++) {
        opt[better[i].ss].pb({better[i].ff,i});
    }

    for (int j = n-1; j >= 1; j--) {
        if (opt[j].empty()) continue;
        sort (opt[j].begin(), opt[j].end());
        int ind = j, qnt = opt[j].size();
        while(qnt--) {
            if (resp[ind] == resp[0]) {
                resp[ind] = encd[opt[j].rbegin()->ss];
                opt[j].pop_back();
            }
            else {
                qnt++;
            }
            ind++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (resp[i] == resp[0]) {
            resp[i] = encd[opt[0].rbegin()->ss];
            opt[0].pop_back();
        }
    }

    cout << resp[1];
    for (int i = 2; i <= n; i++)
        cout << ' ' << resp[i];
    cout << '\n';
}

int main () {
    fastio;
    solve();
    return 0;
}