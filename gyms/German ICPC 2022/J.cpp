#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define vi vector<ll>
#define pb push_back
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
map<string, int> cd;
map<int, string> dcd;
set<string> cand;
int cnt;
int vts[200][200], winners [200];
int code (string s) {
    if (cd.find(s) != cd.end())
        return cd[s];
    cd[s] = cnt++;
    dcd[cnt] = s;
    cand.insert(s);
    return cnt;
}
string dcode (int a) {
    return dcd[a];
}
void solve () {
    int c,v, slct;
    cin >> c >> v;
    string aux;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < c; j++) {
            cin >> aux;
            vts[j][code(aux)]++;
        }
    cin >> aux;
    slct = code(aux);
    cout << slct<< endl;
    for (int i = 0 ; i < c; i ++) {
        ii wn = {0,0};
        for (int j = 0; j < cnt; j++) {
            if (wn.f < vts[i][j]) {
                wn = {vts[i][j], j};
            }
        }
        winners [i] = (wn.f > c/2) ? wn.s : -1;
    }
    queue <string> tp;
    bool ok = false;
    for (int i = 0; i < c ;i ++) {
        cout << i << ": winner = " << winners[i] << endl;
        if (winners[i] == slct) {
            ok = true;
            tp.push(dcode(slct));
            break;
        }
        string a;
        for (auto s : cand) {
            if (code(s) != winners[i]) {
                tp.push(s);
                a = s;
                break;
            }
        }
        cand.erase(a);
    }

    if (!ok) {
        cout << "*" << endl;
        return;
    }

    cout << tp.front(); tp.pop();
    while(!tp.empty()){
        cout << ' ' << tp.front(); tp.pop();
    }
    cout << endl;
}

int main () {
    fastio;
    int nt = 1;
    // cin >> nt;
    while (nt--)
        solve();
    return 0;
}