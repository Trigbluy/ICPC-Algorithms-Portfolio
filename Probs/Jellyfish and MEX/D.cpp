#include <bits/stdc++.h>

#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

const int INF  = numeric_limits<int> :: max();
const int NMAX = 5e3+100;

int dp_[NMAX];
map<int,int> freq;

void prepare () {
    for (int i = 0 ; i < NMAX; i++) {
        dp_[i] = INF;
    }
    freq.clear();
    dp_[0] = 0;
}

int dp (int a) {
    if(dp_[a] != INF)
        return dp_[a];
    
    for (int j = 0; j < a; j++) {
        if (freq[j])
            dp_[a] = min(dp_[a], dp(j) + a*(freq[j]-1) + j);
    }

    return dp_[a];
}

void solve() {
    prepare();

    int n, aux;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        freq[aux]++;
    }

    int MEX;
    for (int i = 0; i <= NMAX; i++) {
        if (freq[i] == 0) {
            MEX = i;
            break;
        }
    }

    cout << dp(MEX) << endl;
}

int main () {
    fastio;
    int nt = 1;
    cin >> nt;
    while(nt--)
        solve();
    return 0;
}