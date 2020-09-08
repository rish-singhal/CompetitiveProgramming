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
    vector<int> v(3);
    string a, b;
    cin >> a >> b;
    forn(i, 3)
    {
        v[0] = v[1] = v[2] = 0;
        string s = "";
        s += (char)('a' + i);
        v[i]++;
        forn(j, 3 * n - 1)
        {
            set<int> x;
            forn(p, 3)
            {

                string k = "";
                k += s[s.size() - 1];
                k += (char)('a' + p);
                if (k != a && k != b)
                {
                    x.insert(p);
                }
            }
            vector<int> op;
            for (auto ccc : x)
                op.pb(ccc);
            if (op.size() == 1)
            {
                v[op[0]]++;
                s += (char)('a' + op[0]);
            }
            if (op.size() == 2)
            {
                if (v[op[0]] > v[op[1]])
                {
                    v[op[1]]++;
                    s += (char)('a' + op[1]);
                }
                else
                {
                    v[op[0]]++;
                    s += (char)('a' + op[0]);
                }
            }
        }
        if (v[0] == n && v[1] == n && v[2] == n)
        {
            cout << "YES\n";
            cout << s << endl;
            return 0;
        }
        cout << s << endl;
    }
    cout << "NO\n";
    return 0;
}