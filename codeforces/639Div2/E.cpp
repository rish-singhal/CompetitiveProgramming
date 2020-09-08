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
const int inf = 1e9;
void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

vector <vector<int> > adj(MAXN), radj(MAXN);
int n,m;
int vis[MAXN];
vector<int> tp;

void dfs(int u){
	vis[u] = 1;
	for(auto i:adj[u]){
		if(vis[i]==1){
			cout<<-1<<endl;
			exit(0);
		}
		if(vis[i]==0) dfs(i);
	}
	vis[u]=2;
	tp.pb(u);
}

int main(){
  fio();
  cin>>n>>m;
  forn(i,m){
  	int u,v; cin>>u>>v;
  	adj[u].pb(v);
  	radj[v].pb(u);
  }
  for1(i,n)
  	if(vis[i]==0)dfs(i);
  vector<int> dp(n+1);
  iota(all(dp),0);
  vector<int> rdp(n+1, inf);
  iota(all(rdp),0);
  for(auto i:tp){
  	dp[i] = min(dp[i],i);
  	for(auto j:radj[i])
  		dp[j] = min(dp[j], dp[i]);
  }
  for(auto i:vector<int>(tp.rbegin(), tp.rend())){
  	rdp[i] = min(rdp[i],i);
  	for(auto j:adj[i])
  		rdp[j] = min(rdp[j], rdp[i]);
  }
  int count = 0;
  string an ="";
  for1(i,n){
  	if(dp[i]<i || rdp[i]<i){
  		an+="E";
  	}
  	else {
  		an+="A";
  		++count;
  	}
  }
  cout<<count<<endl;
  cout<<an<<endl;
  return 0;
}