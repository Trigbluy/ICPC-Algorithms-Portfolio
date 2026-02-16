#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define vi vector<int>
#define pb push_back
using namespace std;
const int NMAX = 2e5 + 100;
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

void ppol (vi& p) {
    cout << "Polinomio de tamanho " << p.size() << endl;
    for (int i = 0; i < p.size(); i++) {
        cout << i << ": " << p[i] << endl;
    }
}

int qnt [NMAX];
vi pol1, pol2;
void solve () {
    string str;
    cin >> str;
    int n = str.size() - 1;
    // cout << "n = " << n << endl;
    for (int l = 0; l < 3; l++){
        pol1 = vi (2*n + 1, 0);
        pol2 = vi (n + 1, 0);
        char cg = 'a' + l;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == cg) {
                pol1[n + i] = 1;
                pol2[n - i] = 1;
            }
        }
        
        // Printing pols
        // ppol(pol1);
        // ppol(pol2);

        pol1 = multiply(pol1, pol2);
        // ppol(pol1);

        for (int i = 1; i < n; i++) {
            qnt[i] += pol1[2*n + i];
        }
    }
    vi ans;
    for (int i = 1; i < n; i++) {
        if (ans.empty() || qnt[ans[0]] == qnt[i])
            ans.pb(i);
        else if (qnt[ans[0]] < qnt[i]) {
            ans.clear();
            ans.pb(i);
        }
    }

    cout << qnt[ans[0]] << endl;
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++)
        cout << ' ' << ans[i];
    cout << endl;
}

int main () {
    fastio;
    int nt = 1;
    // cin >> nt;
    while(nt--) {
        solve();
    }
    return 0;
}