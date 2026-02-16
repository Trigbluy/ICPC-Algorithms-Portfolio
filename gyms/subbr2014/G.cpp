#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define vi vector<int>
#define pb push_back
#define ii pair<ll,ll>
#define lll pair<ll,ii>
#define f first
#define s second
using namespace std;
const int NMAX = 2e2;
const int INF = numeric_limits<int> :: max();
int n, states;
char grid [NMAX][NMAX];
int  marc [NMAX][NMAX];
int  dx[4] = {1, 0, -1, 0},
     dy[4] = {0, 1, 0, -1};

bool valid(int i, int j) {
    if (!grid[i][j]) return false;
    int ind;
    bool bg;
    if (grid[i][j] < 'Z') {
        ind = grid[i][j] - 'A';
        bg = true;
    }
    else {
        ind = grid[i][j] - 'a';
        bg = false;
    }

    if (((states & (1LL << ind)) > 0) != bg) {
        return true;
    }
    return false;
}

void solve () {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];

    for (int i = 0; i <= n+1; i++) {
        marc[0][i] = 1;
        marc[n+1][i] = 1;
        marc[i][0] = 1;
        marc[i][n+1] = 1;
    }

    int ans = INF;
    for (states = 0; states < (1LL << 10); states++) {
        if (!valid(1,1)) continue;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                marc[i][j] = 0;

        queue<lll> tp;
        tp.push({1,{1,1}});
        while(!tp.empty()) {
            lll p = tp.front(); tp.pop();
            int d = p.f, i = p.s.f, j = p.s.s;

            if (marc[i][j]) continue;
            marc[i][j] = 1;
            if (i == n && j == n) {
                ans = min(ans, d);
                break;
            }

            for (int k = 0; k < 4; k++) {
                int iv = i + dx[k],
                    jv = j + dy[k];
                if (!marc[iv][jv] && valid(iv, jv))
                    tp.push({d+1,{iv,jv}});
            }
        }
    }
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main () {
    fastio;
    solve();
    return 0;
}