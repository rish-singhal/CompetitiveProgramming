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
    string s;
    cin >> s;
    reverse(all(s));
    int cnt = 0;
    for (auto &c : s)
        if (c == '0')
            cnt++;
        else if (cnt)
            cnt--;
        else
            c = '0';
    reverse(all(s));
    cout << s << endl;
    return 0;
}