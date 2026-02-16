#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
#define pb push_back
typedef long long ll;
using namespace std;

typedef vector<int> vi;
const int NMAX = 2e5;
const ll M    = 998244353;
vi graph[NMAX];
int  val[NMAX], dof[NMAX], marc[NMAX];
ll   fat[NMAX];

ll bpow (ll a, ll b) {
    if (b == 0) return 1;
    if (b%2) return (a*bpow((a*a)%M, b/2)) % M;
    return bpow((a*a)%M, b/2);
}
struct mrat {
    ll up, down;
    mrat(ll a = 0, ll b = 1) : up(a%M), down(b%M){};

    mrat operator+(ll a) {
        return mrat(((up + a*down)%M + M)%M, down);
    };
    mrat operator+(mrat aux) {
        return mrat(((up*aux.down + down*aux.up)%M + M)%M, (down*aux.down)%M);
    };
    mrat operator*(ll a) {
        return mrat(((a*up)%M + M)%M, down);
    };
    mrat operator*(mrat aux) {
        return mrat(((aux.up*up)%M + M)%M, ((down*aux.down)%M + M)%M);
    };
    mrat operator/(ll a) {
        return mrat(up,((down*a)%M + M)%M);
    }
    bool operator==(mrat aux) {
        return (up == aux.up) && (down == aux.down);
    };
    bool operator!=(mrat aux) {
        return !((up == aux.up) && (down == aux.down));
    };

    bool empty () {
        return up == -1;
    };

    ll show () {
        return up*bpow(down, M-2) % M;
    };
}; 

void dfs (int v) {
    marc[v] = 1;
    for (int i = 0; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        if (marc[viz] == 0) {
            dof[viz] = v;
            dfs(viz);
        }
    }
}

mrat sump (ll k) {
    mrat ans(0);
    for (int i = 1; i <= k; i++) {
        ans = ans + mrat(i, k*(k+1));
    }
}

mrat E1_[NMAX], E2_[NMAX];

void prepare () {
    fat[0] = 1;
    for (int i = 1; i < NMAX; i++) {
        fat[i] = (i*fat[i-1])%M;
    }
    mrat nll(-1);
    for (int i = 0; i < NMAX; i++) {
        E1_[i] = E2_[i] = nll;
    }
}

mrat E1 (int v) {
    if (E1_[v] != mrat(-1)) return E1_[v];

    mrat ans(val[v]);
    mrat sumE(0);
    int nf = 0;

    for (int  i = 0; i < graph[v].size(); i++) {
        int viz = graph[v][i];
        if (viz == dof[v])  continue;
        sumE = sumE + E1(viz);
        nf++;
    }

    ans = ans + sumE*sump(nf);
    E1_[v] = ans;
    return ans;
}

mrat E2 (int v) {
    if (v == -1)            return 0;
    if (E2_[v] != mrat(-1)) return E2_[v];
    int pai = dof[v];
    mrat sumE(E2(dof[pai]));
    mrat ans(0);
    int nf = 1;
    for (int i = 0; i < graph[pai].size(); i++) {
        int viz = graph[pai][i];
        if (viz == v) continue;
        sumE = sumE + E1(viz);
        nf++;
    }

    ans = ans + sumE*sump(nf) + mrat(val[pai]);
    E2_[v] = ans;
    return ans;
}

int main(){
    fastio;

    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i + 1];
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    prepare();
    dof[1] = -1;
    dfs(1);

    mrat ans(0);
    E1(1);
    for (int i = 1; i <= n; i++) {
        ans = ans + E2(i);
        for (int j = 0; j < graph[i].size(); j++) {
            int viz = graph[i][j];
            if (viz != dof[i])
                ans = ans + E1(viz);
        }
    }

    ans = ans/n;

    cout << ans.show() << endl;
    return (0);
}