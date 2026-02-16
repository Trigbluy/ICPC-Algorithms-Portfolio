    #include <bits/stdc++.h>
    using namespace std;
    map <int, int> num;

    void solve () {
        num.clear();
        int n;
        cin >> n;
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            num[a]++;
        }
        int np = 0;
        int ne = 0;
        int inf = numeric_limits<int> :: max();
        for (auto b : num) {
            np += min(b.second,num[b.first ^ inf]);
            ne += b.second;
        }

        cout << ne - np/2 << endl;
    }

    int main () {
        int nt = 1;
        cin >> nt;
        while (nt--) {
            solve();
        }
        return 0;
    }