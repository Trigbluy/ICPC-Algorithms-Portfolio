    #include <bits/stdc++.h>
    #define fastio ios_base :: sync_with_stdio(false), cin.tie(0),cout.tie(0)
    #define ll long long
    // #define int ll
    #define pb push_back
    #define ii pair<int,int>
    #define vi vector<int>
    #define vii vector <ii>
    #define ff first
    #define ss second
    #define endl '\n'
    using namespace std;
    const int INF = numeric_limits<int> :: max();
    void solve () {
        int n;
        cin >> n;
        vi pre, slimes, pos;
        int aux;
        pre.pb(0);
        slimes.pb(0);
        pos.pb(0);
        for (int i = 1; i <= n; i++) {
            cin >> aux;
            slimes.pb(aux);
            pre.pb(aux + pre[i-1]);
        }
        vi resp(n +1,-1);
        unordered_map <ll, int> foi;
        queue<ii> fila;

        for (int i = 1; i <= n; i++)
            fila.push({i,i});
        int nr = 0;
        while(nr < n && !fila.empty()) {
            auto v = fila.front(); fila.pop();
            int  l  = v.ff;
            int  r  = v.ss;
            int  sz = pre[r] - pre[l-1];
            if (sz <= 0) sz = INF;

            if (r + 1 <= n && pre[r+1] - pre[r] < sz) {
                if (resp[r+1] == -1) {
                    resp[r+1] = r - l + 1;
                    nr ++;
                }
                int ind = (r+1) + (n+1)*(l);
                if (!foi[ind]) {
                    fila.push({l, r+1});
                    foi[ind] = 1;
                }
            }
            if (l-1 > 0  && pre[l-1] - pre[l-2] < sz) {
                if (resp[l-1] == -1) {
                    resp[l-1] = r - l + 1;
                    nr++;
                }
                int ind = (r) + (n+1)*(l-1);
                if (!foi[ind]) {
                    fila.push({l-1, r});
                    foi[ind] = 1;
                }
            }
        }

        for (int i = 1; i <= n; i++)
            cout << resp[i] << ' ';
        cout << endl;
    }

    int32_t main () {
        fastio;
        int nt = 1;
        cin >> nt;
        while (nt--)
            solve();
        return 0;
    }