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
vector<int> v;
vector<vector<pair<int,int> > > adj(MAXN);
vector<vector<int> > boo(MAXN);
int vis[MAXN];
int co[MAXN];

void dfs(int u, int c){
	co[u] = c;
	vis[u] = 1;
	for(auto i:adj[u]){
		int cc = i.fi, vv = i.se;
		if(vis[vv]==1 && co[vv]!=cc^c){
			cout<<"NO"<<endl;
			exit(0);
		}
		if(!vis[vv]) dfs(vv, cc^c);
	}
}

int main(){
  fio();
  cin>>n>>m;
  v.resize(n);
  for(auto &i:v){
   cin>>i;
}	

  forn(i,m){	
  	int t; cin>>t;
  	while(t--){
  		int x; cin>>x;
  		x--;
  		boo[x].pb(i);
  	}
  }
  map< pair<int,int> , int> mm;
  forn(i,n){
  	int a = boo[i][0];
  	int b = boo[i][1];
  	if(v[i]==0)
  		{
  			adj[a].emplace_back(1,b);
  			adj[b].emplace_back(1,a);
  		}
  	else 
  		{
			adj[b].emplace_back(0,a);
			adj[a].emplace_back(0,b);
  		}
  }
  forn(i,m) if(!vis[i]) dfs(i,0);
  cout<<"YES\n";
}
