#include <bits/stdc++.h>

using namespace std;

int n, m;
int a,b;
set <int> jack;
int main ()
{
    cin.tie(0);
    ios_base :: sync_with_stdio(false);
    while (true)
    {
        int resp = 0;
        cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;
        jack.clear();
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            jack.insert(a);
        }
        for(int i = 0; i < m; i++)
        {
            cin >> b;
            resp += jack.count(b);
        }

        cout << resp << endl;
    }
    return 0;
}