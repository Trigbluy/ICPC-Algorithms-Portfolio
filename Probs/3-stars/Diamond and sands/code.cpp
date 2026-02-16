#include <iostream>

using namespace std;

// https://www.beecrowd.com.br/judge/en/problems/view/1069

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a ,resp;
    char b;
    cin >> n;
    cin.get(b);
    for (int j = 0; j < n; j++)
    {
        //cin.get(b);
        bool doit = true;
        resp = a = 0;
        do
        {
            cin.get(b);
            if (b == '<')
            {
                a++;
            }
            else if (b == '>')
            {
                if (a > 0)
                {
                    a--;
                    resp++;
                };
            }
            else if (b == '\n')
                doit = false;
        } while (doit);
        cout << resp << '\n';
    }
    return 0;
}