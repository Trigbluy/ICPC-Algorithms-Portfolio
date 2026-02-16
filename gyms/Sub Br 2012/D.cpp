#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define maxn 10006
using namespace std;

int v[maxn];

int main () {
    int n, i, sum=0, resp=0;
    while(scanf("%d", &n)!=EOF){
        sum=0;
        resp=0;
        for(i=0;i<n;i++){
            cin >> v[i];
            sum += v[i];
        }
        if(!(sum%n)){
            sum/=n;
            for(i=0;i<n;i++){
                resp += abs(sum-v[i]);
            }
            resp /= 2;
            resp++;
            cout << resp << endl;
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}
