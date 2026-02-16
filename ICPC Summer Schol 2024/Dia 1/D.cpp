#include <bits/stdc++.h>

using namespace std;

const int NMAX = 500000;

vector<int> graph[NMAX];

int marc[NMAX], prof[NMAX];

queue<pair<int,int>> reserva;

int n, m;

bool dfs (int v, int pai)
{
    marc[v] = 1;
    int num_out = 0;
    for (int i = 0; i < graph[v].size(); i ++)
    {
        int viz = graph[v][i];
        // cout << "Entered " << v << " to " << viz << endl;
        if (marc[viz] == 0)
        {
            prof[viz] = prof[v] + 1;
            if(dfs(viz, v) == true)
            {
                num_out++;
                reserva.push({v,viz});
                // cout << "set " << v << " to " << viz << endl;
            }
            else
            {
                reserva.push({viz,v});
                // cout << "set " << viz << " to " << v << endl;
            }
        }
        else
        {
            if (viz != pai)
            {
                if (prof[viz] > prof [v])
                {
                    reserva.push({v,viz});
                    num_out++;
                }
            }
        }
    }
    // cout << "Num_out de " << v << " eh " << num_out<< endl;  
    if (num_out % 2 == 0)
        return true;
    return false;
}

int main()
{
    if (n == 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cin >> n >> m;
    int a,b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (marc[i] == 0)
            if (dfs(i,-1) == false)
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
    
    while(!reserva.empty())
    {
        cout << reserva.front().first << " " << reserva.front().second << endl;
        reserva.pop();
    }

    return 0;
}