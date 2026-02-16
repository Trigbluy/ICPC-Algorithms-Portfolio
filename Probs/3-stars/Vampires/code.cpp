#include <bits/stdc++.h>

using namespace std;

// https://www.beecrowd.com.br/judge/en/problems/view/1093

int main ()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int ev1, ev2, at, d;
    int n1, n2;
    float res, p1, p2;
    float resp;
    cin >> ev1 >> ev2 >> at >> d;
    while (ev1 != 0)
    {
        // prob = prob1/(prob1 + prob2) -- prob1 = S (a+b) escolhe b * p^b * (1-p)^b
        n1 = ev1/d + (ev1 % d != 0);
        n2 = ev2/d + (ev2 % d != 0);
        p1 = at/6.0;
        p2 = 1 - p1;
        resp = 0;
        cout << n1 << n2 << p1 << p2;
        for (int b = 0; b < n2; b ++)
        {
            res = 1;
            for (int i = n1 + b; i > n1; i --)
                res*=i;
            for (int i = 2; i <= b; i ++)
                res/= i;
            res*= pow(p1,n1)*pow(p2,b);
            resp += res;
        }
        resp*= 100;
        //cout << "d";
        cout << fixed << setprecision(1) << resp << '\n';
        cin >> ev1 >> ev2 >> at >> d;
    }
    return 0;
}