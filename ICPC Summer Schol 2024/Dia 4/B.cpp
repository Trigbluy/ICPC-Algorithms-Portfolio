#include <bits/stdc++.h>

using namespace std;

const int NMAX    = 110;
const int sum_max = 10005;

bool dp_ [NMAX][sum_max];

unsigned int numbers[NMAX][2];

unsigned int t2, t1;
int t, n;

int main ()
{
    cin >> t;

    while (t--)
    {
        cin >> n;
        t2 = t1 = 0;

        memset(dp_, 0, sizeof(dp_));

        int a,b;
        for (int j = 0; j <= 1; j++)
            for (int i = 1; i <= n; i++)
            {
                cin >> a ;

                numbers[i][j] = a;

                t2 += a*a;
                t1 += a;
            }

        dp_[0][0] = true;

        for (int i = 1; i <= n ; i++)
            for (int j = 0; j < sum_max; j++)
            {
                if (dp_[i-1][j] == 1)
                {
                    dp_[i][j + numbers[i][0]] = true;
                    dp_[i][j + numbers[i][1]] = true;
                }
            }

        unsigned min = 1e9;
        for (unsigned int j = 0; j < sum_max; j++)
        {
            if (dp_[n][j] == 1)
            {
                unsigned int aux = j*j + (t1-j)*(t1-j);
                if (min > aux)
                    min = aux;
            }
        }

        unsigned int ans = (n-2)*t2 + min;
        cout << ans << endl;
    }

    return 0;
}