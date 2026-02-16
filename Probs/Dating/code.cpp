#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pb push_back
#define vi vector<int>
using namespace std;
const int MMAX = 1e6+100;
const int NMAX = 2e5+100;
int n, m;
struct cmp {
    int sz = 0, sz_n = 0, sz_k = 0;
    cmp(int a, int b) : sz_n(a), sz_k(b), sz(a+b){};
    cmp operator+ (cmp a) {
        return cmp(sz_n + a.sz_n, sz_k + a.sz_k);
    }
};
cmp comps [NMAX + MMAX];

void uni_comp(int i, int j) {

}

int main () {
    fastio;
    cin >> n >> m;
    int k;
    for (int i = 0; i <n; i++) {
    }
}
