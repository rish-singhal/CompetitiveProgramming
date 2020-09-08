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

int n,q; 
vector<int> a(MAXN);
vector<vector<int>> adj(MAXN);
int pa[MAXN][20], dp[MAXN][101];
int d[MAXN];

void dfs(int u, int p = 0){
	dp[u][a[u]] = 1;
	d[u] = d[p]+1;
	if(p!=-1){
		forn(i,101) dp[u][i]+=dp[p][i];
	}
	pa[u][0] = p;
	for(int i = 1; i<=19; i++){
		pa[u][i] = pa[pa[u][i-1]][i-1];
	}
	for(auto i:adj[u])
		if(i!=p) dfs(i,u);
}

int go(int u, int di){
	int ds = 0;
	for(int i=19;i>=0;i--){
		if(ds+(1<<i)<=di){
			ds+=1<<i;
			u = pa[u][i];
		}
	}
	return u;
}

int lca(int u, int v){
	if(d[u]>d[v]) swap(u,v);
	if(d[u]!=d[v]){
		v = go(v, d[v]-d[u]);
	}
	if(u==v) return u;
	for(int i=19;i>=0;i--){
		if(pa[u][i]!=pa[v][i]){
			u = pa[u][i];
			v = pa[v][i];
		}
	}
	return pa[u][0];
}

void res(){
	cin>>n>>q;
	forn(i,n+1){
		a[i] = 0;
		adj[i].clear();
		forn(j,20) pa[i][j] = 0;
		forn(j,101) dp[i][j] = 0;
		d[i] =0;
	}
}

void solve(){
	res();
	for1(i,n) cin>>a[i];
	forn(i,n-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	while(q--){
		int u,v; cin>>u>>v;
		vector<int> aa(101);
		int lc = lca(u,v);
		//cout<<u<<" "<<v<<" "<<lc<<endl;
		//cout<<go(u,1)<<endl;
		int an = 1e8;
		vector<int> in;
		forn(i,101) {
			aa[i] = dp[u][i] + dp[v][i] - 2*dp[lc][i] + (a[lc]==i);
			if(aa[i]>=2){
				an = 0;
			}
			if(aa[i]) in.pb(i);
			//cout<<aa[i]<<" ";
		}
		//cout<<endl;
	    if(an == 0){
	    	cout<<0<<endl;
	    }
	    else{
	    	for(int i=0;i<(in.size()-1);i++)
	    		an = min(an, in[i+1]-in[i]);
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