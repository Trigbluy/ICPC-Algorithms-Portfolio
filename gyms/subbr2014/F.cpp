#include <bits/stdc++.h>
#define mod 10000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> matrix;

matrix I;
int n;

matrix multi(matrix a, matrix b){
    matrix c = matrix(n, vi(n, 0));
    int i, j, k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                c[i][k] += (a[i][j]*b[j][k])%mod;
                c[i][k] %= mod;
            }
        }
    }
    return c;
}

matrix expo(matrix a, int b){
    if (b == 0) return I;
    if (b%2) return (multi(a,expo(multi(a, a), b/2)));
    return expo(multi(a, a), b/2);
}

int main () {
    int i, j, l, a, s, t;
    cin >> n >> l;
    cin >> s >> t;s--;t--;
    matrix m = matrix(n, vi(n, 0));
    I = matrix(n, vi(n, 0));
    for(i=0;i<n;i++){
        I[i][i] = 1;
        for(j=0;j<4;j++){
            cin >> a;a--;
            m[i][a]++;
        }
    }
    m = expo(m, l);
    cout << m[s][t] << endl;
    return 0;
}