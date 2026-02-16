#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
const int NMAX = 4e5;

bool cool (ii p1, ii p2, ii p3) {
    if((p1.f == p2.f) && (p2.f == p3.f)) return true;
    if((p1.f == p2.f) || (p2.f == p3.f)) return false;
    
    if((p1.s == p2.s) && (p2.s == p3.s)) return true;
    if((p1.s == p2.s) || (p2.s == p3.s)) return false;

    if((p3.s - p1.s)*(p2.f-p1.f) == (p3.f - p1.f)*(p2.s-p1.s)) return true;
    return false;
}

void solve() {
    int n;
    cin >> n;
    if (n <= 6) {
        cout << "possible" << endl;
        return;
    }
    vii pts;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        pts.pb({a,b});
    }

    vector<pair<ii,ii>> df;
    vii pilha;
    for (ii p : pts) {
        bool okay = false;
        for (auto rt : df){
            if(cool(rt.f,rt.s,p))
                okay = true;
        }
        if (okay) 
            continue;
        if (df.size() == 3) {
            cout << "impossible" << p.f << ' ' << p.s << endl;
            return; 
        }
        pilha.pb(p);

        if (pilha.size() == 10 - 3*df.size()) {
            bool consegui = false;
            for (int i = 1; i < pilha.size(); i++)
                for (int j = i+1; j < pilha.size(); j++) {
                    int cnt = 0;
                    for (int k = j+1; k < pilha.size(); k++) {
                        if (cool(pilha[i],pilha[j],pilha[k]))
                            cnt++;
                    }
                    if (cnt >= 2) {
                        bool ok = false;
                        for (auto rt : df)
                            if (cool(rt.f,rt.s,pilha[i]) && cool(rt.f,rt.s,pilha[j]))
                                ok = true;
                        if (ok)
                            continue;
                        consegui = true;
                        df.pb({pilha[i],pilha[j]});
                        vii aux;
                        for (int t = 0 ; t < pilha.size(); t++){
                            if (!cool(pilha[i],pilha[j],pilha[t]))
                                aux.pb(pilha[t]);
                        }
                        pilha = aux;
                    }
                }
            if (consegui)
                continue;
            cout << "impossiblee" << endl;
            return;
        }
    }
        if (df.size() == 3 && pilha.size()) {
            cout << "impossible3" << endl;
            return;
        }
        if ((pilha.size() > 6-2*df.size())) {
            int linhas = 3-df.size();
            for (int u = 0; u < linhas; u++) {
                if ((pilha.size() <= 6-2*df.size())) {
                    cout << "possible" << endl;
                    return;
                }
                for (int i = 1; i < pilha.size(); i++)
                    for (int j = i+1; j < pilha.size(); j++) {
                        int cnt = 0;
                        for (int k = j+1; k < pilha.size(); k++)
                            if (cool(pilha[i],pilha[j],pilha[k]))
                                cnt++;
                        if (cnt) {
                            df.pb({pilha[i],pilha[j]});
                            vii aux;
                            for (int t = 0 ; t < pilha.size(); t++){
                                if (!cool(pilha[i],pilha[j],pilha[t]))
                                    aux.pb(pilha[t]);
                            }
                            pilha = aux;
                        }
                    }
            }
            if (pilha.size()) {
                cout << "impossibler" << endl;
                return;
            }
        }
        cout << "possible" << endl;
        return;
}

int32_t main () {
    fastio;
    int nt = 1;
    while(nt--)
        solve();
    return 0;
}