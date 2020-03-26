#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,j,k) for(int i=j;i<k;i++)
const int MAXN = 1e5 +5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int ds[MAXN];
vector <vector<int> > adj(MAXN);
int par[MAXN][30];
int lgn, n;

void dfs(int u, int p, int d=0){
  ds[u] = d;
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

int main(){
  fio();
  memset(ds, -1, sizeof ds); 
   cin>>n;
  lgn = 32 - __builtin_clz(n);
   forn(i,0,n-1){
    int u,v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  dfs(1,0);
  int q; cin>>q;
  while(q--){
    int u,v; cin>>u>>v;
    cout<<(ds[u] + ds[v] - 2*ds[lca(u,v)])<<endl;
  }
  return 0;
}

