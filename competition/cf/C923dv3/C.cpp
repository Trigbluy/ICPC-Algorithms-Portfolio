#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
using namespace std;
set<int> s1, s2;

void solve () {
    int n,m,k;
    cin >> n >> m >> k;
    s1.clear();
    s2.clear();

    int aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        s1.insert(aux);
    }
    for (int i = 0; i < m; i++) {
        cin >> aux;
        s2.insert(aux);
    }

    int only1 = 0, only2 = 0, bth12 = 0;
    bool poss = true;
    for (int i = 1; i <= k; i++) {
        if (s1.find(i) != s1.end()) {
            if (s2.find(i) != s2.end()) {
                bth12++;
            }
            else {
                only1++;
            }
        }
        else if (s2.find(i) != s2.end()) {
            only2++;
        }
        else {
            poss = false;
            break;
        }
    }

    if (poss) {
        if (only1 <= k/2 && only2 <= k/2) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    else
        cout << "NO\n";
}

int main () {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}