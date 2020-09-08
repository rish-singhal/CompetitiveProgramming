#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define pii pair<LL,LL> 
#define forn(i,n) for(LL i=0;i<(n);i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forr(i,n) for(int i=n;i>=0;i--)
#define all(x) x.begin(), x.end()
const int MAXN = 500 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int dp[MAXN][MAXN];

int main(){
  fio();
  int n,k; cin>>n>>k;
  LL an = 0;
  vector<pii> v;
  LL ax =0;
  forn(i,n){
  	LL a,b; cin>>a>>b;
  	v.pb({a, b});
  	ax+=a+b;
  }
  forn(i,n)
  	forn(r,k){
  		if((i==0 && r>=1)|| (i>=1 && dp[i-1][r]==0)) continue;
  		forn(j,k){
  			LL a = v[i].fi, b = v[i].se;
  			if((a-j+b)%k<=b && j<=a)
  					dp[i][(j+r)%k] = 1;
  		}
  	}
  LL ann = 0;
  forn(i,k){
  	if(dp[n-1][i]){
  		LL j = (ax%k -i + k)%k;
  		LL zz = (ax-j-i)/k;
  		ann = max(zz,ann);
  	}
  }
  cout<<ann<<endl;
  return 0;
}