#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main () {
    int n, m, i, j, a, flag, resp=0;
    cin >> n >> m;
    for(i=0;i<n;i++){
        flag = 0;
        for(j=0;j<m;j++){
            cin >> a;
            if(!a) flag=1;
        }
        if(!flag) resp++;
    }
    cout << resp << endl;
    return 0;
}