#include <bits/stdc++.h>

using namespace std;

priority_queue <pair <int,int>> delis;

int main ()
{
    int n, p;

    cin >> n;
    
    while (n != 0)
    {
        while (!delis.empty())
            delis.pop();

        cin >> p;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> aux;
            cin >> aux.first >> aux.second;
            delis.push(aux);
        }
        int time = 0, piz = 0;

        while (piz < p && !delis.empty())
        {
            if(delis.top().second + piz <= p)
            {
                time += delis.top().first;
                piz += delis.top().second;
                cout << "del " << delis.top().first << "-" << delis.top().second << '\n';
            }
            delis.pop();
        }

        cout << time << " min.\n";

        cin >> n;
    }

    return 0;
}