#include <bits/stdc++.h>

using namespace std;
const int NMAX = 1e5 + 10;
set<int> graph[NMAX];
int grau[NMAX], marc[NMAX], szcomp[NMAX];
pair  <int,int> ordem[NMAX];
priority_queue<pair<int,int>> to_pross;
set <int> processed;

int n, m, A, B;
int ncomp;


int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie(0);
    cout.tie(0);

    cin >> n  >> m >> A >> B;

    int a,b;
    for (int i =0;i < m ; i++)
    {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    for (int i = 1; i <= n ;i ++)
    {
        grau[i] = graph[i].size();
        ordem [i] = {grau[i], i};
    }

    sort (ordem + 1, ordem + n + 1);

    int pt = 0;
    while (ordem[++pt].first < A)
            to_pross.push(ordem[pt]);

    while (!to_pross.empty())
    {
        auto anl = to_pross.top();  to_pross.pop();
        if (anl.first >= A) break;
        int v = anl.second;
        if (processed.find(v) != processed.end()) continue;
        processed.insert(v);

        for (auto viz : graph[v])
        {
            if (processed.find(viz) == processed.end()){
                grau[viz]--;
                to_pross.push({grau[viz],viz});
            }
        }
    }

    // Contar componentes e tamanho deles
    
    return 0;
}   