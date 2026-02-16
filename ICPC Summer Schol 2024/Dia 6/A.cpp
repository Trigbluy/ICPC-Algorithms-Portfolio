#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ff first
#define ss second
const int NMAX = 5e5 + 10;

vector<int> graph[NMAX];
int prof[NMAX];
map <int,int> ants;

int n;

void dfs (int v, int pai)
{
    if (graph[v].size() == 1 && v != 1)
    {
        ants[prof[v]]++;
        return;
    }

    for (int i = 0; i < graph[v].size(); i++)
    {
        int viz = graph[v][i];
        if (viz != pai)
        {
            prof[viz] = prof[v] + 1;
            dfs(viz, v);
        }
    }
}

int main ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int x,y;
    for (int i = 0 ; i < n - 1 ; i ++)
    {
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    int ans = 0;
    for (auto v : graph[1])
    {
        ants.clear();
        prof[v] = 0;
        dfs(v,1);
        int val = 0;
        for (auto par : ants)
        {
            int depth = par.ff;
            int f     = par.ss;

            if (val < depth)
                val = depth;
            val += f;
        }
        ans = max(ans, val);
    }
    
    cout << ans << endl;

    return 0;
}