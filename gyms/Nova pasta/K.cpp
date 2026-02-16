    #include <bits/stdc++.h>
    #define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
    #define vi vector<ull>
    #define pb push_back
    typedef long long ll;
    typedef unsigned long long ull;
    using namespace std;

    void solve () {
        string str;
        cin >> str;

        char lc = str[0];
        vi roots;
        for (int i = 1; i < str.size(); i++){
            if (str[i] != lc)
                roots.pb(2*i+1);
            lc = str[i];
        }

        vi pol, aux;
        pol.pb(1);
        for (auto r : roots) {
            aux = pol;
            aux.pb(0);
            pol.pb(0);
            for (int i = 0; i < aux.size() - 1; i++) {
                pol[i+1] = r*aux[i] + aux[i+1];
            }
        }
        int s = 1;
        cout << pol.size() - 1 << endl;
        if ((str[0] == 'A')^(!(pol.size()%2)))
            s = 0;
        if (!s)
            cout << '-';
        cout << pol[0];
        for (int i = 1; i < pol.size(); i++)
            if ((i%2) ^ s)
                cout << ' ' << pol[i];
            else
                cout << " -" << pol[i];
        cout << endl;
    }

    int main(){
        fastio;
        solve();
        return (0);
    }