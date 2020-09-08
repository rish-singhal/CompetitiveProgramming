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
LL in[21][21], c[21];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    int n; cin>>n;
    forn(i,n){
      int a; cin>>a;
      a--;
      forn(i,20) in[a][i] += c[i];
      c[a]++;
    }
    LL an = 0;
    vector <LL> dp(1<<20,1e15);
    dp[0]=0;
    forn(msk,1<<20)
      forn(j,20)
        if((msk&(1<<j))==0){
         LL kk = 0;
          forn(k,20)
            if(msk&(1<<k)){
              kk += in[j][k];
            }
        dp[msk^(1<<j)] = min(dp[msk^(1<<j)], dp[msk] + kk);
        }
    cout<<dp[(1<<20)-1]<<endl;
    return 0;
}

