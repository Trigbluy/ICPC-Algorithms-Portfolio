#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0),cout.tie(0)
#define ll long long
#define int ll
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector <ii>
#define ff first
#define ss second
#define endl '\n'
using namespace std;

struct monster {
    int life, pos;
    bool operator <(monster& a) {
        int posa = labs(a.pos);
        int posme = labs(pos);
        if (posa < posme)
            return 0;
        if (posme < posa)
            return 1;
        if (posa > 0)
            return 1;
        return 0;
    };
};

void solve () {
    int n, k;
    cin >> n >> k;
    vector<monster> line;
    vi prefix;
    int a, x;
    for (int i = 0; i < n; i++) {
        cin >> a;
        line.pb({a,0});
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        line[i].pos = x;
    }

    sort(line.begin(), line.end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += line[i].life;
        if (sum > k*labs(line[i].pos)) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int32_t main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while (nt--)
        solve();
    return 0;
}