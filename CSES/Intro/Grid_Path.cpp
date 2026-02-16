#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define ld long double
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
// #define int ll
#define pb push_back
#define f first
#define s second
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define endl '\n'
using namespace std;
typedef vector<ll> vll;
const int NMAX= 1e6+10;
const ll M = 1e9+7;
string str;
ii dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};
int di (char c) {
    if (c == '?') return -1;
    if (c == 'R') return 0;
    if (c == 'U') return 1;
    if (c == 'L') return 2;
    if (c == 'D') return 3;
}
int poss (ii p) {
    int x = p.f;
    int y = p.s;
    return (1<=x && x <= 7) && ((1<=y && y <= 7));
}
int poss (int x, int y){
    return poss({x,y});
}

void solve () {
    cin >> str;
    
}

int32_t main () {
    fastio;
    int n_c = 1;
    // cin >> n_c;
    while (n_c--)
        solve();

    return 0;
}