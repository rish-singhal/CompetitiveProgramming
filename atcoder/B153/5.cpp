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

bool comp(pair<LL,LL> i1, pair<LL,LL> i2) 
{ 
    if(i1.fi*i2.se > i2.fi*i1.se) 
        return true;
    if(i1.fi*i2.se > i2.fi*i1.se && i1.fi > i2.fi)  
      return true;

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    LL h,n; cin>>h>>n;
    vector <pair<LL,LL> > a(n);
    forn(i,n) cin>>a[i].fi>>a[i].se;
    vector <LL> dp(h+1,1e18);
    dp[h] = 0;
    for(LL i = h; i>=0 ;i--){
      for(auto j:a){
        dp[max(0LL,i-j.fi)] = min(dp[max(0LL,i-j.fi)], dp[i] + j.se);
      }
//      for(auto j:dp) cout<<j<<" ";
  //    cout<<endl;
    }
    cout<<dp[0]<<endl;
    return 0;
}

