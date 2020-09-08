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
    string a, b;
    cin >> a >> b;
    string x = "abc";
    // do
    // {
    //     string k = "";
    //     k += x[2];
    //     k += x[0];
    //     if (x.find(a) == string::npos && x.find(b) == string::npos && k != a && k != b)
    //     {
    //         cout << "YES\n";
    //         forn(oo, n)
    //                 cout
    //             << x;
    //         return 0;
    //     }
    // } while (next_permutation(all(x)));
    // x = "abc";
    do
    {
        if (x.find(a) == string::npos && x.find(b) == string::npos)
        {
            cout << "YES\n";
            forn(oo, n)
                    cout
                << x[0];

            forn(oo, n)
                    cout
                << x[1];

            forn(oo, n)
                    cout
                << x[2];
            cout << endl;
            return 0;
        }
    } while (next_permutation(all(x)));
    cout << "NO\n";
    return 0;
}