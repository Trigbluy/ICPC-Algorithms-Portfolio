#include <bits/stdc++.h>

using namespace std;

int main () {
    ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, h, ans = 0;
    cin >> n;
    multiset<int> arrows;

    while(n--) {
        cin >> h;
        if (arrows.find(h) != arrows.end())
            arrows.erase(arrows.find(h));
        else
            ans++;
        if (h != 1)
            arrows.insert(h-1);
    }

    cout << ans << endl;
    return 0;
}