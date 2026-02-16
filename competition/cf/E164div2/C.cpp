    #include <bits/stdc++.h>
    #define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
    #define endl '\n'
    #define vi vector<int>
    #define pb push_back

    using namespace std;
    const int INF = numeric_limits<int> :: max();

    void solve() {
        string x, y;
        cin >> x >> y;
        int ind = -1;
        for (int i = 0; i < x.size(); i++) {
            if (ind == -1) {
                if (x[i] > y[i])
                    ind = 0;
                else if (x[i] < y[i])
                    ind = 1;
            }
            else if (ind == 0) {
                if (x[i] > y[i])
                    swap(x[i], y[i]);
            }
            else {
                if (x[i] < y[i])
                    swap(x[i], y[i]);
            }
        }

        cout << x << endl << y << endl;
    }
    int main () {
        fastio;
        int nt = 1;
        cin >> nt;
        while(nt--)
            solve();
        return 0;
    }