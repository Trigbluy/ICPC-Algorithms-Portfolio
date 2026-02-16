#include <bits/stdc++.h>

using namespace std;
int n;
vector <int> demand;

pair<pair<int,int>,long long> work (pair<pair<int,int>,long long>)
{
    
}


int main ()
{
    cin >> n;
    while (n != 0)
    {
        demand.clear();

        for(int i = 0; i < n; i ++)
        {  
            int a;
            cin >> a;
            demand.push_back(a);
        }
        cout << work(n-1) << '\n';
        cin >> n;
    }
    
    return 0;
}