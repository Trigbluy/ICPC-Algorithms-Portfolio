#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define fin(i,a,b) for(int i = a; i < b; i++)
#define f first
#define s second
#define endl '\n'
#define int ll
const signed NMAX = 3*10e5 + 3;
const signed M = 998244353;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<int,int> mpii;

int arr[NMAX];

int countInversions(int arr[], int n)
{
    vector<int> v;

    // Store array elements in sorted order
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }

    // Store the count of inversions
    int ans = 0;

    // Traverse the array
    for (int i = 0; i < n; i++) {

        // Store the index of first
        // occurrence of arr[i] in vector V
        auto itr = lower_bound(
            v.begin(), v.end(), arr[i]);

        // Add count of smaller elements
        // than current element
        ans += itr - v.begin();

        // Erase current element from
        // vector and go to next index
        v.erase(itr);
    }

    // Print the result
    cout << ans;

    return 0;
}

void solve(){
    int n;
    cin >> n;
    fin(i,0,n)
        cin >> arr[i];
    countInversions(arr,n);
    cout << endl;
}

signed main (){
    fastio;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}