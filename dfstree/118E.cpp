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
int dis[MAXN], dp[MAXN];

vector<pair<int,int>> v;

void dfs(int i, int p){
	//cout<<i<<" "<<p<<endl;
	dp[i] = 0;
	for(auto j:adj[i]){
		if(j==p) continue;
		if(dis[j]==0){
			dis[j] = dis[i]+1;
			dfs(j,i);
			dp[i]+=dp[j];
			v.pb({i,j});
		}
		else if(dis[i]>dis[j]){
			dp[i]++;
		//	v.pb({j,i});
		}
		else if(dis[i]<dis[j]){
			dp[i]--;
			v.pb({j,i});
		}
	}
	if(dp[i]==0 && p!=0){
		cout<<"0"<<endl;
		exit(0);
	}
}

int main(){
  fio();
  cin>>n>>m;
  forn(i,m){
  	int u, v; cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  dis[1]=1;
  dfs(1,0);
  for(auto i:v) cout<<i.fi<<" "<<i.se<<endl;

  return 0;
}