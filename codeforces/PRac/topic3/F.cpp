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
const int MAXN = 5e4 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int n,k;
vector<vector<int>>adj(MAXN);
int dp[MAXN][505];

void dfs(int i, int p){
	//cout<<i<<" "<<p<<endl;
	dp[i][0] = 1;
	for(auto u:adj[i]){
		if(u==p) continue;
		dfs(u,i);
		for1(d,k) dp[i][d]+=dp[u][d-1];
	}
}

LL an = 0;

void dfs2(int i, int p){
	//cout<<i<<" "<<p<<endl;
	if(p!=0){
		for1(d,k) dp[p][d]-=dp[i][d-1];
		for1(d,k) dp[i][d]+=dp[p][d-1];
	}
	an+=(LL) dp[i][k];
	//cout<<i<<": "<<dp[i][k]<<endl;
	for(auto u:adj[i]){
		//cout<<u<<" --";
		if(u!=p) dfs2(u,i);
	}
	if(p!=0){
		for1(d,k) dp[i][d]-=dp[p][d-1];
		for1(d,k) dp[p][d]+=dp[i][d-1];
	}
}

int main(){
  fio();
  cin>>n>>k;
  forn(i,n-1){
  	int u,v; cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  dfs(1,0);
  // for1(i,n){
  // 	cout<<i<<": ";
  // 	forn(j,k+1) cout<<dp[i][j]<<" ";
  // 	cout<<endl;
  // }
  dfs2(1,0);
  cout<<(an/2)<<endl;
  return 0;
}