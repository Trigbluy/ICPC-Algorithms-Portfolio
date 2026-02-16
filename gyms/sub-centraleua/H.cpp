#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'
using namespace std;
const int NMAX = 700;

map <string, int> indices;
int n;
int has_parent [NMAX];

vector <int> graph [NMAX], num;
vector <string> names;

int ind (string a) {
    if (indices[a] != 0)    return indices[a];

    int indc = ++n;
    indices[a] = indc;
    names.pb(a);
    // cout << "Defining " << indc << " as " << names[indc - 1] << " indice" << endl;
    return indc;
}

void dfsE (int v) {
    cout << "im in " << v << endl;

    num.pb(1);
    for (auto viz : graph[v])
        dfsE(viz);
    num.pb(0);
}

string cmd, in;
int main () {
    cin >> cmd;
    n = 0;
    names.clear();
    indices.clear();
    num.clear();
    if (cmd == "ENCODE") {
        int mng_atual = -1;
        while (cin >> in) {
            if (in.size() <= 1) break;
            if (in[in.size() - 1] == ':') {
                mng_atual = ind(in.substr(0,in.size()-1));
            }
            else {
                int indc = ind(in);
                has_parent[indc] = 1;
                graph[mng_atual].pb(indc);
                //cout << cmd << " has indice " << indc << " and mngr " << mng_atual << endl;
            }
        }
        for (auto a : names)
            cout << a << endl;
        dfsE(1);
    }
}