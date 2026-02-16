#include <bits/stdc++.h>
#define maxn 100009

using namespace std;
typedef long long int ll;

ll v[maxn];

int main(){
    int i, n, pos=0, dist=0, resp=0;
    ll sum=0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> v[i];
        sum += v[i];
    }
    if(sum&1) cout << "N" << endl;
    else{
        sum /= 2;
        for(i=0;i<n-1;i++){
            if(i) dist -= v[i-1];
            while(pos<n-1 && dist<sum){
                dist += v[pos];
                pos++;
            }
            if(dist==sum) resp++;
        }
        if(resp>1) cout << "Y\n";
        else cout << "N\n";
    }
}