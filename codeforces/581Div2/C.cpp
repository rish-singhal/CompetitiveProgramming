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
LL inf = 1e18;
LL d[105][105];
LL par[1000005];
LL dis[1000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    LL n;
    cin >> n;
    forn(i, n)
    {
        forn(j, n) if (i != j) d[i][j] = inf;
    }
    forn(i, n)
    {
        string x;
        cin >> x;
        forn(j, n) if (x[j] == '1') d[i][j] = 1;
    }
    LL m;
    cin >> m;
    vector<LL> v(m);
    forn(i, m)
    {
        dis[i] = inf;
        cin >> v[i];
        v[i]--;
    }
    dis[0] = 0;

    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (d[i][k] < inf && d[k][j] < inf)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    par[0] = -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + d[v[i]][j] < m && v[i + d[v[i]][j]] == j)
            {
                if (dis[i + d[v[i]][j]] > dis[i] + d[v[i]][j])
                {
                    dis[i + d[v[i]][j]] = dis[i] + d[v[i]][j];
                    par[i + d[v[i]][j]] = i;
                }
            }
        }
    }
    vector<LL> an;
    LL p = par[m - 1];
    an.pb(v[m - 1] + 1);
    while (p >= 0)
    {
        an.pb(v[p] + 1);
        p = par[p];
    }
    reverse(all(an));
    cout << an.size() << endl;
    for (auto i : an)
        cout << i << " ";
    cout << endl;
    return 0;
}