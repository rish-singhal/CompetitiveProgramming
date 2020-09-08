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

vector<vector<int>> adj(MAXN);
vector<int> v(MAXN);
vector <int> ann;
void dfs(int u, int p, int h1, int h2){
	 //cout<<u<<": "<<h1<<" "<<h2<<endl;
	int val = h1;
	int nh1 = h2, nh2 = h1;
	if(h1!=v[u]) {
		nh2=h1^1;
		ann.pb(u);
	}
	for(auto i:adj[u])
		if(i!=p) dfs(i,u,nh1,nh2);
}

int main(){
  fio();
  int n; cin>>n;
  forn(i,n-1){
  	int u,v; cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  for1(i,n) cin>>v[i];
  for1(i,n){
  	int x; cin>>x;
  	v[i] = (v[i]!=x);
  }
  dfs(1,0,0,0);
  cout<<ann.size()<<endl;
  for(auto i:ann) cout<<i<<endl;
  return 0;
}