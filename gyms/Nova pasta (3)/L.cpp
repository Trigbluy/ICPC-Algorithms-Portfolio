#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define f first
#define s second
// #define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
const ll M = 1e9+7;
int n, a, b, c;
int g[3];
vi x;

vi vet (vi el, ll sum) {
    // cout << "Buscando " << sum << endl;
    if (!el[0]) return vi(n+2,0);
    vector<vi> moch(n+1,vi(sum+1,0));
    for (int i = 0; i <= n; i++)
        moch[i][0] = 1;
    for (int i = 1; i <= n; i++){
        if(el[i])
            for (int j = 0; j <= sum; j++){
                // cout << j  << ' ' << x[i] << endl;
                if (moch[i-1][j] && !moch[i][j])
                    moch[i][j] = moch[i-1][j];
                if (moch[i-1][j] && ((j+x[i]) <= sum))
                    moch[i][j+x[i]] = i;
            }
        else
            for (int j = 0; j <= sum; j++)
                moch[i][j] = moch[i-1][j];
        // cout << "Mochila" << endl;
        
        // for (int x = 0; x <= n; x++) {
        //     for (int y = 0; y <= sum; y++)
        //         cout << moch[x][y] << ' ';
        //     cout << endl;
        // }
    }
    vi ans(n+2,0);
    for (int i = sum; i >= 1; i--){
        if (moch[n][i]){
            // cout << "Achou em " << i << endl;
            ans[n+1] = i;
            int na = n;
            while(i!=0){
                // cout << na << ' ' << i << ' ' << moch[na][i] << endl;
                ans[moch[na][i]] = 1;
                ans[0]++;
                int ax = moch[na][i];
                i -= x[ax];
                na = ax - 1;
            }
            break;
        }
    }
    // cout << endl;
    return ans;
}

bool poss (int k, int sum) {
    // cout << "Trying " << k << ' ' << sum << endl;
    vi el(n+1,1);
    el[0] = n;
    for (int r = 0; r < 3; r++) {
        vi va = vet(el, g[r]*k);
        for (int i = 1; i <= n; i++)
            if(va[i])
                el[i] = 0, el[0]--, sum -= x[i];
    }
    // cout << "Deu " << sum << endl;
    return !sum;
}

void solve () {
    cin >> n >> a >> b >> c;
    x.assign(n+1,0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }
    sort(x.begin(),x.end());
    g[0] = a, g[1] = b, g[2] = c;
    sort (g, g+3); swap(g[0],g[2]);
    int l = 1, r = sum/g[0] + 1, m;
    while (l < r){
        m = (l+r)/2;
        if(poss(m,sum)) r = m;
        else l = m+1;
    }
    cout << l << endl;
}

int main () {
    fastio;
    int nt = 1;
    //cin >> nt;
    while (nt--)
        solve();
    return 0;
}