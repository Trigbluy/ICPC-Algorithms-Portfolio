#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void solve () {
    int saque = 0; // left 0, right 1
    bool ended = false;
    char a;
    int pontos [2] = {0,0}, jogos [2] = {0,0};
    while (cin >> a) {
        switch (a)
        {
        case 'S':
            pontos[saque]++;
            break;
        
        case 'R':
            pontos[!saque]++;
            saque = !saque;
            break;
        case 'Q':
            if (ended) {
                cout << jogos[0] << " ";
                if (!saque) cout << "(winner)";
                cout << " - " << jogos[1];
                if (saque) cout << " (winner)";
                cout << '\n';
                break;
            }
            cout << jogos[0] << " (" << pontos[0];
            if (!saque)
                cout << '*';
            cout << ") - " << jogos[1] << " (" << pontos[1];
            if (saque)
                cout << '*';
            cout << ")\n";
        };

        int a = 0, b = 1;
        for (int i = 0; i < 2; i++) {
            if (pontos[a] == 10 || (pontos[a] >= 5 && pontos[a] >= pontos[b] + 2)) {
                jogos[a]++;
                if (jogos[a] == 2) ended = true;
                pontos[a] = pontos[b] = 0;
            }
            a = 1, b = 0;
        }
        
    }
}
int main () {
    fastio;
    solve();
    return 0;
}