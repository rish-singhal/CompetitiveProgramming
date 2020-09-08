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
    int t;
    cin >> t;
    while (t--)
    {
        LL a;
        string b;
        cin >> a >> b;
        if (a == 0)
            cout << b << endl;
        else
        {
            LL k = 0;
            for (auto i : b)
            {
                k = (k * 10 + i - '0') % a;
            }
            cout << (__gcd(a, k)) << endl;
        }
    }
    return 0;
}