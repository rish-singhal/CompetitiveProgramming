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
    forn(z,t){
      int n; cin>>n;
      vector<int> v(n);
      forn(i,n) cin>>v[i];
      int m = 1e8;
      int c= 0;
      for(int i = n-1;i>=0;i--)
         { if( m < v[i]) c++;
           else m = v[i];
         }
      cout<<c<<endl;
    }
      return 0;
}

