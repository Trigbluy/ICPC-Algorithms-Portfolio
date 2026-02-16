#include <bits/stdc++.h>
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define vi vector<int>
#define pb push_back
typedef long long ll;
#define ss second
#define ff first
using namespace std;

const int NMAX = 4e5 + 100;
const ll  inf  = numeric_limits<ll> :: max();
const int sq   = 632;

struct vf {
    int sz;
    vi elements;
    void add (int a) {
        elements[a]++;

        bool zer = true;
        for (int i = 1; i <= sz; i++)
            if (elements[i] == 0)
            {
                zer = false;
                break;
            }
        if (zer == true)
            for (int i = 1; i <= sz; i++)
                elements[i]--;
    }
    
    bool operator <(vf& aux) {
        for (int i = 1; i <= sz; i++)
            if (elements[i] == aux.elements[i])
                continue;
            else
                return elements[i] < aux.elements[i];
        return elements[0] < aux.elements[0];
    }

    bool operator ==(vf& aux) {
        for (int i = 1; i <= sz; i++)
            if (elements[i] != aux.elements[i])
                return 0;
        return 1;
    }
    bool operator !=(vf& aux) {
        for (int i = 1; i <= sz; i++)
            if (elements[i] != aux.elements[i])
                return 1;
        return 0;
    }
};

int n, k;
vi arr;
int freq[NMAX];
unordered_set<int> brands;

vf vfreq[NMAX];

void add (int a, int sz) {
    freq[a]++;
    if (freq[a] == sz)
        brands.insert(a);
    else
        brands.erase(a);
}

void del (int a, int sz) {
    freq[a]--;
    if (freq[a] == sz)
        brands.insert(a);
    else
        brands.erase(a);
}

bool poss_big (int sz) {
    if (sz == 0)
        return true;

    for (int i = 0; i < NMAX; i++) {
        freq[i] = 0;
    }
    brands.clear();

    int i;
    for (i = 1; i <= sz*k && i <= n; i++) {
        add(arr[i], sz);
    }

    if (brands.size() == k)
        return true;
    while (i <= n) {
        add(arr[i], sz);
        del(arr[i - sz*k], sz);
        i++;

        if (brands.size() == k)
            return true;
    }
    return false;
}

void solve () {
    cin >> n >> k;

    int aux;
    arr.pb(0);
    for (int i = 0; i < n; i++){
        cin >> aux;
        arr.pb(aux);
    }

    if (k >= sq) {
        for (int i = n/k; i >= 0; i--)
            if (poss_big (i) == 1) {
                cout << i*k << endl;
                return;
            }
    }
    else {
        vfreq[1].sz = k;
        vi zero(k + 1,0);
        vfreq[1].elements = zero;
        vfreq[1].elements[0] = 1;
        vfreq[1].add(arr[1]);

        for (int i = 2; i <= n; i++) {
            vfreq[i] = vfreq[i-1];
            vfreq[i].add(arr[i]);
            vfreq[i].elements[0] = i;
        }

        // for (int i = 1; i <= n; i++) {
        //     cout << "vfreq " << vfreq[i].elements[0] << endl;
        //     for (int j = 1; j <= vfreq[i].sz; j++) {
        //         cout << vfreq[i].elements[j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        sort(vfreq + 1, vfreq + n + 1);

        // for (int i = 1; i <= n; i++) {
        //     cout << "vfreq " << vfreq[i].elements[0] << endl;
        //     for (int j = 1; j <= vfreq[i].sz; j++) {
        //         cout << vfreq[i].elements[j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << "=================" << endl;

        int i = 2, mx = 0;
        auto ant = 1;
        while (i <= n) {
            if (vfreq[ant] != vfreq[i] && ant != i-1) {
                mx = max(mx, vfreq[i-1].elements[0] - vfreq[ant].elements[0]);
                // cout << i << '-' << mx << ' ' << ant<< endl;

                // cout << "vfreq " << vfreq[i-1].elements[0] << endl;
                // for (int j = 1; j <= vfreq[i-1].sz; j++)
                //     cout << vfreq[i-1].elements[j] << ' ';
                // cout << endl;
                // for (int j = 1; j <= vfreq[ant].sz; j++)
                //     cout << vfreq[ant].elements[j] << ' ';
                // cout << endl;
                ant = i;
            }
            else if (vfreq[ant] != vfreq[i])
                ant = i;
            i++;
        }

        if (vfreq[ant] == vfreq[n] && ant != n) {
            mx = max(mx, vfreq[n].elements[0] - vfreq[ant].elements[0]);
            // cout << "i" << '-' << mx<< endl;
        }
        cout << mx << endl;
    }
}


int main (){
    fastio;
    solve();
    return 0;
}