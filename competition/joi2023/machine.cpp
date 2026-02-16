#include <bits/stdc++.h>

using namespace std;

vector <int> lits, buttons;
int n, m, q;

pair<int,int> dd (int pos, int me, int md)
{
    int a,v;
    if (0 <= pos && pos < me)
    {
        a = md + ((n - md - me) - (lits[n - md - 1] - ((me > 0)? lits[me - 1] : 0)));
        v = pos;
    }
    else if (me <= pos && pos < n - md)
    {
        a = md + ((n - md - pos - 1) - (lits[n - md - 1] - lits[pos]));
        v = me + ((pos > 0? lits[pos - 1] : 0) - ((me > 0)? lits[me - 1] : 0));
    }
    else
    {
        a = n - 1 - pos;
        v = me + (lits[n - md - 1] - ((me > 0)? lits[me - 1] : 0));
    }
    return {a,v};
}

int main ()
{
    cin >> n >> m;

    char a;
    cin >> a;
    lits.push_back(a == 'R');

    for (int i = 1; i < n; i++)
    {
        char a;
        cin >> a;
        lits.push_back(lits[i-1] + (a == 'R'));
    }

    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        buttons.push_back(a - 1);
    }

    cin >> q;

    while (q--)
    {
        int l,r;
        cin >> l >> r;
        
        int md = 0, me = 0, pa = 0;

        for (int b = l - 1; b < r; b++)
        {
            int pos = buttons[b];
            int a,v;

            if (me + md < n)
            {
                if (0 <= pos && pos < me)
                {
                    a = md + ((n - md - me) - (lits[n - md - 1] - ((me > 0)? lits[me - 1] : 0)));
                    v = pos;
                }
                else if (me <= pos && pos < n - md)
                {
                    a = md + ((n - md - pos - 1) - (lits[n - md - 1] - lits[pos]));
                    v = me + ((pos > 0? lits[pos - 1] : 0) - ((me > 0)? lits[me - 1] : 0));
                }
                else
                {
                    a = n - 1 - pos;
                    v = me + (lits[n - md - 1] - ((me > 0)? lits[me - 1] : 0));
                }

                if (v>=a)
                {
                    int av = pos - 1;
                    if (a != 0)
                    {
                        int ind = 0, m, litm;
                        a = dd(pos,me,md).second + ((((lits[pos] - (pos > 0? lits[pos - 1] : 0)) == 1) && !(pos >= n - md)) || (pos < me)) - a;
                        while (ind < av)
                        {
                            m = (av + ind)/2;
                            litm = dd(m,me,md).second + ((((lits[av] - (av > 0? lits[av - 1] : 0)) == 1) && !(av >= n - md)) || (av < me));
                            
                            if (litm > a)
                                av = m - 1;
                            if (litm < a)
                                ind = m + 1;
                            if (litm == a)
                                av = m;
                        }
                        cout << '(' << ind << ' ' << m << ' ' << av << ')' << "  =  " << '[' << litm << '=' << a << ']' << ' ';
                    }
                    else
                        av = pos;
                    // for (av  = pos - 1; a > 0 && av >= 0; av--)
                    //     if ((((lits[av] - (av > 0? lits[av - 1] : 0)) == 1) && !(av >= n - md)) || (av < me))
                    //         a--;
                    // av++;
                    // cout << av << '\n'; 
                    md = ((n - av) > md)? n - av : md;

                    if (me + md >= n)
                    {
                        pa = n - md;
                    }
                }
                else
                {
                    int va;
                    for (va = pos + 1; v >= 0 && va < n; va++)
                        if (((lits [va] - lits[va - 1] == 0 && !(va < me))) || (va >= n - md))
                            v--;

                    me = (va > me)? va : me;

                    if (me + md >= n)
                    {
                        pa = me;
                    }
                }
            }
            else
            {
                if (pos >= pa)
                {
                    a = n - pos - 1;
                    v = pa;

                    if (a > v)
                        pa = pos + 1 + v + 1;
                    else
                        pa = pa - a;
                }
                else
                {
                    a = n - pa;
                    v = pos;

                    if (a > v)
                        pa = pa + v + 1;
                    else
                        pa = pos - a;
                }
            }
            //cout << me << '-' << md << '-' << pa << '\n';
        }

        if (me + md < n)
            cout << me + lits[n - md - 1] - (me>0? lits[me - 1] : 0) << '\n';
        else
            cout << pa << '\n';
    }
    return 0;
}