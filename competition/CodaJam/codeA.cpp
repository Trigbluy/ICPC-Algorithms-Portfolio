#include <bits/stdc++.h>

using namespace std;

map <pair<long long,int> , int> quantW;
int dict[26];
int t, n, a;

long long deze (int n)
{
    long long ans = 1;
    for (int i = 0; i < n; i++)
        ans*=10;
    return ans;
}

pair<long long,int> encode (string &ae)
{
    pair<long long,int> ans;
    int numb = ae.length();
    int inter[10];
    for (int i = 0; i < numb; i++)
    {
        inter[i] = dict[ae[i] - 'A'];
    }
    for (int i = 0; i < numb; i++)
        ans.first+=inter[i]*deze(numb-i-1);
    ans.second = numb;

    return ans;
}

int main ()
{


    string wr;
    cin >> t;
    int b = 0;

    while(b++ < t)
    {
        quantW.clear();
        for (int i = 0; i < 26; i ++)
        {
            cin >> a;
            dict[i] = a;
        }

        //cout << dict [0];

        cin >> n;
        int sayit = false;
        for (int i = 0; i < n; i++)
        {
            cin >> wr;
            pair<long long,int> aux= encode(wr);
            //cout << aux.first << "==" << wr << '\n';
            if (quantW.find(aux) == quantW.end())
                quantW.emplace(aux,1);
            else
            {    
                sayit = true;
            }
        }

        if (sayit)
            cout << "Case #" << b << ": YES\n";
        else
            cout << "Case #" << b << ": NO\n";
    }
    return 0;
}