#include <bits/stdc++.h>
typedef long double ld;
typedef long long ll;
using namespace std;
int main() {
    ld e, v;
    ll h, m;
    cin >> e >> v;
    h = e/v;
    e = e - h*v;
    m = (60*e)/v;
    h += 19;
    while (m >= 60) {
        m -= 60;
        h++;
    }
    while (h >= 24) h -= 24;
    printf("%02d:%02d\n", h, m);

    return 0;
}