#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define endl "\n"
#define ff first
#define ss second

const int NMAX = 1e3 + 10;
const ll M1 = 1e9 + 9;
const ll M2 = 1e9 + 7;
const ll p  = 31;

ll hash1[NMAX], hash2[NMAX], expo[NMAX];

string word, in;
unordered_map <ull,int> freq[NMAX];

void reset_map (int n)
{
    for(int i = 0; i < n; i++)
        freq[i].clear();
}
ll exp(ll a, ll b, ll m=M1){
    ll r = 1LL;

    while(b>0LL){
        if(b&1){
            r = (r*a)%m;
            b--;
        }
        else{
            a = (a*a)%m;
            b /= 2LL;
        }
    } 

    return r;
}

ll inv_p1 = exp(p, M1-2, M1);
ll f_hash1(int l, int r){  //hash 0 -> i : hash[i+1]
    return ((hash1[r + 1] - hash1[l] + M1) * exp(inv_p1, l, M1) )%M1;
}


ll inv_p2 = exp(p, M2-2, M2);
ll f_hash2(int l, int r){
    return ((hash2[r + 1] - hash2[l] + M2) * exp(inv_p2, l, M2) )%M2;
}

ull f_hash(int l, int r)
{
    return f_hash1(l, r)*M2 + f_hash2(l, r);
}


int main ()
{
    ios_base :: sync_with_stdio(false);
    cin.tie();

    while(getline(cin, in))
    {
        if (in == "" || in == "\n")
            return 0;
        if (in.size() == 0) return 0;

        word.clear();
        for (char c : in)
            if (c != ' ')
                word.push_back(c);

        ll pot_p1 = 1, pot_p2 = 1;

        
        for(int i = 0; i < (int) word.size(); i++){

            hash1[i + 1] = (hash1[i] + (((ll) (word[i] - 'a') + 1) * pot_p1) % M1)%M1;
            hash2[i + 1] = (hash2[i] + (((ll) (word[i] - 'a') + 1) * pot_p2) % M2)%M2;

            pot_p1 = (pot_p1*p)%M1;
            pot_p2 = (pot_p2*p)%M2;
        }
    
        
        int n = word.size() + 1;
        reset_map(n);
        // cout << n << endl;
        int max_size = 0;
        for (int i = 0; i < n; i++)
        {
            if (word[i] == ' ') continue;
            for (int j = i; j < n; j++)
            {
                if (word[j] == ' ') continue;
                // cout << "counting " << i << " , " << j << "  ->   ";
                // for (int y = i; y <= j; y++) cout << word[y]; cout << " __ with hash: " << f_hash(i,j) << endl;
                freq[j-i+1][f_hash(i,j)] ++;
                if (max_size < j-i+1) max_size = j - i +1;
            }
        }



        for (int i = 0; i <= max_size; i++)
        {
            // cout << "Printing freq size = " << i << endl;
            int max = 0;
            for (auto par : freq[i])
            {
                // cout << par.ff << " ";
                if (par.ss > max) max = par.ss;
            }
            if (max > 1)
                cout << max << endl;
        }
    }

    return 0;
}