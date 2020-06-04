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
const int MAXN = 2e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}


int par[MAXN][21];
int a[MAXN];
int ds[MAXN];
int lgn = 20, n;
vector<vector<int>> adj(MAXN);
int dp[MAXN][101];

void dfs(int u, int p, int d=0){
  ds[u] = d;
  dp[u][a[u]] = 1;
  forn(i,101) dp[u][i] += dp[p][i];
  if(p!=-1) par[u][0] = p;
  for(int i=1;i<=lgn;i++)
    par[u][i] = par[par[u][i-1]][i-1];
  for(auto &v:adj[u]){
    if(v!=p)
      dfs(v,u, d+1);
  }
}

int mov(int u, int k){
  for(int i=0;i<=lgn;i++)
    if(k>>i&1) u = par[u][i];
  return u;
}

int lca(int u, int v){
  if(ds[u] > ds[v]) swap(u,v);
  v = mov(v,ds[v]-ds[u]);
  if(u==v){
    return u;
  }
  for(int i=lgn;i>=0;i--){
    if(par[u][i]!=par[v][i]){
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

void res(){
	cin>>n;
	forn(i,n+1){
		ds[i] = a[i] = 0;
		forn(j,21) par[i][j]=0;
		adj[i].clear();
		forn(j,101) dp[i][j]=0;
	}
}

void solve(){
	res();
	int q; 	
	cin>>q;
	for1(i,n) cin>>a[i];
	forn(i,n-1){
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	while(q--){
		int u, v; cin>>u>>v;
		int lc = lca(u,v);
		vector<int> in;
		int b = 0;
		forn(i,101)
			{
				int x = dp[u][i] + dp[v][i] - 2*dp[lc][i] + (a[lc]==i);
				if(x>=2) b = 1;
				if(x) in.pb(i);
			}
		if(b) cout<<0<<endl;
		else{
			int an = 500;
			for(int i=0;i<(in.size()-1);i++)
				an = min(an, -in[i]+in[i+1]);
			cout<<an<<endl;
		}
	}
}

int main(){
  fio();
  int t; cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}