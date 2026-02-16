#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define I {1,0,0,1}
#define M (int (1e6))
ull mb, b;
ull n;

struct matrix{
    ull x11,x12,x21,x22;
    matrix operator *(matrix b){
        matrix out = {(x11*b.x11 + x12*b.x21) % M, (x11*b.x12 + x12*b.x22) % M,
                      (x21*b.x11 + x22*b.x21) % M, (x21*b.x12 + x22*b.x22) % M};
        return out;
    }
};

matrix pow_b (matrix a, ull q)
{
    if (q == 0) return I;
    if (q == 1) return a;
    if (q % 2 == 0) return pow_b(a*a, q/2);
    return a*pow_b(a*a, q/2);
}

int main ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n >> mb >> b)
    {
        matrix f012 = {(mb*mb + b)%M, mb%M, mb%M, 1LL},
               A    = {mb % M,1LL,b % M,0LL}, resp;
        
        resp = f012 * pow_b(A, n/5LL);

        cout << setw(6) << setfill('0') << resp.x22 << '\n';
    }
    return 0;
}