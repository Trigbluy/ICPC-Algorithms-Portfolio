#include <bits/stdc++.h>

using namespace std;

int main ()
{
    string pattern;
    priority_queue <int> in_air;
    while (cin >> pattern)
    {
        bool okay = true;
        int numb_ball = 0;
        int pt_sz = pattern.size();
        cout << pattern << ": ";
        while (!in_air.empty())
            in_air.pop();
        for (auto a : pattern)
            numb_ball += a - '0';

        if (numb_ball % pt_sz == 0)
        {
            for (int i = 0; i < 2*pt_sz + 10; i++)
            {
                if (pattern[i % pt_sz] != '0')
                    in_air.push(-(pattern[i % pt_sz] + i - '0'));
                if (!in_air.empty() && in_air.top() == -i)
                {
                    in_air.pop();
                    if (!in_air.empty() && in_air.top() == -i)
                    {
                        cout << "invalid pattern" << endl;
                        okay = false;
                        break;
                    }
                }
            }
            if (okay)
                cout << "valid with " << numb_ball/pt_sz << " balls" << endl;
        }
        else
            cout << "invalid # of balls" << endl;
    }

    return 0;
}