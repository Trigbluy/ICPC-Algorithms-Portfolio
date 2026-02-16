#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define int ll
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

using namespace std;

void solve () {
    int n;
    cin >> n;
    if (n == 3 || n == 2) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    int i = 1, j = n;
    cout << (n+1)/2;
    while (i < (n+1)/2 && j > (n+1)/2){
        cout << ' ' << j-- << ' ' << i++;
    }
    if (n%2 == 0)
        cout << ' ' << j;
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