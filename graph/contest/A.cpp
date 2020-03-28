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

int ds[MAXN];
vector <vector<int> > adj(MAXN);
int par[MAXN][30];
int lgn, n;

void dfs(int u, int p=-1, int d=0){
  ds[u] = d;
  for(auto &v:adj[u]){
    if(v!=p)
      dfs(v,u, d+1);
  }
}

int main(){
  fio();
  cin>>n;
  for(int i=0;i<n-1;i++){
    int u,v; cin>>u>>v;
    adj[u].pb(v);
    adj[v].pb(u); 
  } 
  dfs(1);
  int q; cin>>q;
  while(q--){
      int a,b; cin>>a>>b;
      LL k = ds[a] + ds[b];
      cout<<(k&1?"Odd":"Even")<<"\n";
  }
      return 0;
}

