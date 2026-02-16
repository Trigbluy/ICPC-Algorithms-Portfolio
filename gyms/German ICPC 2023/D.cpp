#include <bits/stdc++.h>
#define pb push_back
#define int ld
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
struct pol {
    vi pl;
    int32_t n;
    pol(int32_t a, int b) : n(a){
        if (a == 0 && b == 2){
            pl.pb(1);
            return;
        }
        pl.pb(0);
        for (int32_t i = 1; i <= a; i++)
            pl.pb(b);
    };
    pol operator* (pol a) {
        pol aux(n+a.n, 0);
        for (int32_t i = 0; i <= n; i++)
            for (int32_t j = 0; j <= a.n; j++)
                aux.pl[i+j] += pl[i]*a.pl[j];
        return aux;
    }
    void print () {
        cout << "Printing.. " << n << endl;
        for (int32_t i = 0 ; i <= n; i++)
            cout << pl[i] << ' ';
        cout << endl;
        cout << "Finished" << endl;
    }
};

pol pw (pol p, int32_t b) {
    pol ans(0,2);
    for (int32_t i = 1; i <= b; i++)
        ans = ans*p;
    return ans;
}
int32_t main () {
    int32_t szs[] = {4, 6, 8, 12 ,20};
    int32_t n;
    pol aux(0,2);
    for (int32_t i = 0; i < 5; i++){
        // aux.print();
        cin >> n;
        aux = aux * pw(pol(szs[i],1),n);
    }
    // aux.print();
    vii ans;
    for (int32_t i = 0; i <= aux.n; i++)
        if (aux.pl[i])
            ans.pb({aux.pl[i], i});
    sort(ans.rbegin(), ans.rend());

    cout << ans[0].s;
    for (int32_t i = 1; i < ans.size(); i++)
        cout << ' ' << ans[i].s;
    cout << endl;
    return 0;
}