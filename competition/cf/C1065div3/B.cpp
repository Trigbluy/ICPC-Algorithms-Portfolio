#include <bits/stdc++.h>
#define fin(a,b,c) for(int a = b; a < c; a++)
#define pb push_back
using namespace std;
typedef vector<int> vi;
int main ()
{
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vi arr;
        fin(i,0,n){
            int a;
            cin >> a;
            arr.pb(a);
        }
        cout << ((arr[0] == -1)?(((arr[n-1] == -1)?0:arr[n-1])):arr[0]);
        fin(i,1,n-1)
            cout << ' ' << ((arr[i] == -1)?0:arr[i]);
        if(n!=1)
            cout << ' ' << ((arr[n-1] == -1)?((arr[0] == -1)?0:arr[0]):arr[n-1]);
        cout << endl;
    }
    return 0;
}