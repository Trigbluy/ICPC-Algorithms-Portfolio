#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int> 
#define vi vector<int>
#define endl '\n'
using namespace std;
const int NMAX = 5e2 + 20;
int tiles [NMAX][NMAX];
int precol[NMAX][NMAX][3];
int prelin[NMAX][NMAX][3];

void solve () {
    int n, p, a, b;
    cin >> n >> p;
    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        tiles[a][b] = 1;
    }
    for (int i = 0; i < p; i++) {
        cin >> a >> b;
        tiles[a][b] = 2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            precol[i][j][1] = precol[i][j-1][1] + (tiles[j][i] == 1);
            precol[i][j][2] = precol[i][j-1][2] + (tiles[j][i] == 2);
            
            prelin[i][j][1] = prelin[i][j-1][1] + (tiles[i][j] == 1);
            prelin[i][j][2] = prelin[i][j-1][2] + (tiles[i][j] == 2);
        }
    }
    // cout << "Tiles :" << endl;
    // for (int x = 1; x <= n; x++) {
    //     for (int y = 1; y <= n; y++)
    //         cout << tiles[x][y] << ' ';
    //     cout << endl;
    // }
    int ans[3] = {0,0,0};
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++){
            int color = 0;
            for (int sz = 0; sz + max(x,y) <= n; sz++) {
                // bool okay = true;
                // for (int i = 0; i <= sz; i++) {
                //     if (tiles[x+i][y+sz] != color) {
                //         if (color == 0)
                //             color = tiles[x+i][y+sz];
                //         else if (tiles[x+i][y+sz]){
                //             okay = false;
                //             // cout << "False in " << sz << ' ' << i << endl;
                //             break;
                //         }
                //     }
                // }
                
                // if (!okay) break;
                // for (int j = 0; j <= sz; j++) {
                //     if (tiles[x+sz][y+j] != color) {
                //         if (color == 0)
                //             color = tiles[x+sz][y+j];
                //         else if (tiles[x+sz][y+j]){
                //             okay = false;
                //             // cout << "False jn " << sz << ' ' << j << endl;
                //             break;
                //         }
                //     }
                // }
                // if (!okay) break;
                // cout << "Adding to " << color << " in " << x << ',' << y << " with sz = " << sz << endl;
                int nb =    prelin[x+sz][y+sz][1] - prelin[x+sz][y-1][1] +
                            precol[y+sz][x+sz][1] - precol[y+sz][x-1][1];
                            
                int nw =    prelin[x+sz][y+sz][2] - prelin[x+sz][y-1][2] +
                            precol[y+sz][x+sz][2] - precol[y+sz][x-1][2];
                if (!color) {
                    if (nb && !nw)
                        color = 1;
                    else if (!nb && nw)
                        color = 2;
                    else if (nb && nw)
                        break;
                }
                else {
                    if (color == 1 && nw)
                        break;
                    else if (color == 2 && nb)
                        break;
                }
                ans[color]++;
            }
        }
    cout << ans[1] << ' ' << ans[2] << endl; 
}

int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}