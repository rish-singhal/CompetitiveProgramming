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

int n,m;

vector<vector<int>> adj(MAXN);
vector<int> ch(MAXN);
int val[MAXN], val2[MAXN];
int an =0;

void dfs(int u, int v){
	int b = ch[u];
	if(b==0) val[u]=0;
	else val[u] = val[v]+1;
	val2[u] = max(val[u],val2[v]);
	for(auto i:adj[u]){
		if(i!=v) {
			dfs(i,u);
		}
	}
	if(adj[u].size()==1 && val2[u]<=m && u!=1){
		an++;
	}
	//cout<<u<<" "<<val[u]<<" "<<val2[u]<<endl;
}

int main(){
  fio();
   cin>>n>>m;
  for1(i,n) cin>>ch[i];
  forn(i,n-1){
  	int u,v; cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  dfs(1,0);
  cout<<an<<endl;

  return 0;
}