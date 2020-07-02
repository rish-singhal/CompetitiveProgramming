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
const int INF = 1e9;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

struct CentroidDecompos{
	vector<set<int>> v;
	vector<int> dad, sz, ds, col;
	set<pair<int,int>> an[MAXN];
	vector<vector<int>> par;
	int nn, lgn = 20;
	CentroidDecompos(vector<set<int>> &v): v(v){
		nn = v.size();
		ds.resize(nn,0);
		dad.resize(nn);
		col.resize(nn);
		sz.resize(nn);
		par.assign(nn, vector<int>(21,0));
		forn(i,nn) an[i].insert({INF,-1});
		inidfs(0, -1);
		build(0, -1);
	}
	void build(int u, int p){
		int n = dfs(u,-1);
		int cent = centroid(u, -1, n);
		dad[cent] = p==-1?cent:p;
		for(auto i:v[cent]){
			v[i].erase(cent);
			build(i, cent);
		}
		v[cent].clear();
	}
	int dfs(int u, int p){
		sz[u] = 1;
		for(auto i:v[u])
			if(i!=p) sz[u] += dfs(i,u);
		return sz[u];
	}
	void inidfs(int u, int p){
		if(p!=-1) par[u][0] = p;
	  	for(int i=1;i<=lgn;i++)
	    	par[u][i] = par[par[u][i-1]][i-1];
		for(auto i:v[u])
			if(i!=p) {
				ds[i] = ds[u] + 1;
				inidfs(i,u);
			}
	}
	int centroid(int u, int p, int n){
		for(auto i:v[u])
			if(i!=p && sz[i] > (n/2)) return centroid(i, u, n);
		return u;
	}	
	int lca(int u, int v){
	  if(ds[u] > ds[v]) swap(u,v);
	  int dd = ds[v]-ds[u];
	  for(int i=0;i<=lgn;i++)
	    if(dd>>i&1) v = par[v][i];
	  if(u==v) return u;
	  for(int i=lgn;i>=0;i--)
	    if(par[u][i]!=par[v][i])
	      u = par[u][i], v = par[v][i];
	  return par[u][0];
	}
	int dis(int u, int x){
		return ds[u] + ds[x] - 2*ds[lca(u,x)];
	}
	void up(int u){
		int x = u;
		while(1){
			int dd = dis(u,x);
			if(an[x].find({dd,u})!=an[x].end()) 
				an[x].erase({dd,u});
			else an[x].insert({dd,u});
			if(dad[x]==x) break;
			x = dad[x];
		}
	}
	int qu(int u){
		int x = u;
		int ans = 2*INF;
		while(1){
			ans = min(ans, (*an[x].begin()).fi + dis(u,x));
			if(dad[x]==x) break;
			x = dad[x];
		}
		return ans;
	}
};

int main(){
  fio();
  int n,m; cin>>n;
  vector<set<int>> v(n);
  forn(i,n-1){
  	int a,b; cin>>a>>b;
  	a--,b--;
  	v[a].insert(b);
  	v[b].insert(a);
  }
  CentroidDecompos cd(v);
  cin>>m;

  while(m--){
  	int t,u; cin>>t>>u;
  	if(t==0){
  		cd.up(--u);
  	}
  	else{
  		int an = cd.qu(--u);
  		cout<<(an>=INF?-1:an)<<endl;
  	}
  }
  return 0;
}