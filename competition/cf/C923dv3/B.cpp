#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
using namespace std;

vector <int> dsu;
vector <int> sz;
set <int> head;
int top (int a) {
    while (dsu[a] != dsu[dsu[a]])
        dsu[a] = dsu[dsu[a]];
    return dsu[a];
}

void merge (int a, int b){
    if (sz[top(a)] > sz[top(b)])    swap(a,b);

    sz[top(b)] += sz[top(a)];
    head.erase(top(a));
    dsu[a] = top(b);
}

int size_of (int a) {
    for (auto par : head) {
        if (sz[par] == a)
            return par;
    }
}

void solve () {
    int n;
    cin >> n;
    dsu.clear();
    sz.clear();
    dsu.push_back(0);
    sz.push_back(0);
    int a;
    for (int i = 1; i <= n; i++) {
        dsu.push_back(i);
        sz.push_back(1);
        head.insert(i);
        cin >> a;
        if (a != 0) {
            int to = size_of(a);
            merge (i,to);
        }
    }

    map <int, char> used;
    int ct = 0;
    for (int i = 1; i <= n; i++) {
        if (used[top(i)] == 0) {
            used[top(i)] = 'a' + ct++;
        }
        cout << used[top(i)];
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