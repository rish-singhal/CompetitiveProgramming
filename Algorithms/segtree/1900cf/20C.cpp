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

// 1 + 3 + 1 = 5

int main(){
  fio();
  int n,m; cin>>n>>m;
  vector<vector<pair<int,LL>>> adj(n+1);
  forn(i,m){
 	LL u,v,w; cin>>u>>v>>w;
 	adj[u].pb({v,w});
 	adj[v].pb({u,w});
  }
  vector<LL> di(n+1,1e18), pa(n+1,-1);
  priority_queue <array<LL,3>, vector<array<LL,3>>, greater<array<LL,3>>> pq;
  pq.push({0,1,-1});
  while(!pq.empty()){
  	auto v = pq.top();
  	pq.pop();
  	if(di[v[1]]<v[0]) continue;
  	//cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
  	di[v[1]] = v[0];
  	pa[v[1]] = v[2];
  	for(auto i:adj[v[1]]){
  		LL w = i.se;
  		int u = i.fi;
  		//if(v[1]==3) cout<<w<<" "<<u<<endl;
  		if(di[u]>w+v[0]){
  			pq.push({w+v[0],u,v[1]});
  		}
  	}
  }
  if(pa[n]==-1){
  	cout<<-1<<endl;
  	return 0;
  }

  vector<int> an;
  int x = n;
  an.pb(n);
  while(pa[x]!=-1){
  	an.pb(pa[x]);
  	x = pa[x];
  }
  for(auto i:vector<int>(an.rbegin(),an.rend()))
  	cout<<i<<" ";
  cout<<endl;
  return 0;
}