#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int> 
#define vi vector<int>
#define endl '\n'
using namespace std;
const int NMAX = 5e4 + 10;
const int sqn  = 250;
const int QMAX = 1e5 + 10;
vi graph[NMAX][2];
int marc[NMAX], comp[NMAX], mini[NMAX], pilha[NMAX];
int c, p;

int arr[NMAX];
pair <int, ii> qrs [QMAX];
int ans[QMAX];

struct bb {
    multiset<int> left, right;
    int sz = 0;
    bb () {sz = 0;};
    void correct () {
        if (right.size() > sz/2) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        else if (right.size() < sz/2) {
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
        else if (left.size() < sz/2) {
            left.insert(*right.begin());
            right.erase(right.begin());
        } else if (left.size() > sz/2 + 1) {
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }
    }
    void add (int a) {
        if (!sz) {
            left.insert(a); sz++;
            return;
        }
        sz++;
        if (a >= *left.begin())
            right.insert(a);
        else
            left.insert(a);
        correct();
    }
    void erase (int a) {
        if(sz) {
            if (left.find(a) != left.end()) {
                left.erase(left.find(a));
            }
            else if (right.find(a) != right.end()) {
                right.erase(right.find(a));
            }
            sz--;
            correct();
        }
    }
    int med () {
        if (right.empty()) return 1;
        if (*left.begin() == *right.rbegin()) return 1;
        int resp =  *left.rbegin() - 1;
        resp =  *lower_bound(left.begin(), left.end(), resp);
        if (resp == *left.rbegin() && resp == *right.begin())
            return *upper_bound(right.begin(), right.end(), resp);
        return resp;
    }
    // void print () {
    //     cout << "Situacao: " << sz << endl;
    //     for(auto a : left)
    //         cout << a << ' ';
    //     cout << endl;
    //     for(auto a : right)
    //         cout << a << ' ';
    //     cout << endl;
    // }
};

int dfs_k (int v, int ind) {
    marc[v] = !ind;
    for (int i = 0 ; i < graph[v][ind].size (); i++) {
        int viz = graph[v][ind][i];
        if (marc[viz] == ind)
            dfs_k(viz, ind);
    }
    if (!ind)
        pilha[++p] = v;
    else {
        comp[v] = c;
        mini[c] = min(mini[c], v);
    }
}

void kosaraju (int n) {
    c = 0;
    p = -1;
    for (int i = 1; i <= n; i++) {
        if (marc[i] == 0)
            dfs_k(i, 0);
    }
    for (int i = p; i >= 0; i--) {
        int viz = pilha[i];
        if (marc[viz]) {
            c++;
            mini[c] = viz;
            dfs_k(viz, 1);
        }
    }
    
    for (int i = 0; i < n; i++) {
        int v = pilha[i];
        for (int j = 0 ; j < graph[v][0].size(); j++) {
            int viz = graph[v][0][j];
            mini[comp[v]] = min (mini[comp[v]], mini[comp[viz]]);
        }
        arr[v] = mini[comp[v]];
    }
}

bool comparator (pair<int, ii> a, pair<int, ii> b) {
    if (a.ss.ss/sqn != b.ss.ss/sqn) {
        return a.ss.ss/sqn < b.ss.ss/sqn;
    } else if (a.ss.ff != b.ss.ff) {
        return a.ss.ff < b.ss.ff;
    } else if (a.ss.ss != b.ss.ff) {
        return a.ss.ss < b.ss.ff;
    } else {
        return a.ff < b.ff;
    }
}

void solve () {
    int n, q, a, b;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        graph[i][0].pb(a);
        graph[a][1].pb(i);
    }

    kosaraju(n);
    // cout << "Arr:" << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << arr[i] << ' ';
    // cout << endl;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        qrs[i] = {i, {a,b}};
    }
    sort (qrs, qrs + q, comparator);
    bb box;
    int lc = 1, rc = 0;
    for (int i = 0; i < q; i++){
        auto el = qrs[i];
        int ind = el.ff;
        int l   = el.ss.ff;
        int r   = el.ss.ss;
        // cout << ind << ": " << l << ' ' << r << endl;

        while(rc < r)
            box.add(arr[++rc]);
        while (lc > l)
            box.add(arr[--lc]);
        while (lc < l)
            box.erase(arr[lc++]);
        while (rc > r)
            box.erase(arr[rc--]);
        box.print();
        cout << lc << ',' << rc << ' ' << box.med() << endl;
        ans[ind] = box.med(); 
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;
}

int main () {
    fastio;
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}