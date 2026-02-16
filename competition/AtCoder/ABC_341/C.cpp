#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ff first
#define ss second
using namespace std;

const int NMAX = 5e2 + 10;

int grid [NMAX][NMAX];
int moves [NMAX];
int h, w, n;

bool poss (int i, int j) {
    pair<int,int> mvs [] = {{0, -1}, {0, +1}, {-1, 0}, {+1, 0}};

    for (int p = 0; p < n; p++){
        auto mv = mvs[moves[p]];
        int x = i + mv.ff;
        int y = j + mv.ss;

        if(!grid[x][y])
            return false;
        i = x,  j = y;
    }
    return true;
}

void solve () {
    cin >> h >> w >> n;
    char aux;
    for (int i = 0; i < n; i++){
        cin >> aux;
        switch (aux)
        {
        case 'L':
            moves[i] = 0;
            break;
        case 'R':
            moves[i] = 1;
            break;
        case 'U':
            moves[i] = 2;
            break;
        case 'D':
            moves[i] = 3;
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> aux;
            grid[i][j] = (aux == '.');
        }
    }
    
    int ans = 0;
    for (int i = 1; i < h - 1; i++)
        for (int j = 1; j < w - 1; j++)
            if (grid[i][j] && poss(i,j))
                ans++;
    
    cout << ans << endl;
}

signed main () {
    fastio;
    int n_c = 1;
    while (n_c--) {
        solve();
    }
    return 0;
}