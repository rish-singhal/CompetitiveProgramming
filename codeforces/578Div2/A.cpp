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
    int n;
    cin >> n;
    vector<int> v(10, 0);
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (c == 'L')
        {
            for (auto &x : v)
            {
                if (x == 0)
                {
                    x = 1;
                    break;
                }
            }
        }
        else if (c == 'R')
        {
            for (int i = 9; i >= 0; i--)
            {
                if (v[i] == 0)
                {
                    v[i] = 1;
                    break;
                }
            }
        }
        else
        {
            v[c - '0'] = 0;
        }
    }
    for (auto i : v)
        cout << i;
    cout << endl;
    return 0;
}
