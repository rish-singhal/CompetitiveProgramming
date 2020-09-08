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

void solve(){
	LL n; cin>>n;
	vector <LL> v(n+1);
	for1(i,n) cin>>v[i];
	vector <LL> dp(n+1, 0);
	for(LL i = n; i>=1;i--){
		for(LL j = 2*i; j<=n ; j+=i){
			if(v[j]>v[i])dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	LL an = 0;
	// for1(i,n) cout<<dp[i]<<" ";
	// cout<<endl;
	for1(i,n) an = max(an, dp[i]);
	cout<<(an+1)<<endl;
}

int main(){
  fio();
  int  t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}