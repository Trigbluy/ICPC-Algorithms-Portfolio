#include <bits/stdc++.h>
#define ll long long

using namespace std;
string str;


int main (){
    int n;
    cin >> n;
    string aux;

    for (int i = 1; i <= n; i++){
        aux.clear();
        int a = i, p =0;
        while (a != 0) {
            aux.push_back('0' + a % 10);
            a        /= 10;
            p++;
        }
        reverse(aux.begin(), aux.end());

        for (char i : aux){
            if (i == '\0')
                break;
            str.push_back(i);
        }
    }

    ll cont = 0;
    for (int i = 0; i <= str.size()+1; i++) {
        if (str[i] == '4' && str[i+1] == '2'){
            cont++;
        }
    }
    cout << cont << endl;
    return 0;
}