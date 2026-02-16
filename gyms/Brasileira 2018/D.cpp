#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define maxn 10009
#define pb push_back
#define EPS 1e-7
#define vc vector<char>
#define vcs pair<vc, string>

using namespace std;

typedef long long ll;
typedef long double ld;

map <vcs, int> mp;

int main(){
    fastio;
    int n, i, flag, resp=0;
    char c;
    vc nome;
    string s;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> c;
        flag = 0;
        nome.clear();
        while(c!='@'){
            if(c=='+') flag=1;
            if(!flag && c!='.') nome.pb(c);
            cin >> c;
        }
        cin >> s;
        if(!mp[{nome, s}]){
            mp[{nome, s}] = 1;
            resp++;
        }
    }
    cout << resp << endl;
    return (0);
}