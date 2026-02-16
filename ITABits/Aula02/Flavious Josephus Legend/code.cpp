#include <iostream>
#include <queue>

using namespace std;

int nc, n, k;
queue <int> peaple;


int main ()
{
    
    cin >> nc;
    for(int t = 1; t <= nc; t++)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
            peaple.push(i);

        for (int i = 1; i < k ; i++)
        {
            peaple.push(peaple.front());
            peaple.pop();
        }

        peaple.pop();
        
        for(int p = 1; p < n - 1; p++)
        {
            for (int i = 1; i < k; i++)
            {
                peaple.push(peaple.front());
                peaple.pop();
            }
            peaple.pop();
        }
        cout << "Case " << t << ": " << peaple.front() << endl;
        peaple.pop();           
    }
}