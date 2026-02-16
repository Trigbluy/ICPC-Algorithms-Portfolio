#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    while (n--)
    {
        // MARGARITA -> M,A,R,G,I,T
        int ingr[] = {0,0,0,0,0,0};

        char a;
        scanf(" %c", &a);
        while (a != '\n')
        {
            switch (a)
            {
            case 'M':
                ingr[0]++;
                break;
            case 'A':
                ingr[1]++;
                break;
            case 'R':
                ingr[2]++;
                break;
            case 'G':
                ingr[3]++;
                break;
            case 'I':
                ingr[4]++;
                break;
            case 'T':
                ingr[5]++;
                break;
            default:
                break;
            }

            
            scanf("%c", &a);
        }
        
        cout << min(ingr[0], min(ingr[1]/3, min(ingr[2]/2, min(ingr[3], min(ingr[4], ingr[5]))))) << endl;
    }

    return 0;
}