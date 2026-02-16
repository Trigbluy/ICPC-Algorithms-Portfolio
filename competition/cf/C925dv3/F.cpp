#include <bits/stdc++.h> 
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define ull unsigned ll
#define pb push_back
#define ff first
#define ss second
#define pii pair <ll,ll>
#define vii vector <pii>
#define vi vector <ll>
#define endl '\n'

using namespace std;

const int NMAX = 2e5 + 10;
set<int> graph [NMAX];
int marc[NMAX], processed[NMAX];

bool dfs (int v) {
    marc [v] = 1;
    for (int viz : graph[v]) {
        if (marc[viz] == 1) {
            if (processed[viz] == 0)
                return true;
        }
        else
            if (dfs(viz))
                return true;
    }
    processed[v] = 1;
    return false;
}

void solve (){

    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cin >> k;
        cout << "YES" << endl;
        return;
    }

    for (int i = 0; i <= n + 2; i++)
    {
        graph[i].clear();
        marc[i] = 0;
        processed[i] = 0;
    }
    

    int ant, aux;
    for (int j = 0; j < k; j++) {
        cin >> ant;
        cin >> ant;
        for (int i = 2; i < n; i++) {
            cin >> aux;
            graph[ant].insert(aux);
            ant = aux;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (marc[i] == 0)
            if (dfs(i) == true) {
                cout << "NO" << endl;
                return;
            }
    }
    cout << "YES" << endl;
}

int main (){
    fastio;
    int nt;
    cin >> nt;
    while (nt--){
        solve();
    }
    return 0;
}