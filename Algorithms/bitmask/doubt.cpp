#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
const LL inf = 1e17;

LL dp[1<<17];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n; cin>>n;
  vector<LL> a(n), b(n);
  forn(i,n) cin>>a[i];
  forn(i,n) cin>>b[i];
  for1(msk,((1<<n)-1)){
  	dp[msk] = inf;
  	int k = __builtin_popcount(msk) - 1;
  	forn(j,n)
  		if((msk>>j)&1)
  		   	dp[msk] = min(dp[msk],dp[msk^(1<<j)]+b[j]^a[k]);
  }
  cout<<dp[(1<<n)-1]<<endl;
  return 0;
}