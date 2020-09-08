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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    int len = (int)sqrt(n + .0) + 1;
    vector<int> b(len);
    forn(i, n) cin >> v[i];
    forn(i, n)
    {
        b[i / len] += v[i];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        int c_l = l / len, c_r = r / len;
        if (c_l == c_r)
        {
            for (int i = l; i <= r; i++)
            {
                sum += v[i];
            }
        }
        else
        {
            for (int i = l; i < (c_l + 1) * len; i++)
            {
                sum += v[i];
            }
            for (int i = c_l; i < c_r; i++)
            {
                sum += b[i];
            }
            for (int i = (c_r)*len; i <= r; i++)
            {
                sum += v[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}