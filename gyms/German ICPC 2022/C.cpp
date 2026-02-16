#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define minn 10009
#define EPS 1e-7
typedef long long ll;
typedef long double ld;
using namespace std;

ld dp[minn][6];
int tim[minn][5];

int main(){
    fastio;
    int i, n, d;
    ld c, mini;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> d >> c;
        if(i){
            mini = dp[i-1][0];
            if(i>5 && dp[i-1][5]>EPS) mini = min(mini, dp[i-1][5]);
            if(i>4){
                if(dp[i-1][4]>EPS) mini = min(mini, dp[i-1][4]);
                if(tim[i-1][4]>0){
                    dp[i][5] = dp[i-1][4] + (0.25*c);
                }
            }
            if(i>3){
                if(dp[i-1][3]>EPS) mini = min(mini, dp[i-1][3]);
                if(tim[i-1][3]>0){
                    tim[i][4] = tim[i-1][3]-d;
                    dp[i][4] = dp[i-1][3] + (0.25*c);
                }
            }
            if(i>2){
                if(dp[i-1][2]>EPS) mini = min(mini, dp[i-1][2]);
                if(tim[i-1][2]>0){
                    tim[i][3] = tim[i-1][2]-d;
                    dp[i][3] = dp[i-1][2] + (0.25*c);
                }
            }
            if(i>1){
                if(dp[i-1][1]>EPS) mini = min(mini, dp[i-1][1]);
                if(tim[i-1][1]>0){
                    tim[i][2] = tim[i-1][1]-d;
                    dp[i][2] = dp[i-1][1] + (0.25*c);
                }
            }
            if(tim[i-1][0]>0){
                tim[i][1] = tim[i-1][0]-d;
                dp[i][1] = dp[i-1][0] + (0.5*c);
            }
            dp[i][0] = mini + c;
        }
        else{
            dp[i][0] = c;
        }
        tim[i][0] = 120-d;
    }
    mini = 1e8;
    for(i=0;i<6;i++){
        if(dp[n-1][i]>EPS) mini = min(mini, dp[n-1][i]);
    }
    cout << fixed << setprecision(2) << mini << endl;
}