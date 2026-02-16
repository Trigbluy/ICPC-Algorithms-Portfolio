#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int t;
    long long n;

    cin >> t;
    int b = 0;
    while (b++ < t)
    {
        cin >> n;
        int cont = 0;
        if (n > 26)
        {
            n--;
            long long k = sqrtl(n/13) - 1;
            if (k < 0)
                k = 0;
            n -= k*(k-1)*13;
            while (n >= 26*k)
                n-= 26*k++;
                
            
            while(n >= k)
            {
                //cout << n << ',' << k << '\n';
                n -= k;
                cont++;
            }
            if (n<0)
                cout << "po";
            
            cout << "Case #" << b << ": " << (char) (cont + 'A') << '\n';
        }
        else
            cout << "Case #" << b << ": " << (char) (n + 'A' - 1) << '\n';
        
    }
    return 0;
}