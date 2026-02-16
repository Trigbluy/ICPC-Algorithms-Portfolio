#include <bits/stdc++.h>
#define M 10000
using namespace std;

struct mat {
    int  a11 = 1, a12 = 0,
         a21 = 0, a22 = 1;
    mat operator*(mat b) {
        return {(a11*b.a11 + a12*b.a21) % M, (a11*b.a12 + a12*b.a22) % M,
                (a21*b.a11 + a22*b.a21) % M, (a21*b.a12 + a22*b.a22) % M};
    }
};

mat bpow (mat A, int b) {
    if(!b) return mat();
    if(b%2) return A*bpow(A*A, b/2);
    return bpow(A*A, b/2);
}

int main () {
    int a, b, n, k; 
    cin >> a >> b >> n >> k;

    mat A = {2*a, ((b-a*a) + M) % M,
             1    , 0    };

    mat V = bpow(A, n - 1);

    int t1 = 2*a,
        t0 = 2;

    int tn = (V.a11 * t1 + V.a12 * t0) % M;

    if (b < a*a || ((!(n%2)) && b != a*a)) {
        tn += M - 1;
    }
    
    while(--k) tn/=10;
    cout << tn % 10 << endl;

    return 0;
}