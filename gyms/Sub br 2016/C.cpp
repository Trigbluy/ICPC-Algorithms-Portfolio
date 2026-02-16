#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define maxn 1004
#define f first
#define s second
#define maximum 0x3f3f3f3f

typedef vector<int> vi;

typedef pair<int,vi> ii;

priority_queue <ii> q;
typedef map <vi, int> mp;

vi val(maxn), A(8), B(8), antval(8), R(8);
mp dp, vis;

void dijk(){
    int d, i;
    while(!q.empty()){
        A = q.top().s;
        d = -q.top().f;
        q.pop();
        if(d>dp[A]) continue;
        if(A==R) break;
        vis[A] = 2;
        for(i=0;i<8;i++){
            B = A;
            if(i%4){
                swap(B[i], B[i-1]);
                if(!vis[B] || (vis[B]==1 && dp[A]+antval[A[i]]+antval[A[i-1]]<dp[B])){
                    vis[B] = 1;
                    dp[B] = dp[A]+antval[i]+antval[i-1];
                    q.push({-dp[B], B});
                }
                swap(B[i], B[i-1]);
            }
            if(i%4<3){
                swap(B[i], B[i+1]);
                if(!vis[B] || (vis[B]==1 && dp[A]+antval[A[i]]+antval[A[i+1]]<dp[B])){
                    vis[B] = 1;
                    dp[B] = dp[A]+antval[i]+antval[i+1];
                    q.push({-dp[B], B});
                }
                swap(B[i], B[i+1]);
            }
            swap(B[i], B[(i+4)%8]);
            if(!vis[B] || (vis[B]==1 && dp[A]+antval[A[i]]+antval[A[(i+4)%8]]<dp[B])){
                vis[B] = 1;
                dp[B] = dp[A]+antval[i]+antval[(i+4)%8];
                q.push({-dp[B], B});
            }
            swap(B[i], B[(i+4)%8]);
        }
    }
}

int main () {
    int i, a;
    for(i=0;i<8;i++){
        cin >> a;
        val[a] = i;
        antval[i] = a;
    }
    for(i=0;i<8;i++){
        cin >> a;
        A[i] = val[a];
    }
    q.push({0, A});
    for(i=0;i<8;i++) R[i]=val[antval[i]];
    dijk();
    cout << dp[R] << endl;
    return 0;
}