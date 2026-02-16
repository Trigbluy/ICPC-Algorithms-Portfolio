#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define fastio ios_base :: sync_with_stdio(false), cin.tie(0), cout.tie()

using namespace std;

const int NMAX = 2e5+10;
const ld R = 1e3;
const ld INF = __LDBL_MAX__ - 1;

struct line{
    ll a;
    mutable ld b, x_inter;
    int id;
    mutable set <int> ids;
    bool operator <(line r){
        if (a < r.a)    return true;
        if (a == r.a && b < r.b) return true;

        return false;
    }
};

vector <line> cht, tbordered, tbacessed;
set <int> solutions;

ld inter (line l1, line l2){
    // a*x + b = c*x + d -> x = (d-b)/(a-c)
    return (l2.b - l1.b)/((ld)(l1.a - l2.a));
}

void add_line (line tba){
    if(!cht.empty() && cht.back().a == tba.a){
        if (fabsl(cht.back().b - tba.b) < 1e-6) {
            cht.back().ids.insert(tba.id);
            return;
        }
        else {
            cht.pop_back();
        }
    }

    tba.ids.insert(tba.id);

    while (cht.size() >= 2) {
        auto last   = cht[cht.size() - 1];
        auto plast = cht[cht.size() - 2];
        if (inter(last, tba) - inter(plast, last) < 1e-6)
            cht.pop_back();
        else {
            if (fabsl(inter(last, tba) - inter(plast, last)) < 1e-6)
                for (auto i : last.ids)
                    tba.ids.insert(i);
            break;
        }
    }

    ld aux = INF;
    if (!cht.empty()) {
        aux = inter(cht.back(), tba);
        cht.back().x_inter = aux;
    }

    cht.push_back(tba);
}


int n;

int32_t main (){
    fastio;
    cin >> n;
    int vt,vs;
    set <int> vazio;
    for (int i = 0 ; i < n; i ++){
        cin >> vt >> vs;
        tbordered.push_back ({vs, -((ld)(R*vs))/vt, INF, i, vazio});
        tbacessed.push_back ({vs, -((ld)(R*vs))/vt, INF, i, vazio});
    }
    sort(tbordered.begin(), tbordered.end());

    for (auto r : tbordered)
        add_line(r);
        
    for (auto L : cht) {
        if (L.x_inter > 1e-6) {
            for (auto id : L.ids)
                solutions.insert(id);
        }
    }

    for (auto id : solutions)
        cout << id + 1 << " ";
    cout << endl;

    return 0;
}