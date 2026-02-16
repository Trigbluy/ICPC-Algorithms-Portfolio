#include <bits/stdc++.h>
typedef long double ld;
typedef long long ll;
#define ii pair<int,int>
#define pb push_back
#define f first
#define s second
using namespace std;
const int NMAX = 3e5;
int pai[NMAX], sz[NMAX];
vector <pair<int, ii>> arestas;
int dad (int a) {
    while (pai[a] != pai[pai[a]])
        pai [a] = pai[pai[a]];
    return pai[a] = pai[pai[a]];
}
void merge (int a, int b) {
    if (dad(a) == dad(b)) return;
    if (sz[dad(a)] > sz[dad(b)])    swap(a,b);
    sz[dad(b)] += sz[dad(a)];
    pai[dad(a)] = dad(b);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    int a,b,c;
    for (int i = 0; i <= n; i++) {
        pai[i] = i;
        sz [i] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        arestas.pb({c,{a,b}});
    }
    sort(arestas.begin(), arestas.end());
    for (auto ar : arestas) {
        a = ar.s.f;
        b = ar.s.s;
        c = ar.f;

        merge(a,b);
        if (sz[dad(1)] >= k) {
            cout << c << endl;
            return 0;
        }
    }
    return 0;
}