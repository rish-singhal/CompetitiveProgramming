#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,n) for(int i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 2e3 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[MAXN][MAXN];

int main(){
  fio();
  int n; cin>>n;
  vector<pair<LL,LL> > v(n+1);
  v[0].fi = 1e18;
  for1(i,n){
	cin>>v[i].fi;
	v[i].se = i;
	}
  sort(v.begin(),v.end(),greater<pair<LL,LL> >());

  for1(i,n){
  	auto u = v[i];
  	for(LL j = 0; j<i; j++){
  		LL l = j;
  		LL r = (i-1-j);
  		dp[l+1][r] = max(dp[l+1][r],dp[l][r] + abs(l+1-u.se)*u.fi);
  		dp[l][r+1] = max(dp[l][r+1],dp[l][r] + abs(n- r -u.se)*u.fi);
  	}
  }
 // cout<<endl;
  LL an = 0;
  forn(i,n+1)  an = max(an, dp[i][n-i]);
  cout<<an<<endl;
  return 0;
}
