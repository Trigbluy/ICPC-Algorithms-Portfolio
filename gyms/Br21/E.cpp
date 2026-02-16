#include <bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

void solve () {
    int n, a, t;
    cin >> n;
    queue <int> q[2];

    for (int i = 0 ; i < n; i++){
        cin >> t >> a;
        q[a].push(t);
    }
    t = 0;
    int dir = -1;
    while (!q[0].empty() || !q[1].empty()) {
        if (dir != -1 && !q[dir].empty() && q[dir].front() <= t) {
            t = max(q[dir].front() + 10, t);
            q[dir].pop();
        }
        else {
            if (!q[0].empty())
                dir = 0;
            if (!q[1].empty())
                dir = 1;
            if (!q[0].empty() && !q[1].empty() && q[1].front() > q[0].front()) {
                dir = 0;
            }
            t = max(t, q[dir].front()) + 10;
            q[dir].pop();
        }
    }

    cout << t << endl;
}

int main () {
    int nt = 1;
    while (nt--)
        solve();
    return 0;
}