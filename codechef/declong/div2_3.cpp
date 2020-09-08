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
    int t; cin>>t;
    while(t--)
    {
      int n; cin>>n;
      string s; cin>>s;
      vector<int> v[26];
      forn(i,n) v[s[i]-'a'].pb(i);
      int gap = n;
      forn(i,26)
        for(int j = 1;j<v[i].size();j++)
          gap  = min(gap,v[i][j] - v[i][j-1]);
      cout<<(n-gap)<<endl;
    }
    return 0;
}

