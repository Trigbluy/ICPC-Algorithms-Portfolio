#include <bits/stdc++.h>

#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define iii tuple<ll,ll,ll>
#define vi vector<ll>
#define pb push_back

using namespace std;
const int   NMAX   = 4e5 + 100;
const ll    bas[3] = {29, 31, 37},
            mod[3] = {1000000007LL, 1000000009LL, 998244353LL};
ll pows[NMAX][3];
map<int,int> freq;
int zer_freq;
int n, k, a;
ll full_1[3];

map<iii, int> mapa;

void prepare () {
    for (int j = 0; j < 3; j++) {
        pows[0][j] = 1;
    }
    for (int i = 1; i< NMAX; i++)
        for (int j = 0; j < 3; j++)
            pows[i][j] = (pows[i-1][j]*bas[j] ) % mod[j];

    for (int i = 0; i < k; i++)
        for (int j = 0; j < 3; j++)
            full_1[j]    = (full_1[j] + pows[i][j]) % mod [j];
    for (int i = 1; i <= n; i++)
        freq[i] = 0;
}

int main () {
    fastio;
    cin >> n >> k;

    vi arr;
    arr.pb(0);
    for (int i = 0 ; i < n; i++) {
        cin >> a;
        arr.pb(a);
    }
    prepare();

    zer_freq = 1;
    iii zer = {0,0,0};
    mapa[zer] = 0;
    ll hash_att[3] = {0,0,0};
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int el = arr[i];
        freq[el]++;

        if ((*freq.begin()).second == zer_freq) {
            zer_freq++;
            for (int j = 0; j < 3 ; j++)
                hash_att[j] = ((hash_att[j] - full_1[j])% mod[j] + mod[j])%mod[j];
        }

        for (int j = 0; j < 3 ; j++)
            hash_att[j] = (hash_att[j] + pows[el-1][j])%mod[j];

        iii aux = {hash_att[0], hash_att[1], hash_att[2]};
        
        if (mapa[aux] != 0 || aux == zer)
            ans = max(ans, i - mapa[aux]);
        else
            mapa[aux] = i;
    }

    cout << ans << endl;
    return 0;
}