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
const int MAXN = 100+5;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector <int> adj[MAXN];
int vis[MAXN];
int cnt = 0;

void dfs(int u, int p)
{
	//cout<<u<<" "<<p<<endl;
	vis[u] = 1;
	for(auto i:adj[u]){
		if(i!=p && vis[i]==1) cnt++;
		if(vis[i]==0) dfs(i,u);
	}
	vis[u] = 2;
}
int main(){
  fio();
  int n, m; cin>>n>>m;
  forn(i,m){
  	int u, v; cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  
  int cc = 0;
  for1(i,n){
   if(vis[i]==0){
  	dfs(i, 0);
  	++cc;
  }
  if(cc>1){
  	cout<<"NO"<<endl;
  	return 0;
  }
}
  cout<<(cnt==1?"FHTAGN!":"NO")<<endl;
  return 0;
}