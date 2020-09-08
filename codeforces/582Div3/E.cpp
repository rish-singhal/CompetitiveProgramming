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
  if (n == 1)
  {
    string x = "abc";
    do
    {
      if (x.find(a) == string::npos && x.find(b) == string::npos)
      {
        cout << "YES\n";
        cout << x << endl;
        return 0;
      }
    } while (next_permutation(all(x)));
    cout << "NO\n"
         << endl;
    return 0;
  }
  else
  {
    string x = "abcabcabc";
    do
    {
      if (x.find(a) == string::npos && x.find(b) == string::npos)
      {
        if (n == 3)
        {
          cout << "YES\n";
          cout << x << endl;
          return 0;
        }
        string s = "";
        s += x[5];
        s += x[0];
        if (s != a && s != b)
        {
          string ss = "";
          for (int i = 0; i < (n / 3); i++)
            ss += x;
          if ((n % 3) == 0)
          {
            cout << "YES\n";
            cout << ss << endl;
            return 0;
          }
          if (n % 3 == 1)
          {
            string y = "abc";
            do
            {
              s = "";
              s += x[5];
              s += y[0];
              if (y.find(a) == string::npos && y.find(b) == string::npos && s != a && s != b)
              {
                cout << "YES\n";
                cout << ss;
                cout << y << endl;
                return 0;
              }
            } while (next_permutation(all(y)));
          }
          if (n % 3 == 2)
          {
            //cout << " wererwe " << endl;
            string y = "abcabc";
            do
            {
              s = "";
              s += x[5];
              s += y[0];
              if (y.find(a) == string::npos && y.find(b) == string::npos && s != a && s != b)
              {
                cout << "YES\n";
                cout << ss;
                cout << y << endl;
                return 0;
              }
            } while (next_permutation(all(y)));
          }
        }
      }
    } while (next_permutation(all(x)));
    cout << "NO\n";
  }
  return 0;
}
