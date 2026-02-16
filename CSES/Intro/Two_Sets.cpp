#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
// #define int ll
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
// #define endl '\n'
using namespace std;
const int NMAX= 1e6+10;
int marc[NMAX];
void solve () {
    ll n;
    cin >> n;
    if (n%4 == 2 || n%4 == 1){
        cout << "NO" << endl;
        return;
    }
    queue<int> q;
    cout << "YES" << endl;
    ll sum = (n*(n+1))/4;
    for (int i = n; sum; i--) {
        if (i < sum) {
            marc[i] = 1;
            sum -= i;
            q.push(i);
        }
        else {
            marc[sum] = 1;
            q.push(sum);
            sum = 0;
        }
    }
    int r;
    cout << (r = q.size()) << endl;
    cout << q.front();
    q.pop();
    while (!q.empty()) {
        cout << ' ' << q.front();
        q.pop();
    }
    cout << endl << n - r << endl;
    int f = 1;
    for (int i = n; i >0; i--)
        if(!marc[i]) {
            if (f)
                f = 0;
            else
                cout << ' ';
            cout << i;
        }
    cout << endl;
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}