#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
#define pb push_back
#define endl '\n'
using namespace std;


int n, k;

void solve () {
    
    cin >> n >> k;

    vector <int> resp (n,0);

    int ctmn = 1, ctmx = n;

    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            if (i % 2 == 0)
                resp[j] = ctmn++;
            else
                resp[j] = ctmx--;
        }
    }
    
    cout << resp[0];
    for (int i = 1; i < n; i++)
        cout << ' ' <<  resp[i];
    cout << endl;
}

int main () {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) 
        solve();
    return 0;
}