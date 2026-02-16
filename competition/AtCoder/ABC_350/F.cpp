#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
#define vi vector<int>
typedef long long ll;
typedef long double ld;
using namespace std;
const int NMAX = 5e5 + 100;
int ind;
struct node {
    string str;
    int sz;
    int pai;
    vi sons;
    bool rev, caps;
    void settup (string s, int dad, bool rv, bool cl) {
        str = s;
        sz  = s.size();
        pai = dad;
        rev = rv;
        caps = cl;
    }

    void add_child (int a) {
        sons.pb(a);
    }

    
};
node nohs [NMAX];
void print (int a) {
    node b = nohs[a];
    if (b.rev == 0) {
        cout << b.str;
        for (int i = 0; i < b.sons.size(); i++) {
            int son = b.sons[i];
            print(son);
        }
    }
    else {
        cout << b.str;
        for (int i = b.sons.size()-1; i >=0; i--) {
            int son = b.sons[i];
            print(son);
        }
    }
}
int main () {
    fastio;
    string total;
    cin >> total;
    int n = total.size();
    int j = 0, p = 1, ant = 0;
    nohs[0].settup("", -1, 0, 0);
    for (int i = 0; i < n; i++) {
        while (total[i] != '(' && total[i] != ')' && i < n) i++;
        if (total[i] == '(') {
            nohs[p].settup(total.substr(j,i-1), ant, 1, 1);
            nohs[ant].add_child(p);
            ant = p++;
            j = i;
        }
        else if (total[i] == ')') {
            nohs[p].settup(total.substr(j,i-1), ant, 0, 0);
            nohs[ant].add_child(p);
            p++;
            ant = nohs[ant].pai;
            j = i;
        }
    }

    print(0);
    return 0;
}