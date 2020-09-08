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

LL deg[MAXN];
vector<vector<LL> > adj(MAXN);
set<LL> ss;
void dfs(int u, int p, int d){
		if(deg[u]==1) {
			ss.insert(d);}
		for(auto i:adj[u]){
			if(i!=p){
				dfs(i,u,d^1);
			}
		}
}

int main(){
  fio();
  int n; cin>>n;
  vector<LL> vv;
  set<LL> s;
  LL man = 0;
  forn(i,n-1){
  	int u,v; cin>>u>>v;
  	deg[u]++, deg[v]++;
  	adj[u].pb(v);
  	adj[v].pb(u);
  }
  for1(i,n){
  	if(deg[i]==1){
  		man++;
  		s.insert(adj[i][0]);
  	}
  }

  man -= s.size();
  man = n-1-man;
  dfs(1,-1,0);
  LL b = 0;
  for(auto i:ss){
  	for(auto j:ss){
  		b|=(i^j);
  	}
  }
  cout<<(b?3:1)<<" "<<man<<endl;

  return 0;
}