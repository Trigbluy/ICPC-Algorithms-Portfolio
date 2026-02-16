#include <bits/stdc++.h>
using namespace std;
int grid [12][12];
int num1c[12];
void solve () {
    int n;

    cin >> n;
    char a;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> a;
            grid [i][j] = a == '1';
        }
    
    for (int i = 0; i < n; i++) {
        num1c[i] = 0;
        for (int j = 0; j < n; j++)
            num1c[i] += grid[j][i];
    }

    int aux = -1, sc = 0;
    for (int i = 0; i < n; i++) {
        if (num1c[i] != 0) {
            if (aux == -1)
                aux = num1c[i];
            else if (num1c[i] == aux) {
                sc = 1;
                break;
            } else {
                sc = 0;
                break;
            }
        }
    }

    if (sc)
        cout << "SQUARE" << endl;
    else
        cout << "TRIANGLE" << endl;
}
int main () {
    int t = 1;
    cin >> t;
    while (t--)
        solve ();
    return 0;
}