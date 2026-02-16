#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define endl '\n'
#define all(v) v.begin(),v.end()
using namespace std;
const int NMAX = 1e5 + 10;
int arr[NMAX];
queue <ll> tp;
map<ll,ll> pre_calc, sum;
int n, q;
ll ind (ll i, ll d) {
    if (i < 0LL || i > n) return -1LL;
    return d*400000LL + i;
}
void preCalc () {
    pre_calc.clear();
    sum.clear();
    int raiz = sqrt(n) + 1;
    for (int d = 1; d <= raiz; d++) {
        for (int i = n; i >= 1;i--) {
            sum     [ind(i, d)] = arr[i]                + sum [ind(i+d, d)];
            pre_calc[ind(i, d)] = pre_calc[ind(i+d, d)] + sum [ind(i+d, d)];
        }
    }
}



void solve () {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    preCalc();
    int raiz = sqrtl(n) + 1;

    while (q--) {
        int s, d, k;
        cin >> s >> d >> k;
        if (k < raiz) {
            ll ans = 0;
            for (int i = 1; i <= k; i++)
                ans += arr[s+d*(i-1)]*i;
            tp.push(ans);
        }
        else {
            // cout << pre_calc[ind(s/d, s%d, d)]  << " - " << pre_calc[ind(s/d + k, s%d, d)]  << " - " << sum[ind(s/d + k, s%d, d)]*k << endl;
            tp.push( pre_calc[ind(s, d)] - pre_calc[ind(s + d*k, d)] - (sum[ind(s + d*k, d)]*(k)));
        }
    }

    while (!tp.empty()) {
        cout << tp.front() << ". ";
        tp.pop();
    }
    cout << endl;
}

int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}