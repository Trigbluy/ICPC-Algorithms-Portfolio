#include <bits/stdc++.h>

using namespace std;

int main(){
    int i, n, ant, a, resp=0;
    cin >> n;
    ant = 0;
    for(i=0;i<n;i++){
        cin >> a;
        if(a>ant) resp++;
        ant = a;
    }
    cout << resp << endl;
}