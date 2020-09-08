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
const int inf = 1e7;

void fio(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}

int main(){
  fio();
  int n,m; cin>>n>>m;
  vector<vector<int>> adj(n);
  forn(i,m){
  	int u,v; cin>>u>>v;
  	u--, v--;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  int a,b,c,d,t1,t2; cin>>a>>b>>t1>>c>>d>>t2;
  a--,b--,c--,d--;
  vector<vector<int>> dp(n,vector<int>(n,-1));	
  forn(u,n){
  	dp[u][u]=0;
  	queue <int> q;
  	q.push(u);
  	while(!q.empty()){
  		int v = q.front();
  		q.pop();
  		for(auto i:adj[v]){
  			if(dp[u][i]!=-1) continue;
  			dp[u][i] = dp[u][v]+1;
  			q.push(i);
  		}
  	}
  }
  if(dp[a][b]>t1 || dp[c][d]>t2){
  	cout<<-1<<endl;
  	return 0;
  }
  int an  = -1;
  if(dp[a][b]<=t1 && dp[c][d]<=t2)
 		 an = m - dp[a][b] - dp[c][d];
  forn(k,2){
  	swap(a,b);
  forn(i,n){
  	forn(j,n){
  		if(dp[a][i] + dp[i][j] + dp[j][b] <= t1 && dp[c][j] + dp[i][j] + dp[i][d]<=t2)
  		an = max(an, m - (dp[a][i] + dp[i][j] + dp[c][j] + dp[i][d] + dp[j][b]) );
  	}
  }
}
  cout<<an<<endl;
  return 0;
}