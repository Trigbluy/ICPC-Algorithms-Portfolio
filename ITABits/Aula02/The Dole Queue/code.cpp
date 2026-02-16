#include <iostream>
#include <queue>

using namespace std;

queue <int> clock;
queue <int> antclock;
queue <int> outced;

int n, k, m, outc, outa, a;
bool first;

int main ()
{
    while(true)
    {
        cin >> n >> k >> m;

        if(n == 0 && k == 0 && m == 0)
            return 0;

        first = true;

        for(int i = 1; i < n; i ++)
            antclock.push(i);

        for(int i = n; i > 0; i--)
            clock.push(i);

        while( n != 0)
        {
            if(!first)
            {
                printf(",");
            }
            else
            {
                first = false;
            }

            for(int i = 1; i < k; i++)
            {
                antclock.push(antclock.front());
                antclock.pop();
            }

            outa = antclock.front();
            antclock.pop();
            n--;
            
            for(int i = 1; i < m; i++)
            {
                clock.push(clock.front());
                clock.pop();
            }

            if(outc == clock.front())
            {
                clock.pop();
            }
            else
            {
                outc = clock.front();
                clock.pop();
                n--;
                for(a = 0; clock.front() != outa; a++)
                {
                    clock.push(clock.front());
                    clock.pop();
                }

                clock.pop();

                for(a <= n; a++;)
                {
                    clock.push(clock.front());
                    clock.pop();
                }

                for(a = 0; antclock.front() != outc; a++)
                {
                    antclock.push(antclock.front());
                    antclock.pop();
                }

                antclock.pop();

                for(a <= n; a++;)
                {
                    antclock.push(antclock.front());
                    antclock.pop();
                }
            }

        }
        
    }
}