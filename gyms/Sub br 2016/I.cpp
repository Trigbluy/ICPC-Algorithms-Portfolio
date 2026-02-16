#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define maxn 50000
#define f first
#define s second

typedef pair<int,int> ii;

int dp[maxn][2];
int v[maxn];

int main () {
    int n, i, resp=1;
    cin >> n;
    dp[0][0] = 1;
    dp[n-1][1] = 1;
    for(i=0;i<n;i++){
        cin >> v[i];
        if(i){
            dp[i][0] = min(dp[i-1][0]+1, v[i]);
        }
    }
    for(i=n-2;i>=0;i--){
        dp[i][1] = min(dp[i+1][1]+1, v[i]);
        if(dp[i][0]==dp[i+1][1]) resp = max(resp, dp[i][0]);
        else resp = max(resp, min(dp[i][0], dp[i+1][1])+1);
    }
    cout << resp << endl;
    return 0;
}