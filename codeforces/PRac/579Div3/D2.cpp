#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define vi vector<int>
#define srt(a) sort(a.begin(), a.end());
#define se second
#define fi first
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    vector<int> v[26];
    string a, b;
    cin >> a >> b;
//    cout<<a.size()<<endl;
    forn(i, a.size())
        v[a[i] - 'a'].pb(i);
    int m = 0;
    for (auto l : v[b[0] - 'a'])
    {
        cout << "rewrwe" << endl;
        int r = l, f = 1;
        LL k = 0;
        for (int i = 1; i < b.size(); i++)
        {
            auto c = lower_bound(all(v[b[i] - 'a']), r + 1);
            if (c == v[b[i] - 'a'].end())
            {
                f = 0;
                break;
            } 
            k  = max( k, *c - r - 1);
            cout<<k<<" wee " <<endl;
            r = *c;
  //          cout<<r<<endl;
        }
        if (f == 0)
            break;
        cout << l << " " << r;
        m  = max(m,k);
        m = max(m, max(l, a.size() - 1 - r));
    }
    cout << m << endl;

    return 0;
}
