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
    int q; cin>>q;
    while(q--){
      int n; cin>>n;
      vector <int> v(35);
      forn(i,n){
        LL k; cin>>k;
        v[__builtin_ctzll(k)]++;
      }
      for(int i=0;i<11;i++)
         v[i+1]+=v[i]/2;
      cout<<(v[11]?"YES\n":"NO\n");
    }
    return 0;
}

