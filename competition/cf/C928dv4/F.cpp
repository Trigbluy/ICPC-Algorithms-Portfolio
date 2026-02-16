#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ff first
#define ss second
using namespace std;
int grid[7][7];

int minimo (int a, int b) {
    if (a == -1 && b != -1)
        return b + 1;
    if (b == -1)
        return a;
    return min(a,b + 1);
}

bool has_problem_in (int i, int j) {
    if (grid[i][j] == 0) return false;
    // if (i <= 0 || i >= 6 || j <= 0 || j >= 6) return false;

    if (grid[i+1][j+1] == 1 && grid[i-1][j-1] == 1 &&
        grid[i-1][j+1] == 1 && grid[i+1][j-1] == 1)
        return true;
    return false;
}

int has_problem () {
    for (int i = 1; i < 6; i++)
        for (int j = 1; j < 6; j++)
            if (has_problem_in(i,j))
                return -1;
    return 0;
}

pair<int,int> pos (int i) {
    i += 9;
    if (i == 12)  i++;
    if (i == 36)  i++;
    if (i%7 >= 6) i+=2;
    return {i/7, i%7};
}

int btf (int casa) {
    if (casa == 22)
        return has_problem();
    auto p = pos(casa);
    int x = p.ff;
    int y = p.ss;

    if (grid[x][y] == 0)
        return btf(casa + 1);
    
    int a = btf(casa + 1);

    grid[x][y] = 0;
    int b = btf(casa + 1);
    grid[x][y] = 1;

    return minimo(a,b);
}

void solve () {
    char aux;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> aux;
            grid[i][j] = (aux == 'B');
        }
    }

    cout << btf(0) << endl;
}

int main () {
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}