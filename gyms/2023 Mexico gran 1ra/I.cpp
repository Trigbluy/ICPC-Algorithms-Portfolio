#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
using namespace std;

const int NMAX = 1e6 + 3;
vector<int> pre[26];
vector<pair<int,int>> V;
int n, k;

bool poss (int a, int b) {
    if (a <= b) {
        for (int i = 0; i < 26; i++) {
            int qnt = pre[i][b] - pre[i][a-1];
            if (qnt > k)
                return false;
        }
    }
    else {
        for (int i = 0; i < 26; i++) {
            int qnt = pre[i][n] - (pre[i][a-1] - pre[i][b]);
            if (qnt > k)
                return false;
        }
    }

    return true;
}
int main () {
    fastio;
    cin >> n >> k;
    string in;
    cin >> in;

    int i = 0, i_ini = 0;
    if (in[0] == in[n-1]) {
        while (in[i] == in[0] && i < n) i++;
        if (i == n) {
            cout << -1 << endl;
            return 0;
        }
        i_ini = i;
    }
    int cnt = 0;
    char ant = in[i_ini];
    V.pb({-1,-1});
    for (int j = 0; j < n; j++) {
        int ind = (j + i_ini) % n;
        if (in[ind] == ant)
            cnt++;
        else {
            V.pb({ant-'a', cnt});
            ant = in[ind];
            cnt = 1;
        }
    }

    V.pb({ant-'a', cnt});

    for (i = 0; i < 26; i++)
        pre[i].pb(0);

    for (int j = 1; j < V.size(); j++) {
        auto p  = V[j];
        int c   = p.ff;
        int qnt = p.ss;

        for (i = 0; i < 26; i++)
            pre[i].pb(pre[i][j]);
        pre[c][j+1] += qnt;
    }
    
    n = V.size() - 1;
    pair <int,int> mx = {-1, -1};
    for (i = 1; i <= n; i++) {
        int l = i;
        int r = i + n;
        int m;
        while (l != r) {
            m = (l+r)/2;
            int ind = (m > n) ? m - n : m;
            if (poss(i, ind) == true)
                l = m;
            else
                r = m - 1;
        }
        l = (l > n) ? l - n : l;
    if (poss(i,l) == false) continue;

        int sz  = l - i + 1;  if(sz < 0) sz += n;

        if (sz > mx.ff)
            mx = {sz,i};
    }

    if (mx.ff == -1) {
        cout << -1 << endl;
        return 0;
    }

    i = mx.ss;
    for (int j = mx.ss; j - mx.ss < mx.ff;) {
        char c  = V[i].ff + 'a';
        int qnt = V[i].ss;
        
        j += qnt;
        while(qnt--)
            cout << c;
        i++;
    }

    cout << endl;
    return 0;
}