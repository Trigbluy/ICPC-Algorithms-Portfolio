#include <bits/stdc++.h>

using namespace std;

int lider[40010];
int sz[40010];
int grid [205][205];
int h,l;

int top (int a)
{
    while (lider[a] != lider[lider[a]])
        lider[a] = lider[lider[a]];
    return lider [a];
}

void merge (int a, int b)
{
    if (top(a) == top(b)) return;

    if (sz[top(a)] > sz[top(b)])
        swap(a,b);
    
    sz[top(b)]    += sz[top(a)];
    lider [top(a)] = lider[top(b)];
}

int val (int i, int j)
{
    if (i < 0 || i >= l || j < 0 || j >= h) return -1;
    return h*i + j;
}

int main ()
{
    cin >> h >> l;

    for (int i = 0; i <= h*l; i ++)
    {
        lider[i] = i;
        sz[i] = 1;
    }

    for (int j = 0; j < h; j++)
        for (int i = 0; i < l; i++)
            cin >> grid[i][j];

    for (int j = 0; j < h; j++)
        for (int i = 0; i < l; i++)
        {
            if (val(i+1,j) != -1)
            {
                if (grid[i+1][j] == grid[i][j])
                    merge(val(i+1,j), val(i,j));
            }
            if (val(i-1,j) != -1)
            {
                if (grid[i-1][j] == grid[i][j])
                    merge(val(i-1,j), val(i,j));
            }
            if (val(i,j+1) != -1)
            {
                if (grid[i][j+1] == grid[i][j])
                    merge(val(i,j+1), val(i,j));
            }
            if (val(i,j-1) != -1)
            {
                if (grid[i][j-1] == grid[i][j])
                    merge(val(i,j-1), val(i,j));
            }
            
        }
    
    int minsz = 0;
    for (int j = 0; j <h; j++)
        for (int i = 0; i < l; i++)
        {
            // cout << "Size of (" << grid[i][j] << ") " << i << ',' << j << " is " << sz[top(val(i,j))] << endl;
            if (sz[top(val(i,j))] < sz[top(minsz)])
            {
                minsz = top(val(i,j));
            }
        }
    
    cout << sz[top(minsz)] << endl;

    return 0;
}   