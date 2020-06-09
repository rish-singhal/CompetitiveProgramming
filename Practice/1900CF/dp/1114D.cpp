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
const int inf = 1e8;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

/*
	
*/


int main(){
  fio();
  int n; cin>>n;
  vector<int> c;
  map<int,int> m;
  int b = -1;
  forn(i,n){
  	int v; cin>>v;
  	if(v!=b) {
  		c.pb(v);
  		m[v]++;
  	}
  	b = v;
  }
  int sz = c.size();
  vector<vector<int>> dp(sz,vector<int>(sz,0));
  auto nc = c;
  reverse(all(nc));
  forn(i,sz){
  	forn(j,sz){
  		if(i==0 || j==0) continue;
  		else{
  			if(nc[j]==c[i]) dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
  			dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
  		}
  	}
  }
 // cout<<dp[sz-1][sz-1]<<endl;
  cout<<(sz-1 - (dp[sz-1][sz-1]+1)/2)<<endl;
  return 0;
}