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


int vis[MAXN], dp[MAXN], lvl[MAXN];
vector<vector<int>> adj(MAXN);
int an = 0;
map<pair<int,int>, int> mm;

void dfs(int u, int p){
	vis[u] = 1;
	dp[u] = 0;
	for(auto i:adj[u]){
		if(!vis[i]){
			lvl[i] = lvl[u]+1;
			dfs(i, u);
			dp[u] += dp[i];
		}
		else if(lvl[i] > lvl[u]){
			dp[u]--;
		}
		else if(lvl[i] < lvl[u]){
			dp[u]++;
		}
	}
	dp[u]--;
	if(dp[u]==0 && u!=1 && mm[{u,p}]==1){
		an++;
	}
}


int main(){
  fio();
  int n,m ;cin>>n>>m;
  forn(i,m){
  	int a,b; cin>>a>>b;
  	if(mm.find({a,b})==mm.end())
  	{
  		adj[a].pb(b);
  		adj[b].pb(a);
  	}
  	mm[{a,b}]++;
  	mm[{b,a}]++;
  }
  dfs(1, 0);
  cout<<(m-an)<<endl;
  return 0;
}