#include <bits/stdc++.h>
using namespace std;
set<int> surv;

int n,r;
int main (){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n >> r)
    {
        surv.clear();
        int aux;
        for (int i = 0; i < r; i++)
        {
            cin >> aux;
            surv.insert(aux);
        }
        if (surv.size() == n)
            cout << "*";
        else
            for (int i = 1; i <= n ; i++)
                if (surv.find(i) == surv.end())
                    cout << i << ' ';
        cout << '\n';
    }
    return 0;
}