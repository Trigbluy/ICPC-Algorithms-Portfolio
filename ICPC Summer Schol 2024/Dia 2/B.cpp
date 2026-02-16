// Tudo errado

#include <bits/stdc++.h>

using namespace std;

const int NMAX  = 100000;

vector <int> graph [NMAX];
int marc[NMAX], pre[NMAX], low[NMAX], pilha[NMAX], qnt_comp[NMAX], comp_pont[NMAX],
    num_vis[NMAX];
int n, t, p, c;
queue <pair<int,int>> pontes;

void novaComponenteBicon (int v)
{
    c++;
    int vertice;
    do
    {
        vertice = pilha[p--];
        qnt_comp[c]++;
        comp_pont[vertice] = c;
        if (p == -1) break;
    } while (vertice != v);
}

void dfs (int v, int pai)
{
    t++;
    pre[v] = low[v] = t;
    marc[v] = 1;
    pilha[++p] = v;

    for (int i = 0; i < graph[v].size(); i++)
    {
        int viz = graph[v][i];

        if(marc[viz] == 0)
        {
            dfs(viz, v);
            low[v] = min(low[v], low[viz]);
        }
        else
        {
            if (viz == pai) continue;

            low[v] = min(low[v],pre[viz]);
        }
    }

    if (v != 1 && low[v] == pre[v]) // eh ponte
    {
        novaComponenteBicon(v);
        pontes.push({v, pai});
    }

}


int main ()
{
    int n_cases = 0;
    while(cin >> n)
    {
        if (n == 0) return 0;
        n_cases++;

        memset(graph, 0, NMAX);
        memset(marc, 0, NMAX);
        memset(pre, 0, NMAX);
        memset(low, 0, NMAX);
        memset(qnt_comp, 0, NMAX);
        memset(num_vis, 0, NMAX);

        int a,b;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            graph [a].push_back(b);
            graph [b].push_back(a);
        }


            // MODELO DE BICONNECTED COMPONENT 
        t = 0;
        p = -1;
        c = 0;

        dfs(1, -1);
        novaComponenteBicon(-1);

        if (pontes.empty())
        {
            cout << "Case " << n_cases << ": 1 1" << endl;
            return 0;
        }

        while(!pontes.empty())
        {
            auto aux = pontes.front();
            pontes.pop();
            num_vis[comp_pont[aux.first]]++;
            num_vis[comp_pont[aux.second]]++;
        }

        int leafs = 0;
        for(int i = 1; i < c + 1; i++)
            if (num_vis[i] == 1)
                leafs++;

        unsigned long long ways = 1;
        for(int i = 1; i < c + 1; i++)
            if (num_vis[c] == 1)
                ways*= qnt_comp[i];
        cout << "Case " << n_cases << ": " << leafs << " " << ways << endl;
    }

    return 0;
}
