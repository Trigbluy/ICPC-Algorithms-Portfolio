#include <bits/stdc++.h>
#define pb push_back
using namespace std;

void solve () {
    int n;
    vector <char> att, obj;
    cin >> n;
    char aux;
    for (int i = 0; i < n; i++){
        cin >> aux;
        att.pb(aux);
    }
    for (int i = 0; i < n; i++){
        cin >> aux;
        obj.pb(aux);
    }

    int sair = 0, entrar = 0;
    for (int i = 0; i < n; i++) {
        if (att[i] == obj[i]) continue;
        if (att[i] == '0') entrar++;
        else               sair++;
    }

    cout << max(entrar, sair) << endl;
}
int main () {
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}