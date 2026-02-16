#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
using namespace std;
map <string, int> poss, att;

void solve () {
    string t, aux, str;
    int n, a, cost = 0;
    cin >> t >> n;
    poss[""] = 0;
    for (int i = 0; i < n; i++){
        cin >> a;
        att = poss;
        for (int j = 0 ; j < a; j++){
            cin >> aux;
            for (auto p : att){
                if (poss[p.ff + aux] != 0) {
                    poss[p.ff + aux] = p.ss + 1;
                }
            }
        }
    }

    if (poss[t])
        cout << poss[t] << endl;
    else
        cout << -1 << endl;
    
}

int main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}