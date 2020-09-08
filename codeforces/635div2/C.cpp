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

vector<vector<int> > adj(MAXN);
LL dis[MAXN], sz[MAXN];
int n,k;
vector<LL> ans;

LL dfs(int i, int p, int d){
	dis[i] = d;
	sz[i] = 0;
	for(auto u:adj[i]){
		if(u!=p){
		 sz[i] += dfs(u,i,d+1)+1;
		}
	}
	ans.pb(dis[i]-sz[i]);
	//cout<<i<<" "<<(sz[i])<<endl;
	return sz[i];
}

int main(){
  fio();
 cin>>n>>k;
  forn(i,n-1){
  	int u,v; cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  dfs(1,0,0);
   sort(all(ans));
  reverse(all(ans));
  LL an =0;
  forn(i,k){
  	an+=ans[i];
  }
  cout<<an<<endl;
  return 0;
}