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

int vis[MAXN], an[MAXN], dis[MAXN];
vector<vector<int> > adj(MAXN);

int main(){
  fio();
  int n,m; cin>>n>>m;
  forn(i,m){
  	int u,v; cin>>u>>v;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  for1(i,n) dis[i] = 1e9;
  queue <pair<int,int>> q;
  q.push({1,0});
  dis[1] = 0;
  while(!q.empty()){
  	auto y = q.front();
  	q.pop();
  	int x = y.fi;
  	if(vis[x]) continue;
  	vis[x] = 1;
  	an[x] = y.se;
  	for(auto i:adj[x]){
  		if(!vis[i]){
  			q.push({i,x});
  		}
  	}
  }
  int chk = 1;
  for(int i=2;i<=n;i++) chk&=(an[i]>=1);
  if(chk){
  	cout<<"Yes"<<endl;
  	for(int i=2;i<=n;i++) cout<<an[i]<<endl;
  }
  else cout<<"No"<<endl;
  return 0;
}