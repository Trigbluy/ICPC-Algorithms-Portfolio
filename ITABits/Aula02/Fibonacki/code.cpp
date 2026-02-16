#include <iostream>
#include <queue>

using namespace std;
int main ()
{
    int t = 0;
    int k = 0, n = 0;
    long int last = 0;
    cin >> t;
    queue <long int> elements;

    for(t != 0; t--;)
    {
        cin >> k >> n;
        //cout << "(" << k << "," << n << ")";
        if( n > k)
        {
            for(int i = 0; i < k; i++)
                elements.push(i);

            elements.push(k*(k-1)/2);
            
            //cout << elements.front();
            //cout << last << endl;
            last = k*(k-1)/2;
            for(k ++; n > k ; k++)
                {
                    //cout <<  elements.front() << " " << last << endl;
                    last += last - elements.front();
                    elements.pop();
                    if(last > 1000007 || last < 0)
                        last = (last % 1000007 + 1000007) % 1000007;
                    elements.push(last);
                }
                
            cout << last << endl;
        }
        else
            cout << n-1 << endl;

        while(!elements.empty())
            elements.pop();
    }
    return 0;
}