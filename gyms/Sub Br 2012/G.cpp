#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio (false), cin.tie(0), cout.tie(0)
typedef long long ll;
#define maxn 26
using namespace std;

vector<pair<int,int>> v(maxn);

int main () {
    int n, a, sum, i, j;
    while(scanf("%d", &n)!=EOF){
        sum = 0;
        for(i = 1; i <= n; i++){
            cin >> a;
            v[a].first = i;
        }
        for(i = 1; i <= n; i++){
            cin >> a;
            v[a].second = i;
        }
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(v[i].first < v[j].first && v[i].second > v[j].second) sum++;
            }
        }
        cout << sum << endl;
        for(auto x : v){
            x.first = 0;
            x.second = 0;
        }

    }
    return 0;
}