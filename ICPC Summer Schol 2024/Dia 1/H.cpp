#include <bits/stdc++.h>

using namespace std;

const int NMAX = 200010;

vector<int> graph[NMAX];

int marc [NMAX];

queue<int> leafs;

int pairs[NMAX][2];
int n, n_leafs;


void dfs (int v)
{
    marc[v] = 1;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int viz = graph[v][i];
        if (marc[viz] == 0)
        {
            dfs(viz);
        }
    }

    if (graph[v].size() == 1)
    {
        n_leafs++;
        leafs.push(v);
    }
}

int main ()
{

    int a,b;
    FILE* in, *out;
    in  = fopen("kingdom.in" , "r");
    out = fopen("kingdom.out", "w");
    fscanf(in, "%d", &n);
    
    for (int i = 0; i < n - 1; i ++)
    {
        fscanf(in, "%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs (1);

    fprintf(out, "%d\n",((n_leafs + 1)/2));

    for (int j = 0 ; j < 2; j++)
        for (int i = 0; i < n_leafs/2; i++)
        {
            a = leafs.front();   leafs.pop();
            pairs [i][j] = a;
        }
    
    for (int i = 0; i < n_leafs/2; i++)
        fprintf(out, "%d %d\n", pairs[i][0] , pairs[i][1]);
    if ((n_leafs % 2) == 1)
    {
        b = leafs.front();
        fprintf(out, "%d %d\n",a ,b);
    }

    fclose(in);
    fclose(out);

    return 0;
}