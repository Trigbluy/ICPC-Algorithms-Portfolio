#include <bits/stdc++.h>

using namespace std;


int n, m;
std :: vector <list<int>> tree;
list <int> vazia;
std :: vector <bool> cats;
vector <bool> started;

int num_rest (int node, int cat_count)
{
    if (started[node])
        return 0;
    started[node] = true;
    if (cat_count + cats[node] > m)
        return 0;
    if (tree[node].size() == 1 && node != 1)
        return 1;

    int resp = 0;
    for(int i : tree[node])
        if (cats[node])
            resp += num_rest(i, cat_count + 1);
        else
            resp += num_rest(i, 0);

    return resp;
}

int main ()
{
    cin >> n >> m;
    int a,b;

    cats.push_back(false);
    tree.push_back(vazia);
    started.push_back(false);

    for(int i = 0; i < n; i ++)
    {
        cin >> a;
        cats.push_back(a);
        tree.push_back(vazia);
        started.push_back(false);
    }

    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    cout << num_rest(1,0) << endl;
    return 0;
}
