#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define endl '\n'
const int NMAX = 2e5 + 10;

using namespace std;

vector<int> graph[NMAX], arestas[NMAX];

int n, m, tmr, p, c;
int marc[NMAX], marca[NMAX], pre[NMAX], low[NMAX], pilha[NMAX], distarest[NMAX], artp[NMAX], compArest[NMAX],
    mnare[NMAX], szComp[NMAX];

pair <int, int> Pontos[NMAX];

queue <int> to_print;

void newBiComp (int idArest){
    c++;
    int a;
    mnare[c] = numeric_limits<int> :: max();
    do {
        if (p == -1)    break;
        szComp[c]++;
        a = pilha[p--];
        compArest[a] = c;
        if (mnare[c] > distarest[a]) mnare[c] = distarest[a];
    } while (a != idArest);
}

void dfs (int v, int pai, int o) {
    // cout << "Dfs in " << v << " from " << pai << endl;
    marc[v] = 1;
    low [v] = pre [v] = ++tmr;
    int qntf = 0;
    for (int i = 0; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        int idArest = arestas[v][i];

        if (marca[idArest] == 1) continue;
        marca[idArest] = 1;
        pilha[++p] = idArest;

        if (marc[viz] == 0) {
            qntf++;
            dfs (viz, v, o);
            low[v] = min(low[v], low[viz]);

            bool newcmp = false;
            if (v == o && qntf >= 2)            newcmp = true;
            if (v != o && low[v] >= pre[v])   newcmp = true;

            if (newcmp) {
                artp[v] = 1;
                newBiComp (idArest);
            }
        }
        else {
            if (viz == pai) continue;

            low[v] = min(low[v], pre[viz]);
        }
    }
}

bool ended;

void findCicle (int last) {
    int v;
    do {
        v = pilha[p--];
        to_print.push(v);
    } while (v != last);
    ended = true;
}



void dfs2 (int v, int cp) {
    if (ended) return;
    marc[v] = 2;
    pilha[++p] = v;

    for (int i = 0; i < graph[v].size(); i++) {
        if (ended) return;

        int viz = graph[v][i];
        int idArest = arestas[v][i];
        if (compArest[idArest] != cp) continue;

        if (marca[idArest] == 2) continue;
        marca[idArest] = 2;

        if (marc[viz] == 2) {
            findCicle(viz);
            return;
        }
        else {
            dfs2(viz,cp);
            if (ended) return;
        }

    }
    p--;
}

void solve () {
    cout << endl;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        arestas[i].clear();
    }

    memset (marc, 0 , n + 2);
    memset (marca, 0 , n + 2);
    memset (pre , 0 , n + 2);
    memset (low , 0 , n + 2);
    memset (artp , 0 , n + 2);
    memset (szComp , 0 , n + 2);
    
    int a,b,d;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        graph[a].pb(b);
        graph[b].pb(a);
        arestas[a].pb(i);
        arestas[b].pb(i);
        distarest[i] = d;
        Pontos[i] = {a,b};
    }
    // for (int i = 0; i < m; i++)
    //     cout << distarest[i] << ' ';

    // cout << "Read OK!" << endl;
    c = 0, tmr = 0, p = -1;
    for (int i = 1; i <= n; i++) {
        if (marc[i] == 0) {
            dfs (i, -1, i);
            // cout << "d " << endl;
            newBiComp(-1);
            // cout << "nbc " << endl; 
        }
    }
    // cout << "DFS 1 OK" << endl;
    int min = 0;
    mnare[0] = numeric_limits<int> :: max();
    for (int i = 1; i <= c; i++)
        if (mnare[i] < mnare[min] && szComp[i] > 1)
            min = i;

    // cout << "Printando os minimos das arestas em cada componente: " << endl;
    // for (int i = 1; i <= c; i++) 
    //     cout << mnare[i] << ' ';

    cout << mnare[min] << ' ';

    int v_ini;
    for (int i = 0; i < m; i++) {
        if (compArest[i] == min) {
            v_ini = Pontos[i].first;
            break;
        }
    }

    p = -1;
    ended = false;
    dfs2(v_ini, min);
    cout << to_print.size() << endl;
    while (!to_print.empty()) {
        int v = to_print.front();
        if (v != 0)
            cout << v << ' ';
        to_print.pop();
    }
    cout << endl;
}

int main () {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}