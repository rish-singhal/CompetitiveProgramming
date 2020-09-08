#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define fi first
#define se second
#define pb push_back
#define forn(i,j,k) for(int i=j;i<k;i++)
const int MAXN = 2e5 +5;

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
//  cout<<u<<" "<<ds[u]<<" ---- "<<endl;
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
  int m; 
  cin>>n>>m;
  set<int> vvv[n];
  lgn = 32 - __builtin_clz(n);
   forn(i,0,n-1){
    int u,v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u);
//    vvv[u].insert(v);
  //  vvv[v].insert(u);
  }
  forn(i,1,n+1) sort(adj[i].begin(), adj[i].end());
  dfs(1,-1);
  //for(int i=1;i<=n;i++) cout<<ds[i]<<" ";
  //cout<<endl;
  while(m--){
    int nn; cin>>nn;
    vector <pair<int,int> > vv(nn);
    forn(i,0,nn) {
      cin>>vv[i].se; 
      vv[i].fi = ds[vv[i].se];
    }
    sort(vv.rbegin(),vv.rend());
 //   for(auto i:vv) cout<<i.fi<<" "<<i.se<<endl;
  //  cout<<"----"<<endl;
    int op = vv[0].se;
    int ff = 0;
    for(int i=1;i<nn;i++){
        op = lca(op, vv[i].se);
//        cout<<vv[i].se<<" : "<<op<<endl;
        if(op==vv[i].se) continue;
        
        if(!binary_search(adj[op].begin(), adj[op].end(), vv[i].se))
        {     cout<<"NO\n";
           ff =1; break;
        }
    }
    if(ff==0) cout<<"YES\n";
  }
  return 0;
}

