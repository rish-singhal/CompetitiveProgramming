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
#define minx(a,b) a = (a)>(b)?(b):(a)
const LL inf = 1e18 + 5;
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
      vector <LL> v(n);
      vector <LL> a(n);
      forn(i,n) cin>>v[i]>>a[i];
      vector <vector<LL> > dp(n,vector<LL>(3,inf));
      dp[0][0] = 0, dp[0][1] = a[0], dp[0][2] = 2*a[0];
      for(int i=1;i<n;i++)
        for(int j=0;j<3;j++)
          for(int k=0;k<3;k++)
            if(v[i-1] + k != v[i] + j)
              minx(dp[i][j], j*a[i] + dp[i-1][k]);
      
      cout<<min({dp[n-1][0], dp[n-1][1],dp[n-1][2]})<<endl;
    }
    return 0;
}

