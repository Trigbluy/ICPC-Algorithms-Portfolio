#include <iostream>
#include <vector>

using namespace std;

vector <int> panels;
int n,t,f, nc;

int main ()
{
    cin >> nc;
    for (int j = 0; j < nc; j++)
    {
        cin >> n >> t >> f;
        panels.clear();

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            panels.push_back(a);
        }

        int media = 0;
        for (int i = 0; i < n; i++)
            media+= panels[i];
        media/= t;
        //cout << media << '\n';
        vector <int> pt (t);
        for (int i = 0; i < t; i++)
            pt[i] = 0;
        
        int nt = 0;
        for (int i = 0; i < n; i++)
        {
            //cout << nt << '-' << pt[nt] << '\n';
            if ((pt[nt] + panels[i] - media <= 0) || (pt[nt] + panels[i] - media <= - pt[nt] + media) || (nt == t))
            {
                pt[nt] += panels[i];
            }
            else
            {
                nt++;
                i--;
            }
        }

        int max = pt[0];
        for (int i = 1; i < t; i++)
            if (pt[i] > max)
                max = pt[i];

        cout << max << " $" << max*f*t << '\n';
        // for (int i = 0; i < t; i++)
        //     cout << ' ' << pt[i];
        //     cout << '\n';
    }

    return 0;
}