    #include <bits/stdc++.h>
    #define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
    #define vi vector<ll>
    #define pb push_back
    #define ii pair<ll,ll>
    #define f first
    #define s second
    typedef long long ll;
    using namespace std;
    const int NMAX = 5e5 + 100;
    vi bgraph[NMAX];
    int color[NMAX], sz[NMAX];
    vector<pair<int,ii>> arestas;
    int cnt;
    vector <ii> opts;
    vi resp;
    bool dfs (int v, int c) {
        for (int i = 0 ; i < bgraph[v].size(); i++) {
            int viz = bgraph[v][i];
            if (color[viz]/2 != c/2) {
                color[viz] = c;
                dfs (viz, c^1);
            }
            else {
                if (color[viz] == c^1)
                    return false;
            }
        }
        return true;
    }

    bool add_edge (int a, int b) {
        bgraph[a].pb(b);
        bgraph[b].pb(a);
        if (color[a] == 0 && color[b] == 0) {
            color[a] = 2*(++cnt);
            color[b] = 2*cnt + 1;
            sz[color[a]/2] = 2;
            return true;
        }
        if (color[a] == 0) {
            color[a] = 2*(color[b]/2) + !(color[b]%2);
            sz[color[b]/2]++;
            return true;
        }
        if (color[b] == 0) {
            color[b] = 2*(color[a]/2) + !(color[a]%2);
            sz[color[a]/2]++;
            return true;
        }
        if (color[a]/2 == color[b]/2) {
            return !(color[a] %2 == color[b] % 2);
        }

        if (sz[color[a]/2] > sz[color[b]/2])    swap(a,b);

        color[a] = color[b]^1;
        return dfs(a, color[a]^1);
    }

    bool verify (int a, int b) {
        return !(color[a]^1 == color[b]);
    }

    bool limpar() {
        for (auto p : opts){
            if (!add_edge(p.f,p.s))
                return false;
        }
        opts.clear();
        return true;
    }
    bool compute (int sz) {
        if (opts.size() < 2) return limpar();
        int cm = -1;
        if (opts[0].f == opts[1].f || opts[0].f == opts[1].s)
            cm = opts[0].f;
        if (opts[0].s == opts[1].f || opts[0].s == opts[1].s)
            cm = opts[0].s;
        if (cm == -1){
            resp.pb(sz);
            return limpar();
        }
        for (ii p : opts) {
            if (cm != p.f && cm != p.s){
                resp.pb(sz);
                return limpar();
            }
        }
    }
    void solve () {
        int n, m;
        cin >> n >> m;
        int x, y, b;
        ii alt;
        for (int i = 0 ; i < m; i++) {
            cin >> x >> y >> b;
            if (x > y) swap(x,y);
            arestas.pb({b,{x,y}});
        }
        sort(arestas.rbegin(), arestas.rend());
        int sz_ant = arestas[0].f;
        bool db = false;
        for (auto aux : arestas) {
            int sz = aux.f;
            int a = aux.s.f;
            b = aux.s.f;
            alt = {0,0};
            if(sz_ant!=sz){
                if (!compute(sz_ant)){
                    db = true;
                    break;
                }
            }
            if (verify(a,b)) {
                opts.pb({a, b});
            }
            sz_ant = sz;
        }
        if (!db)
            compute(sz_ant);

        if (resp.empty()) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        sort(resp.begin(),resp.end());
        for (auto p : resp)
            cout << p << endl;
    }

    int main () { 
        fastio;
        int nt = 1;
        // precalc();
        while (nt--)
            solve();
        return 0;
    }