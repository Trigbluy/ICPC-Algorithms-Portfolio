#include <bits/stdc++.h> 
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ll long long
#define ull unsigned ll
#define pb push_back
#define ff first
#define ss second
#define pii pair <ll,ll>
#define vii vector <pii>
#define vi vector <ll>
#define endl '\n'

using namespace std;

const int NMAX = 2e6 + 10;
const ull M    = 998244353;

ull fat[NMAX];

ull bi_pow (ull q, ull p){
    if (p == 1)
        return q % M;
    if (p % 2)
        return (bi_pow((q*q) % M, p/2)*q)%M;
    return bi_pow((q*q)%M, p/2);
}

ull inv (ull a) {
    return bi_pow(a, M-2);
}

void preCalc() {
    fat[0] = fat[1] = 1;
    for(int i = 2; i < 2e6 + 1; i++)
        fat[i] = (fat[i-1] * i) % M;
}

void solve (){
    ll c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

    if (c1 > c2 + 1 || c2 > c1 + 1) {
        cout << 0 << endl;
        return;
    }

    if (c1 == 0 && c2 == 0)
        if (c3 != 0 && c4 != 0) {
            cout << 0 << endl;
            return;
        }
        else{
            cout << 1 << endl;
            return;
        }

    ull ans = 0;

    if (c1>=c2) {
        ull t1 = ((fat[c3+c1-1] * inv(fat[c3])) % M)*inv(fat[c1-1]) % M; // c3 -> c1 caixas
        ull t2 = ((fat[c4+c2] * inv(fat[c4])) % M)*inv(fat[c2]) % M;
        if (t1 == 0 || c3 == 0)  t1 = 1;
        if (t2 == 0 || c4 == 0)  t2 = 1;
        ans = (ans + (t1*t2)% M) % M;
    }

    if (c2 >= c1){
        ull t1 = ((fat[c4+c2-1] * inv(fat[c4])) % M)*inv(fat[c2-1]) % M; // c3 -> c1 caixas
        ull t2 = ((fat[c3+c1] * inv(fat[c3])) % M)*inv(fat[c1]) % M;
        if (t1 == 0 || c4 == 0)  t1 = 1;
        if (t2 == 0 || c3 == 0)  t2 = 1;
        ans = (ans + (t1*t2)% M) % M;
    }

    cout << ans << endl;
}

int main (){
    fastio;
    preCalc();
    int nt;
    cin >> nt;
    while (nt--){
        solve();
    }
    return 0;
}