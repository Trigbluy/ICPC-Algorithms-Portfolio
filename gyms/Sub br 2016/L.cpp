#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
using namespace std;
const int NMAX = 350;
int tiles[NMAX][NMAX];
int dsu[NMAX*NMAX], sz[NMAX*NMAX];
int pai (int a) {
    while (dsu[a] != dsu[dsu[a]])
        dsu[a] = dsu[dsu[a]];
    return dsu[a];
}
void merge (int a, int b){
    if (pai(a) == pai(b)) return;
    if (sz[pai(a)] > sz[pai(b)])    swap(a,b);
    sz[pai(b)] += sz[pai(a)];
    dsu[pai(a)] = pai(b);
}
void solve () {
    int h, l;
    cin >> h >> l;
    for (int i = 0 ; i < h; i++)
        for (int j = 0; j < l; j++) {
            cin >> tiles[i][j];
            dsu[i*300 + j] = i*300 + j;
            sz [i*300 + j] = 1;
        }

    for (int i = 0 ; i < h; i++)
        for (int j = 0; j < l; j++) {
            int x = i-1, y = j;
            if (0 <= x && x < h && 0 <= y && y < l)
                if (tiles[i][j] == tiles [x][y])
                    merge(i*300 + j, x*300 + y);
            x = i+1, y = j;
            if (0 <= x && x < h && 0 <= y && y < l)
                if (tiles[i][j] == tiles [x][y])
                    merge(i*300 + j, x*300 + y);
            x = i, y = j + 1;
            if (0 <= x && x < h && 0 <= y && y < l)
                if (tiles[i][j] == tiles [x][y])
                    merge(i*300 + j, x*300 + y);
            x = i, y = j - 1;
            if (0 <= x && x < h && 0 <= y && y < l)
                if (tiles[i][j] == tiles [x][y])
                    merge(i*300 + j, x*300 + y);
        }
    int min = 3e5;
    for (int i = 0 ; i < h; i++)
        for (int j = 0; j < l; j++) {
            if (sz[pai(i*300 + j)] < min)
                min = sz[pai(i*300 + j)];
        }
    
    cout << min << endl;
}

int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}