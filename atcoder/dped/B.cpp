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
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

LL dp[MAXN];	

int main(){
  fio();
  int n,k; cin>>n>>k;
  vector <LL> v(n);
  forn(i,n) cin>>v[i];
  dp[0] = 0;
  for1(i,n-1){
  	LL ans = 1e18;
  	for1(j,k){
  		if(i<j) break;
  		ans = min(ans, dp[i-j] + abs(v[i-j]-v[i]));
  	}
  	dp[i] = ans;
  }
  cout<<dp[n-1]<<endl;
  return 0;
}