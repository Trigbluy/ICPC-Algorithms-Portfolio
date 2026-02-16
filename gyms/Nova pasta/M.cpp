#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x, resp=0, a, la=-10000, sum=1;
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> a;
        if(la+x>=a) sum++;
        else sum = 1;
        resp = max(resp, sum);
        la = a;
    }
    cout << resp;
    return (0);
}