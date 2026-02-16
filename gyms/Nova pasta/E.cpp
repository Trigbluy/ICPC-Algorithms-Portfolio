    #include <bits/stdc++.h>
    #define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
    #define vi vector<int>
    #define pb push_back
    typedef long long ll;
    using namespace std;

    void solve () {
        int s, n;
        string str;
        cin >> str >> s;

        vi arr, pre;
        pre.pb(0);
        arr.pb(0);
        for (auto c : str) {
            if (c == 'E') {
                arr.pb(1);
                pre.pb(*pre.rbegin() + 1);
            } else if (c == 'P'){
                arr.pb(0);
                pre.pb(*pre.rbegin());
            }
        }
        for (auto c : str) {
            if (c == 'E') {
                arr.pb(1);
                pre.pb(*pre.rbegin() + 1);
            } else if (c == 'P') {
                arr.pb(0);
                pre.pb(*pre.rbegin());
            }
        }

        n = str.size();
        vi nxt(2*n+1);
        nxt[2*n] = (arr[n])? 2*n : -1;
        for (int i = 2*n - 1; i >= 1; i--) {
            if (arr[i])
                nxt[i] = i;
            else
                nxt[i] = nxt[i+1];
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i])
                ans += s;
            else if (nxt[i] != -1) {
                ans += max(s - (nxt[i] - i) , 0);
            }
        }

        cout << ans << endl;
    }

    int main(){
        fastio;
        solve();
        return (0);
    }