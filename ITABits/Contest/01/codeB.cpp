#include <iostream>

using namespace std;

int main ()
{
    int n;
    char anal;
    int min, dist;
    int drug;

    cin >> n;
    while(n != 0)
    {
        drug = 2;
        dist = 0;
        min = n;
        for(int i = 0; i < n; i++)
        {
            cin >> anal;
            if(drug == 0)
            {
                if(anal == '.')
                    dist++;
                else if (anal == 'D')
                    dist = 0;
                else if (anal == 'R')
                {
                    if(min > dist + 1)
                        min = dist + 1;
                    drug = 1;
                    dist = 0;
                }
                else if (anal =='Z')
                {
                    min = 0;
                    break;
                }
            }
            else if (drug == 1)
            {
                if(anal == '.')
                    dist++;
                else if (anal == 'R')
                    dist = 0;
                else if (anal == 'D')
                {
                    if(min > dist + 1)
                        min = dist + 1;
                    drug = 0;
                    dist = 0;
                }
                else if (anal == 'Z')
                {
                    min = 0;
                    break;
                }
            }
            else if (anal == 'R')
                drug = 1;
            else if (anal == 'D')
                drug = 0;
            else if (anal == 'Z')
            {
                min = 0;
                break;
            }

        }
        cin.ignore(n,'\n');
        cout << min << endl;
        cin >> n;
    }
    return 0;
}